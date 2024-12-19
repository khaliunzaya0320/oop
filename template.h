#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Зангилаа бүтэц
template <class T>
struct Node{
  T data;     //Зангилааны өгөгдлийг хадгалах хувьсагч
  Node *next; //Дараагийн зангилааны хаягийг хадгалах заагч
};

//Linked list класс
template <class T>
class LinkedList{
  protected:
    Node<T> *head; //Эхлэл зангилааны хаягийг хадгалах заагч

  public:
    LinkedList(){
      head = NULL;
    }

    ~LinkedList(){
      while (head){
        Node<T> *tmp = head;
        head = head->next;   //Дараагийн зангилааг head рүү шилжүүлнэ
        delete tmp;          //Одоогийн зангилааг устгана
      }
    }

    // Жагсаалтын сүүлд элементийг нэмэх функц
    void add(T t){
      Node<T> *newNode = new Node<T>;
      newNode->data = t;
      newNode->next = NULL;

      if(head == NULL){
        head = newNode; //Жагсаалт хоосон бол шинэ зангилааг эхлэл болгоно
      }
      else{
        Node<T> *tmp = head;
        while(tmp->next){
          tmp = tmp->next; //Жагсаалтын төгсгөл хүртэл явна
        }
        tmp->next = newNode; //Жагсаалтын төгсгөлд шинэ зангилааг холбоно
      }
    }

    // Index - дүгээрт элемент оруулна
    void insert(T t, int index){
      int len = length(); //Жагсаалтын уртыг авна

      if(index == 0){
        Node<T> *newNode = new Node<T>;
        newNode->data = t;
        newNode->next = head;
        head = newNode;  //Жагсаалтын эхэнд элемент нэмнэ
      }
      else if(index >= len){
        add(t);           // Жагсаалтын сүүлд нэмнэ
      }
      else{
        Node<T> *newNode = new Node<T>;
        newNode->data = t;
        Node<T> *temp = head;

        for(int i = 0; i < index - 1; i++){
          temp = temp->next;
        }

        newNode->next = temp->next; //Шинэ зангилааг холбоно
        temp->next = newNode;
      }
    }

    // i-р элементийн утгыг буцаана
    T get(int index){
      int len = length();

      if(index >= len || index < 0){
        cout << "Индекс буруу байна!" << endl;
        return T();
      }

      Node<T> *tmp = head;
      for(int i = 0; i < index; i++){
        tmp = tmp->next;
      }

      return tmp->data; //Тухайн зангилааны өгөгдлийг буцаана
    }

    // i-р элементийг устгана
    void delete(int index){
      if(index < 0 || index >= length()){
        cout << "Индекс буруу байна!" << endl;
        return;
      }

      Node<T> *toDelete;
      if(index == 0){
        toDelete = head;
        head = head->next; //Эхний зангилааг устгах
      }
      else{
        Node<T> *tmp = head;
        for(int i = 0; i < index - 1; ++i){
          tmp = tmp->next;
        }
        toDelete = tmp->next;
        tmp->next = toDelete->next; //Зангилааг жагсаалтаас салгах
      }
      delete toDelete; //Зангилааг устгах
    }

    // Жагсаалтын уртыг буцаана
    int length(){
      int l = 0;
      Node<T> *tmp = head;
      while(tmp != NULL){ //Жагсаалтын төгсгөл хүртэл явна
        l++;
        tmp = tmp->next;
      }
      return l;
    }
};
