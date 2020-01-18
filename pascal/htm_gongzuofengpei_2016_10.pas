program htm_gongzuofengpei_2016_10_23;
var
  n,i,j,tp,ans:integer;
  a:array[1..20] of integer;
  b:array[1..20] of boolean;
  c:array[1..20,1..20] of integer;
procedure qpl(k:integer;tp:integer);
var
  i:integer;
begin
  if tp>=ans then exit;
  if k=n+1 then ans:=tp;
  for i:=1 to n do
    if b[i]=false then
    begin
      b[i]:=true; a[k]:=i;
      qpl(k+1,tp+c[k,a[k]]);
      b[i]:=false;
    end;
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      read(c[i,j]);
  ans:=10000;
  qpl(1,0);
  writeln(ans);
end.

