program htm_1782_taolinongchang_dfs_2017_1_25;
type
  int=array[1..10] of integer;
var
  a:array[1..20] of int;
  n,i,j,ans:integer;
  m:string;
  b:int;
procedure dfs(k,s:integer;b:int);
var
  i:integer;
  t:boolean;
  sum:int;
begin
  if k=n+1 then
  begin
    if s>ans then ans:=s;
    exit;
  end;
  t:=false;
  for i:=10 downto 1 do
  begin
    sum[i]:=a[k][i]+b[i];
    if sum[i]>9 then begin t:=true; break; end;
  end;
  if not t then begin dfs(k+1,s+1,sum); end;
  dfs(k+1,s,b);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(m);
    for j:=1 to length(m) do begin val(m[j],a[i][9-length(m)+j]); end;
  end;
  dfs(1,0,b);
  writeln(ans);
end.
