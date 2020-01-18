program h_1102_gongluchengche_DP_2017_8_2;
var
  f:array[0..100] of longint;
  v:array[1..10] of longint;
  n,i,j:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  for i:=1 to 10 do read(v[i]);
  readln(n);
  for i:=1 to n do
  begin
    f[i]:=maxlongint;
    for j:=1 to min(i,10) do f[i]:=min(f[i],f[i-j]+v[j]);
  end;
  writeln(f[n]);
end.
