
#define PIC_MASTER_COMMAND	0x20
#define PIC_MASTER_DATA		0x21
#define PIC_MASTER_IMR		0x21
#define PIC_SLAVE_COMMAND	0xA0
#define PIC_SLAVE_DATA		0xA1
#define PIC_SLAVE_IMR		0xA1

#define EOI	0x20

#include "stdint.h"
#include "IDT.h"
#include "PIC.h"

void pic_remap(int interrupt_num)
{
    outb(PIC_MASTER_COMMAND, 0x11);
    outb(PIC_SLAVE_COMMAND, 0x11);
    outb(PIC_MASTER_DATA, interrupt_num);
    outb(PIC_SLAVE_DATA, interrupt_num+8);
    outb(PIC_MASTER_DATA, 0x04);
    outb(PIC_SLAVE_DATA, 2);
    outb(PIC_MASTER_DATA, 0x01);
    outb(PIC_SLAVE_DATA, 0x01);
}

void pic_mask_irqs(uint16_t mask)
{
    outb(PIC_MASTER_IMR, (uint8_t) mask);
    outb(PIC_SLAVE_IMR, (uint8_t) (mask>>8));
}

void pic_send_eoi(int irq_num)
{
    outb(PIC_MASTER_COMMAND, EOI);
    if (irq_num>7)
        outb(PIC_SLAVE_COMMAND, EOI);
}
