
#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node(T data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class DoublyLinkList
{
public:
    Node<T> *frontHead = nullptr;
    Node<T> *rearHead = nullptr;

    void insertByFront(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (frontHead == nullptr && rearHead == nullptr)
        {
            frontHead = node;
            rearHead = node;
        }
        else
        {
            node->right = frontHead;
            frontHead->left = node;
            frontHead = node;
        }
    }
    void insertByRear(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (frontHead == nullptr && rearHead == nullptr)
        {
            frontHead = node;
            rearHead = node;
        }
        else
        {
            node->left = rearHead;
            rearHead->right = node;
            rearHead = node;
        }
    }
    void traversByFront()
    {
        Node<T> *temp = frontHead;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
    }
    void traversByRear()
    {
        Node<T> *temp = rearHead;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->left;
        }
        cout << endl;
    }
    void deleteAll()
    {
        frontHead = nullptr;
        rearHead = nullptr;
    }
    void deleteRear()
    {
        Node<T> *temp = rearHead;
        rearHead = temp->left;
        temp->left = nullptr;
        rearHead->right = nullptr;
    }
    void deleteFront()
    {
        Node<T> *temp = frontHead;
        frontHead = temp->right;
        frontHead->left = nullptr;
        temp->right = nullptr;
    }
    bool isPresent(T data)
    {
        Node<T> *nodeRear = rearHead;
        Node<T> *nodeFront = frontHead;
        while (nodeFront != nullptr && nodeRear != nullptr)
        {
            if (nodeFront->data == data || nodeRear->data == data)
            {
                return true;
            }
            nodeFront = nodeFront->right;
            nodeRear = nodeRear->left;
            if (nodeRear == nodeFront)
                return false;
        }
        return false;
    }
    bool isEmpty()
    {
        return (rearHead == nullptr && frontHead == nullptr);
    }
    int numberOfElement()
    {
        if (isEmpty())
            return 0;
        Node<T> *frontNode = frontHead;
        Node<T> *rearNode = rearHead;
        int number = 0;
        while (frontNode != nullptr && rearHead != nullptr)
        {
            number = (frontNode == rearNode) ? number + 1 : number + 2;
            frontNode = frontNode->right->right;
        }
        return number;
    }
    void insertByValueAfter(T data, T where)
    {
        if (isEmpty())
            return;
        Node<T> *node = new Node<T>(data);
        if (where == rearHead->data)
        {
            rearHead->right = node;
            node->left = rearHead;
            rearHead = node;
            return;
        }
        Node<T> *nodeFront = frontHead;
        while (nodeFront != nullptr)
        {
            if (nodeFront->data == where)
            {
                Node<T> *rNode = nodeFront->right;
                nodeFront->right = node;
                node->left = nodeFront;
                node->right = rNode;
                rNode->left = node;
            }
            nodeFront = nodeFront->right;
        }
    }
    void insertByValueBefore(T data, T where)
    {
        if (isEmpty())
            return;
        Node<T> *node = new Node<T>(data);
        Node<T> *rNode = frontHead;
        if (rNode->data == where)
        {
            node->right = rNode;
            rNode->left = node;
            frontHead = node;
            return;
        }
        while (rNode != nullptr)
        {
            rNode = rNode->right;
            if (rNode->data == where)
            {
                Node<T> *lNode = rNode->left;
                lNode->right = node;
                node->left = lNode;
                node->right = rNode;
                rNode->left = node;
                return;
            }
        }
    }
    void deletionByValue(T data)
    {
        if (isEmpty())
            return;
        if (frontHead->data == data)
        {
            frontHead = frontHead->right;
            frontHead->left = nullptr;
        }
        else if (rearHead->data == data)
        {
            rearHead = rearHead->left;
            rearHead->right = nullptr;
        }
        else
        {
            Node<T> *rNode = frontHead;
            while (rNode != nullptr)
            {
                if (rNode->data == data)
                {
                    Node<T> *lNode = rNode->left;
                    rNode = rNode->right;
                    lNode->right = rNode;
                    rNode->left = lNode;
                    return;
                }
                rNode = rNode->right;
            }
        }
    }
    Node<T> *getFrontHead()
    {
        return this->frontHead;
    }
    Node<T> *getRearHead()
    {
        return this->rearHead;
    }
    void setFrontHead(Node<T> *frontHead, Node<T> *rearHead)
    {
        this->frontHead = frontHead;
        this->rearHead = rearHead;
    }
    void update(T newValue , T which){
        if(frontHead != nullptr){
            Node<T>* temp = frontHead;
            do
            {
                if(temp->data == which){
                    temp->data = newValue;
                    return;
                }
                temp = temp->right;
            }while(temp != rearHead);
            
        }
    }
};