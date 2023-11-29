#include "spimcore.h"

/* ALU */
/* 10 Points */
void ALU(unsigned A, unsigned B, char ALUControl, unsigned* ALUresult, char* Zero)
{
	// should i initizlized char* Zero to "0"


	if (strcmp("000", ALUControl) == 0) {// addition or don't care
		*ALUresult = A + B;
	}

	else if (strcmp("001", ALUControl) == 0) {// subtraction
		*ALUresult = A - B;
	}
	else if (strcmp("010", ALUControl) == 0) {// set on less than
		if (A < B) {
			ALUresult = 1;
		}
		else
			ALUresult = 0;
	}
	else if (strcmp("011", ALUControl) == 0) {// set on less than unsigned
		
	}

	else if (strcmp("100", ALUControl) == 0) {// AND operation
		if (A == B)
			ALUresult = 1;
		else
			ALUresult = 0;
	}
	else if (strcmp("101", ALUControl) == 0) {	//XOR
		if (A != B)
			ALUresult = 1;
		else
			ALUresult = 0;
	}
	else if (strcmp("110", ALUControl) == 0) {// shift left 16?
		ALUresult = B << 16;
	}
	else if (strcmp("111", ALUControl) == 0) {// R-type instruction

		// either A or B

		ALUresult = A;



	}

	if (ALUresult == 0) {
		strcpy(Zero, "1");
	}
	else
		strcpy(Zero, "0");

}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC, unsigned* Mem, unsigned* instruction)
{


}

/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned* op, unsigned* r1, unsigned* r2, unsigned* r3, unsigned* funct, unsigned* offset, unsigned* jsec)
{


}

/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op, struct_controls* controls)
{

}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1, unsigned r2, unsigned* Reg, unsigned* data1, unsigned* data2)
{

}

/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset, unsigned* extended_value)
{
	extended_value = offset << 16;
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1, unsigned data2, unsigned extended_value, unsigned funct, char ALUOp, char ALUSrc, unsigned* ALUresult, char* Zero)
{

	// i type uses extended value
	if (ALUSrc == 0) {
		ALU(data1, extended_value, ALUOp, ALUresult, Zero);
	}
	else if (ALUOp == 111) {

	}
	else
		ALU(data1,data2,ALUOp,ALUresult,Zero);

	//If overflows, then it halts and return 1


	return 0;
}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned* memdata, unsigned* Mem)
{

}

/* Write Register */
/* 10 Points */
void write_register(unsigned r2, unsigned r3, unsigned memdata, unsigned ALUresult, char RegWrite, char RegDst, char MemtoReg, unsigned* Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec, unsigned extended_value, char Branch, char Jump, char Zero, unsigned* PC)
{

}