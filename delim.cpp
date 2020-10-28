#include <fstream>
#include "delim.h"

delim::delim(){
//constructor
}

delim::~delim(){
//destructor
}

/*
parseFile() method - parses user's file to check if there are any missing delimeters
int - returns 0 for the purpose to exit program after one error is found
parameter - string of filename
*/
int delim::parseFile(string filename){
  int lineNum = 1;
  bool repeating = true;
  ifstream readFile;
  readFile.open(filename, ios::in);
  //instantiate a stack of size 20
  GenStack<char> stack(20);
  while(repeating){
    while(!readFile.eof()){
      string str;
      char c;
      getline(readFile, str);
      for(int i = 0; i < str.length(); ++i){
        c = str[i];
        //if it finds an "open" delimter then push it onto the stack
        if(c == '{'){
          stack.push(c);
        }else if(c == '['){
          stack.push(c);
        }else if(c == '('){
          stack.push(c);
          /* if it finds any of the "closing" delimeters, then peek() to check the top item on the stack matches the respective delimter
          if it matches, then pop it off the stack
          */
        }else if( c == '}'){
          if(stack.peek() == '{'){
            stack.pop();
          }else if(stack.peek() == '('){
            //if it doesn't match, then output an error message
            cout << "Line Num: " << lineNum << " expected ) but found " << c << endl;
            return 0; //returns 0 to  end the method, so the user has a chance to fix their file
          }else if(stack.peek() == '['){
            cout << "Line Num: " << lineNum << " expected ] but found " << c << endl;
            return 0;
          }
        }else if ( c == ']'){
          if(stack.peek() == '['){
            stack.pop();
          }else if(stack.peek() == '('){
            cout << "Line Num: " << lineNum << " expected ) but found " << c << endl;
            return 0;
          }else if(stack.peek() == '{'){
            cout << "Line Num: " << lineNum << " expected } but found " << c << endl;
            return 0;
          }
        }else if ( c == ')'){
          if(stack.peek() == '('){
            stack.pop();
          }else if(stack.peek() == '{'){
            cout << "Line Num: " << lineNum << " expected } but found " << c << endl;
            return 0;
          }else if(stack.peek() == '['){
            cout << "Line Num: " << lineNum << " expected ] but found " << c << endl;
            return 0;
          }
        }

      }
      lineNum++;
    }

    //checks if stack is empty to confirm that all delimters match
    if(stack.isEmpty() == 1){
      string userInput;
      cout << "No missing or incorrect delimeters! " << endl;
      cout << "Would you like to process another file? (yes/no) " << endl;
      cin >> userInput;

      if(userInput == "yes"){
        string file;
        cout << "What is the test file you would like to process? (include .txt extension) " << endl;
        cin >> file;
        continue;
      }else{
        repeating = false;
      }
    }else{
      //if stack isn't empty, then there are missing delimeters
      char missing;
      if(stack.peek() == '('){
        missing = ')';
      }else if(stack.peek() == '['){
          missing = ']';
      }else if(stack.peek() == '{'){
          missing = '}';
      }
      //output missing delimeter to the user
      cout << "Reached end of file: missing " << missing << endl;
      repeating = false;
      return 0;
    }

  }

}
