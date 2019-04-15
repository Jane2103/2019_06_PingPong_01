//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftUpTimer(TObject *Sender)
{
        if (leftPaddle -> Top >= 10) leftPaddle -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x41) leftUp -> Enabled = true;  //A
        if (Key == 0x5A) leftDown -> Enabled = true;  //Z
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x41) leftUp -> Enabled = false;
        if (Key == 0x5A) leftDown -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftDownTimer(TObject *Sender)
{
        if (leftPaddle -> Top + leftPaddle -> Height <= 452) leftPaddle -> Top += 10;
        //if (leftPaddle -> Top + leftPaddle -> Height <= background -> Height) leftPaddle -> Top += 10;
}
//---------------------------------------------------------------------------

