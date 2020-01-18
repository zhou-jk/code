var
  c,f:array[1..1000] of integer;
  n,i,j,ans:integer;
begin
  assign(input,'seq.in'); assign(output,'seq.out');
  reset(input); rewrite(output);
  readln(n); readln(c[1]);
  f[1]:=1;
  for i:=2 to n do
  begin
    readln(c[i]);
    for j:=1 to i-1 do
      if (abs(c[i]-c[j])<>1)and(f[j]>f[i]) then f[i]:=f[j];
    inc(f[i]);
    if f[i]>ans then ans:=f[i];
  end;
  writeln(n-ans);
  close(input); close(output);
end.
