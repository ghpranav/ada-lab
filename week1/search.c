#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linear_search(int *a, int n, int key)
{
	int i, res, count = 0;
	for(i = 0; i < n; i++)
	{
		res = *(a + i);
		count++;
		if(res == key)
			break;
	}
	return count;
}

int binary_search(int *a, int n, int key)
{
	int l = 0, u = n - 1, m, count = 0, res;
	while(l < u)
	{
		m = (l + u) / 2;
		res = *(a + m) == key;
		count++;
		if(res)
			break;
		else
		{
			if(key < *(a +m))
				u = m - 1;
			else
				l = m + 1;
		}
	}
	return count;
}

int main()
{
	int n, *a, i, tmp;
	FILE *f1, *f2, *f3; //, *f4, *f5. *f6;
	
	f1 = fopen("linear_bc.txt","a");
	f2 = fopen("linear_wc.txt","a");
	f3 = fopen("linear_ac.txt","a");
	// f4 = fopen("binary_bc.txt","a");
	// f5 = fopen("binary_wc.txt","a");
	// f6 = fopen("binary_ac.txt","a");
	
	printf("Enter size of array: ");
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	
	srand(time(0));
	for(i = 0; i < n; i++)		
		*(a + i) = rand() % n;
	
	fprintf(f1, "%d %d\n", n, linear_search(a, n, *(a + 0)));
	fprintf(f2, "%d %d\n", n, linear_search(a, n, *(a + n - 1)));
	fprintf(f3, "%d %d\n", n, linear_search(a, n, *(a + rand() % n)));
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	// fclose(f4);
	// fclose(f5);
	// fclose(f6);
	
	free(a);
	
	return 0;
}
