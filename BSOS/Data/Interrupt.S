
.extern debugtext
.macro intr_stub nr
.global FehlerMeldungasm\nr
FehlerMeldungasm\nr:
    pushl $0
    pushl $\nr
    jmp common_itr_handler
.endm

.macro intr_stub_error_code nr
.global FehlerMeldungasm\nr
FehlerMeldungasm\nr:
    pushl $\nr
    jmp common_itr_handler
.endm

.macro hardware nr
.global HardwareMeldungasm\nr
HardwareMeldungasm\nr:
    pushl $0
    pushl $\nr
    jmp hardware_intr_handler
.endm

.macro sys nr
.global SoftwareMeldungasm\nr
SoftwareMeldungasm\nr:
    pushl $0
    pushl $\nr
    jmp sys_intr_handler
.endm

// Exceptions
intr_stub 0
intr_stub 1
intr_stub 2
intr_stub 3
intr_stub 4
intr_stub 5
intr_stub 6
intr_stub 7
intr_stub_error_code 8
intr_stub 9
intr_stub_error_code 10
intr_stub_error_code 11
intr_stub_error_code 12
intr_stub_error_code 13
intr_stub_error_code 14
intr_stub 15
intr_stub 16
intr_stub_error_code 17
intr_stub 18
intr_stub 19

// IRQs
hardware 0
hardware 1
hardware 2
hardware 3
hardware 4
hardware 5
hardware 6
hardware 7
hardware 8
hardware 9
hardware 10
hardware 11
hardware 12
hardware 13
hardware 14
hardware 15

// Syscall
sys 0

.extern handle_hardware_interrupt
hardware_intr_handler:
    // CPU-Zustand sichern
    push %ebp
    push %edi
    push %esi
    push %edx
    push %ecx
    push %ebx
    push %eax

    // Handler aufrufen
    push %esp
    call handle_hardware_interrupt
    add $4, %esp

    // CPU-Zustand wiederherstellen
    pop %eax
    pop %ebx
    pop %ecx
    pop %edx
    pop %esi
    pop %edi
    pop %ebp

    // Fehlercode und Interruptnummer vom Stack nehmen
    add $8, %esp

    iret

.extern handle_interrupt
common_itr_handler:
    // CPU-Zustand sichern
    push %ebp
    push %edi
    push %esi
    push %edx
    push %ecx
    push %ebx
    push %eax
    // Handler aufrufen

    pushl %esp
    call handle_interrupt
    add $4, %esp


    // CPU-Zustand wiederherstellen
    pop %eax
    pop %ebx
    pop %ecx
    pop %edx
    pop %esi
    pop %edi
    pop %ebp

    // Fehlercode und Interruptnummer vom Stack nehmen
    add $8, %esp

    iret

.extern handle_software_interrupt
sys_intr_handler:
    // CPU-Zustand sichern
    push %ebp
    push %edi
    push %esi
    push %edx
    push %ecx
    push %ebx
    push %eax

    // Handler aufrufen
    push %esp
    call handle_software_interrupt
   // add $4, %esp
    mov %eax, %esp
    // CPU-Zustand wiederherstellen
    pop %eax
    pop %ebx
    pop %ecx
    pop %edx
    pop %esi
    pop %edi
    pop %ebp

    // Fehlercode und Interruptnummer vom Stack nehmen
    add $8, %esp

    iret
