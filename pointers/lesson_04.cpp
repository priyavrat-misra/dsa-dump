#include <stdio.h>

int main(){
	int a = 1025;  // 00000000 00000000 00000100 00000001
	int *p = &a;
	printf("size of int = %ld bytes\n", sizeof(int));
	printf("addr(p) = %d, val(p) = %d\n", p, *p);
	printf("addr(p+1) = %d, val(p+1) = %d\n", p+1, *(p+1));
	char *p0 = (char*) p;  // typecast
	printf("size of char = %ld byte\n", sizeof(char));
	printf("addr(p0) = %d, val(p0) = %d\n", p0, *p0);
	printf("addr(p0+1) = %d, val(p0+1) = %d\n", p0+1, *(p0+1));
}
