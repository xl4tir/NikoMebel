//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	Image2->SendToBack();

}

class Reg{
	public:
		AnsiString login, pass, mail, tel;

		Reg(AnsiString l,AnsiString p,AnsiString m,AnsiString t){
			login = l;
			pass = p;
			mail = m;
			tel = t;
		}

		bool RegCheck(){
			if(login=="" || pass=="" || mail == "" || tel == "" ){
				ShowMessage("Одне із полів не є заповненим. Спробуйте ще раз!");
				return false;
			}else{
				return true;
			}
		}

};
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	 Reg R(Edit1->Text, Edit2->Text, Edit3->Text, Edit4->Text);

	 if(R.RegCheck()){
		 ADOQuery1->Parameters->ParamByName("RegLog")->Value = Edit1->Text;
		 ADOQuery1->Parameters->ParamByName("RegPass")->Value = Edit2->Text;
		 ADOQuery1->Parameters->ParamByName("RegMail")->Value = Edit3->Text;
		 ADOQuery1->Parameters->ParamByName("RegTel")->Value = Edit4->Text;
		 ADOQuery1->ExecSQL();
		 Label1->Caption = "Ваш аккаунт успішно зареєстровано!";
		 Label1->Font->Color= clRed;
		 Label1->Alignment = taCenter;

		 Timer1->Interval = 2000;
         Timer1->Enabled = true;
	 }else{
		Edit1->Text = "";
		Edit2->Text = "";
		Edit3->Text = "";
		Edit4->Text = "";
	 }




}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Form1->Show();
	Form2->Hide();
	Edit1->Text = "";
	Edit2->Text = "";
	Edit3->Text = "";
	Edit4->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	Form1->Show();
	Form2->Hide();
    Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

