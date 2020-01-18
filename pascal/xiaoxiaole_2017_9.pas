//PrayerOJ 1424
//WA
var
  f:array[0..248,1..287] of boolean;
  a:array[1..248] of byte;
  n,i,j,t,ans:integer;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a[i]);
    f[i,a[i]]:=true;
    j:=i-1; t:=a[i];
    while f[j,t] do
    begin
      dec(j,t-a[j]+1); inc(t);
      f[i,t]:=true;
    end;
    if t>ans then ans:=t;
  end;
  write(ans);
end.



