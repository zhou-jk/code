program bstm_1812_tongji_2017_2_4;
var
  a:array[1..50000] of longint;
  n,i,s:word;
procedure sort(l,r:longint);
var
  i,j,x,y:longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if not(i>j) then
    begin
      y:=a[i];
      a[i]:=a[j];
      a[j]:=y;
      inc(i);
      j:=j-1;
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  write(a[1],' '); s:=1;
  for i:=2 to n do
  begin
    if a[i]<>a[i-1] then
    begin
      writeln(s);
      s:=0;
      write(a[i],' ');
    end;
    inc(s);
  end;
  writeln(s);
end.

