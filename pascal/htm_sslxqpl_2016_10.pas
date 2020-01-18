program htm_shengsolianxiquanpailie_2016_10_23;
var
  n:integer;
  a:array[1..10] of integer;
  b:array[1..10] of boolean;
procedure qpl(k:integer);
var
  i:integer;
begin
  if k=n+1 then
  begin
    for i:=1 to n do write(a[i]:5);
    writeln;
    exit;
  end;
  for i:=1 to n do
    if b[i]=false then
    begin
      b[i]:=true; a[k]:=i;
      qpl(k+1);
      b[i]:=false;
    end;
end;
begin
  readln(n);
  qpl(1);
end.