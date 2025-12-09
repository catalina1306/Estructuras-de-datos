#pragma once
#include <string>
#include <iostream>

template <typename T>

class Stack
{
private:
    T* data;      // arreglo dinamico
    int capacity; // maximo de elementos
    int top;      // indice del ultimo elemento
    bool resize();

public:
    Stack(int capacity);
    ~Stack();
    bool push(T value);
    bool pop();
    T peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void clear();
    void show();
};

