program h_1939_juxingfenge_tanxin_2017_7_30;
var
  v,s:array[1..1999] of longint;
  n,m,t,i,n1,n2,ans:longint;
procedure calc(v,s:longint;var s1:longint);
begin
  ans:=ans+v*s;
  inc(s1);
end;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=v[(l+r)div 2];
  repeat
    while v[i]>x do inc(i);
    while x>v[j] do dec(j);
    if i<=j then
    begin
      y:=v[i]; v[i]:=v[j]; v[j]:=y;
      y:=s[i]; s[i]:=s[j]; s[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n,m);
  t:=n+m-2;
  for i:=1 to n-1 do
  begin
    read(v[i]);
    s[i]:=1;
  end;
  for i:=n to t do
  begin
    read(v[i]);
    s[i]:=2;
  end;
  sort(1,t);
  for i:=1 to t do
    if s[i]=1
    then calc(v[i],n2+1,n1)
    else calc(v[i],n1+1,n2);
  writeln(ans);
end.
