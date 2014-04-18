#include "IDT.h"
#include "TextMode.h"


void pit_init(int freq)
{
   int counter = 1193182 / freq;
   outb(0x43, 0x16);
   outb(0x40,counter & 0xFF);
   outb(0x40,counter >> 8);
}
