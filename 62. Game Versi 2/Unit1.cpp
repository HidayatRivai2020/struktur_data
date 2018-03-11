//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
struct kotak
   {
      kotak *Atas;
      kotak *Bawah;
      kotak *Kiri;
      kotak *Kanan;
      int isi;
   };
kotak *KiriAtas;
kotak *KananBawah;
kotak *Baru;
kotak *Awal=NULL;
kotak *Akhir=NULL;
kotak *temp;
kotak *Kosong;
int total, jumlah, a, A[24];


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
int x, z, n;
bool ketemu=false;
x=StrToInt(Edit1->Text);
Edit1->Clear();
Edit1->SetFocus();

if (x<0 || x>24)
   {
      ShowMessage("data tidak ditemukan");
   }
else
   {
      z=0, n=a;
      while (z<n && ketemu==false)
         {
            if (x==A[z])
               {
                  ketemu=true;
               }
            else
               {
                  z++;
               }
         }
      if (ketemu==false)
         {
            ShowMessage("data tidak ditemukan");
         }
      else
         {
            while (z<n)
               {
                  A[z]=A[z+1];
                  z++;
               }
            a--;

            Baru=new kotak;
            Baru->Atas=NULL;
            Baru->Bawah=NULL;
            Baru->Kiri=NULL;
            Baru->Kanan=NULL;
            Baru->isi=x;

            total++;

            if (total<=5)
               {
                  jumlah++;
                  if (Awal==NULL)
                     {
                        Awal=Baru;
                        Akhir=Baru;
                        temp=Awal;
                        KiriAtas=Awal;
                     }
                  else
                     {
                        Akhir->Bawah=Baru;
                        Baru->Atas=Akhir;
                        Akhir=Baru;
                     }
                  if (jumlah==5)
                     {
                        jumlah=0;
                     }
               }
            else
               {
                  jumlah++;
                  if (temp->Kanan==NULL)
                     {
                        temp->Kanan=Baru;
                        Awal=Baru;
                        Akhir=Baru;
                        Awal->Kiri=temp;
                     }
                  else
                     {
                        Akhir->Bawah=Baru;
                        Baru->Atas=Akhir;
                        Akhir=Baru;
                        temp=temp->Bawah;
                        temp->Kanan=Akhir;
                        Akhir->Kiri=temp;
                     }
               }
            if (jumlah==5)
               {
                  jumlah=0;
                  temp=Awal;
               }
         }
   }

if (total>=25)
   {
      ShowMessage("silahkan mulai permainan");
      Input->Enabled=false;
      Start->Enabled=true;
      kotak *CekKosong;
      CekKosong=KiriAtas;
      bool stop=false;

      while (CekKosong!=NULL && stop==false)
         {
            Kosong=CekKosong;
            while (Kosong!=NULL && stop==false)
               {
                  if (Kosong->isi==0)
                     {
                        stop=true;
                     }
                  else
                     {
                        Kosong=Kosong->Bawah;
                     }
               }
            CekKosong=CekKosong->Kanan;
         }
   }

kotak *tampil, *tampil2;
tampil2=KiriAtas;
ListBox1->Clear();

while (tampil2!=NULL)
   {
      tampil=tampil2;
      while (tampil!=NULL)
         {
            if (tampil==Kosong)
               {
                  ListBox1->Items->Add("");
               }
            else
               {
                  ListBox1->Items->Add(tampil->isi);
               }
            tampil=tampil->Bawah;
         }
      tampil2=tampil2->Kanan;
   }

ListBox2->Clear();
int d=0;
while (d<a)
   {
      ListBox2->Items->Add(A[d]);
      d++;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
while (a<25)
   {
      A[a]=a;
      ListBox2->Items->Add(A[a]);
      a++;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartClick(TObject *Sender)
{
Start->Enabled=false;
if (Kosong->Atas!=NULL)
   {
      Up->Enabled=true;
   }
if (Kosong->Bawah!=NULL)
   {
      Down->Enabled=true;
   }
if (Kosong->Kiri!=NULL)
   {
      Left->Enabled=true;
   }
if (Kosong->Kanan!=NULL)
   {
      Right->Enabled=true;
   }
Submit->Enabled=true;



}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpClick(TObject *Sender)
{
int temp;
temp=Kosong->isi;
Kosong->isi=Kosong->Atas->isi;
Kosong->Atas->isi=temp;
Kosong=Kosong->Atas;

if (Kosong->Atas==NULL)
   {
      Up->Enabled=false;
      Down->Enabled=true;
   }
else
   {
      Up->Enabled=true;
      Down->Enabled=true;
   }
kotak *tampil, *tampil2;
tampil2=KiriAtas;
ListBox1->Clear();

while (tampil2!=NULL)
   {
      tampil=tampil2;
      while (tampil!=NULL)
         {
            if (tampil==Kosong)
               {
                  ListBox1->Items->Add("");
               }
            else
               {
                  ListBox1->Items->Add(tampil->isi);
               }
            tampil=tampil->Bawah;
         }
      tampil2=tampil2->Kanan;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightClick(TObject *Sender)
{
int temp;
temp=Kosong->isi;
Kosong->isi=Kosong->Kanan->isi;
Kosong->Kanan->isi=temp;
Kosong=Kosong->Kanan;

if (Kosong->Kanan==NULL)
   {
      Right->Enabled=false;
      Left->Enabled=true;
   }
else
   {
      Right->Enabled=true;
      Left->Enabled=true;
   }
kotak *tampil, *tampil2;
tampil2=KiriAtas;
ListBox1->Clear();

while (tampil2!=NULL)
   {
      tampil=tampil2;
      while (tampil!=NULL)
         {
            if (tampil==Kosong)
               {
                  ListBox1->Items->Add("");
               }
            else
               {
                  ListBox1->Items->Add(tampil->isi);
               }
            tampil=tampil->Bawah;
         }
      tampil2=tampil2->Kanan;
   }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::LeftClick(TObject *Sender)
{
int temp;
temp=Kosong->isi;
Kosong->isi=Kosong->Kiri->isi;
Kosong->Kiri->isi=temp;
Kosong=Kosong->Kiri;

if (Kosong->Kiri==NULL)
   {
      Left->Enabled=false;
      Right->Enabled=true;
   }
else
   {
      Left->Enabled=true;
      Right->Enabled=true;
   }
kotak *tampil, *tampil2;
tampil2=KiriAtas;
ListBox1->Clear();

while (tampil2!=NULL)
   {
      tampil=tampil2;
      while (tampil!=NULL)
         {
            if (tampil==Kosong)
               {
                  ListBox1->Items->Add("");
               }
            else
               {
                  ListBox1->Items->Add(tampil->isi);
               }
            tampil=tampil->Bawah;
         }
      tampil2=tampil2->Kanan;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DownClick(TObject *Sender)
{
int temp;
temp=Kosong->isi;
Kosong->isi=Kosong->Bawah->isi;
Kosong->Bawah->isi=temp;
Kosong=Kosong->Bawah;

if (Kosong->Bawah==NULL)
   {
      Down->Enabled=false;
      Up->Enabled=true;
   }
else
   {
      Down->Enabled=true;
      Up->Enabled=true;
   }
kotak *tampil, *tampil2;
tampil2=KiriAtas;
ListBox1->Clear();

while (tampil2!=NULL)
   {
      tampil=tampil2;
      while (tampil!=NULL)
         {
            if (tampil==Kosong)
               {
                  ListBox1->Items->Add("");
               }
            else
               {
                  ListBox1->Items->Add(tampil->isi);
               }
            tampil=tampil->Bawah;
         }
      tampil2=tampil2->Kanan;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SubmitClick(TObject *Sender)
{
kotak *cek;
cek=KiriAtas;
kotak *cek2;
int y=1;
bool susun=true;

while (cek!=NULL && susun==true)
   {
      cek2=cek;
      while (cek2!=NULL && susun==true)
         {
            if (cek2->isi==y)
               {
                  y++;
                  cek2=cek2->Kanan;
                  if (y==25)
                     {
                        y=0;
                     }
               }
            else
               {
                  susun=false;
               }
         }
      cek=cek->Bawah;
   }
if (susun==true)
   {
      ShowMessage("selamat. puzzle telah tersusun");
      Up->Enabled=false;
      Down->Enabled=false;
      Left->Enabled=false;
      Right->Enabled=false;
      Submit->Enabled=false;
      Start->Enabled=true;
   }
else
   {
      ShowMessage("silahkan lanjutkan permainan");
   }
}
//---------------------------------------------------------------------------
