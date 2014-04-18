#ifndef TextModeh
#define TextModeh


void removecursor(void);
void TextNachObenVerschieben(void);
void BildschirmFaerben(void);
void BildschirmLeeren(void);
void SchreibeInVideoSpeicher(const char Text[], int Farbe);
void SchreibeText(const char Text[]);

void SchreibeINT(const int Text);
int ZeichenAnzahl(const char Text[]);
void SchreibeFormatiertenText(const char Text[], int Farbe, char Position);


#endif
