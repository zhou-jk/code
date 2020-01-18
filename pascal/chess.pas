var
  f:array[1..200,1..200] of int64;
  n,i,j,k,c:integer;
begin
  assign(input,'chess.in'); assign(output,'chess.out');
  reset(input); rewrite(output);
  readln(n);
  f[1,1]:=1;
  for i:=1 to n do
    for j:=1 to n do
    begin
      read(c);
      if c=0 then continue;
      inc(f[i,j+c],f[i,j]);
      inc(f[i+c,j],f[i,j]);
    end;
  writeln(f[n,n]);
  close(input); close(output);
end.


