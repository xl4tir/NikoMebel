object Form7: TForm7
  Left = 0
  Top = 0
  Caption = 'Niko Mebel - '#1055#1110#1076#1090#1074#1077#1088#1076#1078#1077#1085#1085#1103
  ClientHeight = 186
  ClientWidth = 300
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 260
    Height = 56
    Alignment = taCenter
    Caption = 
      #1044#1083#1103' '#1090#1086#1075#1086' '#1097#1086#1073' '#1086#1092#1086#1088#1084#1080#1090#1080', '#1085#1072#1084' '#1087#1086#1090#1088#1110#1073#1085#1080#1081' '#1074#1072#1096' '#1085#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1091', '#1076#1083#1103' '#1091#1079#1075 +
      #1086#1076#1078#1077#1085#1085#1103' '#1076#1077#1090#1072#1083#1077#1081' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103'. '#1052#1080' '#1079#1072#1090#1077#1083#1077#1092#1086#1085#1091#1108#1084#1086' '#1074#1072#1084' '#1079#1072' '#1082#1110#1083#1100#1082#1072' '#1093#1074#1080#1083#1080 +
      #1085'!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object Button1: TButton
    Left = 24
    Top = 138
    Width = 113
    Height = 34
    Caption = #1055#1110#1076#1090#1074#1077#1088#1076#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 160
    Top = 138
    Width = 113
    Height = 34
    Caption = #1047#1072#1082#1088#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 24
    Top = 96
    Width = 249
    Height = 26
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    TextHint = #1053#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1091
  end
  object DateTimePicker1: TDateTimePicker
    Left = 0
    Top = -3
    Width = 186
    Height = 21
    Date = 44375.000000000000000000
    Time = 0.862521828705212100
    TabOrder = 3
    Visible = False
  end
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=NikoMeb.mdb;Persist' +
      ' Security Info=False'
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 264
    Top = 152
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'Login'
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'SELECT * FROM basket WHERE buyer = :Login')
    Left = 264
    Top = 120
  end
  object ADOQuery2: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'Login'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      'SELECT * FROM users WHERE login = :Login')
    Left = 264
    Top = 88
  end
  object ADOQuery3: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'MeblName'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end
      item
        Name = 'Price'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end
      item
        Name = 'Login'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end
      item
        Name = 'Tel'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end
      item
        Name = 'OrderNum'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end
      item
        Name = 'Status'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end
      item
        Name = 'Time'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO orders (MeblName, Price,  buyer, tel, order_num, sta' +
        'tus_, time_) VALUES (:MeblName, :Price, :Login, :Tel, :OrderNum,' +
        ' :Status, :Time)'
      '')
    Left = 264
    Top = 56
  end
  object ADOQuery4: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'SELECT order_num FROM orders')
    Left = 264
    Top = 24
  end
  object ADOQuery5: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'Login'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      'DELETE * FROM basket WHERE buyer = :Login')
    Top = 22
  end
end
