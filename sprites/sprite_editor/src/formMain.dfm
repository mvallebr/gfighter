object frmMain: TfrmMain
  Left = 255
  Top = 332
  Width = 587
  Height = 376
  Caption = 'PCFighter Sprite Editor'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000BBBBBBBB0000000000000000
    00000BBBBBBBBBBBBBB00000000000000000BBBBBBBBBBBBBBBB000000000000
    00BBBBBBBBBBBBBBBBBBBB00000000000BBBBBBBBB0000BBBBBBBBB000000000
    BBBBBBBBB099990BBBBBBBBB00000000BBBBBBBB09999990BBBBBBBB0000000B
    BBBBBBB0900000090BBBBBBBB00000BBBBBBBB000BBBBBB000BBBBBBBB0000BB
    BBBBB00BBBBBBBBBB00BBBBBBB0000BBBBBBB0BBBBBBBBBBBB0BBBBBBB000BBB
    BBBB0BBBBBBBBBBBBBB0BBBBBBB00BBB0000BBBBBBBBBBBBBBBB0000BBB00BBB
    BBB0BBBBBBBBBBBBBBBB0BBBBBB00BBBBBBB0BBBBBBBBBBBBBB0BBBBBBB00BBB
    BBBB0BBBBBBBBBBBBBB0BBBBBBB00BBBBBBBBBB00BBBBBB00BBBBBBBBBB00BBB
    BBBBBB0000BBBB0000BBBBBBBBB00BBBBBBBBB0000BBBB0000BBBBBBBBB000BB
    BBBBBB0000BBBB0000BBBBBBBB0000BBBBBBBB0000BBBB0000BBBBBBBB0000BB
    BBBBBB0000BBBB0000BBBBBBBB00000BBBBBBBB00BBBBBB00BBBBBBBB0000000
    BBBBBBBBBBBBBBBBBBBBBBBB00000000BBBBBBBBBBBBBBBBBBBBBBBB00000000
    0BBBBBBBBBBBBBBBBBBBBBB00000000000BBBBBBBBBBBBBBBBBBBB0000000000
    0000BBBBBBBBBBBBBBBB00000000000000000BBBBBBBBBBBBBB0000000000000
    00000000BBBBBBBB00000000000000000000000000000000000000000000FFF0
    0FFFFF8001FFFE00007FFC00003FF800001FF000000FE0000007C0000003C000
    0003800000018000000180000001000000000000000000000000000000000000
    0000000000000000000000000000800000018000000180000001C0000003C000
    0003E0000007F000000FF800001FFC00003FFE00007FFF8001FFFFF00FFF}
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 579
    Height = 322
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Actions'
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 177
        Height = 294
        Align = alLeft
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Inputs'
      ImageIndex = 1
    end
    object TabSheet3: TTabSheet
      Caption = 'States'
      ImageIndex = 2
    end
    object TabSheet4: TTabSheet
      Caption = 'Triggers'
      ImageIndex = 3
    end
  end
  object MainMenu1: TMainMenu
    Left = 544
    Top = 16
    object Sprite1: TMenuItem
      Caption = 'Sprite'
      object Properties1: TMenuItem
        Caption = 'Properties'
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'E&xit'
        OnClick = Exit1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object About1: TMenuItem
        Caption = 'About'
      end
    end
  end
end
