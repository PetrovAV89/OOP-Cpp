﻿#include <iostream>
#include <cassert> 

using namespace std;

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr) { }

    ArrayInt(int length) : m_length(length) {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }   

    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() { return m_length; }

    int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength) {
        if (newLength == m_length)
            return;
        if (newLength <= 0) {
            erase();
            return;
        }
        int* data = new int[newLength];
        if (m_length > 0) {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index) {
        assert(index >= 0 && index <= m_length);
        int* data = new int[m_length + 1];
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];
        data[index] = value;
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }



    void pop_back() {
        assert(m_length > 0);
        int* data = new int[m_length - 1];
        for (int i = 0; i < m_length - 1; ++i) {
            data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void pop_front() {
        assert(m_length > 0);
        int* data = new int[m_length - 1];
        for (int i = 0; i < m_length; ++i) {
            data[i] = m_data[i+1];
        }
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void sort() {       
        for (int i = 0; i < m_length; ++i) {
            for (int j = 0; j < m_length - 1; ++j) {
                if (m_data[j] > m_data[j + 1]) {
                    int val = m_data[j];
                    m_data[j] = m_data[j + 1];
                    m_data[j+1] = val;
                }
            }
        }
    }

    void print() const {
        for (int i = 0; i < m_length; ++i) {
            cout << m_data[i] << " ";
        }
        cout << endl;
    }

    void fill_array() const {
        for (int i = 0; i < m_length; ++i) {
            m_data[i] = rand() % 10;
        }
    }

    ~ArrayInt() {
        delete[] m_data;
    }
};



int main() {
    ArrayInt array(10);
    array.fill_array();
    array.print();

    array.pop_back();
    array.print();

    array.pop_front();
    array.print();

    array.sort();
    array.print();

    return 0;
}