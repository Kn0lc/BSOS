#ifndef PCIh
#define PCIh

void pic_remap(int interrupt_num);
void pic_mask_irqs(uint16_t mask);
void pic_send_eoi(int irq_num);

#endif