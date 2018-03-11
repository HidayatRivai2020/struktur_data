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
bool atas=true;
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
    }
 else
    {
       if (atas==true)
          {
             Baru->Next=Awal;
             Awal=Baru;
             Akhir->Next=Awal;
             atas=false;
          }
       else
          {
             Akhir->Next=Baru;
             Akhir=Baru;
             Akhir->Next=Awal;
             atas=true;
          }
    }
 A->Enabled=true;
 V->Enabled=true;

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
void __fastcall TForm1::AClick(TObject *Sender)
{
 Akhir=Awal;
 Awal=Akhir->Next;

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

void __fastcall TForm1::VClick(TObject *Sender)
{
 List *Cari=Awal;
 while (Cari->Next!=Akhir)
    {
        Cari=Cari->Next;
    }
 Akhir=Cari;
 Awal=Akhir->Next;

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

