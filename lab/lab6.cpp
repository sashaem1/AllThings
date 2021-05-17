#include <iostream>
#include <string>

using namespace std;

template <typename ty>
class List
{
 public:
    List();
    ~List();
    void push_back(ty data);
    void push_front(ty data);
    void pop_front();
    void pop_back();
    void insert(ty data, int index);
    void removeAt(int index);
    void clear();
    int GetSize() {return size;}
    ty& operator[](const int index);

 private:
    template <typename t>
    class Node
    {
     public:
        t data;
        Node *pNext;
        Node(t _data, Node *_pNext=nullptr): data(_data), pNext(_pNext){}
    };
    int size;
    Node<ty> *head;
};

template <typename ty>
List<ty>:: List()
{
    size = 0;
    head = nullptr;
}

template <typename ty>
List<ty>:: ~List()
{
    clear();
}

template <typename ty>
void List<ty>:: push_back(ty data)
{
    if(head == nullptr)
    {
        head = new Node<ty>(data);
    }
    else
    {
        Node<ty> *current = this->head;
        while ( current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<ty>(data);
    }
    size++;
}
template <typename ty>
void List<ty>:: push_front(ty data)
{
    head = new Node<ty>(data,head);
    size++;
}
template <typename ty>
void List<ty>:: pop_front()
{
    Node<ty> *temp =head;
    head = head->pNext;
    delete temp;
    size--;

}
template <typename ty>
void List<ty>:: pop_back()
{
    removeAt(size - 1);
}
template <typename ty>
void List<ty>::insert(ty data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<ty> *previouse = this->head;
        for (int i = 0; i < index-1; i++)
        {
            previouse = previouse->pNext;
        }
        Node<ty> *NewNode = new Node<ty>(data, previouse->pNext);
        previouse->pNext = NewNode;
        size++; 
    }

}
template <typename ty>
void List<ty>:: removeAt(int index)
{
     if (index == 0)
     {
         pop_front();
     }
     else
     {
         Node<ty> *previous = this->head;
         for (int i = 0; i < index-1; i++)
         {
             previous = previous->pNext;
         }
         Node<ty> *ToDelete = previous->pNext;
         previous->pNext = ToDelete->pNext;
         delete ToDelete;
         size--;
     }
}
template <typename ty>
void List<ty>:: clear()
{
    while (size!=0)
    {
        this->pop_front();
    }
    
}
template <typename ty>
ty& List<ty>:: operator[](const int index)
{
    int coutner = 0;
    Node<ty> *current = this->head;
    while (current!= nullptr)
    {
        if(coutner == index) return current->data;
        current = current->pNext;
        coutner++;

    }

}


class worker
{
 private:
    string Fio;
 public:
    worker(): Fio("Ivanov I.I."){}
    worker(string _Fio): Fio(_Fio){}
    string GetFio ()
    {
        return Fio;
    }
};

class departament
{
 private:
    List<worker*> workers;
 public:
    ~departament()
    {
        workers.clear();
        cout << "complite destruct\n";
    }
    void add(worker* w)
    {
        workers.push_back(w);
    }
};

int main()
{

    worker* w1 = new worker() ;
    worker* w2 = new worker("Bobrov I.M."); 
    worker* w3= new worker("Vasilev V.V.");
    {
        departament Depar;
        Depar.add(w1);
        Depar.add(w2);
        Depar.add(w2);
    }
    cout << w1->GetFio() << " exist\n";
    cout << w2->GetFio() << " exist\n";
    cout << w3->GetFio() << " exist\n";
}