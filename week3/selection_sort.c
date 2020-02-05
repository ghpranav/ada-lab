#include<stdio.h>
#include<stdlib.h>

int selection_sort(int *a, int n) {
	int count = 0, min, tmp, i, j;
	for(i=0; i<n-1; i++) {
		min = i;
		for(j=i+1; j<n; j++) {
			count++;
			if(*(a+j) < *(a+min))
				min= j;
		}
		tmp = *(a+min);
		*(a+min) = *(a+i);
		*(a+i) = tmp;
	}
	return count;
}

int main() {
	int *a, n, i, tmp;
	FILE *fp;
	
	fp = fopen("selection.txt", "a");
	
	printf("Enter array size: ");
	scanf("%d", &n);
	
	for(tmp=0; tmp<6; tmp++) {
		a = (int *)malloc(n * sizeof(int));
		
		for(i=0; i<n; i++)
			*(a+i) = rand() % (n*10);
	
		fprintf(fp,"%d %d\n",n,selection_sort(a,n));
	
		n += 50;
	}
	
	fclose(fp);
	free(a);
	return 0;
}
