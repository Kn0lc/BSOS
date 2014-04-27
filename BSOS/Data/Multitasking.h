#ifndef MULTITASKING_H_INCLUDED
#define MULTITASKING_H_INCLUDED
#include "stdint.h"

void task_a();
void task_b();
struct cpu_state* SoftwareMeldung1(struct cpu_state* cpu); // da in dieser Datei (Multitasking.c die BaseKernel cpu gesichert wurde (als static) ist sie auch nur hir (nach dem Interrup) was sie war (nachdem die baseKernel(cpu-register) gesichert und die funktion verlassen wurde
struct cpu_state* init_task(uint8_t* stack, void* entry);
void init_multitasking(void);
struct cpu_state* schedule(struct cpu_state* cpu);
#endif // MULTITASKING_H_INCLUDED
