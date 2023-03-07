//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit8.h"
#include "Unit9.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
AnsiString MainLogin, MebelName;

__fastcall TForm5::TForm5(TComponent* Owner, AnsiString NameMebel, AnsiString Login)
	: TForm(Owner)
{
	Label5->Caption = Login;
	MainLogin = Login;
	MebelName = NameMebel;

	ADOQuery1->Parameters->ParamByName("NameMebl")->Value = NameMebel;
	ADOQuery1->Active=true;
	ADOQuery1->First();

	AnsiString Title = ADOQuery1->FieldValues["Categories"];
	Title = Title + " - ";
	Title = Title + ADOQuery1->FieldValues["Name"];
	Label1->Caption = Title;

	Form5->Caption = "Niko Mebel - "+Title;

	AnsiString Desc = ADOQuery1->FieldValues["Desc"];
	Label2->Caption = Desc;

	AnsiString Img = ADOQuery1->FieldValues["Img"];
	Image3->Picture->LoadFromFile(Img);

	AnsiString Size = "Розмір (мм): ";
    Size = Size+ADOQuery1->FieldValues["Size"];
	Label4->Caption = Size;

	AnsiString Price = ADOQuery1->FieldValues["Price"];
	Price = Price + " UAH";
    Label3->Caption = Price;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::N1Click(TObject *Sender)
{
	Form3->Show();
	Form5->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::adClick(TObject *Sender)
{
	ADOQuery2->Parameters->ParamByName("Login")->Value = MainLogin;
	ADOQuery2->Parameters->ParamByName("MeblName")->Value = MebelName;
	ADOQuery2->ExecSQL();
	ShowMessage("\"" + MebelName + "\"" + " добавлено до вашого кошика!");
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image5Click(TObject *Sender)
{

	ADOQuery3->Parameters->ParamByName("MeblName")->Value = MebelName;
	ADOQuery3->Parameters->ParamByName("Login")->Value = MainLogin;
	ADOQuery3->ExecSQL();
	ShowMessage("\"" + MebelName + "\"" + " добавлено до вашого списку бажань!");
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm5::N3Click(TObject *Sender)
{
	   Form6= new TForm6(this, MainLogin);
	   Form6->Show();
	   Form5->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N7Click(TObject *Sender)
{
 	 Form9= new TForm9(this, MainLogin);
	 Form9->Show();
	 Form5->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N8Click(TObject *Sender)
{
	 Form8= new TForm8(this, MainLogin);
	 Form8->Show();
	 Form5->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N5Click(TObject *Sender)
{
	Form1= new TForm1(this);
	Form1->Show();
	Form5->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Niko1Click(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

