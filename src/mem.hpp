#include <stdlib.h>

template<class T, int s>
class MemoryClass {
	T* mem;
public:

	MemoryClass() {
		mem = (T*)malloc(sizeof(T)*(1 << s));
	}

	T& operator[](unsigned long long index) {
		return mem[index];
	}
};
