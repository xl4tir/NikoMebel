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
TForm9 *Form9;

AnsiString MainLogin;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner, AnsiString Login)
	: TForm(Owner)
{
	MainLogin = Login;

    ADOQuery1->Parameters->ParamByName("Login")->Value = MainLogin;
	ADOQuery1->Active=true;
    ADOQuery2->Active=true;

	int TopPlusPanel=-75, q=0, temp_order_num=0, order_num=0,ImgToLeft =0;
	if(!ADOQuery1->Eof){
		ADOQuery1->First();


		do{
			order_num = ADOQuery1->FieldValues["order_num"];

			if(temp_order_num != order_num){
                ImgToLeft = 0;
				TopPlusPanel = TopPlusPanel + 75;

                TPanel *OrderPanel = new TPanel(this);
				OrderPanel->Parent = this->Panel1;
				OrderPanel->Caption = " ";
				OrderPanel->Left = 37;
				OrderPanel->Top = 16 + TopPlusPanel;
				OrderPanel->Name = "OrderPanel" + IntToStr(q);
				OrderPanel->Height =57;
				OrderPanel->Width = 625;

				AnsiString ImgColor, Order_Status = ADOQuery1->FieldValues["status_"];

				if(Order_Status == "� ������" || Order_Status == "��������"){
				   ImgColor  = "blue-back.png";
				}else if(Order_Status == "³������"){
                    ImgColor  = "red-back.png";
				}else if(Order_Status == "��������"){
                    ImgColor  = "green-back.png";
				}

				TImage *BackImg = new TImage(this);
				BackImg->Parent = this->Panel1;
				BackImg->Picture->LoadFromFile(ImgColor);
				BackImg->Height =57;
				BackImg->Width = 625;
				BackImg->Name = "BackImg" + IntToStr(q);
				BackImg->Left = 37;
				BackImg->Top = 16+ TopPlusPanel;


				AnsiString OrderNumLabel = "���������� �";
				OrderNumLabel = OrderNumLabel + IntToStr(order_num) + " ";

				int Panel2_Left = OrderPanel->Left;
				int Panel2_Top = OrderPanel->Top;

				TLabel *OrderNum = new TLabel(this);
				OrderNum->Parent = this->Panel1;
				OrderNum->Caption = OrderNumLabel;
				OrderNum->Left = 15 + Panel2_Left;
				OrderNum->Top = 8 + Panel2_Top;
				OrderNum->AutoSize = true;
				OrderNum->Alignment = taLeftJustify;
				OrderNum->Name = "OrderNum" + IntToStr(q);
				OrderNum->Font->Style = TFontStyles()<< fsBold << fsItalic;
				OrderNum->Font->Size = 9;



				TLabel *StatusOrder = new TLabel(this);
				StatusOrder->Parent = this->Panel1;
				StatusOrder->Caption = Order_Status;
				StatusOrder->Left = 15 + Panel2_Left;
				StatusOrder->Top = 27 + Panel2_Top;
				StatusOrder->AutoSize = true;
				StatusOrder->Alignment = taLeftJustify;
				StatusOrder->Name = "StatusOrder" + IntToStr(q);
				StatusOrder->Font->Size = 11;

				AnsiString Order_Date = ADOQuery1->FieldValues["time_"];

				TLabel *DateLabel = new TLabel(this);
				DateLabel->Parent = this->Panel1;
				DateLabel->Caption = Order_Date;
				DateLabel->Left = 152 + Panel2_Left;
				DateLabel->Top = 8 + Panel2_Top;
				DateLabel->AutoSize = true;
				DateLabel->Alignment = taLeftJustify;
				DateLabel->Name = "DateLabel" + IntToStr(q);
				DateLabel->Font->Size = 9;
				DateLabel->Font->Style = TFontStyles() << fsItalic;

				AnsiString Price =  ADOQuery1->FieldValues["Price"];
                Price = Price + " UAH";

				TLabel *summa = new TLabel(this);
				summa->Parent = this->Panel1;
				summa->Caption = "���� ����������";
				summa->Left = 271 + Panel2_Left;
				summa->Top = 8 + Panel2_Top;
				summa->AutoSize = true;
				summa->Alignment = taLeftJustify;
				summa->Name = "summa" + IntToStr(q);
				summa->Font->Size = 8;
				summa->Font->Style = TFontStyles() << fsBold;
				summa->Font->Color = (TColor) RGB (0x8c, 0x8a, 0x8a);


				TLabel *PriceLabel = new TLabel(this);
				PriceLabel->Parent = this->Panel1;
				PriceLabel->Caption = Price;
				PriceLabel->Left = 271 + Panel2_Left;
				PriceLabel->Top = 27 + Panel2_Top;
				PriceLabel->Width = 110;
				PriceLabel->Alignment = taLeftJustify;
				PriceLabel->Name = "PriceLabel" + IntToStr(q);
				PriceLabel->Font->Size = 11;


                q++;

				this->Repaint();

			}


			ADOQuery2->First();
			if(!ADOQuery2->Eof){

				do{
					   if(ADOQuery2->FieldValues["Name"] == ADOQuery1->FieldValues["MeblName"]){

							TImage *DivanImage = new TImage(this);
							DivanImage->Parent = this->Panel1;
							DivanImage->Left = 576 + 37 - ImgToLeft;
							DivanImage->Top = 9 + 16 + TopPlusPanel;
							DivanImage->Width = 40;
							DivanImage->Height = 40;
							DivanImage->Stretch = true;
							DivanImage->Picture->LoadFromFile(ADOQuery2->FieldValues["Img"]);
							DivanImage->Cursor = crHandPoint;
					   }

                       ADOQuery2->Next();
				}while(!ADOQuery2->Eof);


			}


			ImgToLeft = ImgToLeft +  46;
			temp_order_num = ADOQuery1->FieldValues["order_num"];
			ADOQuery1->Next();
		}while(!ADOQuery1->Eof);




	}

}
//---------------------------------------------------------------------------
void __fastcall TForm9::N1Click(TObject *Sender)
{
	Form3->Show();
	Form9->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::N3Click(TObject *Sender)
{
	Form6 = new TForm6(this, MainLogin);
	Form6->Show();
	Form9->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::N7Click(TObject *Sender)
{
	 Form9= new TForm9(this, MainLogin);
	 Form9->Show();
	 Form9->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::N8Click(TObject *Sender)
{
	   Form8= new TForm8(this, MainLogin);
	   Form8->Show();
	   Form9->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::N5Click(TObject *Sender)
{
	Form1= new TForm1(this);
	Form1->Show();
	Form9->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Niko1Click(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------
