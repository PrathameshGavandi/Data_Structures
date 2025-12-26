/*
Program Name : Singly Linear Linked List
Language     : Java
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

class node
{
    public int data;
    public node next;

    //Important
    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL
{
    private node first;
    private int iCount;

    SinglyLL()
    {
        System.out.println("Object of SinglyLL gets created");
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            newn.next = this.first;
            first = newn;
        }
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
            
        }
        this.iCount++;
    }

    public void DeleteFirst()
    {
        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            this.first = this.first.next;
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            temp = this.first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        System.gc();
        this.iCount--;
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

        while(temp != null)
        {
            System.out.print("| " + temp.data +" | ->");
            temp = temp.next;
        }
        System.out.println("null\n");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no,int pos)
    {
        node newn = null;
        node temp = null;
        int iCnt = 0;

        newn = new node(no);

        if((pos < 1) || (pos > this.iCount + 1)) // Filter
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == this.iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt < pos -1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            this.iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if((pos < 1) || (pos > this.iCount)) // Filter
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == this.iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            System.gc();
            this.iCount--;
        }
    }
}


class SinglyLinear
{
    public static void main(String A[])
    {
        SinglyLL obj = null;    //Refrence

        obj = new SinglyLL();

        //or//

        //SinglyLL obj = new SinglyLL();

        int iRet = 0;

        //
        System.out.println("-------------------------------------------------------------");
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after InsertFirst are :" + iRet);
        System.out.println("-------------------------------------------------------------");

        //
        System.out.println("-------------------------------------------------------------");
        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after InsertLast are :" + iRet);
        System.out.println("-------------------------------------------------------------");

        //
        System.out.println("-------------------------------------------------------------");
        obj.DeleteFirst();

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after DeleteFirst are :" + iRet);
        System.out.println("-------------------------------------------------------------");

        //
        System.out.println("-------------------------------------------------------------");
        obj.DeleteLast();

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after DeleteLast are :" + iRet);
        System.out.println("-------------------------------------------------------------");

        //
        System.out.println("-------------------------------------------------------------");
        obj.InsertAtPos(61,3);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after InsertAtPos are :" + iRet);
        System.out.println("-------------------------------------------------------------");

        //
        System.out.println("-------------------------------------------------------------");
        obj.DeleteAtPos(3);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after DeleteAtPos are :" + iRet);
        System.out.println("-------------------------------------------------------------");


        // Important for memory Deallocation
        obj = null;
        System.gc();
    }
}
