#include <iostream>
#include <vector>
using namespace std;


//Linked list загвар класс
template <typename T>

class LinkedList{
protected:
  //Зангилаа бүтэц
  struct Node{
    T data;
    Node *next;

    //Зангилаа бүтцийн байгуулагч функц
    Node(T d){
    data = d;
    next = NULL;
    }
  }

  Node *head;
  int size;

  //Linked list классын байгуулагч функц
  LinkedList(){
    size = 0;
    head = NULL;
  }

  //Linked list классын устгагч функц
  ~LinkedList(){
    while(head){
      Node *tmp = head;   //элементийг устгахдаа хэрэглэх заагч
      head = head->next;
      delete tmp;
    }
  }

public:
  //Жагсаалтын сүүлд элементийг нэмэх функц
  void add(T t){
    Node *newNode = new Node(t);

    if(head == NULL){   //Хэрэв элементгүй бол жагсаалтын эхэнд оруулна
      head = newNode;
    }
    else{
      Node *tmp = head;
      while(tmp->next){ //Жагсаалтын төгсгөл хүртэл явна
        tmp = tmp->next;
      }
      tmp->next = newNode; //Жагсаалтын төгсгөлд очоод элементийг холбоно
    }
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

    size--;
  }

  //Жагсаалтын уртыг буцаана
  int length(){
    return size;
  }
};



int main(){

  return 0;
}