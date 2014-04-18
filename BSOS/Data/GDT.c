#define GDT_FLAG_DATASEGM 0x02
#define GDT_FLAG_CODESEGM 0x0a
#define GDT_FLAG_TSS 0x09

#define GDT_FLAG_SEGMENT 0x10
#define GDT_FLAG_RING0 0x00
#define GDT_FLAG_RING3 0x60
#define GDT_FLAG_PRESENT 0x80

#define GDT_FLAG_4K_GRAN 0x800
#define GDT_FLAG_32_BIT 0x400

#define GDT_ENTRIES 5

#include "stdint.h"
#include "GDT.h"

static uint64_t gdt[GDT_ENTRIES];


void load_gdt()
{
    struct
    {
        uint16_t limit;
        void * pointer;
    } __attribute__((packed)) gdtp =
    {
        .limit = GDT_ENTRIES * 8 - 1,
        .pointer = gdt,
    };
    asm volatile("lgdt %0" : : "m" (gdtp));

    asm volatile("mov $0x10, %ax;");
    asm volatile("mov %ax, %ds;");
    asm volatile("mov %ax, %es;");
    asm volatile("mov %ax, %fs");
    asm volatile("mov %ax, %gs");
    asm volatile("mov %ax, %ss;");
    asm volatile("ljmp $0x8, $.1;");
    asm volatile(".1:");
}

static void set_entry(int i, unsigned int base, unsigned int limit, int flags)
{
    gdt[i] = limit & 0xffffLL;
    gdt[i] |= (base & 0xffffffLL) << 16;
    gdt[i] |= (flags & 0xffLL) << 40;
    gdt[i] |= ((limit >> 16) & 0xfLL) << 48;
    gdt[i] |= ((flags >> 8 )& 0xffLL) << 52;
    gdt[i] |= ((base >> 24) & 0xffLL) << 56;
}

void init_gdt()
{
    set_entry(0, 0, 0, 0);
    set_entry(1, 0, 0xfffff, GDT_FLAG_SEGMENT | GDT_FLAG_32_BIT | GDT_FLAG_CODESEGM | GDT_FLAG_4K_GRAN | GDT_FLAG_PRESENT);
    set_entry(2, 0, 0xfffff, GDT_FLAG_SEGMENT | GDT_FLAG_32_BIT | GDT_FLAG_DATASEGM | GDT_FLAG_4K_GRAN | GDT_FLAG_PRESENT);
    set_entry(3, 0, 0xfffff, GDT_FLAG_SEGMENT | GDT_FLAG_32_BIT | GDT_FLAG_CODESEGM | GDT_FLAG_4K_GRAN | GDT_FLAG_PRESENT | GDT_FLAG_RING3);
    set_entry(4, 0, 0xfffff, GDT_FLAG_SEGMENT | GDT_FLAG_32_BIT | GDT_FLAG_DATASEGM | GDT_FLAG_4K_GRAN | GDT_FLAG_PRESENT | GDT_FLAG_RING3);

    load_gdt();
}

