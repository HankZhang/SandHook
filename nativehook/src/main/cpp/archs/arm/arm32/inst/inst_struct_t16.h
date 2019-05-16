//
// Created by swift on 2019/5/12.
//

#ifndef SANDHOOK_NH_INST_STRUCT_T16_H
#define SANDHOOK_NH_INST_STRUCT_T16_H


#include "instruction.h"
#include "inst_code_arm32.h"

#define STRUCT_T16(X) T16_STRUCT_##X
#define OPCODE_T16(X) T16_OPCODE_##X
#define DEFINE_OPCODE_T16(X, V) const U32 OPCODE_T16(X) = V;
#define DEFINE_STRUCT_T16(X) struct STRUCT_T16(X) : public Base

#define DEFINE_STRCUT_BASE_T16(w_base, w_op) \
    InstT16 opcode:w_op;    \
    InstT16 opcode_base:w_base;


//Shift (immediate), add, subtract, move, and compare
//opcode_base == 0b00
DEFINE_OPCODE_T16(BASE_SASMC, 0b00)
//Data-processing
DEFINE_OPCODE_T16(DATA_PROC, 0b010000)

DEFINE_OPCODE_T16(SPDIABE, 0b010001)

DEFINE_OPCODE_T16(MISC, 0b1011)


DEFINE_OPCODE_T16(B, 0b11100)
DEFINE_STRUCT_T16(B) {
    InstT16 imm11:11;
    InstT16 opcode:5;
};

DEFINE_OPCODE_T16(B_COND, 0b1101)
DEFINE_STRUCT_T16(B_COND) {
    InstT16 imm8;
    InstT16 cond:4;
    InstT16 opcode:4;
};


DEFINE_OPCODE_T16(BX_BLX_1, 0b01000111)
DEFINE_OPCODE_T16(BX_BLX_2, 0b000)
DEFINE_STRUCT_T16(BX_BLX) {
    InstT16 opcode2:3;
    InstT16 rm:4;
    InstT16 op:1;
    InstT16 opcode1:8;
};



#endif //SANDHOOK_NH_INST_STRUCT_T16_H
