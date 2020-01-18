program luogu_1551_qinqi_Disjoint_Sets_2017_7_10;
var
  f:array[1..5000] of integer;
  n,m,p,i,a,b:integer;
function gf(k:integer):integer;
begin
  if f[k]=k then exit(k);
  f[k]:=gf(f[k]);
  gf:=f[k];
end;
begin
  readln(n,m,p);
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do
  begin
    readln(a,b);
    a:=gf(a);
    b:=gf(b);
    f[a]:=b;
  end;
  for i:=1 to p do
  begin
    readln(a,b);
    if gf(a)=gf(b)
    then writeln('Yes')
    else writeln('No');
  end;
end.

