program htm_1174_nainiutongxun_dfs_2017_1_25;
var
  a:array[1..12,1..3] of byte;
  b:array[1..12] of boolean;
  c:array[1..12] of byte;
  n,i,ans:longint;
procedure dfs(k,sum:longint);
var i,j,s:longint;
begin
  if sum>=ans then exit;
  if k=n+1 then
  begin
    ans:=sum;
    exit;
  end;
  for i:=1 to n do
    if not b[i] then
    begin
      b[i]:=true; c[k]:=i; s:=sum;
      for j:=1 to 3 do
        if a[k,j]<k then s:=s+abs(i-c[a[k,j]]);
      dfs(k+1,s);
      b[i]:=false;
    end;
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i,1],a[i,2],a[i,3]);
  ans:=maxlongint;
  dfs(1,0);
  writeln(ans);
end.
