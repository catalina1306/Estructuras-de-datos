#include <iostream>
#include "Stack.hpp"

Stack::Stack(int cap)
{
    capacity = cap;
    data = new int[capacity];
    top = -1;
}

Stack::~Stack()
{
    delete[] data;
}

bool Stack::isEmpty() const
{
    if (top == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool Stack::isFull() const
{
    if (top == capacity-1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool Stack::push(int val)
{   
    if (isFull())
    {
        throw std::out_of_range("Pila LLena");
        return false;
    }
    else
    {
    top++;
    data[top] =  val;
    return true;
    }
}

bool Stack::pop()
{
    if (isEmpty()){
        throw std::out_of_range("Pila Vacia");
        return false;
    }
    else 
    {   
        top--;
        return true;
    }
}

int Stack::peek() const 
{   
    if (isEmpty())
    {
        throw std::out_of_range("Pila Vacia");
    }
    else 
    {
        return data[top];
    }
}
