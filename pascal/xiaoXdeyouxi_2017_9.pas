//PrayerOJ 2002
var 
  vis: array[1..1000,1..1000] of boolean;
  n,m,q,x,y,i: longint;
function check(x,y:integer): byte;
begin
  if (x>0)and(x<=n)and(y>0)and(y<=m)and not vis[x,y]
    then
  begin
    vis[x,y] := true;
    exit(1);
  end
  else exit(0);
end;
begin
  read(n,m,q);
  for i:=1 to q do
  begin
    read(x,y);
    writeln(check(x,y)+check(x+1,y)+check(x-1,y)+check(x,y+1)+check(x,y-1));
  end;
end.
