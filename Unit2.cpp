//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        AnsiString introduction = "Witaj w grze PingPong";
        AnsiString space = "\n\n";
        AnsiString rulesDescriptionForLeftPlayer = "Lewy gracz steruje wciskajac klawisze A oraz Z. ";
        AnsiString rulesDescriptionForRightPlayer = "Prawy gracz steruje wciskajac strza³ki w górê lub dó³.";
        //AnsiString space = "\n";
        AnsiString aboutGame = "Gra powsta³a w ramach projektu Przysz³y Programista.";
        //AnsiString space = "\n";
        AnsiString contactWithAuthor = "Jeœli masz sugestie co do poprawy dzia³ania gry napisz maila: jan.lakomy.programista@gmail.com";
        //AnsiString space = "\n";
        AnsiString goodbye = "Mi³ej zabawy!";

        ShowMessage(introduction + space + rulesDescriptionForLeftPlayer + rulesDescriptionForRightPlayer +
                    space + aboutGame + space + contactWithAuthor + space + goodbye);
}
//---------------------------------------------------------------------------

