program htm_huanghouwenti1276_shensolianxi_2016_10_30;
var
  n:integer;
  b,c,d:array[-9..20] of boolean;
  ans:int64;
procedure dfs(k:integer);
var
  i:integer;
begin
  if k=n+1 then
  begin
    inc(ans);
    exit;
  end;
  for i:=1 to n do
    if not b[i] and not c[k-i] and not d[k+i]  then
    begin
      b[i]:=true;
      c[k-i]:=true;
      d[k+i]:=true;
      dfs(k+1);
      b[i]:=false;
      c[k-i]:=false;
      d[k+i]:=false;
    end;
end;
begin
  readln(n);
  dfs(1);
  writeln(ans);
end.
