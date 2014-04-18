#include "IDT.h"
#include "TextMode.h"

static char* video = (char*) 0xb8000;


void removecursor()
{
    outb(0x3D4,14);
    outb(0x3D5,0x07);
    outb(0x3D4,15);
    outb(0x3D5,0xD0);
}

void TextInDenVideoSpeicher(const char Text[], int Zeichen, int Farbe, int  LeerzeichenDavor)
{
    int t=0, i;
    if(Zeichen>80) // länger als eine Zeile?
    {
        //Ja ! Also nach Oben schieben (scrollen)
        int Z = Zeichen;
        while(Z>80)
        {
            TextNachObenVerschieben();
            Z -= 80;
        }
    }
    //Nein ! Also Text Scheiben!
    i = LeerzeichenDavor;//Formatierung für Zentriert, etc. durch Leezreichen

    for (i = i; Text[t] != '\0'; i++, t++) // C-Strings haben ein Nullbyte als Abschluss
    {

        // Zeichen i in den Videospeicher kopieren
        video[i * 2] = Text[t];

        // 0x07 = Schwarz auf Hellgrau
        video[i * 2 + 1] = Farbe;
    }
}

void TextNachObenVerschieben()
{
    int i, j;
    for (i = 0, j = 80; i <= 1999; i++, j++)
    {

        // Zeichen i in den Videospeicher kopieren
        video[i * 2] = video[j* 2];
        video[j * 2 + 1] = 0x70;

    }
}

void BildschirmFaerben()
{
    int i;
    // C-Strings haben ein Nullbyte als Abschluss
    for (i = 0; i <= 1999; i++)
    {
        // Hell Grau  auf Hell Grau (entfernt Courser;D)
        video[i * 2 + 1] = 119;
    }
}

void BildschirmLeeren()
{
    removecursor();
    //2000 Leerzeichen
    const char hw[] = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ";
    int i;

    // C-Strings haben ein Nullbyte als Abschluss
    for (i = 0; hw[i] != '\0'; i++)
    {

        // Zeichen i in den Videospeicher kopieren
        video[i * 2] = hw[i];

        video[i * 2 + 1] = 0x70;
    }
}

void SchreibeInVideoSpeicher(const char Text[], int Farbe)
{
    int i;
// C-Strings haben ein Nullbyte als Abschluss
    for (i = 0; Text[i] != '\0'; i++)
    {

        // Zeichen i in den Videospeicher kopieren
        video[i * 2] = Text[i];

        // 0x07 = Schwarz auf Hellgrau
        video[i * 2 + 1] = Farbe;
    }
}

void SchreibeText(const char Text[])
{
    int Farbe = 0x70;
    SchreibeFormatiertenText(Text,Farbe,'l');
}

void SchreibeINT(const int Text1)
{
    const char Text[] = "Test";
    int Farbe = 0x70;
    SchreibeFormatiertenText(Text,Farbe,'l');
}

int ZeichenAnzahl(const char Text[])
{
    int i=0;
    for (i = 0; Text[i] != '\0'; i++)
    {
    }
    return i;
}

void SchreibeFormatiertenText(const char Text[], int Farbe, char Position)
{
    TextNachObenVerschieben();
    int Zeichen = ZeichenAnzahl(Text);
    if(Position == 'l')
    {
        TextInDenVideoSpeicher(Text, Zeichen, Farbe, 10*80); // 10*80 entspricht ca 5 Zeilen von Oben (für besseres Lesen und Scrolling)
    }

    if(Position == 'm')
    {
        int LeerzeichenDavor = (40-(Zeichen/2))+10*80;
        TextInDenVideoSpeicher(Text, Zeichen, Farbe, LeerzeichenDavor);
    }

    if(Position == 'r')
    {
        int LeerzeichenDavor = (80-Zeichen)+10*80;
        TextInDenVideoSpeicher(Text, Zeichen, Farbe, LeerzeichenDavor);
    }
}
