program h_1218_shudehuafen_wanquanbeibao_2017_2_19;
var
  f:array[0..200,0..6] of longint;
  n,k,i,j:integer;
begin
  readln(n,k);
  f[0,0]:=1;
  for i:=1 to n do
    for j:=1 to k do
    begin
      f[i,j]:=f[i-1,j-1];
      if i>=j then inc(f[i,j],f[i-j,j]);
    end;
  writeln(f[n,k]);
end.