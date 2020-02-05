#include<stdio.h>
#include<stdlib.h>

int string_match(char *t, char *p, int n, int m) {
	int i, j, count=0;
	for(i=0; i<n-m+1; i++) {
		j = 0;
		while(j<m) {
			count++;
			if(*(p+j)!=*(t+i+j)) break;
			j++;
		}
		
		if(j==m) return count;
	}
	
	return count;
}

int main() {
	char *t, *p1, *p2;
	int n=1000, m, i;
	FILE *f1, *f2;
	
	f1 = fopen("string_match_bc.txt", "a");
	f2 = fopen("string_match_wc.txt", "a");
	
	printf("Enter length of pattern: ");
	scanf("%d", &m);
	t = (char *)malloc(n * sizeof(char));
	p1 = (char *)malloc(m * sizeof(char));
	p2 = (char *)malloc(m * sizeof(char));
	
	for(i=0; i<n; i++)
		*(t+i) = '0';
	
	for(i=0; i<m; i++)
		*(p1+i) = *(p2+i) = '0';
	
	*(p2+m-1) = '1';
	
	fprintf(f1, "%d %d\n", m, string_match(t, p1, n, m));
	fprintf(f2, "%d %d\n", m, string_match(t, p2, n, m));
	
	fclose(f1);
	fclose(f2);
	free(t);
	free(p1);
	free(p2);
	return 0;
}
