var
  a,c:array[1..10000] of longint;
  n,i:longint;
function fbnq(b:longint):longint;
begin
  if (b=1)or(b=2)
  then begin fbnq:=1; exit; end
  else fbnq:=fbnq(b-2)+fbnq(b-1);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(a[i]);
    c[i]:=fbnq(a[i]);
  end;
  for i:=1 to n do
    writeln(c[i]);
  readln;
end.

