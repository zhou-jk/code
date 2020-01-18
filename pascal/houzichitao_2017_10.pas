//PrayerOJ 2053
var
  s,s1:array[1..10000] of char;
  n,m,l,r,c,i,j,t1,a:longint;
  t:array[1..20000] of char;
begin
  readln(n); readln(s); readln(s1);
  read(m);
  for i:=1 to m do
  begin
    read(l,r,c);
    t1:=r-l+1; c:=c mod t1;
    for j:=l to r do
    begin
      t[j]:=s[j]; t[j+t1]:=s[j];
    end;
    for j:=l to r do s[j]:=t[j+t1-c];
  end;
  for i:=1 to n do
    if s[i]=s1[i] then inc(a);
  write(a);
end.