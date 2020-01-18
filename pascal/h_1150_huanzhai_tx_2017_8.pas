program h_1150_huanzhai_tanxin_2017_8_18;
var
  n,d,i,a,t,s,s1:longint;
begin
  read(n);
  for i:=1 to n do
  begin
    read(d);
    s1:=s; inc(s,d);
    if (s1>=0)and(s<0) then t:=i;
    if (s1<0)and(s>=0) then inc(a,(i-t)*2);
  end;
  write(a+n);
end.