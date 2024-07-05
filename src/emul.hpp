typedef unsigned char byte; // asasdhasgdfhgsafhas portability
typedef unsigned int uint32;

#include "mem.hpp"



class Emul {
private:
	void HCF();
public:
	uint32 eip;
	MemoryClass<byte, 29> memory;
	Emul();
	void tick();
	size_t load(const char *file, size_t maxLengthBytes);
};
