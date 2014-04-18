#ifndef IDTh
#define IDTh

#define IDT_ENTRIES 256

#include <stdint.h>

static inline void outb(uint16_t port, uint8_t data)
{
    asm volatile ("outb %0, %1" : : "a" (data), "Nd" (port));
}
void init_gdt(void);
void init_intr(void);
void load_idt(void);

#endif
