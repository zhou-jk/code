program codevs_1010guohezu_dongtaiguihua_2016_12_30;
var
  a:array[0..20,0..20] of longint;
  n,m,x,y:integer;
begin
  read(n,m);
  for x:=0 to 20 do
    for y:=0 to 20 do a[x,y]:=1;
  readln(x,y);
  a[x,y]:=0;a[x+2,y+1]:=0;a[x+1,y+2]:=0;a[x-1,y+2]:=0;a[x-2,y+1]:=0;a[x-2,y-1]:=0;a[x-1,y-2]:=0;a[x+1,y-2]:=0;a[x+2,y-1]:=0;
  for x:=n-1 downto 0 do
    for y:=m-1 downto 0 do
      if a[x,y]<>0 then a[x,y]:=a[x+1,y]+a[x,y+1];
  writeln(a[0,0]);
end.
