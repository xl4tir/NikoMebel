//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit3.h"
#include "Unit4.h"
#include "Unit1.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit8.h"
#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
AnsiString MainLogin;

__fastcall TForm4::TForm4(TComponent* Owner, AnsiString Categories, AnsiString Login)
	: TForm(Owner)
{
	Label1->Caption=Categories;
	Label2->Caption=Login;
	MainLogin =  Login;
	AnsiString FormCaption = "Niko Mebel - ";
	Form4->Caption =  FormCaption + Categories;
	int k=0,q=1,TopPoz=0;
	ADOQuery2->Parameters->ParamByName("categoria")->Value = Categories;
	ADOQuery2->Active=true;
	if(!ADOQuery2->Eof){
		ADOQuery2->First();
        int i=0;
		do{

			TLabel *temp2 = new TLabel(this);
			temp2->Parent = this->Panel1;
			temp2->Caption = ADOQuery2->FieldValues["Name"];
			temp2->Left = 59 +  k;
			temp2->Top = 133 + TopPoz;
			temp2->AutoSize = false;
			temp2->Width = 105;
			temp2->Alignment = taCenter;
			temp2->Name = "Labelnew" + IntToStr(q);
			temp2->Enabled = true;
			temp2->OnClick = LabelnewClick;
			temp2->Cursor = crHandPoint;
			temp2->Font->Style = TFontStyles()<< fsBold ;
            temp2->Font->Size = 9;



			TImage *temp3 = new TImage(this);
			temp3->Parent = this->Panel1;
			temp3->Left = 59 +   k;
			temp3->Top = 16 + TopPoz ;
			temp3->Width = 105;
			temp3->Height = 105;
			temp3->Stretch = true;
			temp3->Name = "Imagenew" + IntToStr(q);
			temp3->Hint = ADOQuery2->FieldValues["name"];
			temp3->Picture->LoadFromFile(ADOQuery2->FieldValues["Img"]);
			temp3->Cursor = crHandPoint;
//			temp3->OnClick = ImagenewClick;


			AnsiString descFull = ADOQuery2->FieldValues["Desc"];
			AnsiString descPart;
			for(int i=1;i<60;i++){
                descPart = descPart+descFull[i];
			}
			TLabel *temp4 = new TLabel(this);
			temp4->Parent = this->Panel1;
			temp4->Caption = descPart;
			temp4->Left = 59 +  k;
			temp4->Top = 155 + TopPoz ;
			temp4->AutoSize = false;
			temp4->Width = 105;
            temp4->Height = 64;
			temp4->Alignment = taLeftJustify;
            temp4->Hint = ADOQuery2->FieldValues["name"];
			temp4->Name = "LabelText" + IntToStr(q);
			temp4->Enabled = true;
//			temp4->OnClick = LabelTextClick;
			temp4->Cursor = crHandPoint;
			temp4->WordWrap = true;


			AnsiString Price = ADOQuery2->FieldValues["Price"];
			Price = Price +   " UAH";
			TLabel *temp5 = new TLabel(this);
			temp5->Parent = this->Panel1;
			temp5->Caption = Price;
			temp5->Left = 59 +  k;
			temp5->Top = 220+ TopPoz;
			temp5->AutoSize = false;
			temp5->Width = 105;
			temp5->Height = 65;
			temp5->Alignment = taRightJustify;
			temp5->Name = "LabelPrice" + IntToStr(q);
			temp5->Enabled = true;
			temp5->Cursor = crHandPoint;
			temp5->Font->Style = TFontStyles()<< fsBold ;
            temp5->Font->Color = (TColor) RGB (0x8c, 0x8a, 0x8a);


			q++;
			k = k+143.75;
			if(q==6){
				TopPoz = 250;
                k=0;
			}

            this->Repaint();
			ADOQuery2->Next();
            i++;
		}while(!ADOQuery2->Eof);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::N1Click(TObject *Sender)
{
	Form3->Show();
	Form4->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TForm4::LabelnewClick(TObject *Sender)
{
	 TLabel *B=dynamic_cast<TLabel *>(Sender);
	 if (!B) return;


	 Form5 = new TForm5(this, B->Caption, MainLogin);
     Form5->Show();
     Form4->Hide();

	 B=NULL;
}
void __fastcall TForm4::N3Click(TObject *Sender)
{
   Form6 = new TForm6(this, MainLogin);
   Form6->Show();
   Form4->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TForm4::N7Click(TObject *Sender)
{
	Form9 = new TForm9(this, MainLogin);
	Form9->Show();
	Form4->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::N5Click(TObject *Sender)
{
	Form1= new TForm1(this);
	Form1->Show();
	Form4->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::N8Click(TObject *Sender)
{
	Form8= new TForm8(this, MainLogin);
	Form8->Show();
	Form4->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Niko1Click(TObject *Sender)
{
   Form1->Close();
}
//---------------------------------------------------------------------------

