//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define MARGIN 10
#define A 0x41
#define Z 0x5A


TForm1 *Form1;

int x = -10;
int y = -10;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftUpTimer(TObject *Sender)
{
        if (leftPaddle -> Top >= MARGIN) leftPaddle -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        //if (Key == 0x41) leftUp -> Enabled = true;  //A
        //if (Key == 0x5A) leftDown -> Enabled = true;  //Z
        if (Key == A) leftUp -> Enabled = true;  //A
        if (Key == Z) leftDown -> Enabled = true;  //Z
        if (Key == VK_UP) rightUp -> Enabled = true;
        if (Key == VK_DOWN) rightDown -> Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == A) leftUp -> Enabled = false;
        if (Key == Z) leftDown -> Enabled = false;
        if (Key == VK_UP) rightUp -> Enabled = false;
        if (Key == VK_DOWN) rightDown -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftDownTimer(TObject *Sender)
{
        if (leftPaddle -> Top + leftPaddle -> Height <= background -> Height - MARGIN) leftPaddle -> Top += 10;
        //if (leftPaddle -> Top + leftPaddle -> Height <= background -> Height) leftPaddle -> Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightUpTimer(TObject *Sender)
{
        if (rightPaddle -> Top >= MARGIN) rightPaddle -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightDownTimer(TObject *Sender)
{
        if (rightPaddle -> Top + rightPaddle -> Height <= background -> Height - MARGIN) rightPaddle -> Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ballMovementTimer(TObject *Sender)
{
        ball -> Left += x;
        ball -> Top += y;

        //To be changed in the future
        if (ball -> Left - MARGIN <= background -> Left) x = -x;
        if (ball -> Top - MARGIN <= background -> Top) y = -y;
        if (ball -> Left + ball -> Width + MARGIN >= background -> Width) x = -x;
        if (ball -> Top + ball -> Height + MARGIN >= background -> Height) y = -y;

        /*if ((ball -> Left <= leftPaddle -> Left + leftPaddle -> Width) &&
           (ball -> Top + (ball -> Height) / 2 >= leftPaddle -> Top) &&
           (ball -> Top - (ball -> Height) / 2 <= leftPaddle -> Top + leftPaddle -> Height))
           {
                if (x > 0) x = -x;
           } */

        //bouncing the ball with the left paddle
        if ((ball -> Left <= leftPaddle -> Left + leftPaddle -> Width) &&
            (ball -> Top + (ball -> Height) / 2 >= leftPaddle -> Top) &&
            (ball -> Top + (ball -> Height) / 2 <= leftPaddle -> Top + leftPaddle -> Height)) {
                x = -x;
                //y = -y;
        }

        //bouncing the ball with the right paddle
        if ((ball -> Left + ball -> Width >= rightPaddle -> Left) &&
            (ball -> Top + (ball -> Height) / 2 >= rightPaddle -> Top) &&
            (ball -> Top + (ball -> Height) / 2 <= rightPaddle -> Top + rightPaddle -> Height)) {
                x = -x;
        }

        //left out
        if (ball -> Left + ball -> Width + MARGIN < leftPaddle -> Left) {
                ballMovement -> Enabled = false;
                //ball -> Visible = false;
        }

        //right out
        if (ball -> Left > rightPaddle -> Left + rightPaddle -> Width + MARGIN) {
                ballMovement -> Enabled = false;
                //ball -> Visible = false;
        }


}
//---------------------------------------------------------------------------

