// Heap Sort:

#include<stdio.h>

int a[20], n;

void adjust(int a[20], int i, int n)
{
	int item = a[i];
	int j = 2*i;
	
	while(j <= n)
	{
		if(j<n && a[j]<a[j+1])
			j++;
			
		if(item > a[j])
			break;
			
		a[j/2] = a[j];
		j = 2*j;
	}
	
	a[j/2] = item;
}

void heapify(int a[20], int n)
{
	int i;
	
	for(i=n/2;i>=1;i--)
		adjust(a, i, n);
}

void heapsort(int a[20], int n)
{
	int temp, i;
	
	heapify(a, n);
	
	for(i=n; i>=2; i--)
	{
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		
		adjust(a, 1, i-1);
	}
}

void main()
{
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	
	printf("Enter the elements: ");
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("\nElements Before heapsort:\n");
	for(int i=1; i<=n; i++)
	{
		printf("%d\t", a[i]);
	}
	
	heapsort(a, n);
	
	printf("\nElements After heapsort:\n");
	for(int i=1; i<=n; i++)
	{
		printf("%d\t", a[i]);
	}
}