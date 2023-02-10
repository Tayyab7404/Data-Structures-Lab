// Heap Sort:

#include<stdio.h>

int a[20], n;

void adjust(int a[20], int i, int n);
void heapsort(int a[20], int n);
void heapify(int a[20], int n);

void main()
{
    	int i;
    
	printf("Enter the no. of elements: ");
	scanf("%d", &n);

	printf("Enter the elements: ");
	for(i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("\nElements before Heap Sort:\n");
	for(i=1; i<=n; i++)
	{
		printf("%d\t", a[i]);
	}

	heapsort(a, n);

	printf("\nElements after Heap Sort:\n");
	for(i=1; i<=n; i++)
	{
		printf("%d\t", a[i]);
	}
}

void adjust(int a[20], int i, int n)
{
	int item = a[i];
	int j = i*2;
	
	while(j <= n)
	{
		if(j<n && a[j]<a[j+1])
		{
			j++;
		}
			
		if(item > a[j])
		{
			break;
		}
			
		a[j/2] = a[j];
		j *= 2;
	}
	
	a[j/2] = item;
}

void heapify(int a[20], int n)
{
	for(int i=n/2; i>=1; i--)
	{
		adjust(a, i, n);
	}
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
