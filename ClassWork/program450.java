/*
Program Name : Doubly Linear Linked List
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
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLL
{
    private node first;
    private int iCount;
    
    DoublyLL()
    {
        System.out.println("Object of DoublyLL gets Created");
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            { 
                temp = temp.next;
            }

            temp.next = newn;
            newn.prev = temp;
        }
        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
            first.prev = null;
        }

        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        iCount--;
    }

    public void Display()
    {
        node temp = null;
        int iCnt = 0;

        temp = first;

        System.out.print("null");
        while (temp != null)
        {
            System.out.print(" <=> | " + temp.data + " |");
            temp = temp.next;
        }
        System.out.println(" <=> null");

    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;

        int iCnt = 0;

        if((pos < 1) || (pos > iCount + 1))
        {
            System.out.println("Invalid Position\n");
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
            newn = new node(no);

            temp = first;
            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
    }


    public void DeleteAtPos(int pos)
    {
        node temp = null;
        node target = null;

        int iCnt = 0;

        if((pos < 1) || (pos > iCount))
        {
            System.out.println("Invalid Position\n");
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

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            target = temp.next;

            temp.next = target.next;
            target.next.prev = temp;

            target.next = null;
            target.prev = null;

            iCount--;
        }
    }
}
class DoublyLinear
{
    public static void main (String A[])
    {
        DoublyLL obj = null;    //Refrence

        obj = new DoublyLL();

        int iRet = 0;

        //or//

        //DoublyLL obj = new DoublyLL();

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


    }
}