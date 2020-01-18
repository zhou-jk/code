program luogu_1111_xiufugonglu_Kruskal_2017_7_10;
type rec=record
           x,y,t:longint;
         end;
var
  r:array[1..100000] of rec;
  f:array[1..1000] of integer;
  n,m,a,b,o,i:longint;
function gf(k:integer):integer;
begin
  if f[k]=k then exit(k);
  f[k]:=gf(f[k]);
  gf:=f[k];
end;
procedure sort(l,rr:longint);
var
  i,j:longint;
  x,y:rec;
begin
  i:=l; j:=rr; x:=r[(l+rr) div 2];
  repeat
    while r[i].t<x.t do inc(i);
    while x.t<r[j].t do dec(j);
    if i<=j then
    begin
      y:=r[i]; r[i]:=r[j]; r[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<rr then sort(i,rr);
end;
begin
  readln(n,m);
  for i:=1 to m do with r[i] do readln(x,y,t);
  sort(1,m);
  for i:=1 to n do f[i]:=i;
  i:=1;
  while o<n-1 do
  with r[i] do
  begin
     a:=gf(x);
     b:=gf(y);
     if a<>b then
     begin
       inc(o);
       f[a]:=b;
     end;
     inc(i);
     if (i>m)and(o<n-1) then
     begin
       writeln(-1);
       exit;
     end;
  end;
  writeln(r[i-1].t);
end.




