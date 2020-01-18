//PrayerOJ 1666
const
  dx:array[1..4] of integer=(-1,0,1,0);
  dy:array[1..4] of integer=(0,1,0,-1);
var
  h:array[1..500,1..500] of longint;
  v:array[1..500,1..500] of boolean;
  x,y:array[1..250000] of integer;
  m,n,i,j,t,f,l,r,mid:longint;
procedure dfs(x,y:integer);
var i,tx,ty:integer;
begin
  v[x,y]:=false;
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>=1)and(tx<=m)and(ty>=1)and(ty<=n)and v[tx,ty]and(abs(h[tx,ty]-h[x,y])<=mid) then dfs(tx,ty);
  end;
end;
function check:boolean;
begin
  fillchar(v,250000,1);
  dfs(x[1],y[1]);
  for i:=1 to t do
    if v[x[i],y[i]] then exit(false);
  exit(true);
end;
begin
  read(m,n);
  for i:=1 to m do
    for j:=1 to n do
    begin
      read(h[i,j]);
      if h[i,j]>r then r:=h[i,j];
    end;
  x[1]:=1; y[1]:=1;
  for i:=1 to m do
    for j:=1 to n do
    begin
      read(f);
      if f=1 then
      begin
        inc(t);
        x[t]:=i; y[t]:=j;
      end;
    end;
  while l<=r do
  begin
    mid:=(l+r)div 2;
    if check
    then r:=mid-1
    else l:=mid+1;
  end;
  write(l);
end.