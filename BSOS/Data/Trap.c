#include "TextMode.h"



void AktiviereSchrittweisesAusfuehren()
{
asm volatile("pushf\n"
"pop %ax\n"
"or $0x0100, %ax\n"
"push %ax\n"
"popf\n");
}
/*
void DeAktiviereSchrittweisesAusfuehren()
{
    SchreibeText("Ok");
}
*/
