program bstm_1820_shengriliiwu_2017_2_6;
var
  b:array[1..10] of longint;
  n,m,a,i,j,ans:longint;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    read(a);
    inc(b[a]);
  end;
  for i:=1 to m-1 do
    for j:=i+1 to m do inc(ans,b[j]*b[i]);
  writeln(ans);
end.