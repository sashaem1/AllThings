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
    // void show()
    // {
    //     Node<T>:: cout<< data;
    // }
 private:
    template<typename Y>
    class Node
    {
     public:
        Node *pNext;
        Y data;
        Node(Y _data=Y(), Node *_pNext=nullptr): data(_data), pNext(_pNext){}
        // void showData()
        // {
        // cout<< data;
        // }
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
        while ( current != nullptr)
        {
            current = current-> pNext;
        }
        current->pNext = new Node<T>(data);
    }
    size++;
}

int main()
{
    List<int> list;
    list.push_back(1);
    // list.show();
}