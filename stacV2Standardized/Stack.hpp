#pragma once

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

    // Reajuste de tamaño segun necesidad
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
    Stack(int cap)
    {
        if (cap <=0)
        {
            throw std::out_of_range("Invalid Capacity")
        }
        capacity = cap;
        origialCapacity = cap;
        data = new T[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] data;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == capacity - 1;
    }

    int size() const
    {
        return top + 1;
    }

    void clear()
    {
        top = -1;
        delete[] data;
        data = new T[origialCapacity];
    }

    void show();    

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
            return false;
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


