/*
Program Name : Singly Circular Linked List
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

#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCL
{
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    SinglyCL()
    {
        cout<<"Object of SinglyCL gets created\n";
        this -> first = NULL;
        this -> last = NULL;
        this -> iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn -> data = no;
        newn -> next = NULL;

        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
            last->next = first;
        }
        else
        {
            newn -> next = first;
            first = newn;
        }
        last -> next = first;

        iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        if(first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
            last->next = first;
        }
        else
        {
            last -> next = newn;
            last = newn;
            last -> next = first;
        }
        iCount++;
    }

    void DeleteFirst()
    {
        PNODE temp = NULL;

        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            temp = first;

            first = first -> next;
            delete temp;
            last -> next = first;
        }
        iCount--;
    }

    void DeleteLast()
    {
        PNODE temp = NULL;

        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            temp = first;

            while (temp -> next -> next != first)
            {
                temp = temp -> next;
            }
            
            delete last;
            last = temp;

            last -> next = first;
        }
        iCount--;
    }


    void Display()
    {
        PNODE temp = NULL;

        temp = first;

        do
        {
            cout<<"| "<<temp -> data<<" | -> ";
            temp = temp -> next;
        } while (temp != last -> next);

        cout<<"\n";
    }


    int Count()
    {
        return this -> iCount;
    }


    void InsertAtPos(int no, int pos)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;
        int iCnt = 0;

        if((pos < 1) || (pos > iCount + 1))
        {
            cout<<"Invalid Position";
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            temp = first;

            for (iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp -> next;
            }
            
            newn -> next = temp -> next;
            temp -> next = newn;

            iCount++;
        }
    }


    void DeleteAtPos(int pos)
    {
        PNODE temp = NULL;
        PNODE target = NULL;

        int iCnt = 0;

        if((pos < 1) || (pos > iCount))
        {
            cout<<"Invalid Position";
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;

            for (iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp -> next;
            }

            target = temp -> next;

            temp -> next = target -> next;
            delete target;

            iCount--;
        }
        
    }

};

int main()
{

    SinglyCL obj;
    int iRet = 0;

    //
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after InsertFirst are : "<<iRet<<"\n";
    cout<<"-------------------------------------------------------------\n";


    //
    obj.InsertLast(101);
    obj.InsertLast(121);
    obj.InsertLast(151);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after InsertLast are : "<<iRet<<"\n";
    cout<<"-------------------------------------------------------------\n";


    //
    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after DeleteFirst are : "<<iRet<<"\n";
    cout<<"-------------------------------------------------------------\n";


    //
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after DeleteLast are : "<<iRet<<"\n";
    cout<<"-------------------------------------------------------------\n";


    //
    obj.InsertAtPos(61,3);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after InsertAtPos are : "<<iRet<<"\n";
    cout<<"-------------------------------------------------------------\n";


    //
    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after DeleteAtPos are : "<<iRet<<"\n";
    cout<<"-------------------------------------------------------------\n";


    return 0;
}
