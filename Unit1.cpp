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
#define INIT_BALL_LEFT 468
#define INIT_BALL_TOP 208
#define BALL_CENTER ball->Top+(ball->Height)/2


TForm1 *Form1;

int x = -10;
int y = -10;

int leftPlayerPoints = 0;
int rightPlayerPoints = 0;
int numberOfBounces = 0;
float accelerationFactor = 1.0;

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
        if (Key == A) leftUp -> Enabled = true;
        if (Key == Z) leftDown -> Enabled = true;
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

        //Top & bottom margins
        if (ball -> Top - MARGIN <= background -> Top) y = -y;
        if (ball -> Top + ball -> Height + MARGIN >= background -> Height) y = -y;

        //bouncing the ball with the left paddle - easy version
        /*if ((ball -> Left <= leftPaddle -> Left + leftPaddle -> Width) &&
            (ball -> Top + (ball -> Height) / 2 >= leftPaddle -> Top) &&
            (ball -> Top + (ball -> Height) / 2 <= leftPaddle -> Top + leftPaddle -> Height)) {
                x = -x;
                numberOfBounces++;
                //y = -y;
        }*/

        //bouncing the ball with the left paddle - difficult version
        if (ball -> Left <= leftPaddle -> Left + leftPaddle -> Width) {
                if (BALL_CENTER > 1.2 * leftPaddle -> Top && BALL_CENTER < 1.8 * leftPaddle -> Top) {
                        x = -x;
                        numberOfBounces++;
                } else if ((BALL_CENTER > leftPaddle -> Top && BALL_CENTER < 1.2 * leftPaddle -> Top) ||
                           (BALL_CENTER > 1.8 * leftPaddle -> Top && BALL_CENTER <= leftPaddle -> Top + leftPaddle -> Height)) {
                        x = (float) -accelerationFactor * x;
                        numberOfBounces++;
                }
        }

        //bouncing the ball with the right paddle - easy version
        /*if ((ball -> Left + ball -> Width >= rightPaddle -> Left) &&
            (ball -> Top + (ball -> Height) / 2 >= rightPaddle -> Top) &&
            (ball -> Top + (ball -> Height) / 2 <= rightPaddle -> Top + rightPaddle -> Height)) {
                x = -x;
                numberOfBounces++;
        }*/

        //bouncing the ball with the right paddle - difficult version
        if (ball -> Left + ball -> Width >= rightPaddle -> Left) {
                if (BALL_CENTER > 1.2 * rightPaddle -> Top && BALL_CENTER < 1.8 * rightPaddle -> Top) {
                        x = -x;
                        numberOfBounces++;
                } else if ((BALL_CENTER > rightPaddle -> Top && BALL_CENTER < 1.2 * rightPaddle -> Top) ||
                           (BALL_CENTER > 1.8 * rightPaddle -> Top && BALL_CENTER <= rightPaddle -> Top + rightPaddle -> Height)) {
                        x = (float) -accelerationFactor * x;
                        numberOfBounces++;
                }
        }

        //left out
        if (ball -> Left + ball -> Width + MARGIN < leftPaddle -> Left) {
                ballMovement -> Enabled = false;
                rightPlayerPoints++;
                score -> Caption = IntToStr(leftPlayerPoints) + ":" + IntToStr(rightPlayerPoints);
                score -> Visible = true;
                continueGame -> Visible = true;
                outNotification -> Caption = "Out! Punkt dla gracza prawego >";
                outNotification -> Visible = true;
                newGame -> Caption = "Graj od nowa";
                newGame -> Visible = true;
                bounces -> Caption = "Liczba odbiæ: " + IntToStr(numberOfBounces);
                bounces -> Visible = true;
        }

        //right out
        if (ball -> Left > rightPaddle -> Left + rightPaddle -> Width + MARGIN) {
                ballMovement -> Enabled = false;
                leftPlayerPoints++;
                score -> Caption = IntToStr(leftPlayerPoints) + ":" + IntToStr(rightPlayerPoints);
                score -> Visible = true;
                continueGame -> Visible = true;
                outNotification -> Caption = "< Out! Punkt dla gracza lewego";
                outNotification -> Visible = true;
                newGame -> Caption = "Graj od nowa";
                newGame -> Visible = true;
                bounces -> Caption = "Liczba odbiæ: " + IntToStr(numberOfBounces);
                bounces -> Visible = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameClick(TObject *Sender)
{
        ball -> Left = INIT_BALL_LEFT;
        ball -> Top = INIT_BALL_TOP;
        x = -10;
        y = -10;
        leftPlayerPoints = 0;
        rightPlayerPoints = 0;
        numberOfBounces = 0;
        ballMovement -> Enabled = true;
        outNotification -> Visible = false;
        newGame -> Visible = false;
        score -> Visible = false;
        continueGame -> Visible = false;
        bounces -> Visible = false;
        scroll -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::continueGameClick(TObject *Sender)
{
        ball -> Left = INIT_BALL_LEFT;
        ball -> Top = INIT_BALL_TOP;
        x = -10;
        y = -10;
        numberOfBounces = 0;
        ballMovement -> Enabled = true;
        outNotification -> Visible = false;
        newGame -> Visible = false;
        score -> Visible = false;
        continueGame -> Visible = false;
        bounces -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::scrollScroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
        accelerationFactor = ScrollPos;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::startButtonClick(TObject *Sender)
{
        ball -> Left = INIT_BALL_LEFT;
        ball -> Top = INIT_BALL_TOP;
        x = -10;
        y = -10;
        leftPlayerPoints = 0;
        rightPlayerPoints = 0;
        numberOfBounces = 0;
        ballMovement -> Enabled = true;
        outNotification -> Visible = false;
        newGame -> Visible = false;
        score -> Visible = false;
        continueGame -> Visible = false;
        bounces -> Visible = false;
        scroll -> Visible = false;
        startButton -> Visible = false;
}
//---------------------------------------------------------------------------

