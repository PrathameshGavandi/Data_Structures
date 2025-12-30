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

void DisplayPrime(PNODE first)
{

    while(first != NULL)
    {
        int iNum = first -> data;
        int temp = iNum;
        int iCount = 0;

        for(int iCnt = 2; iCnt < iNum; iCnt++)
        {
            if(iNum % iCnt == 0)
            {
                iCount++;
            }
        }

        if(iCount == 0)
        {
            printf("%d\t", iNum);
        }
        
        first = first -> next;
    }
}

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | ->", first->data);
        first = first->next;
    }
    printf(" NULL\n");
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
    InsertFirst(&head, 2);
    InsertFirst(&head, 22);
    InsertFirst(&head, 51);
    InsertFirst(&head, 19);
    InsertFirst(&head, 12);
    InsertFirst(&head, 11);
    InsertFirst(&head, 23);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    //
    DisplayPrime(head);

    return 0;
}