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

        if((this -> first == NULL) && (this -> last == NULL))
        {
            this -> first = newn;
            this -> last = newn;
            this -> last-> next = this -> first;
        }
        else
        {
            newn -> next = this -> first;
            this -> first = newn;
        }
        last -> next = this ->first;

        this -> iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        if(this -> first == NULL && this -> last == NULL)
        {
            this -> first = newn;
            this ->last = newn;
            this -> last-> next = this -> first;
        }
        else
        {
            this -> last -> next = newn;
            this -> last = newn;
            this -> last -> next = this -> first;
        }
        this -> iCount++;
    }

    void DeleteFirst()
    {
        PNODE temp = NULL;

        if((this -> first == NULL) && (this -> last == NULL))
        {
            return;
        }
        else if(this -> first == this -> last)
        {
            delete this -> first;
            this -> first = NULL;
            this -> last = NULL;
        }
        else
        {
            temp = this -> first;

            this -> first = this -> first -> next;
            delete temp;
            this -> last -> next = this -> first;
        }
        this -> iCount--;
    }

    void DeleteLast()
    {
        PNODE temp = NULL;

        if((this -> first == NULL) && (this -> last == NULL))
        {
            return;
        }
        else if(this -> first == this -> last)
        {
            delete this -> first;
            this -> first = NULL;
            this -> last = NULL;
        }
        else
        {
            temp = this -> first;

            while (temp -> next -> next != this -> first)
            {
                temp = temp -> next;
            }
            
            delete this -> last;
            this -> last = temp;

            this -> last -> next = this -> first;
        }
        this -> iCount--;
    }


    void Display()
    {
        PNODE temp = NULL;

        temp = this -> first;

        do
        {
            cout<<"| "<<temp -> data<<" | -> ";
            temp = temp -> next;
        } while (temp != this -> last -> next);

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

        if((pos < 1) || (pos > this -> iCount + 1))
        {
            cout<<"Invalid Position";
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == this -> iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            temp = this -> first;

            for (iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp -> next;
            }
            
            newn -> next = temp -> next;
            temp -> next = newn;

            this -> iCount++;
        }
    }


    void DeleteAtPos(int pos)
    {
        PNODE temp = NULL;
        PNODE target = NULL;

        int iCnt = 0;

        if((pos < 1) || (pos > this -> iCount))
        {
            cout<<"Invalid Position";
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == this -> iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = this -> first;

            for (iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp -> next;
            }

            target = temp -> next;

            temp -> next = target -> next;
            delete target;

            this -> iCount--;
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
