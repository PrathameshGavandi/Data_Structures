#include <iostream>
using namespace std;

#pragma pack(1)
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLLL
{
public:
    node *first;
    int iCount;

    DoublyLLL();

    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

DoublyLLL ::DoublyLLL()
{
    cout << "Linked List Gets Created\n";
    this->first = NULL;
    this->iCount = 0;
}

void DoublyLLL ::InsertFirst(int no)
{
    node *newn = NULL;

    newn = new node(no);

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

void DoublyLLL ::InsertLast(int no)
{
    node *newn = NULL;
    node *temp = NULL;

    newn = new node(no);

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

void DoublyLLL ::InsertAtPos(int no, int pos)
{
    node *temp = NULL;
    node *newn = NULL;
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
        newn = new node(no);

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

void DoublyLLL ::DeleteFirst()
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

void DoublyLLL ::DeleteLast()
{
    node *temp = NULL;

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

void DoublyLLL ::DeleteAtPos(int pos)
{
    node *temp = NULL;
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

void DoublyLLL ::Display()
{
    node *temp = NULL;

    temp = this->first;

    cout << "\nNULL<=>";
    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int DoublyLLL ::Count()
{
    return this->iCount;
}

int main()
{

    DoublyLLL *dobj = new DoublyLLL();

    // InsertFirst
    dobj->InsertFirst(51);
    dobj->InsertFirst(21);
    dobj->InsertFirst(11);

    dobj->Display();

    cout << "Number of After InsertFirst are : " << dobj->Count() << "\n";
    cout << "__________________________________________________________\n";

    // InsertLast
    dobj->InsertLast(101);
    dobj->InsertLast(111);
    dobj->InsertLast(121);

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
    dobj->InsertAtPos(105, 4);

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