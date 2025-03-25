#include <stdio.h>
void main()
{
    int n, m, alloc[10][10], max[10][10], avai[10], need[10][10], i, j, work[10], finish[10], proc = -1, flag = 1;
    printf("Enter the number of Process :");
    scanf("%d", &n);
    printf("Enter the number of resources :");
    scanf("%d", &m);
    printf("Enter the allocation matrix:\n ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter maximum matrix :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("enter the available matrix:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &avai[i]);
    }
    printf("allocation matrix is :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", alloc[i][j]);
        }

        printf("\n");
    }

    printf("maximum matrix is :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", max[i][j]);
        }
        printf("\n");
    }

    printf("Available matrix is :\n");
    for (i = 0; i < m; i++)
    {
        printf("%d\t", avai[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("\nneed matrix is :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }
}
