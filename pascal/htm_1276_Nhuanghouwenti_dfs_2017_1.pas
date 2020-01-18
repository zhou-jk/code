program htm_1276_Nhuanghouwenti_dfs_2017_1_31;
var
  a:array[-9..9] of boolean;
  b:array[2..20] of boolean;
  c:array[1..10] of boolean;
  n,ans:longint;
procedure dfs(k:byte);
var i:byte;
begin
  if k=n+1 then
  begin
    inc(ans);
    exit;
  end;
  for i:=1 to n do
    if not a[k-i]and not b[k+i]and not c[i] then
    begin
      a[k-i]:=true; b[k+i]:=true; c[i]:=true;
      dfs(k+1);
      a[k-i]:=false; b[k+i]:=false; c[i]:=false;
    end;
end;
begin
  readln(n);
  dfs(1);
  writeln(ans);
end.
