#include <iostream>
using namespace std;

class stackArray{
public:
    int *data;
    int nextIndex;
    int capacity;

 stackArray(){
    data = new int[4];
    nextIndex = 0;
    capacity = 4;
 }
//Stack size gets double if stack becomes Full 
 void push(int element){
     if(capacity == nextIndex){
         int *newArray = new int[2*capacity];
         for(int element =0; element < capacity; element++){
             newArray[element] = data[element];
         }

         delete[] data;
         data = newArray;
         capacity = capacity * 2;

     }
         data[nextIndex] = element; 
         nextIndex +=1;
 }
 
 bool isEmpty(){
     if(nextIndex ==0){
         return true;
     }
     return false;
 }

 void pop(){
     if(isEmpty()){
         cout << "Invalid Operation Stack Is empty";
     }else{
        data[nextIndex-1] = -1;
        nextIndex = nextIndex-1;
     }
 }


//It only Display Stack top Element
void top(){
      if(isEmpty()){
         cout << "Invalid Operation Stack Is empty"<< endl;
     }else{
         cout << "Top Element = " << data[nextIndex-1]<<endl;
     }
}

};

int main() {
stackArray obj;
obj.push(1);
obj.push(1);
obj.push(1);
obj.push(1);
obj.push(1);
//This place stack size Becomes 8  beacuase initialy size was 4
}