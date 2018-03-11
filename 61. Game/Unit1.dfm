object Form1: TForm1
  Left = 192
  Top = 124
  Width = 668
  Height = 546
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
    Left = 392
    Top = 16
    Width = 210
    Height = 32
    Caption = 'Hidayat Riva'#39'i'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 448
    Top = 56
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
  object Label3: TLabel
    Left = 128
    Top = 40
    Width = 121
    Height = 30
    Caption = 'PUZZLE'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Copperplate Gothic Bold'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 48
    Top = 424
    Width = 82
    Height = 74
    Caption = 'Jack'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -64
    Font.Name = 'Chiller'
    Font.Style = []
    ParentFont = False
  end
  object Start: TButton
    Left = 32
    Top = 16
    Width = 75
    Height = 73
    Caption = 'Start'
    TabOrder = 0
    OnClick = StartClick
  end
  object ListBox1: TListBox
    Left = 120
    Top = 96
    Width = 401
    Height = 313
    Columns = 3
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -80
    Font.Name = 'Bookman Old Style'
    Font.Style = []
    ItemHeight = 90
    ParentFont = False
    TabOrder = 1
  end
  object UP: TButton
    Left = 272
    Top = 16
    Width = 75
    Height = 65
    Caption = 'UP'
    Enabled = False
    TabOrder = 2
    OnClick = UPClick
  end
  object Down: TButton
    Left = 280
    Top = 424
    Width = 83
    Height = 65
    Caption = 'Down'
    Enabled = False
    TabOrder = 3
    OnClick = DownClick
  end
  object Left: TButton
    Left = 24
    Top = 200
    Width = 83
    Height = 81
    Caption = 'Left'
    Enabled = False
    TabOrder = 4
    OnClick = LeftClick
  end
  object Right: TButton
    Left = 536
    Top = 208
    Width = 81
    Height = 81
    Caption = 'Right'
    Enabled = False
    TabOrder = 5
    OnClick = RightClick
  end
  object Submit: TButton
    Left = 536
    Top = 416
    Width = 75
    Height = 73
    Caption = 'Submit'
    Enabled = False
    TabOrder = 6
    OnClick = SubmitClick
  end
end
