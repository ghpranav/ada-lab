#include<stdio.h>
#include<stdlib.h>

int calls, count;

int fibonacci(int n) {
	calls++;
	if (n <= 1) {
		return n;
	} else {
		count ++;
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	int n, i, temp, num, res;
	FILE *f1, *f2;
	
	f1 = fopen("fibonacci_calls.txt", "a");
	f2 = fopen("fibonacci_count.txt", "a");
	
	printf("Enter number of testcases: ");
	scanf("%d", &n);
	
	for (i=0, temp=5; i<n; i++, temp+=5) {
		calls = 0;
		count = 0;
		num = rand() % temp;
		res = fibonacci(num);
		fprintf(f1, "%d %d\n", num, calls);
		fprintf(f2, "%d %d\n", num, count);
	}
	
	fclose(f1);
	fclose(f2);
	return 0;
}
