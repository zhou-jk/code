var
  a,b:array[1..100000] of longint;
  c:array[1..50000] of byte;
  n,m,i,ans:longint;
procedure dfs(k,t:longint);
var
  i,j:longint;
  f:boolean;
begin
  if n-k<=ans-t then exit;
  if k=n+1 then
  begin
    if t>ans then ans:=t;
    if n-t>ans then ans:=n-t;
    exit;
  end;
  for i:=0 to 1 do
  begin
    f:=false;
    for j:=1 to m do
    begin
      if a[j]=k then
        if b[j]<k then
          if i=c[b[j]] then
          begin
            f:=true;
            break;
          end;
      if b[j]=k then
        if a[j]<k then
          if i=c[a[j]] then
          begin
            f:=true;
            break;
          end;
    end;
    if f then continue;
    c[k]:=i;
    dfs(k+1,t+i);
  end;
end;
begin
  assign(input,'decorate.in'); assign(output,'decorate.out');
  reset(input); rewrite(output);
  readln(n,m);
  for i:=1 to m do readln(a[i],b[i]);
  ans:=-1;
  dfs(1,0);
  writeln(ans);
  close(input); close(output);
end.

