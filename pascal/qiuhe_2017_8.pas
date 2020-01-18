//PrayerOJ 1207
var
  number,color:array[1..100000] of longint;
  s:array[1..100000,0..300] of longint;
  n,m,i,j,ans:longint;
begin
  read(n,m);
  for i:=1 to n do read(number[i]);
  for i:=1 to n do read(color[i]);
  i:=1;
  while i<=n do
  begin
    for j:=1 to s[color[i],0] do ans:=(ans+(s[color[i],j]+i)*(number[s[color[i],j]]+number[i]))mod 10007;
    inc(s[color[i],0]); s[color[i],s[color[i],0]]:=i;
    inc(i,2);
  end;
  for i:=1 to m do s[i,0]:=0;
  i:=2;
  while i<=n do
  begin
    for j:=1 to s[color[i],0] do ans:=(ans+(s[color[i],j]+i)*(number[s[color[i],j]]+number[i]))mod 10007;
    inc(s[color[i],0]); s[color[i],s[color[i],0]]:=i;
    inc(i,2);
  end;
  write(ans);
end.
