#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n, req[50], mov = 0, cp;
    printf("enter the intial head position \n");
    scanf("%d", &cp);
    printf("enter the number of request \n");
    scanf("%d", &n);
    printf("Enter the request order \n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }
    mov = mov + abs(cp - req[0]);

    for (i = 1; i < n; i++)
    {
        mov = mov + abs(req[i] - req[i - 1]);
    }
    printf("\n");
    printf("Total head movment =%d\n", mov);
}
