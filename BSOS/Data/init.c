#include "stdint.h"
#include "IDT.h"
#include "GDT.h"
#include "SystemUhr.h"
#include "TextMode.h"
#include "PIC.h"
#include "Trap.h"
#include "Multitasking.h"


void init(void)
{
    BildschirmLeeren();
    SchreibeText("Hallo Welt :D !");
    init_gdt();
    load_idt();
  //pit_init(1);
 // SchreibeText("test1");
   //asm ("int $32");
 //  SchreibeText("Test");
 //AktiviereSchrittweisesAusfuehren();
//init_multitasking();
 SchreibeText("test");
 asm volatile("int $48");
}
