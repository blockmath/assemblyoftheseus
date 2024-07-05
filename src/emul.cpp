#include "emul.hpp"

Emul::Emul() {
	memory = MemoryClass<byte, 29>();
	eip = 0;
}


void Emul::tick() {
	uint32 iword = ((uint32)memory[eip] << 24) | ((uint32)memory[eip + 1] << 16) | ((uint32)memory[eip + 2] << 8) | ((uint32)memory[eip + 3]);
	if ((iword >> 27) == 0b11111) { // datamove (up for change)
		uint32 iword2 = ((uint32)memory[eip+4] << 24) | ((uint32)memory[eip+5] << 16) | ((uint32)memory[eip+6] << 8) | ((uint32)memory[eip+7]);
		iword = (iword & 0x07ffffff) << 2;
		iword2 = (iword & 0x07ffffff) << 2;
		*(uint32 *)&memory[iword2] = *(uint32 *)&memory[iword];
		eip += 8;
		return;
	}
	byte arg1 = (iword >> 16) & 0xff;
	byte arg2 = (iword >> 8) & 0xff;
	int dr = (iword >> 24) & 0b00000111;
	byte *rptr = &memory[eip+dr];
	eip += 4;
	switch (iword >> 27) {
		case 0: // jump
			if(eip - 4 == iword << 2) {std::cout<<"The virtual machine caught on virtual fire. Task was failed successfully."<<std::endl;exit(0);}
			eip = iword << 2;
			break;
		case 1: // add
			*rptr = arg1 + arg2;
			break;
		case 2: // sub
			*rptr = arg1 - arg2;
			break;
		case 3: // mul
			*rptr = arg1 * arg2;
			break;
		case 4: // div
			*rptr = arg1 / arg2;
			break;
		case 5: // and
			*rptr = arg1 & arg2;
			break;
		case 6: // ora
			*rptr = arg1 | arg2;
			break;
		case 7: // eor
			*rptr = arg1 ^ arg2;
			break;
		case 8:// out
			std::cout<<arg1;
			break;
		case 30: // beq
			if (arg1 == 0){
				if(arg2 == 0) {std::cout<<"The virtual machine caught on virtual fire. Task was failed successfully."<<std::endl;exit(0);}
				eip = (eip - 4)+(arg2 << 2);
			}
			break;
		case 31: // datamove
			break;
	}

}

#include <stdio.h>

size_t Emul::load(const char *file, size_t maxLengthBytes) {
	FILE *file = fopen(file, "rb");
	size_t yield = fread(&memory[0], 1, maxLengthBytes, file);
	fclose(file);
	return yield;
}
