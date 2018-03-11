//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
struct List
{
   List *Next;
   List *Prev;
   int isi;
};
List *Baru;
List *Awal=NULL;
List *Akhir=NULL;
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
 int x;
 x=StrToInt(Edit1->Text);
 Edit1->Clear();
 Edit1->SetFocus();
 Baru= new List;
 Baru->Next=NULL;
 Baru->isi=x;

 if (Awal==NULL)
    {
       Awal=Baru;
       Akhir=Baru;
       Akhir->Next=Awal;
       Awal->Prev=Akhir;
    }
 else
    {
       Susun->Enabled=true;
       Akhir->Next=Baru;
       Baru->Prev=Akhir;
       Akhir=Baru;
       Akhir->Next=Awal;
       Awal->Prev=Akhir;
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
void __fastcall TForm1::SusunClick(TObject *Sender)
{
 List *Rapi=Awal, *Kecil, *Banding;
 int temp;

 while (Rapi!=Akhir)
    {
       Kecil=Rapi;
       Banding=Kecil->Next;
       while (Banding!=Awal)
          {
             if (Kecil->isi>Banding->isi)
                {
                   Kecil=Banding;
                }
             Banding=Banding->Next;
          }
       temp=Rapi->isi;
       Rapi->isi=Kecil->isi;
       Kecil->isi=temp;
       Rapi=Rapi->Next;
    }
 List *Tampil=Awal;
 ListBox1->Items->Clear();
 while (Tampil!=Akhir)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
 ListBox1->Items->Add(Akhir->isi);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AClick(TObject *Sender)
{
 Akhir=Akhir->Next;
 Awal=Awal->Next;

 List *Tampil=Awal;
 ListBox1->Clear();
 while (Tampil!=Akhir)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
 ListBox1->Items->Add(Akhir->isi);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VClick(TObject *Sender)
{
 List *Cari=Awal;
 while (Cari->Next!=Akhir)
    {
       Cari=Cari->Next;
    }
 Awal=Akhir;
 Akhir=Cari;

 List *Tampil=Awal;
 ListBox1->Clear();
 while (Tampil->Next!=Awal)
    {
        ListBox1->Items->Add(Tampil->isi);
        Tampil=Tampil->Next;
    }

}
//---------------------------------------------------------------------------

