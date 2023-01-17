// Program 2:

#include<stdio.h>
#include<string.h>

void main()
{
    int i,n,count=0,max=0;
    char s[50];

    printf("Enter a string of 1's and 0's: ");
    scanf("%[^\n]s",s);
    
    n = strlen(s);

    for(i=0;i<n;i++)
    {
        if(s[i] == '1') count++;

        else
        {
            if(max<count) max = count;
            count = 0;
        }
    }

    if(max<count) max = count;

    printf("Largest sequence of 1's in the string is: %d",max);
}
