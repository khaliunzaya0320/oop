#include <bits/stdc++.h>

//Зангилаа бүтэц
template <class T>
struct Node{
  T data;
  Node *next;
};

//Linked list загвар класс
template <class T> 
class LinkedList{
protected:
  Node<T> *head;

  //Linked list классын байгуулагч функц
  LinkedList(){
    head = NULL;
  }

  //Linked list классын устгагч функц
  ~LinkedList(){
    while(head){
      Node<T> *tmp = head;   //элементийг устгахдаа хэрэглэх заагч
      head = head->next;
      delete tmp;
    }
  }

public:
  //Жагсаалтын сүүлд элементийг нэмэх функц
  void add(T t){
    Node<T> *newNode = new Node<T>;
    newNode->data = t;
    newNode->next = NULL;

    if(head == NULL){   //Хэрэв элементгүй бол жагсаалтын эхэнд оруулна
      head = newNode;
    }
    else{
      Node<T> *tmp = head;
      while(tmp->next){ //Жагсаалтын төгсгөл хүртэл явна
        tmp = tmp->next;
      }
      tmp->next = newNode; //Жагсаалтын төгсгөлд очоод элементийг холбоно
    }
  }

  //Index - дүгээрт элемент оруулна
  void insert(T t, int index){
    int len = length();

    if(index == 0){
      Node<T> *newNode = new Node<T>;
      newNode->data = t;
      newNode->next = head;
      head = newNode;
    } 
    else if(index >= len){
      add(t);
    } 
    else{
      Node<T> *newNode = new Node<T>;
      newNode->data = t;
      Node<T> *temp = head;

      for (int i = 0; i < index - 1; i++){
        temp = temp->next;
      }

      newNode->next = temp->next;
      temp->next = newNode;
    }
  }

  //i-р элементийн утгыг буцаана
  T get(int index){
    int len = length();
    
    if (index >= len || index < 0){
      return T();
    }

    Node<T> *tmp = head;
    for (int i = 0; i < index; i++){
      tmp = tmp->next;
    }

    return tmp->data;
  }

  //i-р элементийг устгана
  void delete(int index){
    int len = length();
    if (isEmpty()) {
    return;
    } else if (index == 0) {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    return;
    } else if (index >= 0 || index < len) {
    Node<T>* curr = head;
    for (int i = 0; i < index - 1; i++) {
    curr = curr->next;
    }
    Node<T>* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    }

    if(index < 0 || index >= size){
      cout << "Индекс буруу байна!" << endl;
      return;
    }
    Node *toDelete;
    if(index == 0){                //Эхний элементийг устгах
      toDelete = head;
      head = head->next;
    } 
    else{
      Node *tmp = head;
      for(int i = 0; i < index - 1; ++i){  //Индексийн өмнөх элементийг олох
        tmp = tmp->next;
      }
      toDelete = tmp->next;
      tmp->next = toDelete->next;  //Элементийг устгах
    }
    delete toDelete; 
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