program h_1629_xiaoqing100zhounian_beibao_2017_3_4;
var
  s,g:array[0..100,0..100] of integer;
  f,v,i,j:byte;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  exit(b);
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
end.


