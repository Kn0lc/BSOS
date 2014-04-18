.macro settrapflag
pushf
mov bp,sp
or word PTR[BP+0],0100H
popf
.endm

.macro unsettrapflag
pushf
mov bp,sp
AND WORD PTR[BP+0],0FEFFH
popf
.endm

.section multiboot
#define MB_MAGIC 0x1badb002
#define MB_FLAGS 0x0
#define MB_CHECKSUM -(MB_MAGIC + MB_FLAGS)

// Der Multiboot-Header
.align 4
.int    MB_MAGIC
.int    MB_FLAGS
.int    MB_CHECKSUM

.section .text

// Init ist eine Funktion aus init.c
.extern init

// _start muss global sein, damit der Linker es findet und als Einsprungspunkt
// benutzen kann (alle Labels, die nicht global sind, sind nur in dieser Datei
// sichtbar)
.global _start
_start:
// Stack initialisieren
mov $kernel_stack, %esp

// C-Code aufrufen
call init

// Falls wir jemals aus init zurueckkommen sollten, sperren wir die Interrupts und
// halten einfach den Prozessor an. (man braucht ihn ja nicht unnötig heißlaufen lassen.)
_stop:
cli
hlt

// Sollte es doch weitergehen, probieren wir erneut die CPU schlafen zu lassen
jmp _stop

// 8 kB Stack fuer den Kernel. Das Label steht hinter dem freien Speicher,
// weil der Stack nach unten waechst
.section .bss
.space 8192
.global settrapflag
.global RegisterSichern1
.extern RegisterSichern1
 // Das rax-Register wird benoetigt, um ds und es Pushen zu koennen
      pushl %eax

      // Segmentregister auf den Stack pushen
      push %gs
      push %fs

      xorl %eax, %eax
      movw %es, %ax
      pushl %eax

      movw %ds, %ax
      pushl %eax

      // Allzweckregister auf den Stack
      pushl %ebp
      pushl %edi
     pushl %esi
      pushl %edx
      pushl %ecx
      pushl %ebx

      // Der Task-Zustand ist hier fertig gespeichert.

      // Ring 0 Segment-Register laden
      cld
      mov $0x10, %ax
      mov %ax, %ds
      mov %ax, %es


      // Der aktuelle Stackpointer wird dem C-Interrupt-Handler als Parameter
      // uebergeben. Wir haben gerade den Zustand des Gasts im Format des C-Typs
      // interrupt_stack_frame_t auf den Stack gepusht, so dass der C-Handler
      // bequem auf die einzelnen Register des Tasks zugreifen kann.
      pushl %esp

kernel_stack:
