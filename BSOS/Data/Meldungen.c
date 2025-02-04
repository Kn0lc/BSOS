#include "stdint.h"
#include "TextMode.h"
#include "PIC.h"
#include "IDT.h"
#include "Meldungen.h"
#include "Multitasking.h"




///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////    'Echte' ('Fehler') Interrupts  ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////


void handle_interrupt(struct cpu_state* cpu)
{
//struct eflags_state* eflags = cpu->eflags;
//eflags = eflags;
    switch(cpu->intr)
    {
    case 0:
        FehlerMeldung0();
        break;
    case 1:
        FehlerMeldung1();
        break;
    case 2:
        FehlerMeldung2();
        break;
    case 3:
        FehlerMeldung3();
        break;
    case 4:
        FehlerMeldung4();
        break;
    case 5:
        FehlerMeldung5();
        break;
    case 6:
        FehlerMeldung6();
        break;
    case 7:
        FehlerMeldung7();
        break;
    case 8:
        FehlerMeldung8();
        break;
    case 9:
        FehlerMeldung9();
        break;
    case 10:
        FehlerMeldung10();
        break;
    case 11:
        FehlerMeldung11();
        break;
    case 12:
        FehlerMeldung12();
        break;
    case 13:
        FehlerMeldung13();
        break;
    case 14:
        FehlerMeldung14();
    case 15:
        FehlerMeldung15();
        break;
    case 16:
        FehlerMeldung16();
        break;
    case 17:
        FehlerMeldung17();
        break;
    case 18:
        FehlerMeldung18();
        break;
    case 19:
        FehlerMeldung19();
        break;


    default:
        SchreibeText("Irgend etwas leuft falsch :(");
        SchreibeText("--------------------------------------------------------------------------------");
        SchreibeFormatiertenText("Hier ist das Ende ._.", 0x70, 'm');
        SchreibeText("--------------------------------------------------------------------------------");
        asm ("hlt");
    }
}


void FehlerMeldung0()
{
    SchreibeText("Es wurde durch 0 geteilt");
    SchreibeText("--------------------------------------------------------------------------------");
    SchreibeFormatiertenText("Hier ist das Ende ._.", 0x70, 'm');
    SchreibeText("--------------------------------------------------------------------------------");
    asm ("hlt");
}

void FehlerMeldung1()
{


    // SchreibeText("Meldung1: Debug Trab/Fault");    //  Durch das trap flag das auf den STack kommt verschiebt sich alles ""ANPASSSEn!!
    SchreibeText("step");
//asm volatile ("hlt");
}

void FehlerMeldung2()
{


    SchreibeText("Meldung2: Non Maskable Interrupt");


}

void FehlerMeldung3()
{


    SchreibeText("Meldung3: Breakpoint");


}

void FehlerMeldung4()
{
    SchreibeText("Meldung4: Overfolw");

}

void FehlerMeldung5()
{
    SchreibeText("Meldung5: Bound Range");

}

void FehlerMeldung6()
{

    SchreibeText("Meldung6: Invalid Opcode Exception");
    SchreibeFormatiertenText("!! System wird angehalten !!", 0x07, 'm');
    asm("hlt\n");


}

void FehlerMeldung7()
{

    SchreibeText("Meldung7: Device Not available");



}

void FehlerMeldung8()
{

    SchreibeText("Meldung8: Double Foult");



}

void FehlerMeldung9()
{


    SchreibeText("Meldung9: Coprocessor Segment Overrun");



}

void FehlerMeldung10()
{

    SchreibeText("Meldung10: Invalid TSS");



}

void FehlerMeldung11()
{

    SchreibeText("Meldung11: Segment not Present");



}

void FehlerMeldung12()
{

    SchreibeText("Meldung12: Stack Fault");



}

void FehlerMeldung13()
{

    SchreibeText("Meldung13: General Protection");


}

void FehlerMeldung14()
{


    SchreibeText("Meldung14: Page Fault");


}

void FehlerMeldung15()
{


    SchreibeText("Meldung15: Reserviert (Wie um alles in der WELT hast du es geschaft das du das hier siehst???? !:D '0'");


}

void FehlerMeldung16()
{


    SchreibeText("Meldung16: x87 floating Point");


}

void FehlerMeldung17()
{

    SchreibeText("Meldung17: Alignment Check");


}

void FehlerMeldung18()
{


    SchreibeText("Meldung18: Machine Check");


}

void FehlerMeldung19()
{

    SchreibeText("Meldung19: SIMD Floating Point");


}




///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////    Hardware Interrupts  (IRQ's) /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////






void handle_hardware_interrupt(struct cpu_state* cpu)
{

    switch(cpu->intr)
    {
    case 0:
        HardwareMeldung0();
        break;
    case 1:
        HardwareMeldung1();
        break;
    case 2:
        HardwareMeldung2();
        break;
    case 3:
        HardwareMeldung3();
        break;
    case 4:
        HardwareMeldung4();
        break;
    case 5:
        HardwareMeldung5();
        break;
    case 6:
        HardwareMeldung6();
        break;
    case 7:
        HardwareMeldung7();
        break;
    case 8:
        HardwareMeldung8();
        break;
    case 9:
        HardwareMeldung9();
        break;
    case 10:
        HardwareMeldung10();
        break;
    case 11:
        HardwareMeldung11();
        break;
    case 12:
        HardwareMeldung12();
        break;
    case 13:
        HardwareMeldung13();
        break;
    case 14:
        HardwareMeldung14();
    case 15:
        HardwareMeldung15();
        break;


    default:
        SchreibeText("Irgend etwas leuft falsch :(");
        SchreibeText("--------------------------------------------------------------------------------");
        SchreibeFormatiertenText("Hier ist das Ende ._.", 0x70, 'm');
        SchreibeText("--------------------------------------------------------------------------------");
        asm ("hlt");

    }
    if (cpu->intr >= 8)
    {
        outb(0xa0, 0x20);
    }
    else
    {
        outb(0x20, 0x20);
    }
}





static int x=0;


void HardwareMeldung0( )
{
    x++;
    switch(x)
    {
    case 0:
        SchreibeText("0");
        break;
    case 10:
        SchreibeText("10");
        break;
    case 20:
        SchreibeText("20");
        break;
    case 30:
        SchreibeText("0");
        break;
    case 40:
        SchreibeText("10");
        break;
    case 50:
        SchreibeText("20");
        break;
    case 60:
        SchreibeText("0");
        break;
    case 70:
        SchreibeText("10");
        break;
    case 80:
        SchreibeText("20");
        break;
    case 90:
        SchreibeText("0");
        break;
    case 100:
        SchreibeText("10");
        break;
    case 110:
        SchreibeText("10");
        break;
    case 120:
        SchreibeText("20");
        break;
    case 130:
        SchreibeText("0");
        break;
    case 140:
        SchreibeText("10");
        break;
    case 150:
        SchreibeText("20");
        break;
    case 160:
        SchreibeText("0");
        break;
    case 170:
        SchreibeText("10");
        break;
    case 180:
        SchreibeText("20");
        break;
    case 190:
        SchreibeText("0");
        break;
    case 200:
        SchreibeText("200");
        break;
    case 210:
        SchreibeText("10");
        break;
    case 220:
        SchreibeText("20");
        break;
    case 230:
        SchreibeText("0");
        break;
    case 240:
        SchreibeText("10");
        break;
    case 250:
        SchreibeText("20");
        break;
    case 260:
        SchreibeText("0");
        break;
    case 270:
        SchreibeText("10");
        break;
    case 280:
        SchreibeText("20");
        break;
    case 290:
        SchreibeText("0");
        break;
    case 300:
        SchreibeText("10");
        break;
    case 310:
        SchreibeText("10");
        break;
    case 320:
        SchreibeText("20");
        break;
    case 330:
        SchreibeText("0");
        break;
    case 340:
        SchreibeText("10");
        break;
    case 350:
        SchreibeText("2");
        break;
    case 360:
        SchreibeText("0");
        break;
    case 370:
        SchreibeText("10");
        break;
    case 380:
        SchreibeText("20");
        break;
    case 390:
        SchreibeText("0");
        break;
    case 400:
        SchreibeText("400");
        break;
    default:
        SchreibeText("HardwareMeldung0");
        break;
    }

}

void HardwareMeldung1()
{


    SchreibeText("HarwareMeldung1");



}

void HardwareMeldung2()
{


    SchreibeText("HarwareMeldung2");



}

void HardwareMeldung3()
{


    SchreibeText("HarwareMeldung3");



}

void HardwareMeldung4()
{


    SchreibeText("HarwareMeldung4");



}

void HardwareMeldung5()
{


    SchreibeText("HarwareMeldung5");



}

void HardwareMeldung6()
{


    SchreibeText("HarwareMeldung6");



}

void HardwareMeldung7()
{


    SchreibeText("HarwareMeldung7");



}

void HardwareMeldung8()
{


    SchreibeText("HarwareMeldung8");


}

void HardwareMeldung9()
{


    SchreibeText("HarwareMeldung9");



}

void HardwareMeldung10()
{


    SchreibeText("HarwareMeldung10");



}

void HardwareMeldung11()
{


    SchreibeText("HarwareMeldung11");



}

void HardwareMeldung12()
{


    SchreibeText("HarwareMeldung12");



}

void HardwareMeldung13()
{


    SchreibeText("HarwareMeldung13");



}

void HardwareMeldung14()
{


    SchreibeText("HarwareMeldung14");



}

void HardwareMeldung15()
{


    SchreibeText("HarwareMeldung15");



}


///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////    Software Interrupts  /////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////






struct cpu_state* handle_software_interrupt(struct cpu_state* cpu)
{

    switch (cpu->intr)
    {
    case 0:
        cpu=SoftwareMeldung0(cpu);
        break;
    case 1:
        cpu=SoftwareMeldung1(cpu);
        break;
    case 2:
        SoftwareMeldung2();
        break;
    case 3:
        SoftwareMeldung3();
        break;
    case 4:
        SoftwareMeldung4();
        break;

    default:
        SchreibeText("Irgend etwas leuft falsch :(");
        SchreibeText("--------------------------------------------------------------------------------");
        SchreibeFormatiertenText("Hier ist das Ende ._.", 0x70, 'm');
        SchreibeText("--------------------------------------------------------------------------------");
        asm ("hlt");
    }


    return cpu;
}





struct cpu_state* SoftwareMeldung0(struct cpu_state* cpu)
{
    cpu = schedule(cpu);
    return cpu;
}




void SoftwareMeldung2()
{
    SchreibeText("SoftwareMeldung 2");
}

void SoftwareMeldung3()
{
    SchreibeText("SoftwareMeldung 3");
}

void SoftwareMeldung4()
{
    SchreibeText("SoftwareMeldung 4");
}




