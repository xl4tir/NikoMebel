//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Menus.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image2;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N5;
	TImage *Image1;
	TLabel *Label5;
	TLabel *Label7;
	TPanel *Panel1;
	TLabel *Label1;
	TImage *Image13;
	TPanel *Panel3;
	TImage *Image5;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TADOQuery *ADOQuery2;
	TADOQuery *ADOQuery3;
	TADOQuery *ADOQuery4;
	TMenuItem *Niko1;
	void __fastcall Label10Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall Label9Click(TObject *Sender);
	void __fastcall DeleteLabelClick(TObject *Sender);
	void __fastcall Niko1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner, AnsiString Login);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
