//PrayerOJ 1418
uses math;
type arr=array[1..50000] of longint;
var
  n,i,j,k,p,q,l,r,t,ans:longint;
  v:array[1..50000] of boolean;
  s:array[1..12] of longint;
  x,y,hx,hy:arr;
procedure sort(var a,b:arr;l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[b[(l+r)div 2]];
  repeat
    while a[b[i]]<x do inc(i);
    while x<a[b[j]] do dec(j);
    if i<=j then
    begin
      y:=b[i]; b[i]:=b[j]; b[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(a,b,l,j);
  if i<r then sort(a,b,i,r);
end;
procedure add_(n:longint);
begin
  if not v[n] then
  begin
    inc(t);
    s[t]:=n; v[n]:=true;
  end;
end;
begin
  read(n);
  for i:=1 to n do
  begin
    read(x[i],y[i]);
    hx[i]:=i; hy[i]:=i;
  end;
  sort(x,hx,1,n); sort(y,hy,1,n);
  r:=min(4,(n+1)div 2); l:=max(n-3,(n+2)div 2); ans:=maxlongint;
  for i:=1 to r do
    for j:=l to n do
      for k:=1 to r do
        for p:=l to n do
        begin
          t:=0;
          for q:=1 to i-1 do add_(hx[q]);
          for q:=j+1 to n do add_(hx[q]);
          for q:=1 to k-1 do add_(hy[q]);
          for q:=p+1 to n do add_(hy[q]);
          if t<=3 then ans:=min(ans,(x[hx[j]]-x[hx[i]])*(y[hy[p]]-y[hy[k]]));
          for q:=1 to t do v[s[q]]:=false;
        end;
  write(ans);
end.