//PrayerOJ 2087
var g1,g2,k,a,b,x,y,i:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  read(g1,g2,k);
  if g1=g2 then
  begin
    write(0);
    exit;
  end;
  for i:=1 to k do
  begin
    read(a,x,b,y);
    g1:=max(g1+a*x,0); g2:=max(g2+b*y,0);
    if g1=g2 then
    begin
      write(i);
      exit;
    end;
  end;
  write(-1);
end.