#include<stdio.h>
#include<stdlib.h>

FILE *fp1, *fp2, *fp3;

int gcd(long int m, long int n) {
	long int r;
	int count = 0;
	while(n!=0) {
		r = m%n;
		m = n;
		n = r;
		count++;
	}
	fprintf(fp1, "%d\n", count);
	printf("Basic operation count = %d\n", count);
	return m;
}

int consecutive(long int m, long int n) {
	long int min;
	int count = 0;
	
	min = (m<n?m:n);
	while(min>0) {
		count++;
		if(m%min == 0) {
			count++;
			if(n%min == 0) {
				break;
			}
		}
		min--;
	}
	fprintf(fp2, "%d\n", count);
	printf("Basic operation count = %d\n", count);
	return min;
}

int gcd_mod(long int m, long int n) {
	long int r, temp;
	int count = 0;
	while(n!=0) {
		if(m<n) {
			temp = m;
			m = n;
			n = temp;
		}
		m -= n;
		count++;
	}
	fprintf(fp3, "%d\n", count);
	printf("Basic operation count = %d\n", count);
	return m;
}

int main() {
	long int a, b, r;
	int i, choice;
	
	while(1) {
		printf("\n1. Euclid algorithm\n2. Consecutive integer checking\n3. Modified Euclid algorithm\n4. Exit\n");
		scanf("%d", &choice);
		a = rand()%100;
		b = rand()%100;
		switch(choice) {
			case 1:
				fp1 = fopen("Euclid.txt", "a");
				for(i=0; i<20; i++) {
					fprintf(fp1, "%ld ", (a<b?a:b));
					r = gcd(a,b);
					printf("GCD of %ld & %ld = %ld\n", a, b, r);
					a += 10000;
					b += 5000; 
				}
				break;
				
			case 2:
				fp2 = fopen("consecutive.txt", "a");
				for(i=0; i<20; i++) {
					fprintf(fp2, "%ld ", (a<b?a:b));
					r = consecutive(a,b);
					printf("GCD of %ld & %ld = %ld\n", a, b, r);
					a += 10000;
					b += 5000; 
				}
				break;
				
			case 3:
				fp3 = fopen("Euclid_mod.txt", "a");
				for(i=0; i<20; i++) {
					fprintf(fp3, "%ld ", (a<b?a:b));
					r = gcd_mod(a,b);
					printf("GCD of %ld & %ld = %ld\n", a, b, r);
					a += 10000;
					b += 5000; 
				}
				break;
			
			case 4: exit(0);
			
			default: printf("Invalid choice\n");
		}
	}
	return 0;
}
