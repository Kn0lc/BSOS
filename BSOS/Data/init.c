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
 //AktiviereSchrittweisesAusfuehren();
 init_multitasking();
 SchreibeText("test");
 //Hallo
 asm volatile("int $48");
 SchreibeText("Welcome back // Wilkommen Zurueck ");
 SchreibeText("Oder auch: Das Betiebsystem ist am Ende (mit den Nerver)");
}
