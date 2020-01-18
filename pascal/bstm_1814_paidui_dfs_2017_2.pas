program bstm_1814_paidui_dfs_2017_2_4;
var
  a,c:array[0..10] of longint;
  b:array[1..10] of boolean;
  n,k,i,ans:longint;
procedure dfs(t:byte);
var i:byte;
begin
  if t=n+1 then
  begin
    if abs(c[n]-c[1])<=k then inc(ans);
    exit;
  end;
  for i:=2 to n do
    if not b[i] and(abs(a[i]-c[t-1])<=k) then
    begin
      b[i]:=true; c[t]:=a[i];
      dfs(t+1);
      b[i]:=false;
    end;
end;
begin
  readln(n,k);
  for i:=1 to n do readln(a[i]);
  c[1]:=a[1];
  dfs(2);
  writeln(ans);
end.

