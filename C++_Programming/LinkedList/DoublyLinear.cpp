/*
Program Name : Doubly Linear Linked List
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

class DoublyLL
{
private:
    PNODE first;
    int iCount;

public:
    DoublyLL()
    {
        cout << "Object of DoublyLL gets created\n";
        this->first = NULL;
        this->iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newn;
            newn->prev = temp;
        }
        iCount++;
    }

    void DeleteFirst()
    {
        PNODE temp = NULL;

        if (first == NULL)
        {
            return;
        }
        else if (first->next == NULL)
        {
            free(first);
            first = NULL;
        }
        else
        {
            temp = first;

            first = first->next;
            first->prev = NULL;
            delete (temp);
        }
        iCount--;
    }

    void DeleteLast()
    {
        PNODE temp = NULL;

        if (first == NULL)
        {
            return;
        }
        else if (first->next == NULL)
        {
            delete (first);
            first = NULL;
        }
        else
        {
            temp = first;

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }

            free(temp->next);
            temp->next = NULL;
        }

        iCount--;
    }

    void Display()
    {
        PNODE temp = NULL;

        temp = first;

        cout << "NULL ";
        while (temp != NULL)
        {
            cout << " <=> | " << temp->data << " |";
            temp = temp->next;
        }
        cout << " <=> NULL\n";
    }

    int Count()
    {
        return this->iCount;
    }

    void InsertAtPos(int no, int pos)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;
        int iCnt = 0;

        if ((pos < 1) || (pos > iCount + 1))
        {
            cout << "Invalid Position\n";
            return;
        }
        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            temp = first;

            for (iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;

            iCount++;
        }
    }

    void DeleteAtPos(int pos)
    {
        PNODE temp = NULL;
        PNODE target = NULL;

        int iCnt = 0;

        if ((pos < 1) || (pos > iCount))
        {
            cout << "Invalid Position\n";
            return;
        }
        if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;

            for (iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }

            target = temp->next;

            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete (target);

            iCount--;
        }
    }
};

int main()
{
    DoublyLL obj;
    int iRet = 0;

    //
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after InsertFirst are :" << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after InsertLast are :" << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after DeleteFirst are :" << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after DeleteLast are :" << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.InsertAtPos(61, 3);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after InsertAtPos are :" << iRet << "\n";
    cout << "-------------------------------------------------------------\n";

    //
    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes after DeleteAtPos are :" << iRet << "\n";
    cout << "-------------------------------------------------------------\n";
}
