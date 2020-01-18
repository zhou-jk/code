program h_1800_lajizhuangdai_tanxing_2017_5_6;
var
  d,v:array[1..50000] of integer;
  n,m,i,j,k,ans:longint;
  f:boolean;
procedure sort(l,r:longint);
var  i,j,x,y:longint;
begin
  i:=l; j:=r; x:=d[(l+r) div 2];
  repeat
    while d[i]<x do inc(i);
    while x<d[j] do dec(j);
    if i<=j then
    begin
      y:=d[i]; d[i]:=d[j]; d[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
procedure sort1(l,r:longint);
var  i,j,x,y:longint;
begin
  i:=l; j:=r; x:=v[(l+r) div 2];
  repeat
    while v[i]<x do inc(i);
    while x<v[j] do dec(j);
    if i<=j then
    begin
      y:=v[i]; v[i]:=v[j]; v[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort1(l,j);
  if i<r then sort1(i,r);
end;
begin
  readln(n,m);
  for i:=1 to n do read(d[i]);
  for i:=1 to m do read(v[i]);
  sort(1,n); sort1(1,m);
  for i:=1 to n do
  begin
    f:=false;
    for j:=k+1 to m do
      if v[j]>=d[i] then
      begin
        f:=true; k:=j; inc(ans,v[j]);
        break;
      end;
    if not f then
    begin
      writeln(-1);
      exit;
    end;
  end;
  writeln(ans);
end.