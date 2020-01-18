program codevs_1697yaoxiexing_dongtaiguihua_2017_1_18;
type int=array[1..158] of integer;
var
  f:array[1..100] of int;
  n,i,p:integer;
function plus(a,b:int):int;
var
  i,t:integer;
begin
  t:=0;
  for i:=1 to 158 do
  begin
    plus[i]:=a[i]+b[i]+t;
    t:=plus[i] div 10;
    plus[i]:=plus[i] mod 10;
  end;
end;
function x(a:int;b:integer):int;
var
  i,t:integer;
begin
  t:=0;
  for i:=1 to 158 do
  begin
    x[i]:=a[i]*b+t;
    t:=x[i] div 10;
    x[i]:=x[i] mod 10;
  end;
end;
begin
  readln(n);
  f[2][1]:=1;
  for i:=3 to n do f[i]:=x(plus(f[i-2],f[i-1]),i-1);
  for i:=158 downto 1 do
    if f[n,i]>0 then
    begin
      p:=i;
      break;
    end;
  for i:=p downto 1 do write(f[n][i]);
end.