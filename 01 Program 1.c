// Program 1:

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,n;

    printf("Enter size of the array: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter the elements into the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    i=0;

    while(1)
    {
        if(a[abs(a[i])] < 0)
        {
            printf("The duplicate element is: %d",-a[i]);
            break;
        }

        else
        {
            a[abs(a[i])] *= -1;
            i = abs(a[i]);
        }
    }
}
