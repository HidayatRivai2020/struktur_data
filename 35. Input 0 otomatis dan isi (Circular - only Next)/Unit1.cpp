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
bool stop=false;
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
             Akhir->Next=Awal;
          }
       banyak--;
    }

 ListBox1->Clear();
 List *Tampil=Awal;
 while (Tampil!=Akhir)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
 ListBox1->Items->Add(Akhir->isi);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NilaiClick(TObject *Sender)
{
 int x=StrToInt(Edit1->Text);
 if (stop==true)
    {
       ShowMessage("data sudah terisikan semua");
       Nilai->Enabled=false;
    }
 Edit1->Clear();
 Edit1->SetFocus();
 Isikan->isi=x;
 Isikan=Isikan->Next;

 if (Isikan==Akhir)
    {
        stop=true;
    }

 ListBox1->Clear();
 List *Tampil=Awal;
 while (Tampil!=Akhir)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
 ListBox1->Items->Add(Akhir->isi);
}
//---------------------------------------------------------------------------

