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

int LastOccur(PNODE first, int no)
{
    int iCount = 1;
    int iPos = 0;
    while (first != NULL)
    {
        if (first->data == no)
        {
            iPos = iCount;
        }
        iCount++;
        first = first->next;
    }

    return iPos;
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
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);
    InsertFirst(&head, 50);
    InsertFirst(&head, 22);
    InsertFirst(&head, 11);
    InsertFirst(&head, 24);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    //
    iRet = LastOccur(head,11);

    if (iRet < 1)
    {
        printf("Number not found\n");
    }
    else
    {
        printf("Last Occurrence position is : %d\n", iRet);
    }

    return 0;
}