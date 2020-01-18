program h_1192_hechangduixing_dongtaiguihua_2017_2_8;
var
  t,l,r:array[1..100] of integer;
  n,i,j,k,m,le,ri,ans:integer;
begin
  readln(n);
  for i:=1 to n do read(t[i]);
  ans:=10000;
  r[n]:=1;
  for i:=n-1 downto 1 do
  begin
    for j:=i+1 to n do
      if (t[i]>t[j])and(r[j]>r[i]) then r[i]:=r[j];
    inc(r[i]);
  end;
  for i:=1 to n do
  begin
    for j:=1 to i-1 do
      if (t[i]>t[j])and(l[j]>l[i]) then l[i]:=l[j];
    inc(l[i]);
    if n-l[i]-r[i]+1<ans then ans:=n-l[i]-r[i]+1;
  end;
  writeln(ans);
end.
