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

int CountPrime(PNODE first)
{
    int iPrimeCount = 0;

    while(first != NULL)
    {
        int iNum = first->data;
        int iCount = 0;

        if(iNum <= 1)
        {
            first = first->next;
            continue;
        }

        for(int i = 2; i < iNum; i++)
        {
            if(iNum % i == 0)
            {
                iCount++;
                break;   
            }
        }

        if(iCount == 0)
        {
            iPrimeCount++;
        }

        first = first->next;
    }

    return iPrimeCount;
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
    iRet = CountPrime(head);
    printf("Count of prime numbers is : %d",iRet);

    return 0;
}