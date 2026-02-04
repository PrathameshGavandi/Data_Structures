#include <iostream>
using namespace std;

#pragma pack(1)
class Queuenode
{
public:
    int data;
    Queuenode *next;

    Queuenode(int no)
    {
        this->data = no;
        this->next = NULL;
    }
};

class Queue
{
private:
    Queuenode *first;
    int iCount;

public:
    Queue();

    void enqueue(int);  // InsertLast
    int dequeue();      // DeleteFirst
    void Display();
    int Count();
};

Queue :: Queue()
{
    cout << "Queue Gets Created Successfully...\n";

    this->first = NULL;
    this->iCount = 0;
}

void Queue :: enqueue(int no)
{
    Queuenode *newn = NULL;
    newn = new Queuenode(no);
    
    Queuenode *temp = NULL;

    

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp ->next = newn;
      
    }

    this->iCount++;
    
}

int Queue :: dequeue()
{
    int Value = 0;
    Queuenode *temp = this->first;

    if (this->first == NULL)
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

void Queue :: Display()
{
    Queuenode *temp = this->first;

    if (this->first == NULL)
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

int Queue ::Count()
{
    return this->iCount;
}

int main()
{

    Queue *sobj = new Queue();

    // PUSH
    sobj->enqueue(11);
    sobj->enqueue(21);
    sobj->enqueue(51);
    sobj->enqueue(101);

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

    sobj ->enqueue(121);

    sobj->Display();

    cout << "Number of elements in Stack are : " << sobj->Count() << "\n";

    
    cout << "--------------------------------------------------------------\n";


    delete sobj;

    return 0;
}