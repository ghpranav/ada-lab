#include<stdio.h>
#include<stdlib.h>

int calls, count;

int binary(int n) {
	calls++;
	if (n == 1)
		return 1;
	else {
		count++;
		return binary(n/2) + 1;
	}
}

int main() {
	int n, i, num, res, temp;
	FILE *f1, *f2;
	
	f1 = fopen("binary_calls.txt", "a");
	f2 = fopen("binary_count.txt", "a");
	
	printf("Enter number of testcases: ");
	scanf("%d", &n);
	
	for (i=0, temp=10; i<n; i++, temp*=10) {
		calls = count = 0;
		num = rand() % temp;
		res = binary(num);
		fprintf(f1, "%d %d\n", num, calls);
		fprintf(f2, "%d %d\n", num, count);
	}
	
	fclose(f1);
	fclose(f2);
	return 0;
}
