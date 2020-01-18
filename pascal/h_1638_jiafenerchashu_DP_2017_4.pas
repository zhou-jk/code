program h_1638_jiafenerchashu_DP_2017_4_8;
var
  f,g:array[1..30,0..30] of int64;
  s:array[1..30] of byte;
  n,i,j,k:byte;
procedure dfs(l,r:byte);
begin
  if l>r then exit;
  write(g[l,r],' ');
  dfs(l,g[l,r]-1);
  dfs(g[l,r]+1,r);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(s[i]);
    f[i,i]:=s[i]; f[i,i-1]:=1; g[i,i]:=i;
  end;
  for i:=n-1 downto 1 do
    for j:=i+1 to n do
      for k:=i to j do
        if f[i,j]<f[i,k-1]*f[k+1,j]+s[k] then
        begin
          f[i,j]:=f[i,k-1]*f[k+1,j]+s[k];
          g[i,j]:=k;
        end;
  writeln(f[1,n]);
  dfs(1,n);
end.
