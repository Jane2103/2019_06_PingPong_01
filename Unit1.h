//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *leftPaddle;
        TImage *rightPaddle;
        TTimer *leftUp;
        TTimer *leftDown;
        TTimer *rightUp;
        TTimer *rightDown;
        TImage *ball;
        TTimer *ballMovement;
        void __fastcall leftUpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall leftDownTimer(TObject *Sender);
        void __fastcall rightUpTimer(TObject *Sender);
        void __fastcall rightDownTimer(TObject *Sender);
        void __fastcall ballMovementTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
