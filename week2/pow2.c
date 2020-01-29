#include<stdio.h>
#include<stdlib.h>

int pow2(int n) {
	int count = 0;
	if (n == 0) {
		return 0;
	} else {
		count += (pow2(n-1) + pow2(n-1));
		count++;
	}
	return count;
}

int main() {
	int n, i;
	FILE *fp;
	
	fp = fopen("pow2.txt", "a");
	
	printf("Enter number: ");
	scanf("%d", &n);
	
	for(i=0; i<10; i++) {
		fprintf(fp, "%d %d\n", n, pow2(n));
		n += 2;
	}
	
	fclose(fp);
	return 0;
}
