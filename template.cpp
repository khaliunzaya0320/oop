#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;


//Ерөнхий дүрсийн класс
class Shape{
  protected:
    char name[10];
  public:
    Shape(const char *n = "shape"){
      strcpy(name, n);
    }
    void set_name(char *n){
      strcpy(name, n);
    }
    char *get_name(){ return name; }
};

//2D дүрсийн класс
class TwoDShape : public Shape{
  protected:
    float length, area, perimeter;
    int *x, *y;
  public:
    TwoDShape(float l = 0) : Shape(){
      length = l;
      area = 0;
      perimeter = 0;
      x = NULL;
      y = NULL;
    }
    ~TwoDShape(){
      delete []x;
      delete []y;
    }
    void set_x(int _x){ this->x[0] = _x; }
    void set_y(int _y){ this->y[0] = _y; }
    int get_x(){ return x[0]; }
    int get_y(){ return y[0]; }
    float get_area(){ return area; }
    float get_perimeter(){ return perimeter; }
    void findArea(float _a){ area = _a; }
    void findPerimeter(float _p){ perimeter = _p; }
    void setCoordinates(int _x, int _y){}
    //Дүрсийн мэдээллийг гараас авах функц
    void getData(){
      int x, y;
      cout << endl << "Name of shape: ";
      cin >> name;
      set_name(name);
      cout << "X coordinate: ";
      cin >> x;
      set_x(x);
      cout << "Y coordinate: ";
      cin >> y;
      set_y(y);
    }
    //Дүрсийн нэр, талбай, периметрийг хэвлэх функц
    void displayData(){
      cout << endl << "--- " << this->get_name() << " information ---" << endl;
      cout << "Area = " << area << endl;
      cout << "Perimeter = " << perimeter << endl;
    }
};

//Тойрог класс
class Circle : public TwoDShape{
  public:
    Circle() : TwoDShape(){
      x = new int[1];
      y = new int[1];
    }   
    void setCoordinates(int _x, int _y){        
      this->x[0] = _x;        
      this->y[0] = _y;    
    }  
    //Тойргийн мэдээллийг авах функц
    void getData(){
      TwoDShape::getData();           //эх классын getData функцийг дуудна
      cout << "Radius of circle: ";
      cin >> length;

      findArea(PI * length * length); //Тойргийн талбай, периметрийг тооцно
      findPerimeter(2 * PI * length);
    }

    void displayData(){
      TwoDShape :: displayData();
      setCoordinates(*x, *y);
      for(int i = 0; i < 1; i++){
        cout << "Vertex " << i + 1 << " = (" << x[i] << ", " << y[i] << ")" << endl;
      }
    }
};

//Квадрат класс
class Square : public TwoDShape{
  public:
    Square() : TwoDShape(){
      x = new int[4]; 
      y = new int[4]; 
    }
    //Квадратын оройн цэгүүдийг олох функц
    void setCoordinates(int _x, int _y){
      this->x[0] = _x;        
      this->y[0] = _y;        
      this->x[1] = _x;        
      this->y[1] = _y - length;       
      this->x[2] = _x + length;        
      this->y[2] = _y - length;       
      this->x[3] = _x + length;       
      this->y[3] = _y; 
    }
    //Квадратын мэдээллийг авах функц
    void getData(){
      TwoDShape::getData();  //эх классын getData функцийг дуудна
      cout << "Side length of square: ";
      cin >> length;
      findArea(length * length); //Квадратын талбай, периметрийг олно
      findPerimeter(4 * length);
    }
    void displayData(){
      TwoDShape :: displayData();
      setCoordinates(*x, *y);
      for(int i = 0; i < 4; i++){
        cout << "Vertex " << i + 1 << " = (" << x[i] << ", " << y[i] << ")" << endl;
      }
    }
};

//Гурвалжин класс
class Triangle : public TwoDShape{  
  public:
    Triangle() : TwoDShape(){
      x = new int[3]; 
      y = new int[3]; 
    }
    //Гурвалжины оройн цэгүүдийг олох функц  
    void setCoordinates(int _x, int _y){
      this->x[0] = _x;        
      this->y[0] = _y;        
      this->x[1] = _x - length / 2;       
      this->y[1] = _y - (sqrt(3)/2) * length;    
      this->x[2] = _x + length / 2;      
      this->y[2] = _y - (sqrt(3)/2) * length;
    }
    //Гурвалжны суурь,өндрийг гараас авах функц
    void getData(){
      TwoDShape::getData();
      cout << "Side length of triangle: ";
      cin >> length;
      setCoordinates(*x, *y);
      findArea((sqrt(3) / 4) * length * length);  
      findPerimeter(3 * length);
    }
    void displayData(){
      TwoDShape :: displayData();
      setCoordinates(*x, *y);
      for(int i = 0; i < 3; i++){
        cout << "Vertex " << i + 1 << " = (" << x[i] << ", " << y[i] << ")" << endl;
      }
    }
};




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
  int size;

  //Linked list классын байгуулагч функц
  LinkedList(){
    size = 0;
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
    size++;
  }

  //Index - дүгээрт элемент оруулна
  void insert(T t, int index){
    if(index == 0){
      Node<T> *newNode = new Node<T>;
      newNode->data = t;
      newNode->next = head;
      head = newNode;
    }
    Node *newNode = new Node(t);  //Шинэ элемент үүсгэх
    if(index == 0){               //Эхэнд оруулах
      newNode->next = head;
      head = newNode;
    } 
    else{
      Node *tmp = head;
      for(int i = 0; i < index - 1; ++i){  //Зөв индекс хүртэл
        tmp = tmp->next;
      }
      newNode->next = tmp->next;
      tmp->next = newNode;  //Индексийн байрлалд элемент оруулах
    }
    size++;
  }

  //i-р элементийн утгыг буцаана
  T get(int index){
    if (index < 0 || index >= size) {
      throw out_of_range("Индекс буруу байна!");
    }
    Node *tmp = head;
    for (int i = 0; i < index; ++i) {  //Индекс хүртэл гүйж элемент олоод буцаах
      tmp = tmp->next;
    }
    return tmp->data;
  }

  //i-р элементийг устгана
  void delete(int index){
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