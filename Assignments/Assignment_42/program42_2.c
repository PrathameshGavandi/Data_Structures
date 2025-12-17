#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*Head == NULL)  // LInked list empty
    {
        (*Head) = newn;
    }
    else                // Linked list contains atleast 1 node
    {
        newn -> next = (*Head);
        (*Head) = newn;
    }
}

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("| %d |->", Head ->data);
        Head = Head -> next;
    }
    printf("NULL \n");
    
}

void SearchLastOcc(PNODE head, int no)
{
    int iPosition = 1;
    int iLastPosition = 0;
    while (head != NULL)
    {
        if(head -> data == no)
        {
            iLastPosition = iPosition;
        }
        head = head -> next;
        iPosition++;
        
    }
    if(iLastPosition > 0)
    {
        printf("Element %d is Last occurs at position : %d", no,iLastPosition);
    }
    else
    {
        printf("Element %d not found in the list\n", no);
    }

}


int main()
{
    PNODE First = NULL;

    InsertFirst(&First,80);
    InsertFirst(&First,70);
    InsertFirst(&First,30);
    InsertFirst(&First,50);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);

    SearchLastOcc(First,130);
    


    return 0;
}