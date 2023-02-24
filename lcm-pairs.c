#include <stdio.h>
#include <stdlib.h>

/*
Gets the gcd of a and b
*/
int gcd(int a, int b) {
	int x, y, yb;
	/* Set the greater one of a and b to x, and the smaller one to y */
	(a > b) ? (x = a, y = b) : (x = b, y = a);
	while (y) {
		yb = y;
		y = x % y;
		x = yb;
	}
	return x;
		
		
}

/*
Get the lcm of a and b
*/
int lcm(int a, int b) {
	return a * b / gcd(a,b);
}

int pairsSmallerThanM(int m) {
	int abg,k;
	int n = 2;
	int count;
	int result = 0;

	while ( n < m + 1 ) {
		k = n+1;
		count = 0;
		while ( k < m + 1 ) {
			abg = lcm(n, k);
			if (abg < m + 1) count++;
			k++;
		}
		result += count;  
		n++;
	}
	return result;
}

int main(int argc, char *argv[]) {
	if (argc < 3) { printf("ERROR: Not enough arguments, expected at least 2\n"); return 1; }
	int m = atoi(argv[2]);
	int l = atoi(argv[1]);
	int c1;
	int c2 = 0;

	while (l < m + 1) {
		c1 = pairsSmallerThanM(l);
		printf("%d: %d, increase: %d\n", l, c1, c1 - c2);
		c2 = c1;
		l++;
	}

	return 0;
}