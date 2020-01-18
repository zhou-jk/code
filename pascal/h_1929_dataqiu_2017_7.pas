program h_1929_dataiqiu_2017_7_30;
var
  a:array[1..7] of longint;
  i,max,ans:longint;
begin
  for i:=1 to 7 do
  begin
    read(a[i]);
    if a[i]>0 then max:=i;
  end;
  if max=1 then
  begin
    writeln(1);
    exit;
  end;
  ans:=a[1]*(1+max);
  for i:=2 to 7 do ans:=ans+a[i]*i;
  writeln(ans);
end.

