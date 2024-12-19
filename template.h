#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Зангилаа бүтэц
template <class T>
struct Node{
  T data;
  Node *next;
};

// Linked list загвар класс
template <class T>
class LinkedList{
  private:
    Node<T> *head;

  public:
    LinkedList(){
      head = NULL;
    }

    ~LinkedList(){
      while (head){
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
      }
    }

    // Жагсаалтын сүүлд элементийг нэмэх функц
    void add(T t){
      Node<T> *newNode = new Node<T>;
      newNode->data = t;
      newNode->next = NULL;

      if (head == NULL){
        head = newNode;
      }
      else {
        Node<T> *tmp = head;
        while (tmp->next){
          tmp = tmp->next;
        }
        tmp->next = newNode;
      }
    }

    // Index - дүгээрт элемент оруулна
    void insert(T t, int index){
      int len = length();

      if (index == 0){
        Node<T> *newNode = new Node<T>;
        newNode->data = t;
        newNode->next = head;
        head = newNode;
      }
      else if (index >= len){
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

    // i-р элементийн утгыг буцаана
    T get(int index){
      int len = length();

      if (index >= len || index < 0){
        cout << "Индекс буруу байна!" << endl;
        return T();
      }

      Node<T> *tmp = head;
      for (int i = 0; i < index; i++){
        tmp = tmp->next;
      }

      return tmp->data;
    }

    // i-р элементийг устгана
    void deleteNode(int index){
      if(index < 0 || index >= length()){
        cout << "Индекс буруу байна!" << endl;
        return;
      }

      Node<T> *toDelete;
      if(index == 0){
        toDelete = head;
        head = head->next;
      }
      else{
        Node<T> *tmp = head;
        for(int i = 0; i < index - 1; ++i){
          tmp = tmp->next;
        }
        toDelete = tmp->next;
        tmp->next = toDelete->next;
      }
      delete toDelete;
    }

    // Жагсаалтын уртыг буцаана
    int length(){
      int i = 0;
      Node<T> *tmp = head;
      while(tmp != NULL){
        i++;
        tmp = tmp->next;
      }
      return i;
    }
};
