unit BINOperation;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs;

type
  TDivisionResult = record
    DivPart: String;
    ModPart: String;
  end;

  TBINOperation = class(TComponent)
  private
    { Private declarations }
  protected
    { Protected declarations }
  public
    { Public declarations }
    function Add(Bin1, Bin2: String): String;
    function Divide(Bin1, Bin2: String): TDivisionResult;
    function Multiply(Bin1, Bin2: String): String;
    function Subtract(Bin1, Bin2: String): String;
  published
    { Published declarations }
  end;

procedure Register;

implementation

const
  NUMBERS = '0123456789';

procedure Register;
begin
  RegisterComponents('DSO', [TBINOperation]);
end;

function Convert(NFrom, NTo: Byte; Value: String): String;
var
  v: String;
  p, num: Integer;
  res, npos: Int64;
begin
  npos:=1;
  res:=0;
  p:=Length(value);
  while p>0 do begin
    num:=Pos(UpCase(value[p]),NUMBERS)-1;
    Inc(res,num*npos);
    npos:=npos*NFrom;
    Dec(p);
  end;

  npos:=1;
  res:=Abs(res);
  while (res div (npos*NTo))>0 do npos:=npos*NTo;

  v:='';
  while npos>0 do begin
    v:=v+NUMBERS[(res div npos)+1];
    res:=res mod npos;
    npos:=npos div NTo;
  end;

  Result:=v;
end;

{ TBINOperation }

function TBINOperation.Add(Bin1, Bin2: String): String;
var
  n1, n2: Extended;
begin
  n1:=StrToFloat(Convert(2,10,Bin1));
  n2:=StrToFloat(Convert(2,10,Bin2));
  Result:=Convert(10,2,FloatToStr(n1+n2));
end;

function TBINOperation.Divide(Bin1, Bin2: String): TDivisionResult;
var
  n1, n2: Extended;
  d,m: Extended;
begin
  n1:=StrToFloat(Convert(2,10,Bin1));
  n2:=StrToFloat(Convert(2,10,Bin2));
  d:=Round(n1) div Round(n2);
  m:=Round(n1) mod Round(n2);
  Result.DivPart:=Convert(10,2,FloatToStr(d));
  Result.ModPart:=Convert(10,2,FloatToStr(m));
end;

function TBINOperation.Multiply(Bin1, Bin2: String): String;
var
  n1, n2: Extended;
begin
  n1:=StrToFloat(Convert(2,10,Bin1));
  n2:=StrToFloat(Convert(2,10,Bin2));
  Result:=Convert(10,2,FloatToStr(n1*n2));
end;

function TBINOperation.Subtract(Bin1, Bin2: String): String;
var
  n1, n2: Extended;
begin
  n1:=StrToFloat(Convert(2,10,Bin1));
  n2:=StrToFloat(Convert(2,10,Bin2));
  Result:=Convert(10,2,FloatToStr(n1-n2));
end;

end.
