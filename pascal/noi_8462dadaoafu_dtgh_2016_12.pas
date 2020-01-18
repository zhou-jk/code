program noi_8462dadaoafu_dongtaiguihuai_2016_12_25;
var
  s:array[1..100000]of integer;
  f:array[-1..100000]of longint;
  n,j:longint;
  t,i:integer;
function max(a,b:longint):longint;
begin
  if a>b then exit(a)
         else exit(b);
end;
begin
  readln(t);
  for i:=1to t do
  begin
    readln(n);
    for j:=1to n do read(s[j]);
    for j:=1to n do f[j]:=max(s[j]+f[j-2],f[j-1]);
    writeln(f[n]);
  end;
end.