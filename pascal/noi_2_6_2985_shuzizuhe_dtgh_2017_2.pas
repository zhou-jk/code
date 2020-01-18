program noi_2_6_2985_shuzizuhe_dongtaiguihua_2017_2_10;
var
  f:array[0..1000] of longint;
  a:array[1..20] of word;
  n,t,i,j:integer;
begin
  readln(n,t);
  f[0]:=1;
  for i:=1 to n do
  begin
    read(a[i]);
    for j:=t downto a[i] do
    begin
        inc(f[j],f[j-a[i]]);
        //writeln(f[j],' ',f[j-a[i]],' ',j-a[i],' ',i);
    end;
  end;
  writeln(f[t]);
end.


