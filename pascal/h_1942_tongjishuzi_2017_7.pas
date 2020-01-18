program h_1942_tongjishuzi_2017_7_30;
var
  a:array[1..200000] of longint;
  n,i,num,s:longint;
procedure sort(l,r:longint);
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
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  num:=a[1]; s:=1;
  for i:=2 to n do
    if a[i]>a[i-1]
    then begin
           writeln(num,' ',s);
           num:=a[i]; s:=1;
         end
    else inc(s);
  writeln(num,' ',s);
end.