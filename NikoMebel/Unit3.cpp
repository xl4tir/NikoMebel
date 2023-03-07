//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit3.h"
#include <jpeg.hpp>
#include "Unit4.h"
#include "Unit1.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit8.h"
#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
AnsiString MainLogin;

__fastcall TForm3::TForm3(TComponent* Owner, AnsiString login)
	: TForm(Owner)
{
	FormStyle= fsStayOnTop;
	Label1->Caption = login+" ";
	MainLogin = login;
	ADOQuery1->Active=true;

	AnsiString categ;
	int k=0,q=1;
	if(!ADOQuery1->Eof){
		ADOQuery1->First();

		do{
			TLabel *temp = new TLabel(this);
			temp->Parent = this->Panel1;
			temp->Caption = ADOQuery1->FieldValues["name"];
			temp->Left = 59 +  k;
			temp->Top = 130  ;
			temp->AutoSize = false;
			temp->Width = 105;
			temp->Alignment = taCenter;
			temp->Name = "Labels" + IntToStr(q);
			temp->Enabled = true;
			temp->OnClick = Labels1Click;
            temp->Cursor = crHandPoint;
            temp->Font->Style = TFontStyles()<< fsBold ;
			temp->Font->Size = 11;
            temp->Height =20;


			TImage *temp1 = new TImage(this);
			temp1->Parent = this->Panel1;
			temp1->Left = 59 +   k;
			temp1->Top = 16  ;
			temp1->Width = 105;
			temp1->Height = 105;
			temp1->Stretch = true;
			temp1->Name = "Images" + IntToStr(q);
			temp1->Hint = ADOQuery1->FieldValues["name"];
			temp1->Picture->LoadFromFile(ADOQuery1->FieldValues["img"]);
			temp1->Cursor = crHandPoint;



            q++;
            this->Repaint();
			k = k+143.75;

			ADOQuery1->Next();
		}while(!ADOQuery1->Eof);




	}


    k=0,q=1;;
	ADOQuery2->Active=true;
	if(!ADOQuery2->Eof){
		ADOQuery2->First();
        int i=0;
		do{

			TLabel *temp2 = new TLabel(this);
			temp2->Parent = this->Panel2;
			temp2->Caption = ADOQuery2->FieldValues["Name"];
			temp2->Left = 59 +  k;
			temp2->Top = 133  ;
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
			temp3->Parent = this->Panel2;
			temp3->Left = 59 +   k;
			temp3->Top = 16  ;
			temp3->Width = 105;
			temp3->Height = 105;
			temp3->Stretch = true;
			temp3->Name = "Imagenew" + IntToStr(q);
			temp3->Hint = ADOQuery2->FieldValues["name"];
			temp3->Picture->LoadFromFile(ADOQuery2->FieldValues["Img"]);
			temp3->Cursor = crHandPoint;



			AnsiString descFull = ADOQuery2->FieldValues["Desc"];
			AnsiString descPart;
			for(int i=1;i<60;i++){
                descPart = descPart+descFull[i];
			}
			TLabel *temp4 = new TLabel(this);
			temp4->Parent = this->Panel2;
			temp4->Caption = descPart;
			temp4->Left = 59 +  k;
			temp4->Top = 155  ;
			temp4->AutoSize = false;
			temp4->Width = 105;
            temp4->Height = 64;
			temp4->Alignment = taLeftJustify;
            temp4->Hint = ADOQuery2->FieldValues["name"];
			temp4->Name = "LabelText" + IntToStr(q);
			temp4->Enabled = true;

			temp4->Cursor = crHandPoint;
			temp4->WordWrap = true;


			AnsiString Price = ADOQuery2->FieldValues["Price"];
			Price = Price +   " UAH";
			TLabel *temp5 = new TLabel(this);
			temp5->Parent = this->Panel2;
			temp5->Caption = Price;
			temp5->Left = 59 +  k;
			temp5->Top = 220;
			temp5->AutoSize = false;
			temp5->Width = 105;
			temp5->Height = 65;
			temp5->Alignment = taRightJustify;
			temp5->Name = "LabelPrice" + IntToStr(q);
			temp5->Enabled = true;

			temp5->Font->Style = TFontStyles()<< fsBold ;
            temp5->Font->Color = (TColor) RGB (0x8c, 0x8a, 0x8a);


            q++;
			k = k+143.75;


            this->Repaint();
			ADOQuery2->Next();
            i++;
		}while(i!=5);
	}


	
	Image13->SendToBack();
	Image14->SendToBack();
	Panel1->SendToBack();
    Panel2->SendToBack();




}
//---------------------------------------------------------------------------


void __fastcall TForm3::Labels1Click(TObject *Sender)
{
	 TLabel *B=dynamic_cast<TLabel *>(Sender);
	 if (!B) return;


	 Form4 = new TForm4(this, B->Caption, MainLogin);
	 Form4->Show();
     Form3->Hide();

	 B=NULL;
}
//---------------------------------------------------------------------------



void __fastcall TForm3::LabelnewClick(TObject *Sender)
{
	 TLabel *B=dynamic_cast<TLabel *>(Sender);
	 if (!B) return;


	 Form5 = new TForm5(this, B->Caption, MainLogin);
	 Form5->Show();
	 Form3->Hide();


	 B=NULL;


}




void __fastcall TForm3::N3Click(TObject *Sender)
{
	   Form6 = new TForm6(this, MainLogin);
	   Form6->Show();
	   Form3->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N8Click(TObject *Sender)
{
	   Form8= new TForm8(this, MainLogin);
	   Form8->Show();
	   Form3->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TForm3::N7Click(TObject *Sender)
{

	 Form9= new TForm9(this, MainLogin);
	 Form9->Show();
     Form3->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::N5Click(TObject *Sender)
{
	Form1= new TForm1(this);
    Form1->Show();
	Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Niko1Click(TObject *Sender)
{
  Form1->Close();
}
//---------------------------------------------------------------------------

