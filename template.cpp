#include <iostream>
#include <vector>
using namespace std;


//Linked list загвар класс
template <typename T>
class LinkedList{
private:
  T data;
  Node *head;
  Node *next;
  int size;

public:
  //Жагсаалтын сүүлд элемент нэмнэ
  void add(T t){
    Node *newNode = new Node(t);

    size++;
  }

  //Index - дүгээрт элемент оруулна
  void insert(T t, int index){

  }

  //i-р элементийн утгыг буцаана
  T get(int index){

  }

  //i-р элементийг устгана
  void delete(int index){

  }

  //Жагсаалтын уртыг буцаана
  int length(){
    return size;
  }
};


int main(){

  return 0;
}