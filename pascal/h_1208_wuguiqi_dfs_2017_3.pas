program h_1208_wuguiqi_dfs_2017_3_4;
var
  a:array[1..350] of byte;
  b:array[1..4] of byte;
  n,m,i,ans,t:longint;
procedure dfs(k,sum:longint);
var i:byte;
begin
  inc(sum,a[k]);
  if k=n then
  begin
    if sum>ans then ans:=sum;
    exit;
  end;
  for i:=1 to 4 do
    if b[i]>0 then
    begin
      dec(b[i]);
      dfs(k+i,sum);
      inc(b[i]);
    end;
end;
begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do
  begin
    read(t);
    inc(b[t]);
  end;
  dfs(1,0);
  writeln(ans);
end.

