program htm_guowangfangzhi1357_shenso_2016_11_18_yh1_h;
const
  dy:array[1..8] of longint=(-1,0,1,-1,1,-1,0,1);
  dx:array[1..8] of longint=(-1,-1,-1,0,0,1,1,1);
var
  c:array[0..50,0..50] of longint;
  n,m,k,ans:longint;
procedure dfs(y,x,t:longint);
var
  i,ty,tx:longint;
begin
  if t=k then begin inc(ans); exit; end;
  if x=m+1 then begin dfs(y+1,1,t); exit; end;
  if y=n+1 then exit;
  dfs(y,x+1,t);
  if c[y,x]=0 then
  begin
    for i:=1 to 8 do
    begin
      ty:=y+dy[i]; tx:=x+dx[i];
      c[ty,tx]:=c[ty,tx]+1;
    end;
    dfs(y,x+1,t+1);
    for i:=1 to 8 do
    begin
      ty:=y+dy[i]; tx:=x+dx[i];
      c[ty,tx]:=c[ty,tx]-1;
    end;
  end;
end;
begin
  readln(n,m,k);
  dfs(1,1,0);
  writeln(ans);
end.
