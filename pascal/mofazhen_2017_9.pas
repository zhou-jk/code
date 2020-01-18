//PrayerOJ 1689  luogu 2119
var
  s,t,a,b,c,d:array[0..15000] of longint;
  x:array[1..40000] of integer;
  n,m,i,j:word;
begin
  read(n,m);
  for i:=1 to m do
  begin
    read(x[i]);
    inc(s[x[i]]);
  end;
  for i:=1 to (n-1)div 9 do
  begin
    t[n-i+1]:=0;
    for j:=n-i downto 8*i+1 do t[j]:=t[j+1]+s[j]*s[j+i];
    for j:=1 to n-9*i-1 do
    begin
      inc(a[j],s[j+2*i]*t[j+8*i+1]); inc(b[j+2*i],s[j]*t[j+8*i+1]);
    end;
    t[0]:=0;
    for j:=1 to n-9*i-1 do t[j]:=t[j-1]+s[j]*s[j+2*i];
    for j:=8*i+1 to n-i do
    begin
      inc(c[j],s[j+i]*t[j-8*i-1]); inc(d[j+i],s[j]*t[j-8*i-1]);
    end;
  end;
  for i:=1 to m do writeln(a[x[i]],' ',b[x[i]],' ',c[x[i]],' ',d[x[i]]);
end.