#pragma once

class Stack
{
private:
    int* data;    // arreglo dinamico
    int capacity; // maximo de elementos
    int top;      // indice del ultimo elemento

public:
    Stack(int capacity);
    ~Stack();
    bool push(int value);
    bool pop();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
};
