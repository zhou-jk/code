var
  x,v:array[0..100] of longint;
  n,b,i,min,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure dfs(k,s,m:longint);
var i:longint;
begin
  if m>=min then exit;
  if s=0 then
  begin
    min:=m;
    exit;
  end;
  if k=b+1 then exit;
  for i:=s div v[k] downto 1 do dfs(k+1,s-i*v[k],m+i);
end;
begin
  assign(input,'mooomoo.in'); assign(output,'mooomoo.out');
  reset(input); rewrite(output);
  readln(n,b);
  for i:=1 to b do readln(v[i]);
  for i:=1 to n do
  begin
    readln(x[i]);
    min:=100000;
    dfs(1,x[i]-max(x[i-1]-1,0),0);
    inc(ans,min);
  end;
  writeln(ans);
  close(input); close(output);
end.


