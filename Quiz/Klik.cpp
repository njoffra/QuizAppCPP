//---------------------------------------------------------------------------

#include <fmx.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <ctime>
#pragma hdrstop

#include "Klik.h"
#include "Navigacija.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
using namespace std;
TKlikForma *KlikForma;
int sekunda1=0;
int sekunda2=0;
void __fastcall Timer1Timer();
void __fastcall Timer2Timer();

class Igrac{ // bazna klasa igraca
protected:   // proteced da bi djeca mogla naslijedit ove atribute
	int skor;
	int klikovi;
public:
	Igrac(){
		this->klikovi=0;
		this->skor=0;
	}
	virtual void setSkor(){
		this->skor=(int)(this->klikovi/3);
	}
	int getSkor(){
		return this->skor;
	}
	int getKlikovi(){
		return this->klikovi;
	}
	void operator!(){
		this->klikovi++;
	}
	virtual void ispisi_klikove(){  // virtuelna jer ako hocemo samo jednom igracu ispisati tekst mozemo override uraditi
		KlikForma->Igrac1Tekst->Text=0;
		KlikForma->Igrac2Tekst->Text=0;
	}
};

class Igrac1: public Igrac{
private:
	bool pokrenut_timer = false;
public:
	void ispisi_klikove()override { // override virtuelne
		KlikForma->Igrac1Tekst->Text=this->klikovi;
	}
	void pokreni_timer(){
		this->pokrenut_timer=true;
	}
    bool je_li_pokrenut(){
		return this->pokrenut_timer;
	}
};

class Igrac2:public Igrac{
private:
	bool pokrenut_timer = false;
public:
	void pokreni_timer(){
		this->pokrenut_timer=true;
	}
	bool je_li_pokrenut(){
		return this->pokrenut_timer;
	}
	void ispisi_klikove() override{  // override virtuelne
		KlikForma->Igrac2Tekst->Text=this->klikovi;
	}
};
Igrac1 prvi_igrac;
Igrac2 drugi_igrac;

//---------------------------------------------------------------------------
__fastcall TKlikForma::TKlikForma(TComponent* Owner)
	: TForm(Owner)
{
	Igrac igrac;
	igrac.ispisi_klikove();  //kad tek udjemo u igricu ispisujemo oba igraca
}
//---------------------------------------------------------------------------
void __fastcall TKlikForma::zatvori(TObject *Sender, TCloseAction &Action)
{
		NavigacijaForma->KlikButton->Enabled = false;
		this->Close();
		NavigacijaForma->Show();
}
//---------------------------------------------------------------------------


void __fastcall TKlikForma::IzlazDugmeClick(TObject *Sender)
{
		this->Close();
		NavigacijaForma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TKlikForma::Igrac1DugmeClick(TObject *Sender)
{

	if(!prvi_igrac.je_li_pokrenut()){ //da se nebi timer restartovao svakim klikom
		prvi_igrac.pokreni_timer();
		StartTime1= Now();
		}
	VrijemeText1->Visible = true;
	Timer1->Enabled = true;
	VrijemeText1->Enabled = True;
	!prvi_igrac; // operator koji broji klikove
	prvi_igrac.ispisi_klikove();
	if(sekunda1==10){
		Igrac1Dugme->Enabled=false;
		VrijemeText1->Visible= false,
        VrIsteklo1->Text="Vrijeme isteklo";
		Igrac2Dugme->Enabled=true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TKlikForma::Igrac2DugmeClick(TObject *Sender)
{
	if(!drugi_igrac.je_li_pokrenut()){
		drugi_igrac.pokreni_timer();
		StartTime2= Now();
		}
	VrijemeText2->Visible = true;
	Timer2->Enabled = true;
	VrijemeText2->Enabled = True;
	!drugi_igrac; // operator koji broji klikove
	drugi_igrac.ispisi_klikove();
	if(sekunda2==10) {
	   Igrac2Dugme->Enabled=false;
	   VrijemeText2->Visible= false,
		VrIsteklo2->Text="Vrijeme isteklo";
	   if(prvi_igrac.getKlikovi() > drugi_igrac.getKlikovi()){
		RezultatText->Text="Igrac 1 je pobjedio";
		prvi_igrac.setSkor();
		drugi_igrac.setSkor();
		}
	   else if(prvi_igrac.getKlikovi() < drugi_igrac.getKlikovi()){
		RezultatText->Text="Igrac 2 je pobjedio";
		drugi_igrac.setSkor(); // postavljano skor podjelom klikova sa 3
		prvi_igrac.setSkor();
		}
	   else{
		RezultatText->Text="Nerijeseno";
        prvi_igrac.setSkor();
		drugi_igrac.setSkor();
	   }
	}
}
//---------------------------------------------------------------------------



void __fastcall TKlikForma::Timer1Timer(TObject *Sender)
{
	TDateTime Diff = Now() - StartTime1;  // funkcija za timer1
	Word Hour, Min, Sec, MSec;
	DecodeTime(Diff, Hour, Min, Sec, MSec);
	VrijemeText1->Text = String(Sec);
    sekunda1=Sec;
}
//---------------------------------------------------------------------------

void __fastcall TKlikForma::Timer2Timer(TObject *Sender)
{
	TDateTime Diff = Now() - StartTime2;  // funkcija za timer2
	Word Hour, Min, Sec, MSec;
	DecodeTime(Diff, Hour, Min, Sec, MSec);
	VrijemeText2->Text = String(Sec);
    sekunda2=Sec;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------






