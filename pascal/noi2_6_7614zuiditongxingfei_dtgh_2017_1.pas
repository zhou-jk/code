program noi2_6_7614zuiditongxingfei_dongtaiguihua_2017_1_1;
var
  m,b:array[1..101,1..101] of longint;
  n,i,j:integer;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
   readln(n);
   for i:=1 to n do
     for j:=1 to n do read(m[i,j]);
   for i:=n downto 1 do
   begin
     b[i,n]:=b[i+1,n]+m[i,n];
     b[n,i]:=b[n,i+1]+m[n,i];
   end;
   for i:=n-1 downto 1 do
     for j:=n-1 downto 1 do b[i,j]:=min(b[i+1,j],b[i,j+1])+m[i,j];
   writeln(b[1,1]);
end.
