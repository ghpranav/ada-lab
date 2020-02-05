#include<stdio.h>
#include<stdlib.h>

int bubble_sort(int *a, int n) {
	int i, j, tmp, count = 0, flag;
	for(i=0; i<n-1; i++) {
		flag = 0;
		for(j=0; j<n-i-1; j++) {
			count++;
			if(*(a+j+1) < *(a+j)) {
				flag++;
				tmp = *(a+j+1);
				*(a+j+1) = *(a+j);
				*(a+j) = tmp;
			}
		}
		if(flag==0) break;
	}
	return count;
}

int main() {
	int *a, *b, n, i, p, q;
	FILE *f1, *f2;
	
	f1 = fopen("bubble_bc.txt", "a");
	f2 = fopen("bubble_wc.txt", "a");
	
	printf("Enter array size: ");
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	b = (int *)malloc(n * sizeof(int));
	
	p = 10;
	q = rand()%(n*10);
	for(i=0; i<n; i++, p++, q--) {
		*(a+i) = p;
		*(b+i) = q;
	}
	
	fprintf(f1, "%d %d\n", n, bubble_sort(a, n));
	fprintf(f2, "%d %d\n", n, bubble_sort(b, n));
	
	fclose(f1);
	fclose(f2);
	free(a);
	free(b);
	return 0;
}
