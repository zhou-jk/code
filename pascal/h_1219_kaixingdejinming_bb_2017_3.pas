program h_1219_kaixingdejinming_beibao_2017_3_18;
var
  f:array[0..30000]of longint;
  n,m,v,p,i,j:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(v,p);
    for j:=n downto v do f[j]:=max(f[j],f[j-v]+v*p);
  end;
  writeln(f[n]);
end.

