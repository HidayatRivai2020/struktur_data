//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
struct List
{
   List *Prev;
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


void __fastcall TForm1::Button1Click(TObject *Sender)
{
 int x;
 x=StrToInt(Edit1->Text);
 Edit1->Clear();
 Edit1->SetFocus();
 Baru= new List;
 Baru->Next=NULL;
 Baru->Prev=NULL;
 Baru->isi=x;

 if (Awal==NULL)
    {
       Awal=Baru;
       Akhir=Baru;
    }
 else
    {
       if (Baru->isi>=Awal->isi)
          {
             Baru->Next=Awal;
             Awal->Prev=Baru;
             Awal=Baru;
          }
       else if (Baru->isi<=Akhir->isi)
          {
             Akhir->Next=Baru;
             Baru->Prev=Akhir;
             Akhir=Baru;
          }
       else
          {
             List *Cari=Awal->Next;
             while (Baru->isi<Cari->isi)
                {
                   Cari=Cari->Next;
                }
             Baru->Next=Cari;
             Baru->Prev=Cari->Prev;
             Cari->Prev->Next=Baru;
             Cari->Prev=Baru;

          }
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
