program htm_1357_guowangfangzhi_dfs_2017_2_3;
type ar=array[1..8] of integer;
const
  dx:ar=(-1,-1,0,1,1,1,0,-1);
  dy:ar=(0,1,1,1,0,-1,-1,-1);
var
  a:array[1..100,1..100] of boolean;
  n,m,k,i,ans,tx,ty:longint;
procedure dfs(x,y,t:integer);
begin
  if t=k then
  begin
    inc(ans);
    exit;
  end;
  if x=n+1 then exit;
  if y=m+1
  then dfs(x+1,1,t)
  else begin
         dfs(x,y+1,t);
         for i:=1 to 8 do
         begin
           tx:=x+dx[i]; ty:=y+dy[i];
           if (tx<1)or(tx>n)or(ty<1)or(ty>m) then continue;
           if a[tx,ty] then exit;
         end;
         a[x,y]:=true;
         dfs(x,y+1,t+1);
         a[x,y]:=false;
       end;
end;
begin
  readln(n,m,k);
  dfs(1,1,0);
  writeln(ans);
end.
