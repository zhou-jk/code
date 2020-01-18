program h_1904_fajiangjin_tanxin_2017_7_22;
uses math;
var
  s,num:array[1..1030000] of longint;
  b:array[1..1030000] of boolean;
  a:array[1..30000] of longint;
  n,i,j,ans,ma:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    inc(s[a[i]]);
    ma:=max(ma,a[i]);
  end;
  for i:=1 to min(n+ma,1030000) do
    if s[i]=0 then
    begin
      inc(j);
      num[j]:=i;
    end;
  sort(1,n);
  j:=1;
  for i:=1 to n do
    while s[a[i]]>1 do
    begin
      while b[j]or(num[j]<a[i]) do inc(j);
      b[j]:=true;
      dec(s[a[i]]);
      ans:=ans+num[j]-a[i];
    end;
  writeln(ans);
end.
