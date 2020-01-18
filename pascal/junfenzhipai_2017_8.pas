program junfenzhipai_2017_8_19;
//PrayerOJ 1232
var
  a:array[1..100] of integer;
  n,i,avg,s,s1,t,ans:longint;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a[i]);
    inc(avg,a[i]);
  end;
  avg:=avg div n;
  for i:=1 to n do
  begin
    if s>0 then inc(ans);
    s1:=s;
    inc(s,a[i]-avg);
    if (s1>=0)and(s<0) then t:=i;
    if (s1<0)and(s>=0) then inc(ans,i-t);
  end;
  write(ans);
end.

