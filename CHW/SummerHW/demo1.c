#include <stdio.h>
int main() {
	long long a = 0, b = 1;
	printf("The next number is %lli\n", a);
	printf("The next number is %lli\n", b);
	for(int i = 0; i < 44; i++)
	{
		a = a + b;
		b = a + b;
		printf("The next number is %lli\n", a );
		printf("The next number is %lli\n", b);
	}
    return 0;
}