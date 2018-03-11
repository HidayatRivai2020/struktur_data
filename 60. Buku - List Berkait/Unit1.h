//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TButton *Masukkan;
        TListBox *ListBox1;
        TButton *Cari;
        TButton *Keluarkan;
        TButton *Susun;
        TListBox *ListBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TGroupBox *GroupBox1;
        void __fastcall MasukkanClick(TObject *Sender);
        void __fastcall CariClick(TObject *Sender);
        void __fastcall KeluarkanClick(TObject *Sender);
        void __fastcall SusunClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
