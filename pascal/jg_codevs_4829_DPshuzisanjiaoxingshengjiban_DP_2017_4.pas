program jg_codevs_4829_shuzisanjiaoxing_DP_2017_4_30;
var
  f:array[1..1000,1..1000,0..1] of longint;
  a:array[1..1000,1..1000] of integer;
  n,i,j:integer;
function max(a,b:longint):longint;
begin
  if a>b then exit(a)
         else exit(b);
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to i do read(a[i,j]);
  for i:=1 to n do
  begin
    f[n,i,0]:=a[n,i];
    f[n,i,1]:=2*a[n,i];
  end;
  for i:=n-1 downto 1 do
    for j:=1 to i do
    begin
      f[i,j,0]:=max(f[i+1,j,0],f[i+1,j+1,0])+a[i,j];
      f[i,j,1]:=max(max(f[i+1,j,1],f[i+1,j+1,1])+a[i,j],max(f[i+1,j,0],f[i+1,j+1,0])+2*a[i,j]);
    end;
  writeln(f[1,1,1]);
end.