program htm_1772_panduandazhishu_2017_1_30_yh_zj;
var
  a:array[2..maxlongint] of boolean;
  n,i,j,num:longint;
begin
  readln(n);
  for i:=2 to trunc(sqrt(maxlongint)) do
    if not a[i] then
      for j:=i to maxlongint div i do a[i*j]:=true;
  for i:=1 to n do
  begin
    readln(num);
    if a[num]
    then writeln('NO')
    else writeln('YES');
  end;
end.

