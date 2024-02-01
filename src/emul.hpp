typedef unsigned char byte; // asasdhasgdfhgsafhas portability
typedef unsigned int uint32;

#include "mem.hpp"



class Emul {
public:
	uint32 eip;
	MemoryClass<byte, 29> memory;
	Emul();
	void tick();
	int load(const char *file);
};
