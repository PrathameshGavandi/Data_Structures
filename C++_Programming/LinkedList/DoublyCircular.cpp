/*
Program Name : Doubly Circular Linked List
Language     : C++
Author       : Prathamesh R Gavandi
Operations   :
1. InsertFirst
2. InsertLast
3. InsertAtPos
4. DeleteFirst
5. DeleteLast
6. DeleteAtPos
7. Display
8. Count
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;

class DoublyCL
{
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    DoublyCL()
    {
        cout << "Object of DoublyCL gets created.\n";
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (this->first == NULL && this->last == NULL)
        {
            this->first = newn;
            this->last = newn;
        }
        else
        {
            newn->next = this->first;
            this->first->prev = newn;
            this->first = newn;
        }

        this->last->next = this->first;
        this->first->prev = this->last;

        this->iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (this->first == NULL && this->last == NULL)
        {
            this->first = newn;
            this->last = newn;
        }
        else
        {
            this->last->next = newn;
            newn->prev = this->last;
            this->last = newn;
        }

        this->last->next = this->first;
        this->first->prev = this->last;

        this->iCount++;
    }

    void DeleteFirst()
    {
        if (this->first == NULL && this->last == NULL)
        {
            return;
        }

        if (this->first == this->last)
        {
            delete this->first;
            this->first = NULL;
            this->last = NULL;
        }
        else
        {
            PNODE temp = this->first;

            this->first = this->first->next;
            delete temp;

            this->last->next = this->first;
            this->first->prev = this->last;
        }

        this->iCount--;
    }

    void DeleteLast()
    {
        if (this->first == NULL && this->last == NULL)
        {
            return;
        }

        if (this->first == this->last)
        {
            delete this->first;
            this->first = NULL;
            this->last = NULL;
        }
        else
        {
            PNODE temp = this->last;

            this->last = this->last->prev;
            delete temp;

            this->last->next = this->first;
            this->first->prev = this->last;
        }

        this->iCount--;
    }

    void Display()
    {
        if (this->first == NULL && this->last == NULL)
        {
            cout << "Linked List is empty\n";
            return;
        }

        PNODE temp = this->first;

        cout << " <=> ";
        do
        {
            cout << "| " << temp->data << " | <=> ";
            temp = temp->next;
        } while (temp != this->last->next);

        cout << "\n";
    }

    int Count()
    {
        return this->iCount;
    }

    void InsertAtPos(int no, int pos)
    {
        if ((pos < 1) || (pos > this->iCount + 1))
        {
            cout << "Invalid Position";
            return;
        }

        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == this->iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            PNODE temp = this->first;

            for (int i = 1; i < pos - 1; i++)
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

    void DeleteAtPos(int pos)
    {
        if ((pos < 1) || (pos > this->iCount))
        {
            cout << "Invalid Position";
            return;
        }

        if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == this->iCount)
        {
            DeleteLast();
        }
        else
        {
            PNODE temp = this->first;

            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            PNODE target = temp->next;

            temp->next = target->next;
            target->next->prev = temp;

            delete target;

            this->iCount--;
        }
    }
};

int main()
{
    DoublyCL obj;
    int iRet = 0;

    //
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after InsertFirst are : " << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.InsertLast(101);
    obj.InsertLast(121);
    obj.InsertLast(151);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after InsertLast are : " << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after DeleteFirst are : " << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after DeleteLast are : " << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.InsertAtPos(61, 3);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after InsertAtPos are : " << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after DeleteAtPos are : " << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    return 0;
}
