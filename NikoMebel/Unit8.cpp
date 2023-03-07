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
TForm8 *Form8;

AnsiString MainLogin;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner, AnsiString Login)
	: TForm(Owner)
{

	MainLogin = Login;
	Label5->Caption = MainLogin;

	ADOQuery1->Parameters->ParamByName("Login")->Value = MainLogin;
	ADOQuery1->Active=true;
	ADOQuery1->First();
	ADOQuery2->Active=true;



	int k=0,q=1,to_right=0,to_bottom =0, count_top=1;;
	if(!ADOQuery1->Eof){
		ADOQuery1->First();

		do{
            ADOQuery2->First();
			if(!ADOQuery2->Eof){


				do{
					if(ADOQuery1->FieldValues["_namemebl_"] == ADOQuery2->FieldValues["Name"]){
						AnsiString FullMeblName = ADOQuery1->FieldValues["_namemebl_"];

						TLabel *DivanName = new TLabel(this);
						DivanName->Parent = this->Panel1;
						DivanName->Caption = FullMeblName;
						DivanName->Left = 24 + to_right;
						DivanName->Top = 127 + to_bottom;
						DivanName->Name = "FullMeblNameLabel" + IntToStr(q);
						//DivanName->OnClick = FullClick;
						DivanName->Cursor = crHandPoint;
						DivanName->Font->Style = TFontStyles()<< fsBold ;
						DivanName->Font->Size = 10;
						DivanName->Alignment = taCenter;
						DivanName->AutoSize =false;
						DivanName->Width = 137;


						TImage *DivanImage = new TImage(this);
						DivanImage->Parent = this->Panel1;
						DivanImage->Left = 43 + to_right;
						DivanImage->Top = 16 + to_bottom;
						DivanImage->Width = 105;
						DivanImage->Height = 105;
						DivanImage->Stretch = true;
						DivanImage->Name = "DivanImage" + IntToStr(q);
						DivanImage->Hint = ADOQuery1->FieldValues["_namemebl_"];
						DivanImage->Picture->LoadFromFile(ADOQuery2->FieldValues["Img"]);
						DivanImage->Cursor = crHandPoint;

						AnsiString MeblPrice = ADOQuery2->FieldValues["Price"];
                        MeblPrice = MeblPrice + " UAH";

						TLabel *DivanPrice = new TLabel(this);
						DivanPrice->Parent = this->Panel1;
						DivanPrice->Caption = MeblPrice;
						DivanPrice->Left = 34 + to_right;
						DivanPrice->Top = 151 + to_bottom;
						DivanPrice->Name = "DivanPrice" + IntToStr(q);
						//DivanName->OnClick = FullClick;
						DivanPrice->Cursor = crHandPoint;
						DivanPrice->Font->Style = TFontStyles()<< fsBold ;
						DivanPrice->Font->Size = 10 ;
						DivanPrice->Alignment = taLeftJustify;

						

                        TLabel *Divandel = new TLabel(this);
						Divandel->Parent = this->Panel1;
						Divandel->Caption = "X";
						Divandel->Left = 140 + to_right;
						Divandel->Top = 151 + to_bottom;
						Divandel->Name = "Divandel" + IntToStr(q);
						//DivanName->OnClick = FullClick;
						Divandel->Hint =  ADOQuery1->FieldValues["_namemebl_"];
						Divandel->Cursor = crHandPoint;
						Divandel->Font->Style = TFontStyles()<< fsBold ;
						Divandel->Font->Size = 12;
						Divandel->Font->Color = clRed;
						Divandel->Cursor = crHandPoint;
						Divandel->OnClick = DeleteLabelClick;


					}
                    ADOQuery2->Next();
				}while(!ADOQuery2->Eof);




			}







            q++;
			this->Repaint();
            to_right = to_right + 169.6;
			count_top++;
			if(count_top>4){
			   count_top = 1;
			   to_bottom = to_bottom+ 180;
			   to_right = 0;
			}

			ADOQuery1->Next();
		}while(!ADOQuery1->Eof);




	}

}


void __fastcall TForm8::DeleteLabelClick(TObject *Sender)
{
     TLabel *B=dynamic_cast<TLabel *>(Sender);
	 if (!B) return;


	 ADOQuery5->Parameters->ParamByName("Login")->Value = MainLogin;
	 ADOQuery5->Parameters->ParamByName("MeblName")->Value = B->Hint;
	 ADOQuery5->ExecSQL();

	 AnsiString Message = B->Hint;
	 Message = Message + " �������� �� �������";

	 ShowMessage(Message);
	 Form3= new TForm3(this, MainLogin);
	 Form3->Show();
	 Form8->Close();
	 Form8= new TForm8(this, MainLogin);
	 Form8->Show();
	 Form3->Close();
}

//---------------------------------------------------------------------------
void __fastcall TForm8::N1Click(TObject *Sender)
{
	Form3->Show();
	Form8->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm8::N3Click(TObject *Sender)
{
	   Form6= new TForm6(this, MainLogin);
	   Form6->Show();
	   Form8->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::N7Click(TObject *Sender)
{
	 Form9= new TForm9(this, MainLogin);
	 Form9->Show();
	 Form8->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm8::N5Click(TObject *Sender)
{
	Form1= new TForm1(this);
	Form1->Show();
	Form8->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm8::N8Click(TObject *Sender)
{
	   Form8= new TForm8(this, MainLogin);
	   Form8->Show();
	   Form8->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TForm8::Label4Click(TObject *Sender)
{
    ADOQuery3->Parameters->ParamByName("Login")->Value = MainLogin;
	ADOQuery3->ExecSQL();
	Form3= new TForm3(this, MainLogin);
	Form3->Show();
	Form8->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Label10Click(TObject *Sender)
{
    ADOQuery1->Active=false;
    ADOQuery1->Parameters->ParamByName("Login")->Value = MainLogin;
	ADOQuery1->Active=true;
	ADOQuery1->First();

	AnsiString MebelName;
	if(!ADOQuery1->Eof){
		do{
		   MebelName = ADOQuery1->FieldValues["_namemebl_"];

		   ADOQuery4->Parameters->ParamByName("Login")->Value = MainLogin;
		   ADOQuery4->Parameters->ParamByName("MeblName")->Value = MebelName;
		   ADOQuery4->ExecSQL();


           ADOQuery1->Next();
		}while(!ADOQuery1->Eof);

	}


	ShowMessage("������ ���� ��������� �� ������ ������!");
	Form6= new TForm6(this, MainLogin);
	Form6->Show();
	Form8->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Niko1Click(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

