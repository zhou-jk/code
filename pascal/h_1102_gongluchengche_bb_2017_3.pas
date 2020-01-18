program h_1102_gongluchengche_beibao_2017_3_4;
var
  f:array[0..100] of longint;
  m:array[1..10] of integer;
  n,i,j:byte;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  for i:=1 to 10 do read(m[i]);
  readln(n);
  for i:=1 to n do f[i]:=maxlongint;
  for i:=1 to 10 do
    for j:=i to n do
      f[j]:=min(f[j],f[j-i]+m[i]);
  writeln(f[n]);
end.
