program Factorial;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;

function FacIterative(n: Word): Longint;
var
  f: LongInt;
  i: Integer;
begin
  f := 1;
  for i := 2 to n do
    f := f * i;
  Result := f;
end;

function FacRecursive(n: Word): LongInt;
begin
  if n > 1 then
    Result := n * FacRecursive(n - 1)
  else
    Result := 1;
end;

function FacStirling(n: Word): LongInt;
begin
  Result := round(sqrt(2 * Pi * n) * power(n / exp(1), n));
end;

var
  n: Word;

begin
  Read(n);
  Write(FacStirling(n));
end.
