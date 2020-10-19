object Form1: TForm1
  Left = 192
  Top = 114
  Width = 324
  Height = 189
  Caption = 
    'Sudo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 49
    Top = 12
    Width = 10
    Height = 13
    Caption = 'A:'
  end
  object Label2: TLabel
    Left = 49
    Top = 36
    Width = 10
    Height = 13
    Caption = 'B:'
  end
  object Label3: TLabel
    Left = 8
    Top = 108
    Width = 50
    Height = 13
    Caption = 'Eredmény:'
  end
  object Label4: TLabel
    Left = 8
    Top = 132
    Width = 45
    Height = 13
    Caption = 'Maradék:'
  end
  object Edit1: TEdit
    Left = 64
    Top = 8
    Width = 242
    Height = 21
    TabOrder = 0
    Text = '11000011110001001'
  end
  object Edit2: TEdit
    Left = 64
    Top = 32
    Width = 242
    Height = 21
    TabOrder = 1
    Text = '11111111111'
  end
  object Button1: TButton
    Left = 81
    Top = 64
    Width = 33
    Height = 25
    Caption = 'A+B'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 121
    Top = 64
    Width = 33
    Height = 25
    Caption = 'A-B'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 161
    Top = 64
    Width = 33
    Height = 25
    Caption = 'A*B'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 201
    Top = 64
    Width = 33
    Height = 25
    Caption = 'A/B'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Edit3: TEdit
    Left = 64
    Top = 104
    Width = 242
    Height = 21
    TabOrder = 6
  end
  object Edit4: TEdit
    Left = 64
    Top = 128
    Width = 242
    Height = 21
    TabOrder = 7
  end
  object BINOperation1: TBINOperation
    Left = 8
    Top = 8
  end
end
