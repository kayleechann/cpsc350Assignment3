#include <iostream>
using namespace std;

template <typename T>
class GenStack{
public:
  GenStack();
  GenStack(int maxSize);
  ~GenStack();

  void resize();
  void push(T data);
  T pop(); //removes first item on stack
  T peek(); //looks at first item on stack

  bool isFull();
  bool isEmpty();
  int getSize();

private:
  int top;
  int mSize;
  char *myArray;

};

//GenStack.cpp
// template <typename T>
// GenStack<T>::GenStack(){
//   myArray = new T[128];
//   mSize = 128;
//   top = -1;
// }

//overloaded constructor
template <typename T>
GenStack<T>::GenStack(int maxSize){
  myArray = new char[maxSize];
  mSize = maxSize;
  top = -1;
}

template <typename T>
GenStack<T>::~GenStack(){
  delete myArray;
}

template <typename T>
void GenStack<T>::resize(){
  T *tempArray = new T[mSize*2];
  for(int i = 0; i < mSize; ++i){
    tempArray[i] = myArray[i];
  }
  myArray = tempArray;
  mSize = mSize*2;
}

template <typename T>
void GenStack<T>::push(T data){
  if(isFull()){
    resize();
  }
  myArray[++top] = data; //preincrement --> increment before we add
}

template <typename T>
T GenStack<T>::pop(){
  if(isEmpty()){
    cout << "ERROR: stack is empty" << endl;
    return  '\0';
  }
  return myArray[top--]; //doesn't actually remove from array, we're just decrementing the variable that keeps
  //track of the current element
}

template <typename T>
T GenStack<T>::peek(){
  if(isEmpty()){
    cout << "stack is currently empty" << endl;
    return 0;
  }
  return myArray[top];
}

template <typename T>
bool GenStack<T>::isEmpty(){
  //1 = true, 0 = false
  return (top == -1);
}

template <typename T>
bool GenStack<T>::isFull(){
  return (top  == mSize -1 );
}

template <typename T>
int GenStack<T>::getSize(){
  return top + 1;
}
