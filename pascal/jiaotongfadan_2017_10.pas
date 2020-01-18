//PrayerOJ 2008
var
  n,m,l,t,len,k,i,j,p,a:longint;
  s:array[1..100] of longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  read(n,m);
  for i:=1 to n do
  begin
    read(l,t);
    for j:=1 to l do
    begin
      inc(p);
      s[p]:=t;
    end;
  end;
  p:=0;
  for i:=1 to n do
  begin
    read(len,k);
    for j:=1 to len do
    begin
      inc(p);
      a:=max(a,k-s[p]);
    end;
  end;
  write(a);
end.
