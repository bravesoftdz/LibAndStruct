// ACM 2006
// Problem E. Ecology
// Sergio A. Fjodorov

// �������� ������ ��� l <= 30000

{$apptype console}

var
  i, n, l, t: integer;
  m, ms: integer;
  a: array[0..30000] of integer;
  s: integer;

begin
  Read(n, l);
  for i := 1 to n do begin
    Read(t);
    t := t mod l;
    Inc(a[t]);
  end;

  m := 0;
  ms := 0;
  s := 0;

  for i := 1 to l - 1 do begin
    s := s + n - a[l - i] * l;
    if ms > s then begin
      ms := s;
      m := i;
    end;
  end;
  
  Write(m);
end.
