//PrayerOJ 2074
var
  w,h,w1,h1,i:longint;
function min(a,b:byte):byte;
begin
  if a<b then exit(a);
  exit(b);
end;
function solve(l,l1:longint):byte;
begin
  solve:=0;
  while l>l1 do
  begin
    inc(solve);
    dec(l,l div 2);
  end;
end;
begin
  read(w,h,w1,h1);
  if (w1<=w)and(h1<=h)and(w1<=h)and(h1<=w)
  then write(min(solve(w,w1)+solve(h,h1),solve(w,h1)+solve(h,w1)))
  else if (w1<=w)and(h1<=h)
       then write(solve(w,w1)+solve(h,h1))
       else if (h1<=w)and(w1<=h)
            then write(solve(w,h1)+solve(h,w1))
            else write(-1);
end.