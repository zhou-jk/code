program h_1975_zhaopengyou_2017_8_7;
var
  num:array[1..200000] of longint;
  na:array[1..200000] of string;
  n,i:longint;
procedure sort1(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=num[(l+r)div 2];
  repeat
    while num[i]<x do inc(i);
    while x<num[j] do dec(j);
    if i<=j then
    begin
      y:=num[i]; num[i]:=num[j]; num[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort1(l,j);
  if i<r then sort1(i,r);
end;
procedure sort2(l,r:longint);
var
  i,j:longint;
  x,y:string;
begin
  i:=l; j:=r; x:=na[(l+r)div 2];
  repeat
    while na[i]<x do inc(i);
    while x<na[j] do dec(j);
    if i<=j then
    begin
      y:=na[i]; na[i]:=na[j]; na[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort2(l,j);
  if i<r then sort2(i,r);
end;
begin
  readln(n);
  for i:=1 to n do readln(na[i]);
  for i:=1 to n do readln(num[i]);
  sort1(1,n); sort2(1,n);
  for i:=1 to n do writeln(na[i],' ',num[i]);
end.
