#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template <class T>
class LinkedList {
private:
    vector<T> items;
public:
    void add(T t) {
        items.push_back(t);
    }
    void insert(T t, int index) {
        if (index >= 0 && index <= items.size()) {
            items.insert(items.begin() + index, t);
        } else {
            cout << "Индекс буруу байна!" << endl;
        }
    }
    T get(int index) {
        if (index >= 0 && index < items.size()) {
            return items[index];
        }
        throw out_of_range("Индекс буруу байна!");
    }
    void remove(int index) {
        if (index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
        } else {
            cout << "Индекс буруу байна!" << endl;
        }
    }
    int length() {
        return items.size();
    }
};

class Shape {
public:
    virtual float area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}
    float area() const override {
        return 3.14 * radius * radius;
    }
    void display() const override {
        cout << "Тойрог, Радиус: " << radius << ", Талбай: " << area() << endl;
    }
};

class Square : public Shape {
    float side;
public:
    Square(float s) : side(s) {}
    float area() const override {
        return side * side;
    }
    void display() const override {
        cout << "Дөрвөлжин, Тал: " << side << ", Талбай: " << area() << endl;
    }
};

class Triangle : public Shape {
    float side;
public:
    Triangle(float s) : side(s) {}
    float area() const override {
        return (sqrt(3) / 4) * side * side;
    }
    void display() const override {
        cout << "Гурвалжин, Тал: " << side << ", Талбай: " << area() << endl;
    }
};

int main() {
    LinkedList<Shape*> shapes;

    // durs uusgeh
    for (int i = 0; i < 10; ++i) {
        shapes.add(new Circle(rand() % 10 + 1));
        shapes.add(new Square(rand() % 10 + 1));
        shapes.add(new Triangle(rand() % 10 + 1));
    }

    // erembleh
    vector<Shape*> sortedShapes;
    for (int i = 0; i < shapes.length(); ++i) {
        sortedShapes.push_back(shapes.get(i));
    }
    sort(sortedShapes.begin(), sortedShapes.end(), [](Shape* a, Shape* b) {
        return a->area() < b->area();
    });

    for (const auto& shape : sortedShapes) {
        shape->display();
    }

    for (const auto& shape : sortedShapes) {
        delete shape;
    }

    return 0;
}