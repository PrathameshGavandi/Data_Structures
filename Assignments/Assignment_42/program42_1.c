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

void SearchFirstOcc(PNODE head, int no)
{
    int iPosition = 1;
    while (head != NULL)
    {
        if(head -> data == no)
        {
            printf("Element %d is first occurs at position : %d", no,iPosition);
            return;
        }
        head = head -> next;
        iPosition++;
    }
    
    printf("Element %d not found in the list\n", no);       // Works like else if no is not available in linkedlist

}


int main()
{
    PNODE First = NULL;

    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    Display(First);
    SearchFirstOcc(First,151);


    return 0;
}
