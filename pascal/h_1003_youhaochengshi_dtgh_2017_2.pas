program h_1003_youhaochengshi_dongtaiguihua_2017_2_7;
var
  c,d,f:array[1..5000] of integer;
  x,y,n,i,j,ans:integer;
begin
  readln(n);
  for i:=1 to n do readln(c[i],d[i]);
  for i:=2 to n do
  begin
    j:=i-1; x:=c[i]; y:=d[i];
    while (j>0)and(x<c[j]) do
    begin
      c[j+1]:=c[j]; d[j+1]:=d[j];
      dec(j);
    end;
    c[j+1]:=x; d[j+1]:=y;
  end;
  f[1]:=1;
  for i:=2 to n do
  begin
    for j:=1 to i-1 do
      if ((c[i]>c[j])and(d[i]>d[j])or(c[i]<c[j])and(d[i]<d[j]))and(f[i]<f[j]) then f[i]:=f[j];
    inc(f[i]);
    if f[i]>ans then ans:=f[i];
  end;
  writeln(ans);
end.

