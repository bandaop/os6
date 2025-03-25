#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move, index;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &RQ[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &initial);
    printf("Enter the total disk size: ");
    scanf("%d", &size);
    printf("Enter the head movement direction 1 for high, 0 for low: ");
    scanf("%d", &move);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i])
        {
            index = i;
            break;
        }
    }
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }

        // change
        TotalHeadMoment += abs(size - RQ[i - 1] - 1);
        TotalHeadMoment += abs(size - 1 - 0);
        initial = 0;
        for (i = 0; i < index; i++)
        {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // change
        TotalHeadMoment += abs(RQ[i + 1] - 0);
        TotalHeadMoment += abs(size - 1 - 0);
        initial = size - 1;
        for (i = n - 1; i >= index; i--)
        {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    printf("Total head movement is: %d\n", TotalHeadMoment);
    return 0;
}