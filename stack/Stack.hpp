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
                newData[i] = std::move(data[i]);

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

        // constructor de copia
        Stack(const Stack& other)
        {
            capacity = other.capacity;
            origialCapacity = other.origialCapacity;
            top = other.top;

            data = new T[capacity];
            for (int i = 0; i <= top; ++i)
                data[i] = other.data[i];
        }
        
        // asignacion por copia
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

        // constructor de movimiento
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

        // retorna true si la pila esta vacia
        bool isEmpty() const { return top == -1; }

        // retorna true si la pila esta llena
        bool isFull() const { return top == capacity - 1; }

        // retorna la cantidad de espacios utilizados
        int size() const { return top + 1; }

        // limpia la pila manteniendo la configuracion original
        void clear()
        {
            delete[] data;
            capacity = origialCapacity;
            data = new T[origialCapacity];
            top = -1;
        }

        bool push(T value)
        {   
            if (isFull())
                resize(capacity*2);
            
            top++;
            data[top] =  value;
            return true;
        }

        bool pop()
        {
            if (isEmpty())
                throw std::out_of_range("Empty Stack");
            
            top--;

            if (size() < (capacity/4))
                resize(int(capacity * (3.0/4.0)));

            return true;
            
        }

        const T& peek() const
        {   
            if (isEmpty())
                throw std::out_of_range("Empty Stack");
            
            return data[top];
        }

        // muestra visual de la pila
        void show() const
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
};