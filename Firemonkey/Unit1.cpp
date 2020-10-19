//---------------------------------------------------------------------------

#include <fmx.h>


#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->FullScreen=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	GetCursorPos( &p );
	Label1->Position->X=p.x+15;
	Label1->Position->Y=p.y+5;
	Panel1->Position->X=p.x+10;
	Panel1->Position->Y=p.y+10;
	String tmp;
	tmp += "X: ";
	tmp += FloatToStr(p.x);
	tmp += " Y: ";
	tmp += FloatToStr(p.y);
	Label1->Text=tmp;

	Timer1->Interval=10;
}
//---------------------------------------------------------------------------

