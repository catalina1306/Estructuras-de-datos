#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>

class Stack
{
    private:

        // dynamic array
        T* data;            

        // maximum number of elements
        int capacity;
        int origialCapacity;    
        
        // index of the last inserted element
        int top;            

        /*
            Resizes the internal array according to need.
            - If the new capacity is lower than the number of stored elements or 0, throw an exception.
            - Elements are moved to a new dynamic array with updated capacity.
        */
        void resize(int newCapacity)
        {
            if (newCapacity < size() || newCapacity == 0)
                throw std::out_of_range("Invalid NewCapacity");

            T* newData = new T[newCapacity];

            for (int i = 0; i <= top; i++)
                newData[i] = std::move(data[i]);

            delete[] data;
            data = newData;
            capacity = newCapacity;
        }


    public:

        // constructor
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

        // copy constructor
        Stack(const Stack& other)
        {
            capacity = other.capacity;
            origialCapacity = other.origialCapacity;
            top = other.top;

            data = new T[capacity];
            for (int i = 0; i <= top; ++i)
                data[i] = other.data[i];
        }
        
        // copy assignment
        Stack& operator=(const Stack& other)
        {
            if (this == &other)
                return *this;

            delete[] data;

            capacity = other.capacity;
            origialCapacity = other.origialCapacity;
            top = other.top;

            data = new T[capacity];
            for (int i = 0; i <= top; ++i)
                data[i] = other.data[i];

            return *this;
        }

        // move constructor
        Stack(Stack&& other) noexcept
        {
            data = other.data;
            capacity = other.capacity;
            origialCapacity = other.origialCapacity;
            top = other.top;

            other.data = nullptr;
            other.capacity = 0;
            other.top = -1;
        }

        // returns true if the stack is empty
        bool isEmpty() const { return top == -1; }

        // returns true if the stack is full
        bool isFull() const { return top == capacity - 1; }

        // returns the number of used positions
        int size() const { return top + 1; }

        // clears the stack while keeping original configuration
        void clear()
        {
            delete[] data;
            capacity = origialCapacity;
            data = new T[origialCapacity];
            top = -1;
        }

        // inserts a new element at the top
        bool push(T value)
        {   
            if (isFull())
                resize(capacity*2);
            
            top++;
            data[top] =  value;
            return true;
        }

        // removes the top element
        T pop()
        {
            if (isEmpty())
                throw std::out_of_range("Empty Stack");
            
            top--;

            if (size() < (capacity/4))
                resize(int(capacity * (3.0/4.0)));

            return data[top+1];
            
        }

        // returns reference to the element at the top
        const T& peek() const
        {   
            if (isEmpty())
                throw std::out_of_range("Empty Stack");
            
            return data[top];
        }

         // visual representation of the stack
        void show() const
        {
            for (int i = top ; i >=0; i--)
            {
                std::cout << "[" << data[i] <<"] <-" ;
            }
        }
};  