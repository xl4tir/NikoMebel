//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdlib.h>
#include <time.h>
#include "Unit4.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
AnsiString MainLogin;
AnsiString FullPrice;

__fastcall TForm7::TForm7(TComponent* Owner, AnsiString Login, AnsiString Price)
	: TForm(Owner)
{
	 MainLogin = Login;
     FullPrice = Price;
	 ADOQuery2->Parameters->ParamByName("Login")->Value = Login;
	 ADOQuery2->Active=true;
	 Edit1->Text = ADOQuery2->FieldValues["tel"];
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
    srand (time(NULL));
	AnsiString telephone = Edit1->Text;
	int OrderNum, k =0;

	if(telephone[10]){
		ADOQuery1->Parameters->ParamByName("Login")->Value = MainLogin;
		ADOQuery1->Active=true;
		ADOQuery4->Active=true;

		while(k==0){
			OrderNum = rand() %  10000;
			ADOQuery4->First();
			if(!ADOQuery4->Eof){
				ADOQuery4->First();

				do{
				  if(ADOQuery4->FieldValues["order_num"] == OrderNum){
					k--;
				  }
                     ADOQuery4->Next();
				}while(!ADOQuery4->Eof);
			}
			k++;
		}


		ADOQuery1->First();
		if(!ADOQuery1->Eof){
			ADOQuery1->First();

			do{
			   ADOQuery3->Parameters->ParamByName("MeblName")->Value = ADOQuery1->FieldValues["MeblName"];
			   ADOQuery3->Parameters->ParamByName("Price")->Value = FullPrice;
			   ADOQuery3->Parameters->ParamByName("Login")->Value = MainLogin;
			   ADOQuery3->Parameters->ParamByName("Tel")->Value = telephone;
			   ADOQuery3->Parameters->ParamByName("OrderNum")->Value = OrderNum;
			   ADOQuery3->Parameters->ParamByName("Time")->Value = DateTimePicker1->DateTime.FormatString("dd.mm.yyyy");
               ADOQuery3->Parameters->ParamByName("Status")->Value = "��������";
			   ADOQuery3->ExecSQL();

			   ADOQuery1->Next();
			}while(!ADOQuery1->Eof);
		}


	    ShowMessage("���������� �" +IntToStr(OrderNum)+ " ���������!");
		ADOQuery5->Parameters->ParamByName("Login")->Value = MainLogin;
		ADOQuery5->ExecSQL();

		Form7->Close();
		Form3->Show();
		Form6->Close();
	}else{
		ShowMessage("����� �������� �� � ���������!");
	}


}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button2Click(TObject *Sender)
{
	Form7->Close();

}
//---------------------------------------------------------------------------
