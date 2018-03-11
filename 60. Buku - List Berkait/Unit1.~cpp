//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
struct list
   {
      list *next;
      list *prev;
      int isi;
   };
list *awal=NULL;
list *akhir=NULL;
list *baru;
list *cari;

struct kotak
   {
      kotak *kiri;
      kotak *kanan;
      int nilai;
   };
kotak *puncak=NULL;
kotak *dasar=NULL;
kotak *pindah;

int jumlah, i=9, k=9;
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
void __fastcall TForm1::MasukkanClick(TObject *Sender)
{
int x;
if (jumlah==10)
   {
      ShowMessage("rak penuh");
      Masukkan->Enabled=false;
   }
else
   {
      x=StrToInt(Edit1->Text);
      Edit1->Clear();
      Edit1->SetFocus();
      i--;
      jumlah++;

      baru = new list;
      baru->next=NULL;
      baru->prev=NULL;
      baru->isi=x;

      if (akhir==NULL)
         {
            awal=baru;
            akhir=baru;
         }
      else
         {
            awal->prev=baru;
            baru->next=awal;
            awal=baru;
         }
   }

if (jumlah>0)
   {
      Cari->Enabled=true;
   }

list *tampil;
int a=0, kosong=0;
ListBox1->Items->Clear();
while (a<=i)
   {
       ListBox1->Items->Add(kosong);
       a++;
   }

for (tampil=awal;tampil!=NULL;tampil=tampil->next)
   {
      ListBox1->Items->Add(tampil->isi);
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CariClick(TObject *Sender)
{
int x;
bool ketemu=false;

x=StrToInt(Edit1->Text);
Edit1->Clear();
cari=akhir;
while (cari!=NULL && ketemu==false)
   {
      if (cari->isi==x)
         {
            ketemu=true;
         }
      else
         {
            cari=cari->prev;
         }
   }
if (ketemu==true)
   {
      ShowMessage("data ditemukan");
      Keluarkan->Enabled=true;
      Cari->Enabled=false;
      Masukkan->Enabled=false;
   }
else
   {
      ShowMessage("data tidak ditemukan");
   }

ListBox2->Clear();
int b=0, kosong=0;
kotak *show;
while (b<=k)
   {
       ListBox2->Items->Add(kosong);
       b++;
   }
for (show=puncak;show!=NULL;show=show->kanan)
   {
      ListBox2->Items->Add(show->nilai);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::KeluarkanClick(TObject *Sender)
{
list *tampil;
kotak *show;
int a=0, b=0, kosong=0;
ListBox1->Items->Clear();
ListBox2->Items->Clear();

if (awal!=cari)
   {
      pindah = new kotak;
      pindah->kiri=NULL;
      pindah->kanan=NULL;
      pindah->nilai=awal->isi;

      if (dasar==NULL)
         {
            dasar=pindah;
            puncak=pindah;
         }
      else
         {
            puncak->kiri=pindah;
            pindah->kanan=puncak;
            puncak=pindah;
         }
      awal=awal->next;
      awal->prev=NULL;
      i++;
      jumlah--;
      k--;
   }
else
   {
      if (awal==akhir)
         {
            awal=NULL;
            akhir=NULL;
            i++;
            jumlah--;

            ShowMessage("Keluarkan buku");
            Keluarkan->Enabled=false;
            Susun->Enabled=true;
         }
      else
         {
            ShowMessage("keluarkan buku");
            awal=awal->next;
            awal->prev=NULL;
            i++;
            jumlah--;
            Keluarkan->Enabled=false;
            Susun->Enabled=true;
         }
   }
while (a<=i)
   {
      ListBox1->Items->Add(kosong);
      a++;
   }
for (tampil=awal;tampil!=NULL;tampil=tampil->next)
   {
      ListBox1->Items->Add(tampil->isi);
   }
while (b<=k)
   {
      ListBox2->Items->Add(kosong);
      b++;
   }
for (show=puncak;show!=NULL;show=show->kanan)
   {
      ListBox2->Items->Add(show->nilai);
   }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::SusunClick(TObject *Sender)
{
list *tampil;
kotak *show;
int a=0, b=0, kosong=0;
ListBox1->Items->Clear();
ListBox2->Items->Clear();

if (dasar==NULL)
   {
      ShowMessage("buku yang akan disusun kosong");
      Susun->Enabled=false;
      Masukkan->Enabled=true;
      if (jumlah>0)
         {
            Cari->Enabled=true;
         }
      else
         {
            Cari->Enabled=false;
         }
   }
else
   {
      baru=new list;
      baru->isi=puncak->nilai;
      baru->next=NULL;
      baru->prev=NULL;

      if (puncak!=dasar)
         {

            if (awal==NULL)
               {
                  awal=baru;
                  akhir=baru;

                  puncak=puncak->kanan;
                  puncak->kiri=NULL;
                  k++;
                  i--;
                  jumlah++;
               }
            else
               {
                  awal->prev=baru;
                  baru->next=awal;
                  awal=baru;

                  puncak=puncak->kanan;
                  puncak->kiri=NULL;
                  k++;
                  i--;
                  jumlah++;
               }
          }
      else
          {
             if (awal==NULL)
               {
                  awal=baru;
                  akhir=baru;

                  puncak=NULL;
                  dasar=NULL;
                  k++;
                  i--;
                  jumlah++;
               }
             else
               {
                  awal->prev=baru;
                  baru->next=awal;
                  awal=baru;


                  puncak=NULL;
                  dasar=NULL;
                  k++;
                  i--;
                  jumlah++;
               }
          }
   }
while (a<=i)
   {
      ListBox1->Items->Add(kosong);
      a++;
   }
for (tampil=awal;tampil!=NULL;tampil=tampil->next)
   {
      ListBox1->Items->Add(tampil->isi);
   }
while (b<=k)
   {
      ListBox2->Items->Add(kosong);
      b++;
   }
for (show=puncak;show!=NULL;show=show->kanan)
   {
      ListBox2->Items->Add(show->nilai);
   }
}
//---------------------------------------------------------------------------




