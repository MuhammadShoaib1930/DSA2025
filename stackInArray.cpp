#include <iostream>
using namespace std;
template <typename T>
class StackInArray
{
    int size;
    T *data;
    int top = -1;
    T typeFunctionReturn()
    {
        if constexpr (is_pointer_v<T>)
            return nullptr;
        else if constexpr (is_same_v<T, int>)
            return 0;
        else if constexpr (is_same_v<T, float>)
            return 0.000000000000;
        else if constexpr (is_same_v<T, double>)
            return 0.0000000;
        else if constexpr (is_same_v<T, char>)
            return '?';
        else if constexpr (is_same_v<T, string>)
            return "?";
        else if constexpr (is_same_v<T, void>)
            return;
        else
            return T();
    }

public:
    StackInArray(int newSize)
    {
        top = -1;
        this->size = newSize;
        this->data = new T[size];
    }

    void push(T newValue)
    {
        if (top >= size)
            return;
        this->data[++top] = newValue;
    }
    T pop()
    {
        if (top == -1)
        {
            return typeFunctionReturn();
        }
        return this->data[top--];
    }
    T peek()
    {
        if (top == -1)
            return typeFunctionReturn();
        return data[top];
    }
    bool isFull()
    {
        return (size < top);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

template <typename T>
class Node
{
    public:
    T data;
    Node *next;
    Node<T>(T newData, Node<T> *head = nullptr)
    {
        this->data = newData;
        this->next = head;
    }
};
template <typename T>
class StackInList
{
    Node<T> *top = nullptr;
    T typeFunctionReturn()
    {
        if constexpr (is_pointer_v<T>)
            return nullptr;
        else if constexpr (is_same_v<T, int>)
            return 0;
        else if constexpr (is_same_v<T, float>)
            return 0.000000000000;
        else if constexpr (is_same_v<T, double>)
            return 0.0000000;
        else if constexpr (is_same_v<T, char>)
            return '?';
        else if constexpr (is_same_v<T, string>)
            return "?";
        else if constexpr (is_same_v<T, void>)
            return;
        else
            return T();
    }

public:
    void push(T newData)
    {
        Node<T> *node = new Node<T>(newData);
        node->next = top;
        top = node;
    }
    T pop()
    {
        if (top == nullptr)
            return typeFunctionReturn();
        Node<T> *temp = top;
        top = top->next;
        temp->next = nullptr;
        return temp->data;
    }
    T peek()
    {
        if (top == nullptr)
            return typeFunctionReturn();
        return top->data;
    }

    bool isFUll()
    {
        return false;
    }
    bool isEmpty()
    {
        return (top == nullptr);
    }
};