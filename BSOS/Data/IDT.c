#define IDT_FLAG_INTERRUPT_GATE 0xe
#define IDT_FLAG_PRESENT 0x80
#define IDT_FLAG_RING0 0x00
#define IDT_FLAG_RING3 0x60
#define IDT_ENTRIES 256

#include "stdint.h"
#include "IDT.h"
#include "init.h"
#include "Meldungen.h"
#include "TextMode.h"


extern void FehlerMeldungasm0(void);
extern void FehlerMeldungasm1(void);
extern void FehlerMeldungasm2();
extern void FehlerMeldungasm3(void);
extern void FehlerMeldungasm4(void);
extern void FehlerMeldungasm5(void);
extern void FehlerMeldungasm6(void);
extern void FehlerMeldungasm7(void);
extern void FehlerMeldungasm8(void);
extern void FehlerMeldungasm9(void);
extern void FehlerMeldungasm10(void);
extern void FehlerMeldungasm11(void);
extern void FehlerMeldungasm12(void);
extern void FehlerMeldungasm13(void);
extern void FehlerMeldungasm14(void);
extern void FehlerMeldungasm15(void);
extern void FehlerMeldungasm16(void);
extern void FehlerMeldungasm17(void);
extern void FehlerMeldungasm18(void);
extern void FehlerMeldungasm19(void);

extern void HardwareMeldungasm0(void);
extern void HardwareMeldungasm1(void);
extern void HardwareMeldungasm2(void);
extern void HardwareMeldungasm3(void);
extern void HardwareMeldungasm4(void);
extern void HardwareMeldungasm5(void);
extern void HardwareMeldungasm6(void);
extern void HardwareMeldungasm7(void);
extern void HardwareMeldungasm8(void);
extern void HardwareMeldungasm9(void);
extern void HardwareMeldungasm10(void);
extern void HardwareMeldungasm11(void);
extern void HardwareMeldungasm12(void);
extern void HardwareMeldungasm13(void);
extern void HardwareMeldungasm14(void);
extern void HardwareMeldungasm15(void);

extern void SoftwareMeldungasm0(void);
extern void SoftwareMeldungasm1(void);
extern void SoftwareMeldungasm2(void);
extern void SoftwareMeldungasm3(void);
extern void SoftwareMeldungasm4(void);

static uint64_t idt[IDT_ENTRIES];


static void init_pic(void)
{
// Master-PIC initialisieren
    outb(0x20, 0x11); // Initialisierungsbefehl fuer den PIC
    outb(0x21, 0x20); // Interruptnummer fuer IRQ 0
    outb(0x21, 0x04); // An IRQ 2 haengt der Slave
    outb(0x21, 0x01); // ICW 4

// Slave-PIC initialisieren
    outb(0xa0, 0x11); // Initialisierungsbefehl fuer den PIC
    outb(0xa1, 0x28); // Interruptnummer fuer IRQ 8
    outb(0xa1, 0x02); // An IRQ 2 haengt der Slave
    outb(0xa1, 0x01); // ICW 4

// Alle IRQs aktivieren (demaskieren)
    outb(0x20, 0x0);
    outb(0xa0, 0x0);
}
static void idt_set_entry(int i, void (*fn)(), unsigned int selector, int flags)
{
    unsigned long int handler = (unsigned long int) fn;
    idt[i] = handler & 0xffffLL;
    idt[i] |= (selector & 0xffffLL) << 16;
    idt[i] |= (flags & 0xffLL) << 40;
    idt[i] |= ((handler>> 16) & 0xffffLL) << 48;
}

void load_idt(void);



void load_idt(void)
{

    struct
    {
        uint16_t limit;
        void* pointer;
    } __attribute__((packed)) idtp =
    {
        .limit = IDT_ENTRIES * 8 - 1,
        .pointer = idt,
    };

// Interruptnummern der IRQs umbiegen
    init_pic();


// Excpetion-Handler
    idt_set_entry(0, FehlerMeldungasm0, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(1, FehlerMeldungasm1, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(2, FehlerMeldungasm2, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(3, FehlerMeldungasm3, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(4, FehlerMeldungasm4, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(5, FehlerMeldungasm5, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(6, FehlerMeldungasm6, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(7, FehlerMeldungasm7, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(8, FehlerMeldungasm8, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(9, FehlerMeldungasm9, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(10, FehlerMeldungasm10, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(11, FehlerMeldungasm11, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(12, FehlerMeldungasm12, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(13, FehlerMeldungasm13, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(14, FehlerMeldungasm14, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(15, FehlerMeldungasm15, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(16, FehlerMeldungasm16, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(17, FehlerMeldungasm17, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(18, FehlerMeldungasm18, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(19, FehlerMeldungasm19, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
// IRQ-Handler
    idt_set_entry(32, HardwareMeldungasm0, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(33, HardwareMeldungasm1, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(34, HardwareMeldungasm2, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(35, HardwareMeldungasm3, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(36, HardwareMeldungasm4, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(37, HardwareMeldungasm5, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(38, HardwareMeldungasm6, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(39, HardwareMeldungasm7, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(40, HardwareMeldungasm8, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(41, HardwareMeldungasm9, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(42, HardwareMeldungasm10, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(43, HardwareMeldungasm11, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(44, HardwareMeldungasm12, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(45, HardwareMeldungasm13, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(46, HardwareMeldungasm14, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
    idt_set_entry(47, HardwareMeldungasm15, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING0 | IDT_FLAG_PRESENT);
// Syscall
    idt_set_entry(48, SoftwareMeldungasm0, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING3 | IDT_FLAG_PRESENT);
    idt_set_entry(49, SoftwareMeldungasm1, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING3 | IDT_FLAG_PRESENT);
    idt_set_entry(50, SoftwareMeldungasm2, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING3 | IDT_FLAG_PRESENT);
    idt_set_entry(51, SoftwareMeldungasm3, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING3 | IDT_FLAG_PRESENT);
    idt_set_entry(52, SoftwareMeldungasm4, 0x8, IDT_FLAG_INTERRUPT_GATE | IDT_FLAG_RING3 | IDT_FLAG_PRESENT); //////////////Bei Neuen Interrupts die Interrupt.S nicht vergessen zu erweitern !
    asm volatile("lidt %0" : : "m" (idtp));

    asm volatile("sti");
}
