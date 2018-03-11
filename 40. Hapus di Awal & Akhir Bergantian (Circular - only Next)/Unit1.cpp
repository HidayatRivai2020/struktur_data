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
    }
 else
    {
       Akhir->Next=Baru;
       Akhir=Baru;
       Akhir->Next=Awal;
    }
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
void __fastcall TForm1::HapusClick(TObject *Sender)
{
 List *A=Awal;
 if (Awal==Akhir)
    {
       Awal=NULL;
       Akhir=NULL;
    }
 else
    {
       if (atas==true)
          {
             Awal=A->Next;
             Akhir->Next=NULL;
             Akhir->Next=Awal;
             atas=false;
          }
       else
          {
             while (A->Next!=Akhir)
                {
                    A=A->Next;
                }
             Akhir=A;
             Akhir->Next=NULL;
             Akhir->Next=Awal;
             atas=true;
          }
    }

 if (Akhir==NULL && Awal==NULL)
    {
       Hapus->Enabled=false;
    }


 List *Tampil=Awal;
 ListBox1->Clear();
 if (Awal!=NULL)
    {
       while (Tampil!=Akhir)
          {
             ListBox1->Items->Add(Tampil->isi);
             Tampil=Tampil->Next;
          }
       ListBox1->Items->Add(Akhir->isi);
    }
}
//---------------------------------------------------------------------------


