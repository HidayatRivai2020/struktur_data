//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
struct kotak
   {
      kotak *atas;
      kotak *bawah;
      kotak *kiri;
      kotak *kanan;
      int isi;
   };
kotak *A;
kotak *B;
kotak *C;
kotak *D;
kotak *E;
kotak *F;
kotak *G;
kotak *H;
kotak *I;
kotak *kosong;

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

void __fastcall TForm1::StartClick(TObject *Sender)
{

A=new kotak;
B=new kotak;
C=new kotak;
D=new kotak;
E=new kotak;
F=new kotak;
G=new kotak;
H=new kotak;
I=new kotak;

A->isi=1;
A->atas=NULL;
A->kiri=NULL;
A->kanan=B;
A->bawah=D;

B->isi=2;
B->atas=NULL;
B->kiri=A;
B->bawah=E;
B->kanan=C;

C->isi=3;
C->atas=NULL;
C->bawah=F;
C->kiri=B;
C->kanan=NULL;

D->isi=4;
D->atas=A;
D->bawah=G;
D->kiri=NULL;
D->kanan=E;

E->isi=5;
E->atas=B;
E->bawah=H;
E->kiri=D;
E->kanan=F;

F->isi=6;
F->atas=C;
F->bawah=I;
F->kiri=E;
F->kanan=NULL;

G->isi=7;
G->atas=D;
G->bawah=NULL;
G->kiri=NULL;
G->kanan=H;

H->isi=8;
H->atas=E;
H->bawah=NULL;
H->kiri=G;
H->kanan=I;

I->isi=0;
I->atas=F;
I->bawah=NULL;
I->kiri=H;
I->kanan=NULL;

kosong=I;

kotak *tampil, *tampil2;
tampil=A;
tampil2=tampil;
ListBox1->Clear();
for (tampil=A; tampil!=NULL; tampil=tampil->kanan)
   {
      for (tampil2=tampil; tampil2!=NULL; tampil2=tampil2->bawah)
         {
            ListBox1->Items->Add(tampil2->isi);
         }
   }
Start->Enabled=false;
Submit->Enabled=true;
UP->Enabled=true;
Left->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UPClick(TObject *Sender)
{
int temp;
temp=kosong->isi;
kosong->isi=kosong->atas->isi;
kosong->atas->isi=temp;
kosong=kosong->atas;

if (kosong->atas==NULL)
   {
      UP->Enabled=false;
      Down->Enabled=true;
   }
else
   {
      UP->Enabled=true;
      Down->Enabled=true;
   }
kotak *tampil, *tampil2;
tampil=A;
tampil2=tampil;
ListBox1->Clear();
for (tampil=A; tampil!=NULL; tampil=tampil->kanan)
   {
      for (tampil2=tampil; tampil2!=NULL; tampil2=tampil2->bawah)
         {
            ListBox1->Items->Add(tampil2->isi);
         }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RightClick(TObject *Sender)
{
int temp;
temp=kosong->isi;
kosong->isi=kosong->kanan->isi;
kosong->kanan->isi=temp;
kosong=kosong->kanan;

if (kosong->kanan==NULL)
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
tampil=A;
tampil2=tampil;
ListBox1->Clear();
for (tampil=A; tampil!=NULL; tampil=tampil->kanan)
   {
      for (tampil2=tampil; tampil2!=NULL; tampil2=tampil2->bawah)
         {
            ListBox1->Items->Add(tampil2->isi);
         }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LeftClick(TObject *Sender)
{
int temp;
temp=kosong->isi;
kosong->isi=kosong->kiri->isi;
kosong->kiri->isi=temp;
kosong=kosong->kiri;

if (kosong->kiri==NULL)
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
tampil=A;
tampil2=tampil;
ListBox1->Clear();
for (tampil=A; tampil!=NULL; tampil=tampil->kanan)
   {
      for (tampil2=tampil; tampil2!=NULL; tampil2=tampil2->bawah)
         {
            ListBox1->Items->Add(tampil2->isi);
         }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DownClick(TObject *Sender)
{
int temp;
temp=kosong->isi;
kosong->isi=kosong->bawah->isi;
kosong->bawah->isi=temp;
kosong=kosong->bawah;

if (kosong->bawah==NULL)
   {
      Down->Enabled=false;
      UP->Enabled=true;
   }
else
   {
      Down->Enabled=true;
      UP->Enabled=true;
   }
kotak *tampil, *tampil2;
tampil=A;
tampil2=tampil;
ListBox1->Clear();
for (tampil=A; tampil!=NULL; tampil=tampil->kanan)
   {
      for (tampil2=tampil; tampil2!=NULL; tampil2=tampil2->bawah)
         {
            ListBox1->Items->Add(tampil2->isi);
         }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SubmitClick(TObject *Sender)
{
if (A->isi==1 && B->isi==2 && C->isi==3 && D->isi==4 && E->isi==5 && F->isi==6 && G->isi==7 && H->isi==8 && I->isi==0)
   {
      ShowMessage("Selamat, Anda Berhasil");
      Start->Enabled=true;
      Submit->Enabled=false;;
      UP->Enabled=false;
      Down->Enabled=false;
      Right->Enabled=false;
      Left->Enabled=false;
   }
else
   {
      ShowMessage("lanjutkan permainan");
   }
}
//---------------------------------------------------------------------------

