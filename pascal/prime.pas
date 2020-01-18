//PrayerOJ 2004
var
  p:array[1..2000000] of longint;
  ip:array[1..4018233] of byte;
  l,r,i,j,t,m,ans:longint;
begin
  read(l,r);
  ip[1]:=2;
  for i:=2 to r do
  begin
    m:=2;
    if ip[i]=0 then
    begin
      inc(t);
      p[t]:=i;
      m:=1;
    end;
    for j:=1 to t do
    begin
      if i*p[j]>r then break;
      ip[i*p[j]]:=m;
      if i mod p[j]=0 then break;
    end;
  end;
  for i:=l to r do
    if ip[i]<2 then inc(ans);
  write(ans);
end.