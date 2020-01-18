//PrayerOJ 1114
var
  n,ans,t,i,j,k:longint;
begin
  read(n);
  t:=(n+1)div 2;
  for i:=1 to t-1 do
    for j:=1 to t-1 do
    begin
      k:=n-i-j;
      if k<=1 then break;
      if k<=t
      then inc(ans,k-1)
      else inc(ans,k-1-2*(k-t));
    end;
  write(ans);
end.