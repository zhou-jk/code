program htm_guowangfangzhi1357_shenso_2016_11_15;
const
  dy:array[1..8] of integer=(-1,0,1,-1,1,-1,0,1);
  dx:array[1..8] of integer=(-1,-1,-1,0,0,1,1,1);
var
  c:array[-1..20,-1..20] of boolean;
  n,m,k,ans:integer;
procedure dfs(y,x,t:integer);
var
  i,ty,tx:integer;
  b:array[1..8] of boolean;
begin
  if x>=m then begin x:=x-m; inc(y); end;
  if t=k then begin inc(ans); exit; end;
  if y=n then exit;
  if m-x+m*(n-1-y)+1<2*(k-t) then exit;
  {ty:=y; tx:=x+1;
  if tx>=m then begin inc(ty); tx:=tx-m; end;
  while c[ty,tx] do
  begin
    inc(tx);
    if tx>=m then begin inc(ty); tx:=tx-m; end;
  end;
  if ty<n then dfs(ty,tx,t);}
  dfs(y,x+1,t);
  if not c[y,x] then
  begin
    for i:=1 to 8 do
    begin
      ty:=y+dy[i]; tx:=x+dx[i];
      b[i]:=c[ty,tx];
      c[ty,tx]:=true;
    end;
    if ty<n then dfs(y,x+1,t+1);
    for i:=1 to 8 do
    begin
    ty:=y+dy[i]; tx:=x+dx[i];
    c[ty,tx]:=b[i];
    end;
  end;
end;
begin
  readln(n,m,k);
  if k=1
  then ans:=n*m
  else dfs(0,0,0);
  writeln(ans);
end.
