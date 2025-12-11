#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>

class Vector 
{
    private:

        // dynamic array 
        T* data;

        int capacity, size_;

        /*
        
        void resize(int newCapacity)
        {

        }

        void shrink_to_fit()
        {
        
        }
        */


    public:

        // constructor
        Vector(int initialCapacity)
        {   
            if (initialCapacity <=0) 
                throw std::out_of_range("Initial Capacity must be hier than 0");
           
            capacity = initialCapacity;
            data = new T[initialCapacity];
            size_ = 0;
        }

        // copy constructor
        Vector(const Vector& other)
        {
            capacity = other.capacity;
            size_ = other.size_;

            data = new T[capacity];

            for (int i = 0; i < size_; ++i)
                data[i] = other.data[i];
        }

        // move constructor
        Vector(Vector&& other) noexcept
        {
            data = other.data;
            capacity = other.capacity;
            size_ = other.size_;

            other.data = nullptr;
            other.capacity = 0;
            other.size_ = 0;
        }

        // copy assignment
        Vector& operator=(const Vector& other)
        {
            if (this == &other)
                return *this;

            delete[] data;

            capacity = other.capacity;
            size_ = other.size_;

            data = new T[capacity];

            for (int i = 0; i < size_; ++i)
                data[i] = other.data[i];

            return *this;
        }

        // destructor

        ~Vector() { delete[] data;}

        int size() const { return size_;}

        int capacity() const { return capacity;}

        bool empty() const { return size_ == 0;}

        T& operator[](int index)
        {
            if (index >= size_ || index < 0 )
               throw std::out_of_range("index out of range");

            return data[index];

        }

        const T& operator[](int index) const
        {
            if (index >= size_ || index < 0 )
               throw std::out_of_range("index out of range");
            
            return data[index];
        }


        void push_back(const T&& value)
        {
            if (size_ == capacity)
            {
                capacity *=2 ;
                T* newData = new T[capacity];

                for (int i = 0; i < size_; i++)
                    newData[i] = std::move(data[i]);

                delete[] data;
                data = newData;
            }

            data[size_] = std::move(value);
            size_++;
        }


        T pop_back()
        {
            if (empty())
                throw std::out_of_range("Empty Vector");

            size_--;
            return data[size_];
        }  

        Void insert(int index, const T& value)
        {
            // validar el indice
            // revisar capacidad
            // mover los indices
            // insertar valor
        }

        Void erase(int index)
        {
            // validar indice
            // mover los elementos
            // disminuir el size-
        }

        void show() {}
        


};

