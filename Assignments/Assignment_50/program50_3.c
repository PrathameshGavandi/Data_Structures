#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

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

bool CheckSorted(PNODE first)
{
    if (first == NULL || first->next == NULL)
    {
        return true;
    }

    while (first->next != NULL)
    {
        if (first->data > first->next->data)
        {
            return false;
        }
        first = first->next;
    }

    return true;
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;
    bool bRet = false;

    //

    InsertFirst(&head, 27);
    InsertFirst(&head, 26);
    InsertFirst(&head, 23);
    InsertFirst(&head, 22);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    //
    bRet = CheckSorted(head);
    if(bRet == true)
    {
        printf("List is Sorted\n");
    }
    else
    {
        printf("List is not Sorted\n");
    }
    

    return 0;
}