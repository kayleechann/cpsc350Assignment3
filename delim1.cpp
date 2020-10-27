// #include <fstream>
// #include "delim.h"
//
// delim::delim(){
//
// }
//
// delim::~delim(){
//
// }
//
// int delim::parseFile(string filename){
//   int lineNum = 1;
//   bool repeating = true;
//   ifstream readFile;
//   readFile.open(filename, ios::in);
//   GenStack<char> stack(20);
//   while(repeating){
//     while(!readFile.eof()){
//       string str;
//       char c;
//       getline(readFile, str);
//       for(int i = 0; i < str.length(); ++i){
//         c = str[i];
//         if(c == '{'){
//           //cout << "adding { " << endl;
//           stack.push(c);
//         }else if(c == '['){
//           //cout << "adding [ " << endl;
//           stack.push(c);
//         }else if(c == '('){
//           //cout << "adding ( " << endl;
//           stack.push(c);
//         }else if( c == '}'){
//           if(stack.peek() == '{'){
//             stack.pop();
//           }else if(stack.peek() == '('){
//             cout << "Line Num: " << lineNum << " expected ) but found " << c << endl;
//             return 0;
//           }else if(stack.peek() == '['){
//             cout << "Line Num: " << lineNum << " expected ] but found " << c << endl;
//             return 0;
//           }
//         }else if ( c == ']'){
//           if(stack.peek() == '['){
//             stack.pop();
//           }else if(stack.peek() == '('){
//             cout << "Line Num: " << lineNum << " expected ) but found " << c << endl;
//             return 0;
//           }else if(stack.peek() == '{'){
//             cout << "Line Num: " << lineNum << " expected } but found " << c << endl;
//             return 0;
//           }
//         }else if ( c == ')'){
//           if(stack.peek() == '('){
//             stack.pop();
//           }else if(stack.peek() == '{'){
//             cout << "Line Num: " << lineNum << " expected } but found " << c << endl;
//             return 0;
//           }else if(stack.peek() == '['){
//             cout << "Line Num: " << lineNum << " expected ] but found " << c << endl;
//             return 0;
//           }
//         }
//
//       }
//       lineNum++;
//     }
//
//     if(stack.isEmpty() == 1){
//       string userInput;
//       cout << "No missing or incorrect delimeters! " << endl;
//       cout << "Would you like to process another file? (yes/no) " << endl;
//       cin >> userInput;
//
//       if(userInput == "yes"){
//         string file;
//         cout << "What is the test file you would like to process? (include .txt extension) " << endl;
//         cin >> file;
//         continue;
//       }else{
//         repeating = false;
//       }
//     }else{
//       char missing;
//       if(stack.peek() == '('){
//         missing = ')';
//       }else if(stack.peek() == '['){
//           missing = ']';
//       }else if(stack.peek() == '{'){
//           missing = '}';
//       }
//       cout << "Reached end of file: missing " << missing << endl;
//       repeating = false;
//       return 0;
//     }
//
//   }
//
// }
