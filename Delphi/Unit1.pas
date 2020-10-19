unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, BINOperation;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Edit1: TEdit;
    Label2: TLabel;
    Edit2: TEdit;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Label3: TLabel;
    Label4: TLabel;
    Edit3: TEdit;
    Edit4: TEdit;
    BINOperation1: TBINOperation;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.DFM}

procedure TForm1.Button1Click(Sender: TObject);
begin
  Edit3.Text:=BINOperation1.Add(Edit1.Text,Edit2.Text);
  Edit4.Text:='';
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Edit3.Text:=BINOperation1.Subtract(Edit1.Text,Edit2.Text);
  Edit4.Text:='';
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  Edit3.Text:=BINOperation1.Multiply(Edit1.Text,Edit2.Text);
  Edit4.Text:='';
end;

procedure TForm1.Button4Click(Sender: TObject);
var
  r: TDivisionResult;
begin
  r:=BINOperation1.Divide(Edit1.Text,Edit2.Text);
  Edit3.Text:=r.DivPart;
  Edit4.Text:=r.ModPart;
end;

end.
 