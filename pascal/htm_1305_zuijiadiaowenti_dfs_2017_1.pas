program htm_1305_zuijiadiaoduwenti_dfs_2017_1_28;
var
  a,t:array[1..21] of longint;
  n,k,ans,i,j:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure dfs(kk,ma:longint);
var i:longint;
begin
  if ma>=ans then exit;
  if kk=n+1 then
  begin
    ans:=ma;
    exit;
  end;
  for i:=1 to k do
  begin
    inc(a[i],t[kk]);
    dfs(kk+1,max(ma,a[i]));
    dec(a[i],t[kk]);
  end;
end;
begin
  readln(n,k);
  for i:=1 to n do read(t[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if t[i]<t[j] then
      begin
        inc(t[i],t[j]);
        t[j]:=t[i]-t[j];
        dec(t[i],t[j]);
      end;
  i:=1;
  while i<=n do
  begin
    inc(ans,t[i]); inc(i,k);
  end;
  dfs(1,0);
  writeln(ans);
end.
