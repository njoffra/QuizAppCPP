//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Navigacija.h"
#include "Broj.h"
#include "Spajanje.h"
#include "Klik.h"
#include "Zaokruzivanje.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TNavigacijaForma *NavigacijaForma;

//---------------------------------------------------------------------------
__fastcall TNavigacijaForma::TNavigacijaForma(TComponent* Owner)
	: TForm(Owner)
{
	UkupniBodovi->Text = ukupni_bodovi;
}
//---------------------------------------------------------------------------
void __fastcall TNavigacijaForma::BrojButtonClick(TObject *Sender)
{
	BrojForma->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TNavigacijaForma::SpajanjeButtonClick(TObject *Sender)
{
	SpajanjeForma->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TNavigacijaForma::KlikButtonClick(TObject *Sender)
{
	KlikForma->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TNavigacijaForma::ZaokruziButtonClick(TObject *Sender)
{
	ZaokruzivanjeForma->Show();
	this->Hide();
}
//---------------------------------------------------------------------------


