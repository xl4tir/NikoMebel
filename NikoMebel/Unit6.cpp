//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit4.h"
#include "Unit1.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit8.h"
#include "Unit9.h"
#include "Unit7.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;

AnsiString MainLogin;
int FullPrice=0;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner, AnsiString Login)
	: TForm(Owner)
{
	MainLogin = Login;

	Label5->Caption = MainLogin;


	ADOQuery1->Parameters->ParamByName("Login")->Value = MainLogin;
	ADOQuery1->Active=true;
	ADOQuery1->First();
	ADOQuery2->Active=true;



	int k=0,q=1,TopPlusPanel =0;
    FullPrice =0 ;
	if(!ADOQuery1->Eof){
		ADOQuery1->First();

		do{
            ADOQuery2->First();
			if(!ADOQuery2->Eof){


				do{
					if(ADOQuery1->FieldValues["MeblName"] == ADOQuery2->FieldValues["Name"]){
						AnsiString FullMeblName = ADOQuery2->FieldValues["Categories"] ;
						FullMeblName = FullMeblName +  " - ";
						FullMeblName = FullMeblName + ADOQuery1->FieldValues["MeblName"];


						TPanel *DivanPanel = new TPanel(this);
						DivanPanel->Parent = this->Panel1;
						DivanPanel->Caption = " ";
						DivanPanel->Left = 16;
						DivanPanel->Top = 12+ TopPlusPanel;
						DivanPanel->Name = "DivanPanel" + IntToStr(q);
						//DivanName->OnClick = FullClick;
						DivanPanel->Height =85;
						DivanPanel->Width = 665;
						DivanPanel->Hint =    ADOQuery1->FieldValues["MeblName"];
						DivanPanel->Cursor = crHandPoint;
						DivanPanel->OnClick = DeleteLabelClick;



						TImage *BackImg = new TImage(this);
						BackImg->Parent = this->Panel1;
						BackImg->Picture->LoadFromFile("white-back.png");
						BackImg->Height =85;
						BackImg->Width = 665;
						BackImg->Name = "BackImg" + IntToStr(q);


						BackImg->Left = 16;
						BackImg->Top = 12+ TopPlusPanel;

						AnsiString PanelName = "DivanPanel" + IntToStr(q);

						TLabel *DivanName = new TLabel(this);
						DivanName->Parent = this->Panel1;
						DivanName->Caption = FullMeblName;
						DivanName->Left = 88 + DivanPanel->Left;
						DivanName->Top = 12  + DivanPanel->Top;
						DivanName->Name = "FullMeblNameLabel" + IntToStr(q);
						//DivanName->OnClick = FullClick;

						DivanName->Font->Style = TFontStyles()<< fsBold ;
						DivanName->Font->Size = 16;

						TImage *DivanImage = new TImage(this);
						DivanImage->Parent = this->Panel1;
						DivanImage->Left = 12 + DivanPanel->Left;
						DivanImage->Top = 12 + DivanPanel->Top;
						DivanImage->Width = 60;
						DivanImage->Height = 60;
						DivanImage->Stretch = true;
						DivanImage->Name = "DivanImage" + IntToStr(q);
						DivanImage->Hint = ADOQuery1->FieldValues["MeblName"];
						DivanImage->Picture->LoadFromFile(ADOQuery2->FieldValues["Img"]);


						AnsiString MeblSize = "����� (��): ";
						MeblSize = MeblSize + ADOQuery2->FieldValues["Size"];

						TLabel *DivanSize = new TLabel(this);
						DivanSize->Parent = this->Panel1;
						DivanSize->Caption = MeblSize;
						DivanSize->Left = 88 + DivanPanel->Left;
						DivanSize->Top = 47+ DivanPanel->Top;
						DivanSize->Name = "DivanSize" + IntToStr(q);
						DivanSize->Font->Size = 10;

						TLabel *DivanRemove = new TLabel(this);
						DivanRemove->Parent = this->Panel1;
						DivanRemove->Caption = "�������� � ������";
						DivanRemove->Left = 519 + DivanPanel->Left;
						DivanRemove->Top = 47+ DivanPanel->Top;
						DivanRemove->Name = "DivanRemove" + IntToStr(q);
						DivanRemove->Font->Size = 9;
						DivanRemove->Hint =  ADOQuery1->FieldValues["MeblName"];
						DivanRemove->Font->Color= clRed;
						DivanRemove->Font->Style = DivanRemove->Font->Style<<fsUnderline;
						DivanRemove->OnClick = DeleteLabelClick;
						DivanRemove->Cursor = crHandPoint;
						DivanRemove->Enabled=true;
						DivanRemove->BringToFront();


						AnsiString MeblPrice =  ADOQuery2->FieldValues["Price"];
						MeblPrice = MeblPrice + " UAH";

						FullPrice = FullPrice + StrToInt(ADOQuery2->FieldValues["Price"]);

                        TLabel *DivanPrice = new TLabel(this);
						DivanPrice->Parent = this->Panel1;
						DivanPrice->Caption = MeblPrice;
						DivanPrice->Left = 416 + DivanPanel->Left;
						DivanPrice->Top = 14+ DivanPanel->Top;
						DivanPrice->Width = 225;

                        DivanPrice->Alignment = taRightJustify;
						DivanPrice->Name = "DivanPrice" + IntToStr(q);
						DivanPrice->Font->Size = 16;
						DivanPrice->Font->Style = TFontStyles()<< fsBold ;



					}
                    ADOQuery2->Next();
				}while(!ADOQuery2->Eof);




			}






            TopPlusPanel = TopPlusPanel + 100;
            q++;
            this->Repaint();


			ADOQuery1->Next();
		}while(!ADOQuery1->Eof);




	}

	Label8->Caption = "���� �� ������: " + IntToStr(FullPrice) + " UAH";


}
//---------------------------------------------------------------------------
void __fastcall TForm6::Label10Click(TObject *Sender)
{
	Form7 = new TForm7(this, MainLogin, IntToStr(FullPrice));
    Form7->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::N1Click(TObject *Sender)
{
	Form3->Show();
    Form6->Close();
}
//---------------------------------------------------------------------------





void __fastcall TForm6::N7Click(TObject *Sender)
{
	 Form9= new TForm9(this, MainLogin);
	 Form9->Show();
	 Form6->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N8Click(TObject *Sender)
{
	   Form8= new TForm8(this, MainLogin);
	   Form8->Show();
	   Form6->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N5Click(TObject *Sender)
{
	Form1= new TForm1(this);
	Form1->Show();
	Form6->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Label9Click(TObject *Sender)
{
	ADOQuery3->Parameters->ParamByName("Login")->Value = MainLogin;
	ADOQuery3->ExecSQL();	Form6->Close();
	Form3= new TForm3(this, MainLogin);
	Form3->Show();
	Form6->Close();

}
//---------------------------------------------------------------------------
void __fastcall TForm6::DeleteLabelClick(TObject *Sender){

	 TPanel *B=dynamic_cast<TPanel *>(Sender);
	 if (!B) return;


	 ADOQuery4->Parameters->ParamByName("Login")->Value = MainLogin;
	 ADOQuery4->Parameters->ParamByName("MeblName")->Value = B->Hint;
	 ADOQuery4->ExecSQL();

	 AnsiString Message = B->Hint;
     Message = Message + " �������� �� ������";

	 ShowMessage(Message);
	 Form3= new TForm3(this, MainLogin);
	 Form3->Show();
	 Form6->Close();
	 Form6= new TForm6(this, MainLogin);
	 Form6->Show();
	 Form3->Close();
}


void __fastcall TForm6::Niko1Click(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

