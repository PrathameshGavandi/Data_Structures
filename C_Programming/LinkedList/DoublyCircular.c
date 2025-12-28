/*
Program Name : Doubly Circular Linked List
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
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn -> next = *first;
        (*first) -> prev = newn;
        *first = newn;
    }
    (*last) -> next = (*first);
    (*first) -> prev = (*last);

}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last) -> next = newn;
        newn -> prev = *last;
        *last = newn;
    }
    (*last) -> next = (*first);
    (*first) -> prev = (*last);

}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first) -> next;
        free((*first) -> prev);
    }
    (*last) -> next = *first;
    (*first) -> prev = *last;
}


void DeleteLast(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *last = (*last) -> prev;
        free((*last) -> next);
    }
    (*last) -> next = *first;
    (*first) -> prev = *last;
}

void Display(PNODE first,PNODE last)
{
    if(first == NULL && last == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    printf(" <=> ");

    do
    {
        printf("| %d | <=> ",first->data);
        first = first -> next;
    } while (first != last -> next);

    printf("\n");
    
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return 0;
    }

    do
    {
        first = first -> next;
        iCount++;
    } while (first != last -> next);

    return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    PNODE newn = NULL;

    PNODE temp = NULL;
    int iSize = 0;
    int iCnt = 0;

    iSize = Count(*first,*last);

    if((pos < 1) || (pos > iSize + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first,last,no);
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
        newn->next->prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    }
    (*last)->next = (*first);
    (*first)->prev = (*last);

}


void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int iSize = 0;
    int iCnt = 0;

    iSize = Count(*first,*last);

    if((pos < 1) || (pos > iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iSize)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next = target -> next;
        target -> next -> prev = temp;

        free(target);

    }
}


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    //
    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes after InsertFirst are : %d\n",iRet);
    printf("-------------------------------------------------------------\n");


    //
    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,121);
    InsertLast(&head,&tail,151);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes after InsertLast are : %d\n",iRet);
    printf("-------------------------------------------------------------\n");


    //
    DeleteFirst(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes after DeleteFirst are : %d\n",iRet);
    printf("-------------------------------------------------------------\n");


    //
    DeleteLast(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes after DeleteLast are : %d\n",iRet);
    printf("-------------------------------------------------------------\n");


    //
    InsertAtPos(&head,&tail,61,3);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes after InsertAtPos are : %d\n",iRet);
    printf("-------------------------------------------------------------\n");


    //
    DeleteAtPos(&head,&tail,3);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes after DeleteAtPos are : %d\n",iRet);
    printf("-------------------------------------------------------------\n");


    return 0;
}
