//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
           \
#include "Unit1.h"
int totalkupas, xgudang, xpindah, tamu, pesanan, tamukeluar;
bool belumbuka=true;
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

void __fastcall TForm1::BukaClick(TObject *Sender)
{
if (xgudang<1000)
   {
      ShowMessage("gudang belum cukup");
      Buka->Enabled=false;
      Beli->Enabled=true;
      Edit1->Enabled=true;
   }
else
   {
      Bakul->Enabled=true;
      Edit2->Enabled=true;
      Buka->Enabled=false;
      belumbuka=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BeliClick(TObject *Sender)
{
int x;
x=StrToInt(Edit1->Text);
Edit1->Clear();
xgudang=xgudang+x;
Edit3->Text=xgudang;
if (belumbuka==true)
   {
      Buka->Enabled=true;
      Beli->Enabled=false;
      Edit1->Enabled=false;
   }
else
   {
      Bakul->Enabled=true;
      Edit2->Enabled=true;
      Beli->Enabled=false;
      Edit1->Enabled=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BakulClick(TObject *Sender)
{
int x;
x=StrToInt(Edit2->Text);
Edit2->Clear();
if (x>xgudang)
   {
      ShowMessage("Beli Kentang dulu");
      Beli->Enabled=true;
      Edit1->Enabled=true;
      Bakul->Enabled=false;
      Edit2->Enabled=false;
   }
else
   {
      xgudang=xgudang-x;
      Edit3->Text=xgudang;
      xpindah=xpindah+x;
      Edit4->Text=xpindah;
      Bakul->Enabled=false;
      Edit2->Enabled=false;
      Kupas->Enabled=true;
      Edit5->Enabled=true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::KupasClick(TObject *Sender)
{
list *tampil;
int x;
x=StrToInt(Edit5->Text);
Edit5->Clear();
if (x>xpindah)
   {
      ShowMessage("ambil kentang dari gudang");
      Kupas->Enabled=false;
      Edit5->Enabled=false;
      Bakul->Enabled=true;
      Edit2->Enabled=true;
   }
else
   {
      baru=new list;
      baru->next=NULL;
      baru->prev=NULL;
      baru->isi=x;

      if (awal==NULL)
         {
            awal=baru;
            akhir=baru;
         }
      else
         {
            if (baru->isi<=awal->isi)
               {
                  awal->prev=baru;
                  baru->next=awal;
                  awal=baru;
               }
            else if (baru->isi>=akhir->isi)
               {
                  akhir->next=baru;
                  baru->prev=akhir;
                  akhir=baru;
               }
            else
               {
                  cari=akhir;
                  while (baru->isi<cari->isi)
                     {
                        cari=cari->prev;
                     }
                  cari->next->prev=baru;
                  baru->next=cari->next;
                  cari->next=baru;
                  baru->prev=cari;
               }
         }
      ListBox1->Items->Clear();
      for (tampil=awal;tampil!=NULL;tampil=tampil->next)
         {
            ListBox1->Items->Add(tampil->isi);
         }
      xpindah=xpindah-x;
      Edit4->Text=xpindah;
      totalkupas=totalkupas+x;
      Edit6->Text=totalkupas;
      if (xpindah==0)
         {
            Datang->Enabled=true;
            Kupas->Enabled=false;
            Edit5->Enabled=false;
            if (tamu>0)
               {
                  Keluar->Enabled=true;
               }
         }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CekClick(TObject *Sender)
{
list *tampil;
tampil=awal;
cek1->Clear();
cek2->Clear();
cek3->Clear();
if (awal!=NULL && akhir!=NULL)
   {
      cek1->Items->Add(awal->isi);
      cek2->Items->Add(akhir->isi);
      for (tampil=awal;tampil!=NULL;tampil=tampil->next)
         {
            cek3->Items->Add(tampil->isi);
         }
   }
else
   {
      ShowMessage("data kosong");
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DatangClick(TObject *Sender)
{
tamu++;
Edit7->Text=tamu;
Pesan->Enabled=true;
Edit8->Enabled=true;
Datang->Enabled=false;
Batal->Enabled=true;
Keluar->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PesanClick(TObject *Sender)
{
list *a;
int x, masak;
x=StrToInt(Edit8->Text);
Edit8->Clear();
if (x>totalkupas)
   {
      ShowMessage("kupas kurang");
      tamu--;
      Pesan->Enabled=false;
      Edit8->Enabled=false;
      Edit7->Text=tamu;
      Datang->Enabled=false;
      Bakul->Enabled=true;
      Edit2->Enabled=true;
      Batal->Enabled=false;
   }
else
   {
      if (x<=akhir->isi)
         {
            cari=awal;
            while (cari->isi<x)
               {
                  cari=cari->next;
               }

            if (x==cari->isi)
               {
                  ShowMessage("data ketemu");
                  if (cari==awal && awal==akhir)
                     {
                        awal=NULL;
                        akhir=NULL;
                     }
                  else
                     {
                        if (cari==akhir)
                           {
                              akhir=akhir->prev;
                              akhir->next=NULL;
                           }
                        else if (cari==awal)
                           {
                              awal=awal->next;
                              awal->prev=NULL;
                           }
                        else
                           {
                              cari->next->prev=cari->prev;
                              cari->prev->next=cari->next;
                           }
                     }
                  ListBox2->Items->Add(x);
                  totalkupas=totalkupas-x;
                  Edit6->Text=totalkupas;
                  Pesan->Enabled=false;
                  Edit8->Enabled=false;
                  Datang->Enabled=true;
                  Batal->Enabled=false;
               }
            else
               {
                  ShowMessage("data tidak ditemukan");
                  Batal->Click();
               }
         }
      else
         {
            ShowMessage("data tidak ditemukan");
            Batal->Click();
         }

      if (tamu>0)
         {
            Keluar->Enabled=true;
         }
      else
         {
            Keluar->Enabled=false;
            Tutup->Enabled=true;
         }

      ListBox1->Clear();
      for (a=awal;a!=NULL;a=a->next)
         {
            ListBox1->Items->Add(a->isi);
         }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BatalClick(TObject *Sender)
{
Pesan->Enabled=false;
Edit8->Enabled=false;
tamu--;
Batal->Enabled=false;
Datang->Enabled=true;
Edit7->Text=tamu;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::KeluarClick(TObject *Sender)
{
tamukeluar++;
Edit9->Text=tamukeluar;
tamu--  ;
if (tamu==0)
   {
      Keluar->Enabled=false;
      Tutup->Enabled=true;
   }
Edit7->Text=tamu;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TutupClick(TObject *Sender)
{

if (tamu==0)
   {
      Application->Terminate();
   }
else
   {
      ShowMessage("tamu masih ada");
   }

}
//---------------------------------------------------------------------------





