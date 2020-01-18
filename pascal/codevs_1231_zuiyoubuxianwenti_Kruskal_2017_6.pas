program codevs_1231_zuiyoubuxianwenti_Kruskal_2017_6_10;
type a=record
         a,b,c:longint;
       end;
var
  father:array[1..100000] of longint;
  edge:array[1..100000] of a;
  n,m,i,e,fa,fb:longint;
  ans:int64;
function getfather(k:longint):longint;
begin
  if father[k]=k
  then exit(k)
  else father[k]:=getfather(father[k]);
  getfather:=father[k];
end;
procedure sort(l,r:longint);
var
  i,j,x:longint;
  y:a;
begin
  i:=l; j:=r; x:=edge[(l+r) div 2].c;
  repeat
    while edge[i].c<x do inc(i);
    while x<edge[j].c do dec(j);
    if i<=j then
    begin
      y:=edge[i]; edge[i]:=edge[j]; edge[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n,m);
  for i:=1 to m do with edge[i] do readln(a,b,c);
  for i:=1 to n do father[i]:=i;
  sort(1,m);
  i:=0;
  while e<n-1 do
  begin
    inc(i);
    with edge[i] do
    begin
      fa:=getfather(a);
      fb:=getfather(b);
      if fa<>fb then
      begin
        father[fa]:=father[fb];
        inc(ans,c);
        inc(e);
      end;
    end;
  end;
  writeln(ans);
end.

