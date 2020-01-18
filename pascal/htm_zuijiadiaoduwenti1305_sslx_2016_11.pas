program htm_zuijiadiaoduwenti1305_shensolianxi_2016_11_27;
var
  t:array[1..17] of integer;
  k_:array[1..5] of integer;
  n,k,i,ans:integer;
function max(a,b:integer):integer;
begin
  if a>b
    then max:=a
    else max:=b;
end;
procedure dfs(j,ma:integer);
var
  i:integer;
begin
  if ma>=ans then exit;
  if j=n+1 then
  begin
    ans:=ma;
    exit;
  end;
  for i:=1 to k do
  begin
    k_[i]:=k_[i]+t[j];
    dfs(j+1,max(ma,k_[i]));
    k_[i]:=k_[i]-t[j];
  end;
end;
begin
  readln(n,k);
  for i:=1 to n do read(t[i]);
  ans:=10000;
  dfs(1,0);
  writeln(ans);
end.
