#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data, Node<T> *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};
template <typename T>
class LinkList
{
    Node<T> *head;
    int maxLenght;

public:
    LinkList()
    {
        this->head = nullptr;
        this->maxLenght = 0;
    }
    void insertALL(T *array, int n)
    {
        for (int i = 0; i < n; i++)
        {
            insertByRear(array[i]);
        }
    }
    void insertByFront(T data)
    {
        maxLenght++;
        if (head)
        {
            Node<T> *temp = new Node<T>(data);
            temp->next = head;
            head = temp;
        }
        else
        {
            head = new Node<T>(data);
        }
    }
    void insertByRear(T data)
    {
        maxLenght++;
        if (head)
        {
            Node<T> *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = new Node<T>(data);
        }
        else
        {
            head = new Node<T>(data);
        }
    }

    void update(T newData, T oldData)
    {
        if (head)
        {
            Node<T> *temp = head;
            while (temp)
            {
                if (temp->data == oldData)
                {
                    temp->data = newData;
                }
                temp = temp->next;
            }
        }
        else
        {
            return;
        }
    }
    bool isPresent(T data)
    {
        if (head)
        {
            Node<T> *temp = head;
            while (temp)
            {
                if (temp->data == data)
                {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
        else
        {
            return false;
        }
    }
    Node<T> *getNodePresent(T data)
    {
        if (head)
        {
            Node<T> *temp = head;
            while (temp)
            {
                if (temp->data == data)
                {
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }
        else
        {
            return nullptr;
        }
    }

    int getMaxLenght()
    {
        return maxLenght;
    }
    bool isEmpty()
    {
        return (maxLenght == 0);
    }
    void deleteNode(T data)
    {
        if (!head)
            return;
        if (head->data == data)
        {
            head = head->next;
            maxLenght--;
            return;
        }
        Node<T> *temp = head;
        while (temp->next)
        {
            if (temp->next->data == data)
            {
                temp->next = temp->next->next;
                maxLenght--;
                return;
            }
            temp = temp->next;
        }
    }
    Node<T> *getHead()
    {
        return head;
    }
    void setHead(Node<T> *head)
    {
        this->head = head;
    }
    void deleteAll()
    {
        head = nullptr;
    }
    void insertByBefore(T newData, T where)
    {
        Node<T> *node = new Node<T>(newData);
        if (head->data == where)
        {
            node->next = head;
            head = node;
            return;
        }
        Node<T> *temp = head;
        while (temp)
        {
            if (temp->next->data == where)
            {
                node->next = temp->next;
                temp->next = node;
                return;
            }
            temp = temp->next;
        }
    }
    void insertByAfter(T newData, T where)
    {
        Node<T> *node = new Node<T>(newData);
        Node<T> *temp = head;
        while (temp)
        {
            if (temp->data == where)
            {
                node->next = temp->next;
                temp->next = node;
                return;
            }

            temp = temp->next;
        }
    }
    void travers()
    {
        if (head)
        {
            Node<T> *temp = head;
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            return;
        }
    }
};