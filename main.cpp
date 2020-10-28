#include  "delim.h"

int main(int argc, char **argv){
  delim d;

  //check if user entered a command line argument
  if(argc < 2){
    cout << "ERROR: not a valid number of command line argumnets! " <<endl;
  }else if(argc == 2){
    string filename = argv[1];
    d.parseFile(filename);
  }
  return 0;
}
