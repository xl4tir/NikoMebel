//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image2;
	TLabel *Label7;
	TPanel *Panel1;
	TLabel *Label1;
	TImage *Image1;
	TLabel *Label5;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N5;
	TImage *Image13;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TADOQuery *ADOQuery2;
	TMenuItem *Niko1;
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall Niko1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm9(TComponent* Owner, AnsiString Login);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
