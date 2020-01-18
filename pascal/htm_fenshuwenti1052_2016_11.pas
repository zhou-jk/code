program htm_fenshuwenti1052_2016_11_20;
var
  n,i:integer;
  ans:longint;
  p:array[1..20] of string[21];
  b:array[1..20] of boolean;
procedure dfs(k:integer);
var
  i,j:integer;
begin
  if k=n+1 then
  begin
    inc(ans);
    exit;
  end;
  for i:=1 to n do
    if (p[k][i]='1')and(b[i]=false) then
    begin
      //writeln(k,' ',i);
      //for
      b[i]:=true;
      dfs(k+1);
      b[i]:=false;
    end;
end;
begin
  readln(n);
  for i:=1 to n do readln(p[i]);
  //for i:=1 to n do writeln(p[i]);
  dfs(1);
  writeln(ans);
end.
