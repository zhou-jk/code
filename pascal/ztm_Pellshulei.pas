var 
  a: array[1..1000] of longint;
  c: array[1..1000000] of longint;
  n,i: longint;
function Pell(b:longint): longint;
begin
  if (b=1)or(b=2) then
  begin
    Pell := b;
    exit;
  end;
  if c[b]<>-1 then
    Pell := c[b]
  else
  begin
    Pell := (2*Pell(b-1)+Pell(b-2)) mod 32767;
    c[b] := pell;
  end;
end;
begin
  readln(n);
  for i:=1 to 1000000 do
    c[i] := -1;
  for i:=1 to n do
  begin
    readln(a[i]);
  end;
  for i:=1 to n do
    writeln(Pell(a[i]));
  readln;
end.
