program h_1961_mujian_2017_8_5;
type arr=array[1..100000] of longint;
var
  v:array[1..100000] of boolean;
  m,n,i,j,ans:longint;
  a,b:arr;
procedure stop;
begin
  writeln(0);
  halt;
end;
procedure sort(var a:arr;l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(a,l,j);
  if i<r then sort(a,i,r);
end;
begin
  readln(m,n);
  if m>n then stop;
  for i:=1 to m do readln(a[i]);
  for i:=1 to n do readln(b[i]);
  sort(a,1,m); sort(b,1,n);
  j:=1;
  for i:=1 to m do
  begin
    if j>n then stop;
    while b[j]<=a[i] do
    begin
      inc(ans,b[j]);
      inc(j);
      if j>n then stop;
    end;
    inc(j);
  end;
  for i:=j to n do inc(ans,b[i]);
  writeln(ans);
end.
