//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
struct List
{
   List *Next;
   int isi;
};
List *Baru;
List *Awal=NULL;
List *Akhir=NULL;
List *Isikan;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::InputClick(TObject *Sender)
{
 int banyak;
 banyak=StrToInt(Edit1->Text);
 Edit1->Clear();
 Edit1->SetFocus();
 Input->Enabled=false;

 while (banyak>0)
    {
       Baru= new List;
       Baru->Next=NULL;
       Baru->isi=0;

       if (Awal==NULL)
          {
             Awal=Baru;
             Akhir=Baru;
             Isikan=Awal;
          }
       else
          {
             Nilai->Enabled=true;
             Akhir->Next=Baru;
             Akhir=Baru;
          }
       banyak--;
    }

 ListBox1->Clear();
 List *Tampil=Awal;
 while (Tampil!=NULL)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NilaiClick(TObject *Sender)
{
 int x=StrToInt(Edit1->Text);
 Isikan->isi=x;
 Isikan=Isikan->Next;

 if (Isikan==NULL)
    {
       Nilai->Enabled=false;
    }

 List *Tampil=Awal;
 ListBox1->Items->Clear();
 while (Tampil!=NULL)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
}
//---------------------------------------------------------------------------

