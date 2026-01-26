#include <iostream>
using namespace std;

#pragma pack(1)
template<class T>
class node
{
public:
    T data;
    node *next;
    node *prev;

    node(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template<class T>
class DoublyLLL
{
public:
    node<T> *first;
    int iCount;

    DoublyLLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template<class T>
DoublyLLL<T> ::DoublyLLL()
{
    cout << "Linked List Gets Created\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void DoublyLLL<T> ::InsertFirst(T no)
{
    node<T> *newn = NULL;

    newn = new node<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

template<class T>
void DoublyLLL<T> ::InsertLast(T no)
{
    node<T> *newn = NULL;
    node<T> *temp = NULL;

    newn = new node<T>(no);

    if (this->first == NULL)
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

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

template<class T>
void DoublyLLL<T> ::InsertAtPos(T no, int pos)
{
    node<T> *temp = NULL;
    node<T> *newn = NULL;
    int iCnt = 0;

    if ((pos < 1) || (pos > this->iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new node<T>(no);

        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

template<class T>
void DoublyLLL<T> ::DeleteFirst()
{
    if (this->first == NULL) // LL is empty
    {
        return;
    }
    else if (this->first->next == NULL) // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else // LL contains more than 1 element
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

template<class T>
void DoublyLLL<T> ::DeleteLast()
{
    node<T> *temp = NULL;

    if (this->first == NULL) // LL is empty
    {
        return;
    }
    else if (this->first->next == NULL) // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else // LL contains more than 1 element
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

template<class T>
void DoublyLLL<T> ::DeleteAtPos(int pos)
{
    node<T> *temp = NULL;
    int iCnt = 0;

    if ((pos < 1) || (pos > this->iCount))
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = first;
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

template<class T>
void DoublyLLL<T> ::Display()
{
    node<T> *temp = NULL;

    temp = this->first;

    cout << "\nNULL<=>";
    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template<class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;
}

int main()
{
    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    // InsertFirst
    dobj->InsertFirst('C');
    dobj->InsertFirst('B');
    dobj->InsertFirst('A');

    dobj->Display();

    cout << "Number of After InsertFirst are : " << dobj->Count() << "\n";
    cout << "__________________________________________________________\n";

    // InsertLast
    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout << "Number of elements After InsertLast are : " << dobj->Count() << "\n";
    cout << "__________________________________________________________\n";

    // DeleteFirst
    dobj->DeleteFirst();

    dobj->Display();

    cout << "Number of elements After DeleteFirst are : " << dobj->Count() << "\n";
    cout << "__________________________________________________________\n";

    // DeleteLast
    dobj->DeleteLast();

    dobj->Display();

    cout << "Number of elements After DeleteLast are : " << dobj->Count() << "\n";
    cout << "__________________________________________________________\n";

    // InsertAtPos
    dobj->InsertAtPos('$', 4);

    dobj->Display();

    cout << "Number of elements After InsertAtPos are : " << dobj->Count() << "\n";
    cout << "__________________________________________________________\n";

    // DeleteAtPos
    dobj->DeleteAtPos(4);

    dobj->Display();

    cout << "Number of elements After InsertAtPos are : " << dobj->Count() << "\n";
    cout << "__________________________________________________________\n";

    delete dobj;

    return 0;
}