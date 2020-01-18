program h_1354_qiuhewenti3_2017_7_18;
var
  c:array[1..199,0..99] of longint;
  n,m,i,j:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  readln(n,m);
  for i:=1 to n+m-1 do c[i,0]:=1;
  for i:=1 to m-1 do c[i,i]:=1;
  for i:=2 to n+m-1 do
    for j:=1 to m-1 do c[i,j]:=(c[i-1,j-1]+c[i-1,j])mod 10007;
  writeln(c[n+m-1,m-1]);
end.
