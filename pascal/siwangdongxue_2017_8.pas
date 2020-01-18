//n
//PrayerOJ 1658
const
  dx:array[1..4] of integer=(-1,0,1,0);
  dy:array[1..4] of integer=(0,1,0,-1);
var
  n,m,vx,vy,jx,jy,t,i,j,l,r,mid:integer;
  v:array[1..500,1..500] of longint;
  x,y:array[1..250000] of integer;
  f:char;
function check
begin
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(f);
      if f='+' then
      begin
        inc(t);
        x[t]:=i; y[t]:=j;
      end;
      if f='V' then
      begin
        vx:=i; vy:=j;
      end;
      if f='J' then
      begin
        jx:=i; jy:=j;
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
