program noi_2_6_6049_maishu_wanquanbeibao_2017_2_19;
const m:array[1..4] of integer=(10,20,50,100);
var
  f:array[0..1000] of longint;
  n,i,j:integer;
begin
  readln(n);
  if n=0 then
  begin
    writeln(0);
    exit;
  end;
  f[0]:=1;
  for i:=1 to 4 do
    for j:=m[i] to n do inc(f[j],f[j-m[i]]);
  writeln(f[n]);
end.
