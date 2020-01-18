program noi2_6_2728zhaihuashen_dongtaiguihua_2017_1_1;
var
  m,b:array[1..101,1..101] of longint;
  t,r,c,i,j,k:integer;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(r,c);
    for j:=1 to r do
      for k:=1 to c do read(m[j,k]);
    for j:=1 to r+1 do
      for k:=1 to c+1 do b[j,k]:=0;
    for j:=r downto 1 do
      for k:=c downto 1 do b[j,k]:=max(b[j+1,k],b[j,k+1])+m[j,k];
    writeln(b[1,1]);
  end;
end.
