//---------------------------------------------------------------------------

#ifndef BrojH
#define BrojH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Controls3D.hpp>

#include <FMX.Layers3D.hpp>
#include <System.Math.Vectors.hpp>
#include <FMX.Objects.hpp>/
#include <System.Math.Vectors.hpp>/---------------------------------------------------------------------------
class TBrojForma : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1Generisi;
	TButton *Button1;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *EditDisplay;
	TButton *ButtonNum1;
	TButton *ButtonNum2;
	TButton *ButtonNum4;
	TButton *ButtonNum3;
	TButton *ButtonNum5;
	TButton *ButtonMinus;
	TButton *ButtonDijeli;
	TButton *ButtonPuta;
	TButton *ButtonJednako;
	TButton *ButtonPlus;
	TButton *ButtonBrisi;
	TButton *ButtonRezultat;
	TButton *ButtonLZagrada;
	TButton *ButtonDZagrada;
	TButton *Izlaz;
	TTimer *Vrijeme;
	TLabel *VrijemeText;
	TButton *IzlazPravi;
	TTextLayer3D *TextLayer3D1;
	TText *Bodovi;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall NumberClick2(TObject *Sender);
	void __fastcall ButtonJednakoClick(TObject *Sender);
	void __fastcall OperatorClick(TObject *Sender);
	void __fastcall BrisiClick(TObject *Sender);
	void __fastcall IzlazClick(TObject *Sender);
	void __fastcall VrijemeTimer(TObject *Sender);
	void __fastcall IzlazPraviClick(TObject *Sender);
	void __fastcall zatvori(TObject *Sender, TCloseAction &Action);

private:
	TDateTime StartTime;	// User declarations
public:		// User declarations
	__fastcall TBrojForma(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TBrojForma *BrojForma;
//---------------------------------------------------------------------------
#endif

