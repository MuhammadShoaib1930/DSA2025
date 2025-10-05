#include <iostream>
using namespace std;
template <typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data, Node<T>* next = nullptr){
        this->data = data;
        this->next = next;
    }
};
template <typename T>
class CircularLinkList{
    Node<T>* head = nullptr;
    public:
    void insertByLast(T data){
        if(head == nullptr){
            head = new Node<T>(data);
            head->next = head;
        }
        else{
            Node<T>* node = new Node<T>(data);
            Node<T>* forword = head;
            while (forword->next != head)
            {
                forword = forword->next;
            }
            forword->next = node;
            node->next = head;
        }
    }
    void insertByFront(T data){
        if(head == nullptr){
            head = new Node<T>(data);
            head->next = head;
        }else{
            Node<T>* node = new Node<T>(data);
            Node<T>* forword = head;
            while (forword->next != head)
            {
                forword = forword->next;
            }
            node->next = head;
            forword->next = node;
            head = node;
        }
    }
    void insertByValueAfter(T data , T where){
        if(head == nullptr) insertByFront(data);
        else{
            Node<T>* node = new Node<T>(data);
            Node<T>* forword = head;
            do
            {
                if(forword->data == where){
                    Node<T>* fNext = forword->next;
                    node->next = fNext;
                    forword->next = node;
                    return;
                }
                forword = forword->next;
            } while (forword!=head);
            
        }
    }
    void insertByValueBefore(T data , T where){
        if(head == nullptr) insertByFront(data);
        else{
            Node<T>* node = new Node<T>(data);
            Node<T>* forword = head;
            do
            {
                if(forword->next->data == where){
                    Node<T>* fNext = forword->next;
                    forword->next = node;
                    node->next = fNext;
                    if(fNext == head){
                        head = node;
                    }
                    return;
                }
                forword = forword->next;
            } while (forword!=head);
            
        }
    }
    void travers(){
        if(head == nullptr)return;
        Node<T>* forword = head;
        do{
            cout<<forword->data<<" ";
            forword = forword->next;
        }
        while (forword != head);
        cout<<endl;
    }
    void deleteByFront(){
        if(head == nullptr)return;
        else if(head->next == head)
            head = nullptr;
        else{
            Node<T>* forword = head;
            while (forword->next != head)
                forword = forword->next;
            Node<T>* temp = head->next;
            head->next = nullptr;
            forword->next = temp;
            head = temp;
            
        }
    }
    void deleteByRear(){
        if(head == nullptr)return;
        else if(head->next == head) head = nullptr;
        else {
            Node<T>* forword = head;
            while (forword->next->next != head)
                forword = forword->next;
            Node<T>* temp = forword->next;
            forword->next = head;
            temp = nullptr;
            
        }
    }
    void deleteByValue(T value){
        if(head == nullptr)return;
        if(head->next == head && head->data == value) head = nullptr;
        else{
            Node<T>* prev = head;
            Node<T>* curr = prev->next;
            do
            {
                if(curr->data == value){
                    prev->next = curr->next;
                    if(curr == head) head = curr->next;
                    curr = nullptr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            } while (prev!=head);
            
        }
    }
    bool isPresent(T value){
        if(head == nullptr)return false;
        else {
            Node<T>* curr = head;
            do
            {
                if(curr->data == value) return true;
                curr = curr->next;
            } while (curr!=head);
            return false;
        }
    }
    void update(T newValue , T which){
        if(head == nullptr)return;
        Node<T>* curr = head;
        do
        {
            if(curr->data == which){
                curr->data = newValue;
                return;
            }
            curr = curr->next;
        } while (curr!= head);
        
    }
    Node<T>* getHead(){
        return this->head;
    }
    void setHead(Node<T>* head){
        this->head = head;
    }
};