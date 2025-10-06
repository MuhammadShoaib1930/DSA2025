#include <iostream>
#include <type_traits>
using namespace std;
template <typename T>
class QueueInArray
{
    int size;
    T *data;
    int top = -1;
    int rear = -1;
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
    QueueInArray(int newSize)
    {
        top = -1;
        rear = -1;
        this->size = newSize;
        this->data = new T[size];
    }

    void push(T newValue)
    {
        if (rear >= size)
            return;
        top = 0;
        this->data[++rear] = newValue;
    }
    T pop()
    {
        if (top == -1 || rear == -1)
        {
            return typeFunctionReturn();
        }
        T value = data[top];
        for (int i = 0; i < rear; i++)
        {
            data[i] = data[i + 1];
        }
        rear--;
        return value;
    }
    T peek()
    {
        if (top == -1 || rear == -1)
            return typeFunctionReturn();
        return data[top];
    }
    bool isFull()
    {
        return (size < rear);
    }
    bool isEmpty()
    {
        return (top == -1 || rear == -1);
    }
    int getSize() { return rear; }
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
class QueueInList
{
    Node<T> *top = nullptr;
    Node<T> *rear = nullptr;
    int size = -1;
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
        size++;
        Node<T> *node = new Node<T>(newData);
        if (top == nullptr && rear == nullptr)
        {
            top = node;
            rear = node;
        }
        else if (top == rear && top != nullptr)
        {
            rear->next = node;
            rear = node;
        }
    }
    T pop()
    {
        if (top == nullptr || rear == nullptr)
            return typeFunctionReturn();
        Node<T> *temp = top;
        top = top->next;
        temp->next = nullptr;
        size--;
        return temp->data;
    }
    T front()
    {
        if (top == nullptr)
            return typeFunctionReturn();
        return top->data;
    }
    T back()
    {
        if (rear == nullptr)
            return typeFunctionReturn();
        return rear->data;
    }
    int getSize()
    {
        return this->size;
    }
    bool isFull()
    {
        return false;
    }
    bool isEmpty()
    {
        return (top == nullptr && rear == nullptr);
    }
};