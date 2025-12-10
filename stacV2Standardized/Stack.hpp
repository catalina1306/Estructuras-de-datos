#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>

class Stack
{
private:

    // arreglo dinamico
    T* data;            

    // maximo de elementos
    int capacity;
    int origialCapacity;
    
    // indice del ultimo elemento agregado
    int top;            

    /*Reajuste de tamaño segun necesidad
      Si esta ocupado menos de 1/4 de la capacidad se reduce la capacidad a 3/4 
      Si esta a su capacidad maxima se duplica la capacidad*/ 
    void resize(int newCapacity)
    {
        if (newCapacity < size() || newCapacity == 0)
            throw std::out_of_range("Invalid NewCapacity");

        T* newData = new T[newCapacity];

        for (int i = 0; i <= top; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }


public:

    // contructor
    Stack(int cap)
    {
        if (cap <=0)
        {
            throw std::out_of_range("Invalid Capacity");
        }
        capacity = cap;
        origialCapacity = cap;
        data = new T[capacity];
        top = -1;
    }

    // destructor
    ~Stack()
    {
        delete[] data;
    }

    // retorna true si la pila esta vacia
    bool isEmpty() const
    {
        return top == -1;
    }

    // retorna true si la pila esta llena
    bool isFull() const
    {
        return top == capacity - 1;
    }

    // retorna la cantidad de espacios utilizados
    int size() const
    {
        return top + 1;
    }

    // limpia la pila manteniendo la configuracion original
    void clear()
    {
        top = -1;
        delete[] data;
        capacity = origialCapacity;
        data = new T[origialCapacity];
    }

    // muestra visual de la pila
    void show()
    {
        for (int i = top ; i >=0; i--)
        {
            std::cout << " ---\n";
            std::cout << "| " << data[i] <<" |\n" ;
            std::cout << " ---\n";
            std::cout << "  ^  \n" ;
            std::cout << "  |  \n";
        }
    }

    bool push(T value)
    {   
        if (isFull())
        {
            resize(capacity*2);
        }
        top++;
        data[top] =  value;
        return true;
    }

    bool pop()
    {
        if (isEmpty()){
            throw std::out_of_range("Empty Stack");
        }
        else 
        {   
            if (size() < (capacity/4))
            {
                resize(int(capacity * (3.0/4.0)));
            }
            top--;
            return true;
        }
    }

    T peek() const
    {   
        if (isEmpty())
        {
            throw std::out_of_range("Empty Stack");
        }   
        else 
        {
            return data[top];
        }
    }
};