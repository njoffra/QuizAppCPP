//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Asocijacije.h"
#include "Navigacija.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TAsocijacijeForma *AsocijacijeForma;
int skor;
//---------------------------------------------------------------------------
__fastcall TAsocijacijeForma::TAsocijacijeForma(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAsocijacijeForma::zatvori(TObject *Sender, TCloseAction &Action)

{
NavigacijaForma->AsocijacijeButton->Enabled = false;
		NavigacijaForma->ukupni_bodovi += skor; // ukupni_bodovi je deklarisana Navigacija.h
		NavigacijaForma->UkupniBodovi->Text = NavigacijaForma->ukupni_bodovi;
		this->Close();
		NavigacijaForma->Show();
}
//---------------------------------------------------------------------------

