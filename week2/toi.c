#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int toi(int n, char src, char temp, char dest) {
	int count = 0;
	if (n == 1) {
		return 1;
	} else {
		//Move n-1 disks from source to temp
		count += toi(n-1, src, dest, temp);
		
		// Move nth disk from source to dest
		count += 1;
		
		// Move n-1 disks from temp to dest
		count += toi(n-1, temp, src, dest);
	}
	return count;
}

int main() {
	int n, i;
	FILE *fp;
	
	fp = fopen("toi.txt", "a");
	
	printf("Enter number of disks: ");
	scanf("%d", &n);
	
	for(i=0; i<5; i++) {
		fprintf(fp, "%d %d\n", n, toi(n, 'a', 'b', 'c'));
		n += 2;
	}
	
	fclose(fp);
	return 0;
}
