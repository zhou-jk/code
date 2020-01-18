program htm_guowangfangzhi1357_shenso_2016_11_18_yh_z;
const
  dy:array[1..8] of integer=(-1,0,1,-1,1,-1,0,1);
  dx:array[1..8] of integer=(-1,-1,-1,0,0,1,1,1);
var
  c:array[-1..100,-1..100] of boolean;
  n,m,k,ans:integer;
procedure dfs(y,x,t:integer);
var
  i,ty,tx:integer;
  b:array[1..8] of boolean;
begin
  if t=k then begin inc(ans); exit; end;
  repeat
    while c[y,x] do
    begin
      inc(x);
      if x>=m then begin inc(y); tx:=x-m; end;
    end;
    for i:=1 to 8 do
    begin
      ty:=y+dy[i]; tx:=x+dx[i];
      b[i]:=c[ty,tx];
      c[ty,tx]:=true;
    end;
    dfs(y,x,t+1);
    for i:=1 to 8 do
    begin
      ty:=y+dy[i]; tx:=x+dx[i];
      c[ty,tx]:=b[i];
    end;
    inc(tx);
    if tx=m then
    begin
      inc(ty);
      tx:=0;
    end;
    if ty=n then exit;
  until false;
end;
begin
  readln(n,m,k);
  if k=1
  then ans:=n*m
  else dfs(0,0,0);
  writeln(ans);
end.
