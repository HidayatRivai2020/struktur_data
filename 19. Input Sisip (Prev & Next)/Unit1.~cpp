//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
struct List
{
   List *Next;
   int isi;
   int posisi;
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
 Baru= new List;
 Baru->Next=NULL;
 Baru->isi=x;

 if (Awal==NULL)
    {
       Awal=Baru;
       Akhir=Baru;
       Awal->posisi=1;
       ListBox2->Items->Add(Awal->posisi);
       ListBox1->Items->Add(Awal->isi);
       Edit1->SetFocus();
    }
 else
    {
       Sisip->Enabled=true;
       Edit2->Enabled=true;
       Edit2->SetFocus();
       Input->Enabled=false;
       Edit1->Enabled=false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SisipClick(TObject *Sender)
{
 int x;
 x=StrToInt(Edit2->Text);
 Edit2->Clear();
 Baru->posisi=x;
 if (Baru->posisi<=0 || Baru->posisi>Akhir->posisi+1)
    {
       ShowMessage("posisi tidak ditemukan");
       Edit2->SetFocus();
    }
 else
    {
       if (Baru->posisi==Akhir->posisi+1)
          {
             Akhir->Next=Baru;
             Akhir=Baru;
          }
       else
          {
             List *Susun;
             if (Baru->posisi==1)
                {
                   Baru->Next=Awal;
                   Awal=Baru;
                   Susun=Awal;

                }
             else
                {
                   List *Cari=Awal;
                   while (Baru->posisi!=Cari->Next->posisi)
                      {
                         Cari=Cari->Next;
                      }
                   Baru->Next=Cari->Next;
                   Cari->Next=Baru;
                   Susun=Baru;

                }
             while (Susun!=Akhir)
                {
                   Susun=Susun->Next;
                   Susun->posisi=Susun->posisi+1;
                }
          }
        Input->Enabled=true;
        Edit1->Enabled=true;
        Edit1->SetFocus();
        Sisip->Enabled=false;
        Edit2->Enabled=false;
    }

 ListBox1->Clear();
 ListBox2->Clear();

 List *Tampil=Awal;
 while (Tampil!=NULL)
    {
       ListBox1->Items->Add(Tampil->isi);
       ListBox2->Items->Add(Tampil->posisi);
       Tampil=Tampil->Next;
    }
}
//---------------------------------------------------------------------------


