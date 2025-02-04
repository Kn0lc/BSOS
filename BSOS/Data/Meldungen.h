#ifndef Meldungenh
#define Meldungenh


struct eflags_state {
		const unsigned int reserviert:9;
		 unsigned int ID:1;
		 unsigned int VIP:1;
		 unsigned int VIF:1;
		 unsigned int AC:1;
		 unsigned int VM:1;
		 unsigned int RF:1;
		const unsigned int rserveirt2:1;
		 unsigned int NT:1;
		 unsigned int IOPL:2;
		 unsigned int OF:1;
		 unsigned int DF:1;
		 unsigned int IF:1;
		 unsigned int TF:1;
		 unsigned int SF:1;
		 unsigned int ZF:1;
		 unsigned int reserviert3:1;
		 unsigned int AF:1;
		 unsigned int rserveirt4:1;
		 unsigned int PF:1;
		 unsigned int reserviert5:1;
		 unsigned int CF:1;
};
/*
struct eflags_state {
		 unsigned int CF:1;
		 unsigned int reserviert5:1;
		 unsigned int PF:1;
		 unsigned int rserveirt4:1;
		 unsigned int AF:1;
		 unsigned int reserviert3:1;
		 unsigned int ZF:1;
		 unsigned int SF:1;
		 unsigned int TF:1;
		 unsigned int IF:1;
		 unsigned int DF:1;
		 unsigned int OF:1;
         unsigned int IOPL:2;
         unsigned int NT:1;
         const unsigned int rserveirt2:1;
         unsigned int RF:1;
         unsigned int VM:1;
         unsigned int AC:1;
         unsigned int VIF:1;
         unsigned int VIP:1;
         unsigned int ID:1;
         const unsigned int reserviert:9;
};
*/

struct cpu_state {
    // Von Hand gesicherte Register
    uint32_t   eax;
    uint32_t   ebx;
    uint32_t   ecx;
    uint32_t   edx;
    uint32_t   esi;
    uint32_t   edi;
    uint32_t   ebp;

    uint32_t   intr;
    uint32_t   error;

    // Von der CPU gesichert
    uint32_t   eip;
    uint32_t   cs;
    uint32_t eflags;
    uint32_t   esp;
    uint32_t   ss;
};


void FehlerMeldung0();
void FehlerMeldung1();
void FehlerMeldung2();
void FehlerMeldung3();
void FehlerMeldung4();
void FehlerMeldung5();
void FehlerMeldung6();
void FehlerMeldung7();
void FehlerMeldung8();
void FehlerMeldung9();
void FehlerMeldung10();
void FehlerMeldung11();
void FehlerMeldung12();
void FehlerMeldung13();
void FehlerMeldung14();
void FehlerMeldung15();
void FehlerMeldung16();
void FehlerMeldung17();
void FehlerMeldung18();
void FehlerMeldung19();

void HardwareMeldung0();
void HardwareMeldung1();
void HardwareMeldung2();
void HardwareMeldung3();
void HardwareMeldung4();
void HardwareMeldung5();
void HardwareMeldung6();
void HardwareMeldung7();
void HardwareMeldung8();
void HardwareMeldung9();
void HardwareMeldung10();
void HardwareMeldung11();
void HardwareMeldung12();
void HardwareMeldung13();
void HardwareMeldung14();
void HardwareMeldung15();

struct cpu_state*  SoftwareMeldung0(struct cpu_state* cpu);
struct cpu_state* SoftwareMeldung1(struct cpu_state* cpu);
void SoftwareMeldung2();
void SoftwareMeldung3();
void SoftwareMeldung4();


void handle_interrupt(struct cpu_state* cpu);
void handle_hardware_interrupt(struct cpu_state* cpu);
struct cpu_state* handle_software_interrupt(struct cpu_state* cpu);



#endif
