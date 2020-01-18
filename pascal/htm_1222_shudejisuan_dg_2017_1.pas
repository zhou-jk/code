program htm_1223_shudejisuan_digui_2017_1_22;
var
  a:array[1..1000] of longint;
  n:integer;
function f(n:integer):longint;
var
  i:integer;
begin
  if a[n]>0 then exit(a[n]);
  f:=1;
  for i:=1 to n div 2 do f:=f+f(i);
  a[n]:=f;
  //writeln(f,' ',n);
end;
begin
  readln(n);
  a[1]:=1;
  writeln(f(n));
end.
