program Ecology_Generator;

{$APPTYPE CONSOLE}

const
  fl_c = 10;
  mg = 30000;

var 
  i, j, n, l: integer;
  tmp_s: string;

begin
  Randomize;

  for i := 1 to fl_c do begin
    str(i, tmp_s);

    Assign(output, 'g' + tmp_s + '.in');
    Rewrite (output);

    n := Random(mg) + 1;
    l := Random(mg) + 1;

    WriteLn (n, ' ', l);
    for j := 1 to n do
      Write(Random(mg) + 1, ' ');

    Close(output);
  end;
end.
