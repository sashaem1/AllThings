#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
 public:
    List();
    ~List();
    void push_back(T data);
    int GetSize() {return size;}
    T& operator[](const int index);
   
 private:
    template<typename Y>
    class Node
    {
     public:
        Node *pNext;
        Y data;
        Node(Y _data=Y(), Node *_pNext=nullptr): data(_data), pNext(_pNext){}
    };
    int size;
    Node<T> *head;
};

template<typename T>
List<T>:: List()
{
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>:: ~List()
{

}

template<typename T>
void List<T> :: push_back(T data)
{
    if(head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while ( current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    size++;
}

template<typename T>
T& List<T>:: operator[](const int index)
{
    int coutner = 0;
    Node<T> *current = this->head;
    while (current!= nullptr)
    {
        if(coutner == index) return current->data;
        current = current->pNext;
        coutner++;

    }
    
}

int main()
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    for(int i=0; i<list.GetSize(); i++)
    cout << list[i] << endl;
}