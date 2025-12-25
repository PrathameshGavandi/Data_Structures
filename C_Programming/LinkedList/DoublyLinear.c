/*
Program Name : Doubly Linear Linked List
Language     : C
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

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        (*first) -> prev = newn;
        *first = newn;
    }
}

void InsertLast(PPNODE first,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
        
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        (*first) = (*first) -> next;
        free(temp);
        (*first) -> prev = NULL; 
    }
}


void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        free (temp -> next);
        temp -> next = NULL;  
    }
}



void Display(PNODE first)
{
    printf("\nNULL <=>");
    while (first != NULL)
    {
        printf("| %d | <=> ",first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void InsertAtPos(PPNODE first, int no , int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize + 1 ))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn = (PNODE) malloc (sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;
    }
}


void DeleteAtPos(PPNODE first,int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCnt = 0;

    int iSize = Count(*first);

    if((pos < 1) || (pos > iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        target = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next = target -> next;
        temp -> next -> prev = temp;
        free(target);
    }
}



int main()
{
    PNODE head = NULL;
    int iRet = 0;

    //
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n",iRet);
    printf("-------------------------------------------------------------");

    //
    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after InsertLast are : %d\n",iRet);
    printf("-------------------------------------------------------------");

    //
    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after DeleteFirst are : %d\n",iRet);
    printf("-------------------------------------------------------------");

    //
    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after DeleteLast are : %d\n",iRet);
    printf("-------------------------------------------------------------");

    //
    InsertAtPos(&head,61,3);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after InsertAtPos are : %d\n",iRet);
    printf("-------------------------------------------------------------");

    //
    DeleteAtPos(&head,3);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after DeleteAtPos are : %d\n",iRet);
    printf("-------------------------------------------------------------");


    return 0;
}
