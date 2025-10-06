#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node(T data, Node<T> *left = nullptr, Node<T> *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class circularDoublyLinkList
{
    Node<T> *frontHead = nullptr;
    Node<T> *rearHead = nullptr;
    int size = 0;

public:
    void insertRear(T data)
    {
        size++;
        Node<T> *node = new Node<T>(data);
        if (frontHead == nullptr && rearHead == nullptr)
        {
            frontHead = node;
            rearHead = node;
            frontHead->right = rearHead;
            rearHead->left = frontHead;
        }
        else
        {
            rearHead->right = node;
            node->left = rearHead;
            frontHead->left = node;
            node->right = frontHead;
            rearHead = node;
        }
    }
    void insertFront(T data)
    {
        size++;
        Node<T> *node = new Node<T>(data);
        if (frontHead == nullptr && rearHead == nullptr)
        {
            frontHead = node;
            rearHead = node;
            frontHead->right = rearHead;
            rearHead->left = frontHead;
        }
        else
        {
            node->right = frontHead;
            node->left = rearHead;
            frontHead->left = node;
            rearHead->right = node;
            frontHead = node;
        }
    }
    void insertByValueAfter(T newData, T which)
    {
        Node<T> *node = new Node<T>(newData);
        if (frontHead == nullptr && rearHead == nullptr)
            return;
        Node<T> *traversFront = frontHead;
        Node<T> *traversRear = rearHead;
        do
        {
            if (traversFront->data == which)
            {
                Node<T> *traversFrontRight = traversFront->right;
                traversFront->right = node;
                node->left = traversFront;
                node->right = traversFrontRight;
                traversFrontRight->left = node;
                if (frontHead == rearHead)
                    rearHead = node;
                size++;
                return;
            }
            else if (traversRear->data == which)
            {
                Node<T> *traversRearLeft = traversRear->right;
                traversRear->right = node;
                node->left = traversRear;
                node->right = traversRearLeft;
                traversRearLeft->left = node;
                if (frontHead == node->right)
                    rearHead = node;
                size++;
                return;
            }
            else
            {
                traversFront = traversFront->right;
                traversRear = traversRear->left;
            }
        } while (traversFront->left != traversRear->right);
    }
    void traversByFront()
    {
        if (frontHead == nullptr && rearHead == nullptr)
            return;
        Node<T> *traversFront = frontHead;
        int count = 0;
        do
        {
            count++;
            cout << traversFront->data << " ";
            traversFront = traversFront->right;
        } while (traversFront != frontHead);
        cout << endl;
        this->size = count;
    }
    void traversByRear()
    {
        if (frontHead == nullptr && rearHead == nullptr)
            return;
        Node<T> *traversRear = rearHead;
        int count = 0;
        do
        {
            count++;
            cout << traversRear->data << " ";
            traversRear = traversRear->left;
        } while (traversRear != rearHead);
        cout << endl;
        this->size = count;
    }
    void insertByValueBefore(T newData, T which)
    {
        Node<T> *node = new Node<T>(newData);
        if (rearHead == nullptr && frontHead == nullptr)
            return;
        else
        {
            Node<T> *traversFront = frontHead;
            Node<T> *traversRear = rearHead;
            do
            {
                if (traversFront->data == which)
                {
                    Node<T> *traversFrontLeft = traversFront->left;
                    traversFrontLeft->right = node;
                    node->left = traversFrontLeft;
                    node->right = traversFront;
                    traversFront->left = node;
                    if (frontHead == traversFront)
                        frontHead = node;
                    size++;
                    return;
                }
                else if (traversRear->data == which)
                {
                    Node<T> *traversRearLeft = traversRear->left;
                    traversRear->left = node;
                    node->right = traversRear;
                    traversRearLeft->right = node;
                    node->left = traversRearLeft;
                    size++;
                    return;
                }
                else
                {
                    traversFront = traversFront->right;
                    traversRear = traversRear->left;
                }
            } while (traversFront->left != traversRear->right);
        }
    }
    void update(T newData, T which)
    {
        if (frontHead == nullptr && rearHead == nullptr)
        {
            return;
        }
        Node<T> *traversFront = frontHead;
        Node<T> *traversRear = rearHead;
        do
        {
            if (traversFront->data == which)
            {
                traversFront->data = newData;
                return;
            }
            else if (traversRear->data == which)
            {
                traversRear->data = newData;
                return;
            }
            else
            {
                traversFront = traversFront->right;
                traversRear = traversRear->left;
            }
        } while (traversFront->left != traversRear->right);
    }
    Node<T> *getFrontHead()
    {
        return this.frontHead;
    }
    Node<T> *getRearHead()
    {
        return this->rearHead;
    }
    void setHeads(Node<T> *frontHead, Node<T> *rearHead)
    {
        this->rearHead = rearHead;
        this->frontHead = frontHead;
    }

    void deleteByFront()
    {
        if (frontHead == nullptr && rearHead == nullptr)
            return;
        else if (frontHead == rearHead)
        {
            frontHead = nullptr;
            rearHead = nullptr;
            size = 0;
            return;
        }
        Node<T> *temp = frontHead;
        frontHead = temp->right;
        rearHead->right = frontHead;
        frontHead->left = rearHead;
        temp = nullptr;
        size--;
    }
    void deleteByRear()
    {
        if (frontHead == nullptr && rearHead == nullptr)
            return;
        else if (frontHead == rearHead)
        {
            frontHead = nullptr;
            rearHead = nullptr;
            size = 0;
            return;
        }
        Node<T> *temp = rearHead;
        rearHead = rearHead->left;
        rearHead->right = frontHead;
        frontHead->left = rearHead;
        temp = nullptr;
        size--;
    }
    void deleteByValue(T value)
    {
        if (frontHead == nullptr && rearHead == nullptr)
            return;
        else if (frontHead == rearHead && frontHead->data == value)
        {
            frontHead = nullptr;
            rearHead = nullptr;
            size = 0;
            return;
        }
        Node<T> *traversFront = frontHead;
        Node<T> *traversRear = rearHead;
        do
        {
            if (traversFront->data == value)
            {
                Node<T> *temp = traversFront->left;
                frontHead = traversFront->right;
                temp->right = frontHead;
                frontHead->left = temp;
                traversFront = nullptr;
                size--;
                return;
            }
            else if (traversRear->data == value)
            {
                Node<T> *temp = traversRear->right;
                rearHead = rearHead->left;
                temp->left = rearHead;
                rearHead->right = temp;
                traversRear = nullptr;
                size--;
                return;
            }
            else
            {
                traversFront = traversFront->right;
                traversRear = traversRear->left;
            }
        } while (traversFront->left != traversRear->right);
    }
    int getSize()
    {
        return this->size;
    }
};