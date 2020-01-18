var
  a,c:array[1..10000] of longint;
  n,i:longint;
function ff(d,b:longint):longint;
var
  j:longint;
begin
  ff:=0;
  for j:=d to b do
    if b mod j=0 then
      if b<>j
      then ff:=ff+ff(j,b div j)
      else ff:=ff+1;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(a[i]);
    c[i]:=ff(2,a[i]);
  end;
  for i:=1 to n do
    writeln(c[i]);
  readln;
end.
