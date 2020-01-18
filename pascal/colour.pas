var
  f:array[1..10,1..10]of boolean;
  c:array[1..10]of byte;
  n,m,i,a,b,ans:longint;
procedure dfs(k:byte);
var
  b:boolean;
  i,j:byte;
begin
  if k=n+1 then
  begin
    inc(ans);
    exit;
  end;
  for i:=1 to 4 do
  begin
    b:=false;
    for j:=1 to k-1 do
      if f[j,k]and(c[j]=i) then b:=true;
    if b then continue;
    c[k]:=i;
    dfs(k+1);
  end;
end;
begin
  assign(input,'colour.in'); assign(output,'colour.out');
  reset(input); rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(a,b);
    f[a,b]:=true;
    f[b,a]:=true;
  end;
  dfs(1);
  writeln(ans);
  close(input); close(output);
end.

