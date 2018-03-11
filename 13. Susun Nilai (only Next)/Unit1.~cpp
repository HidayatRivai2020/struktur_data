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
 Edit1->Clear();
 Edit1->SetFocus();
 Baru= new List;
 Baru->Next=NULL;
 Baru->isi=x;

 if (Awal==NULL)
    {
       Awal=Baru;
       Akhir=Baru;
    }
 else
    {
       Susun->Enabled=true;
       Akhir->Next=Baru;
       Akhir=Baru;
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
void __fastcall TForm1::SusunClick(TObject *Sender)
{
 List *Rapi=Awal, *Kecil, *Banding;
 int temp;

 while (Rapi->Next!=NULL)
    {
       Kecil=Rapi;
       Banding=Kecil->Next;
       while (Banding!=NULL)
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
 while (Tampil!=NULL)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
}
//---------------------------------------------------------------------------

