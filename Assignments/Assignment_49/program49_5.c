#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

int CountTwoDigit(PNODE first)
{
    int iTwoDigit = 0;
    
    while (first != NULL)
    {
        int iCount = 0;
        int iNum = first -> data;

        while (iNum != 0)
        {
            iNum = iNum / 10;
            iCount++;
        }

        if(iCount == 2)
        {
            iTwoDigit++;
        }
        
        first = first->next;
    }

    return iTwoDigit;
}

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | ->", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    //
    InsertFirst(&head, 51);
    InsertFirst(&head, 120);
    InsertFirst(&head, 30);
    InsertFirst(&head, 520);
    InsertFirst(&head, 22);
    InsertFirst(&head, 111);
    InsertFirst(&head, 24);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    //
    iRet = CountTwoDigit(head);
    printf("Count of two digit elements is : %d\n", iRet);

    return 0;
}