//////////////////////////////////////////////////////////////////
//Final code of Queue using Generic Approach
//////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#pragma pack(1)
template<class T>
class Queuenode
{
public:
    T data;
    Queuenode<T> *next;

    Queuenode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template<class T>
class Queue
{
private:
    Queuenode<T> *first;
    Queuenode<T> *last;

    int iCount;

public:
    Queue();

    void enqueue(T);
    T dequeue(); 
    void Display();
    int Count();
};

template<class T>
Queue<T> :: Queue()
{
    cout << "Queue Gets Created Successfully...\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
        
    }
    this->iCount++;
    
}

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if (this->first == NULL && this->last == NULL)
    {
        cout << "Queue is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if (this->first == NULL && this->last == NULL)
    {
        cout << "Queue is empty\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | - ";
        temp = temp->next;
    }

    cout<<"\n";
}

template<class T>
int Queue<T> ::Count()
{
    return this->iCount;
}

int main()
{

    Queue<double> *sobj = new Queue<double>();

    // PUSH
    sobj->enqueue(11.36453);
    sobj->enqueue(21.37483);
    sobj->enqueue(51.38523);
    sobj->enqueue(101.18253);

    sobj->Display();

    cout << "Number of elements in Queue are : " << sobj->Count() << "\n";

    cout<<"------------------------------------------------------------------\n";


    cout<<"Removed element is : "<<sobj->dequeue()<<"\n";

    sobj->Display();

    cout << "Number of elements in Stack are : " << sobj->Count() << "\n";

    cout<<"------------------------------------------------------------------\n";

    cout<<"Removed element is : "<<sobj->dequeue()<<"\n";

    sobj->Display();

    cout << "Number of elements in Stack are : " << sobj->Count() << "\n";

    cout<<"------------------------------------------------------------------\n";

    cout<<"Removed element is : "<<sobj->dequeue()<<"\n";

    sobj ->enqueue(121.35243);

    sobj->Display();

    cout << "Number of elements in Stack are : " << sobj->Count() << "\n";


    
    cout << "--------------------------------------------------------------\n";


    delete sobj;

    return 0;
}