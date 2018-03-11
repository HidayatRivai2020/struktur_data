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
 Baru->Prev=NULL;
 Baru->isi=x;

 if (Awal==NULL)
    {
       Awal=Baru;
       Akhir=Baru;
    }
 else
    {
       Akhir->Next=Baru;
       Baru->Prev=Akhir;
       Akhir=Baru;
    }
 Hapus->Enabled=true;

 ListBox1->Clear();
 List *Tampil=Awal;
 while (Tampil!=NULL)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::HapusClick(TObject *Sender)
{
 if (Awal==Akhir)
    {
       Awal=NULL;
       Akhir=NULL;
    }
 else
    {
       if (atas==true)
          {
             Awal=Awal->Next;
             Awal->Prev=NULL;
             atas=false;
          }
       else
          {
             Akhir=Akhir->Prev;
             Akhir->Next=NULL;
             atas=true;
          }
    }

 if (Awal==NULL)
    {
       Hapus->Enabled=false;
    }


 List *Tampil=Awal;
 ListBox1->Clear();
 while (Tampil!=NULL)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
}
//---------------------------------------------------------------------------

