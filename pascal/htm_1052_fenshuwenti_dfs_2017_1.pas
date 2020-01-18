program htm_1052_fenshuwenti_dfs_2017_1_25;
var
  a:array[1..20] of boolean;
  b:array[1..20] of string;
  n,i,ans:longint;
procedure dfs(k:byte);
var i:byte;
begin
  if k=n+1 then
  begin
    inc(ans);
    exit;
  end;
  for i:=1 to n do
    if (b[k][i]='1')and not a[i] then
    begin
      a[i]:=true;
      dfs(k+1);
      a[i]:=false;
    end;
end;
begin
  readln(n);
  for i:=1 to n do readln(b[i]);
  dfs(1);
  writeln(ans);
end.