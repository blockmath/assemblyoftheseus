#include <stdlib.h>

Mem::Mem() {
	mem = (T*)malloc(sizeof(T)*(1 << s));
}

T& Mem::operator[](unsigned long long index) {
	return mem[index];
}
