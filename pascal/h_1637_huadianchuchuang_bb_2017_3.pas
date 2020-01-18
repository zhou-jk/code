program h_1637_huadianchuchuang_beibao_2017_3_4;
var
  s,g:array[0..100,0..100] of integer;
  f,v,i,j:byte;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure w(i,j:byte);
begin
  if (i=0)or(j=0) then exit;
  if g[i,j-1]>=g[i-1,j-1]+s[i,j]
  then w(i,j-1)
  else begin
         w(i-1,j-1);
         write(j,' ');
       end;
end;
begin
  readln(f,v);
  for i:=1 to f do
    for j:=1 to v do read(s[i,j]);
  for i:=1 to f do
    for j:=0 to v do g[i,j]:=-maxint;
  for i:=1 to f do
    for j:=i to v do
      g[i,j]:=max(g[i,j-1],g[i-1,j-1]+s[i,j]);
  writeln(g[f,v]);
  w(f,v);
end.


