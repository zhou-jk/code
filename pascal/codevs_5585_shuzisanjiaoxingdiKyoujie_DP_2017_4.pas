program codevs_5585_shuzisanjiaoxingdiKyoujie_DP_2017_4_30;
var
  f:array[1..50,1..50,0..5000] of longint;
  a:array[1..50,1..50] of byte;
  n,k,i,j,p,m:integer;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;
begin
  readln(n,k);
  for i:=1 to n do
    for j:=1 to i do
    begin
      read(a[i,j]);
      m:=max(m,a[i,j]);
    end;
  for i:=1 to n do f[n,i,a[n,i]]:=1;
  for i:=n-1 downto 1 do
    for j:=1 to i do
      for p:=a[i,j] to (n-i+1)*m do
        f[i,j,p]:=f[i+1,j,p-a[i,j]]+f[i+1,j+1,p-a[i,j]];
  for i:=n*m downto 0 do
  begin
    dec(k,f[1,1,i]);
    if k<1 then
    begin
      writeln(i);
      exit;
    end;
  end;
end.




