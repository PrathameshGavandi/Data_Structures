/*
Program Name : Singly Circular Linked List
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

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {
        System.out.println("Object of SinglyCL gets created");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
            this.last.next = this.first;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
            this.last.next = this.first;
        }
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
            this.last.next = this.first;
        }
        else
        {
            this.last.next = newn;
            this.last = newn;
            this.last.next = this.first;
        }
        this.iCount++;
    }

    public void DeleteFirst()
    {
        if(this.first == null && this.last == null)
        {
            System.out.println("Linked List is empty");
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.first = this.first.next;
            this.last.next = this.first;
        }
        this.iCount--;
    }

    public void DeleteLast()
    {
        if(this.first == null && this.last == null)
        {
            System.out.println("Linked List is empty");
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            node temp = this.first;

            while(temp.next != this.last)
            {
                temp = temp.next;
            }

            this.last = temp;
            this.last.next = this.first;
        }
        this.iCount--;
    }

    public void Display()
    {
        if(this.first == null && this.last == null)
        {
            System.out.println("Linked List is empty");
            return;
        }

        node temp = this.first;

        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        } while(temp != this.first);

        System.out.println();
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        if(pos < 1 || pos > this.iCount + 1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            this.InsertFirst(no);
        }
        else if(pos == this.iCount + 1)
        {
            this.InsertLast(no);
        }
        else
        {
            node newn = new node(no);
            node temp = this.first;

            for(int i = 1; i < pos - 1; i++)
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
        if(pos < 1 || pos > this.iCount)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
        }
        else if(pos == this.iCount)
        {
            this.DeleteLast();
        }
        else
        {
            node temp = this.first;

            for(int i = 1; i < pos - 1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            this.iCount--;
        }
    }
}

class SinglyCircular
{
    public static void main(String args[])
    {
        SinglyCL obj = new SinglyCL();
        int iRet = 0;

        //
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after InsertFirst are : " + iRet);
        System.out.println("--------------------------------------------------");


        //
        obj.InsertLast(101);
        obj.InsertLast(121);
        obj.InsertLast(151);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after InsertLast are : " + iRet);
        System.out.println("--------------------------------------------------");


        //
        obj.DeleteFirst();

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after DeleteFirst are : " + iRet);
        System.out.println("--------------------------------------------------");

        
        //
        obj.DeleteLast();

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after DeleteLast are : " + iRet);
        System.out.println("--------------------------------------------------");


        //
        obj.InsertAtPos(61,3);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after InsertAtPos are : " + iRet);
        System.out.println("--------------------------------------------------");


        //
        obj.DeleteAtPos(3);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after DeleteAtPos are : " + iRet);
        System.out.println("--------------------------------------------------");


        // Important for memory Deallocation
        obj = null;
        System.gc();
    }
}
