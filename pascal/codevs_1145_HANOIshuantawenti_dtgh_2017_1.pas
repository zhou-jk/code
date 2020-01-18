program codevs_1145_HANOIshuangtawenti_dongtaiguihua_2017_1_20;
const m=61;
type int=array[1..m] of byte;
var
  f:array[1..200] of int;
  n,i,p:byte;
function x(a:int):int;
var
  i,t:byte;
begin
  t:=0;
  for i:=1 to m do
  begin
    //writeln(i);
    //writeln(a[i],' ',t);
    x[i]:=a[i]*2+t;
    t:=x[i] div 10;
    x[i]:=x[i] mod 10;
  end;
end;
function plus(a:int):int;
var
  i,t:byte;
begin
  plus[1]:=a[1]+1;
  t:=plus[1] div 10;
  plus[1]:=plus[1] mod 10;
  for i:=2 to m do
  begin
    plus[i]:=a[i]+t;
    t:=plus[i] div 10;
    plus[i]:=plus[i] mod 10;
  end;
end;
begin
  readln(n);
  f[1][1]:=1;
  for i:=2 to n do f[i]:=plus(x(f[i-1]));
  f[n]:=x(f[n]);
  //writeln('#');
  for i:=m downto 1 do
    if f[n][i]>0 then begin p:=i; break; end;
  for i:=p downto 1 do write(f[n][i]);
end.
