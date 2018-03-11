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
 Edit1->Text=0;
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
       Baru->Next=Awal;
       Awal=Baru;
       Akhir->Next=Awal;
    }
 A->Enabled=true;
 V->Enabled=true;
 Hapus->Enabled=true;

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
 List *A=Awal;
 while (A->Next!=Akhir)
    {
       A=A->Next;
    }
 Awal=Akhir;
 Akhir=A;

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

void __fastcall TForm1::AClick(TObject *Sender)
{
 Akhir=Awal;
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


void __fastcall TForm1::HapusClick(TObject *Sender)
{
 int x;
 x=StrToInt(Edit1->Text);
 List *Cari=Awal;
 bool ketemu=false;

 while (Cari!=Akhir)
     {
       if (x==Cari->isi)
          {
             ketemu=true;
             if (Cari==Awal)
                {
                   Awal=Awal->Next;
                   Akhir->Next=Awal;
                }
             else
                {
                   List *B=Awal;
                   while (B->Next!=Cari)
                      {
                         B=B->Next;
                      }

                   B->Next=Cari->Next;
                }
          }
       Cari=Cari->Next;
    }

 if (x==Akhir->isi)
    {
       ketemu=true;
       if (Awal==Akhir)
          {
             Awal=NULL;
             Akhir=NULL;
             Hapus->Enabled=false;
             ketemu=true;
          }
       else
          {
             List *B=Awal;
             while (B->Next!=Akhir)
                {
                   B=B->Next;
                }

             Akhir=B;
             Akhir->Next=Awal;
          }
    }

 if (ketemu==false)
    {
       ShowMessage("data tidak ditemukan");
    }

 List *Tampil=Awal;
 ListBox1->Clear();
 if (Akhir!=NULL)
    {
       while (Tampil!=Akhir)
          {
             ListBox1->Items->Add(Tampil->isi);
             Tampil=Tampil->Next;
          }
       ListBox1->Items->Add(Akhir->isi);
    }
  else
    {
       Hapus->Enabled=false;
       A->Enabled=false;
       V->Enabled=false;
    }
}
//---------------------------------------------------------------------------

