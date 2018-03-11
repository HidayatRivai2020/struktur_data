//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
struct List
   {
      List *Next;
      List *Prev;
      int selisih;
      int isi;
   };
List *Awal=NULL;
List *Akhir=NULL;
List *Baru;

int n, total;
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

 Baru = new List;
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
       Awal->Prev=Baru;
       Baru->Next=Awal;
       Awal=Baru;
    }

 total=total+x;
 Edit2->Text=total;

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
int x;
x=StrToInt(Edit1->Text);

if (x>total)
   {
      ShowMessage("pesanan terlalu banyak");
   }
else
   {
      List *Beda=Awal;
      int x2;
      total=total-x;
      while (x>0)
         {
            while (Beda!=NULL)
               {
                  x2=x;
                  if (x2>=Beda->isi)
                     {
                        x2=x2-Beda->isi;
                     }
                  else
                     {
                        x2=Beda->isi-x2;
                     }
                  Beda->selisih=x2;
                  Beda=Beda->Next;
               }

            List *Min=Awal, *Banding=Awal->Next;
            while (Banding!=NULL)
               {
                  if (Min->selisih>Banding->selisih)
                     {
                        Min=Banding;
                     }
                  Banding=Banding->Next;
               }

            if (x>=Min->isi)
               {
                  x=x-Min->isi;
                  if (Min==Awal && Min==Akhir)
                     {
                        Awal=NULL;
                        Akhir=NULL;
                     }
                  else
                     {
                        if (Min==Awal)
                           {
                              Awal=Awal->Next;
                              Awal->Prev=NULL;
                           }
                        else if (Min==Akhir)
                           {
                              Akhir=Akhir->Prev;
                              Akhir->Next=NULL;
                           }
                        else
                           {
                              Min->Prev->Next=Min->Next;
                              Min->Next->Prev=Min->Prev;
                           }
                     }
               }
            else
               {
                  Min->isi=Min->isi-x;
                  x=0;
               }
         }
      Edit2->Text=total;
      if (Awal==NULL)
         {
            Hapus->Enabled=false;
         }

      ListBox1->Clear();
      List *Tampil=Awal;
      while (Tampil!=NULL)
         {
            ListBox1->Items->Add(Tampil->isi);
            Tampil=Tampil->Next;
         }
   }
}
//---------------------------------------------------------------------------

