typedef unsigned char byte; // asasdhasgdfhgsafhas portability

#include "mem.hpp"



class Emul {
public:
	MemoryClass<byte, 29> memory;
	Emul();
	void tick();
};
