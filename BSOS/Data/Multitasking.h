#ifndef MULTITASKING_H_INCLUDED
#define MULTITASKING_H_INCLUDED
#include "stdint.h"
void task1();
void task2();
struct cpu_state* init_task(uint8_t* stack, void* entry);
void init_multitasking(void);
struct cpu_state* schedule(struct cpu_state* cpu);
#endif // MULTITASKING_H_INCLUDED
