//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)

{
	 Image2->SendToBack();

}
//---------------------------------------------------------------------------


class User{
	public:
		AnsiString login,pass;

		User(AnsiString l, AnsiString p){
			login = l;
			pass=p;
		}

		User(){
			login="name";
			pass="pass";
		}

		int ToCheckUser(AnsiString log, AnsiString pas){
			if(login==log && pass== pas){

				return 1;
			}else{
                return 0;
            }
		}


};

void __fastcall TForm1::Button1Click(TObject *Sender)
{

	User U1,U2(Edit1->Text,Edit2->Text);

	ADOQuery1->Active=true;
	int k=0;
	if(!ADOQuery1->Eof){
		ADOQuery1->First();

		do{

			U1.login =  ADOQuery1->FieldValues["login"];
			U1.pass =  ADOQuery1->FieldValues["pass"];

			k =  U2.ToCheckUser(U1.login, U1.pass);
			if(k==1){
                break;
			}

			ADOQuery1->Next();
		}while(!ADOQuery1->Eof);
	}

	if(k == 0){
		ShowMessage("������������ �� ����� ������ �� ������� �� ����. ��������� �� ���!");
	}


	ADOQuery1->Active=false;
	if(k==1){
		Form3 = new TForm3(this, U1.login);
		Form3->Show();
		Form1->Hide();
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form2->Show();
	Form1->Hide();
    Edit1->Text = "";
	Edit2->Text = "";
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


