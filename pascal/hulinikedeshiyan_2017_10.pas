//PrayerOJ 1613
var
  n,i,a,a1:longint;
  ans:int64;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  read(n,a1);
  for i:=2 to n do
  begin
    read(a);
    inc(ans,max(a,a1));
    a1:=a;
  end;
  write(ans);
end.