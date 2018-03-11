object Form1: TForm1
  Left = 335
  Top = 156
  Width = 517
  Height = 387
  Caption = 'Form1'
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 312
    Width = 44
    Height = 28
    Caption = 'Jack'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Jokerman'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 40
    Top = 24
    Width = 168
    Height = 24
    Caption = 'Memindahkan Buku'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 176
    Top = 88
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Masukkan: TButton
    Left = 200
    Top = 120
    Width = 75
    Height = 25
    Caption = 'Masukkan'
    TabOrder = 1
    OnClick = MasukkanClick
  end
  object ListBox1: TListBox
    Left = 40
    Top = 88
    Width = 121
    Height = 201
    ItemHeight = 13
    TabOrder = 2
  end
  object Cari: TButton
    Left = 200
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Cari'
    Enabled = False
    TabOrder = 3
    OnClick = CariClick
  end
  object Keluarkan: TButton
    Left = 200
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Keluarkan'
    Enabled = False
    TabOrder = 4
    OnClick = KeluarkanClick
  end
  object Susun: TButton
    Left = 200
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Susun'
    Enabled = False
    TabOrder = 5
    OnClick = SusunClick
  end
  object ListBox2: TListBox
    Left = 312
    Top = 88
    Width = 121
    Height = 209
    ItemHeight = 13
    TabOrder = 6
  end
  object GroupBox1: TGroupBox
    Left = 248
    Top = 8
    Width = 201
    Height = 65
    TabOrder = 7
    object Label3: TLabel
      Left = 17
      Top = 8
      Width = 168
      Height = 24
      Caption = 'Hidayat Riva'#39'i'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 41
      Top = 33
      Width = 120
      Height = 24
      Caption = '1210962025'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
    end
  end
end
