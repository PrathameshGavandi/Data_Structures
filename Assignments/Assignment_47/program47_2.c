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

void CountDigits(PNODE first)
{

    while(first != NULL)
    {
        int iNum = first -> data;
        int temp = iNum;
        int iCount = 0;

        if(temp == 0 )
        {
            iCount = 1;
        }
        else
        {
            while (temp != 0)
            {
                temp = temp / 10;
                iCount++;
            }
        }
        
        printf("| %-5d | -> %d\n", iNum, iCount);
        
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
    InsertFirst(&head, 51);
    InsertFirst(&head, 2250);
    InsertFirst(&head, 111);
    InsertFirst(&head, 50);
    InsertFirst(&head, 232);
    InsertFirst(&head, 11);
    InsertFirst(&head, 24);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    //
    CountDigits(head);

    return 0;
}