//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N5;
	TLabel *Label1;
	TImage *Image2;
	TImage *Image1;
	TPanel *Panel1;
	TLabel *Label6;
	TPanel *Panel2;
	TLabel *Label7;
	TImage *Image14;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TImage *Image13;
	TADOQuery *ADOQuery2;
	TMenuItem *Niko1;

	void __fastcall Labels1Click(TObject *Sender);

	void __fastcall LabelnewClick(TObject *Sender);


	void __fastcall N3Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall Niko1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner, AnsiString login);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
