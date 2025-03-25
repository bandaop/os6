
#include <stdio.h>
struct node
{
    int data;
    struct node *next;

} *newnode, *temp, *start, *temp1;
int m, n, i, x;

void create()
{
    i = 0;
    start = NULL;
    while (i != n)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        newnode->data = -1;
        if (start == NULL)
            start = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        } // else
        i++;
    } // while

} // create

void allocate()
{
    int count = 0;
    temp1 = start;

    if (temp1->data == -1)
    {

        if (m <= n)
        {
            for (i = 0; i < m - 1; i++)
            {
                temp1->data = 0;
                temp1 = temp1->next;
            }
            temp1->data = -2; // end of file
        } // if
        else
        {
            printf("\nBlocks can not be allocated");
            exit(0);
        }
    } // if
    else
    {
        while (temp1->data != -1)
        {
            temp1 = temp1->next;
            count++;
        }
        if (m + count <= n)
        {
            for (i = 0; i < m - 1; i++)
            {
                temp1->data = 0;
                temp1 = temp1->next;
            } // for
            temp1->data = -2; // end of file
        } // if
        else
        {
            printf("\nBlocks can not be allocated");
            exit(0);
        }
    } // else

} // allocate

void deallocate()
{
    int count = 0;
    temp1 = start;
    while (count != x - 1)
    {
        temp1 = temp1->next;
        if (temp1->data == -2)
            count++;
    } // while

    while (temp1->data != -2)
    {
        temp1->data = -1;
        temp1 = temp1->next;

    } // while*/
    temp1->data = -1;

} // deallocate

void display()
{
    int tot = 0;
    temp1 = start;
    while (temp1 != NULL)
    {
        printf("%d\t", temp1->data);
        if (temp1->data == -1)
            tot++;
        temp1 = temp1->next;
    } // while
    printf("\nTotal allocated blocks are %d", n - tot);
    printf("\nTotal free blocks are %d", tot);
}
void main()
{
    int ch;
    while (1)
    {
        printf("\n1:Create\n");
        printf("2:Add new\n");
        printf("3:Deallocate\n");
        printf("4:Display\n");
        printf("5:Exit\n");
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the size of disk");
            scanf("%d", &n);
            create();
            break;
        case 2:
            printf("Enter the number of blocks to be allocated");
            scanf("%d", &m);
            allocate();
            break;
        case 3:
            printf("Enter the block to delete\n");
            scanf("%d", &x);
            deallocate();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        } // switch
    } // while
} // main

/*output

1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice1
Enter the number of blocks5

1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice4
-1	-1	-1	-1	-1
1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice2
Enter the number of blocks to be allocated2

1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice4
0	-2	-1	-1	-1
1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice3
Enter the block to delete
1

1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice4
-1	-1	-1	-1	-1
1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice2
Enter the number of blocks to be allocated3

1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice4
0	0	-2	-1	-1
1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice2
Enter the number of blocks to be allocated2

1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice4
0	0	-2	0	-2
1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice3
Enter the block to delete
1

1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice4
-1	-1	-1	0	-2
1:Create
2:Add new
3:Deallocate
4:Display
5:Exit

Enter your choice*/
