#include<stdio.h>
#include<stdlib.h>

int count;
void insertsort(int arr[], int n) {
	int i, j, ele;
	for(i=1; i<n;i++) {
		ele = arr[i];
		j = i-1;
		
		while(j>=0 && arr[j]>ele) {
			if(j != i-1)
				count++;
			arr[j+1] = arr[j];
			j--;
		}
		count++;
		
		arr[j+1] = ele;
	}
}

int main() {
	FILE *f1, *f2;
	int *arr, n, t, i;
	f1 = fopen("ins_sort_bc.txt", "a");
	f2 = fopen("ins_sort_wc.txt", "a");
	printf("Enter number of test cases: ");
	scanf("%d", &t);
	while(t--) {
		printf("Enter input size: ");
		scanf("%d", &n);
		arr = (int *)malloc(n*sizeof(int));
		*(arr+0) = rand() % 50;
		for(i=1; i<n; i++)
			*(arr+i) = *(arr+i-1)+2;
		count = 0;
		insertsort(arr, n);
		fprintf(f1, "%d %d\n", n, count);
		*(arr+0) = 1000;
		for(i=0; i<n; i++)
			*(arr+i) = *(arr+i-1) - 3;
		count = 0;
		insertsort(arr, n);
		fprintf(f2, "%d %d\n", n, count);
		free(arr);
	}
	return 0;
}
