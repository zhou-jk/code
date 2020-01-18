uses math;
type arr=array[1..50000] of longint;
var
  a,b,r,g:arr;
  c:array[1..50000] of boolean;
  n,t,i,j,x,y,d,e1,e2,f1,f2:longint;
procedure px(s,t:longint;a:arr;var r:arr);
var
  m,k:longint;
begin
  if s>=t then exit;
  m:=(s+t) div 2;
  px(s,m);
  px(m+1,t);
  i:=s;
  j:=m+1;
  k:=s;
  while (i<=m)and(j<=t) do
    if a[i]<=a[j]
    then begin r[k]:=a[i]; inc(i); inc(k); end
    else begin r[k]:=a[j]; inc(j); inc(k); end;
  while i<=m do
  begin r[k]:=a[i]; inc(i); inc(k) end;
  while j<=t do
  begin r[k]:=a[j]; inc(j); inc(k) end;
end;
begin
  e2:=40000;
  d2:=40000;
  readln(n);
  for i:=1 to n do
  begin
    readln(a[i],b[i]);
    c[i]:=true;
  end;
  e1:=1; e2:=n; f1:=1; f2:=n;
  px(1,n,a,r);
  px(1,n,b,g);
  while d<3 do
  begin
    x:=max(r[e2]-r[e2-1],r[e1+1]-r[e1]);
    y:=max(g[f2]-g[f2-1],g[f1+1]-g[f1]);
    if x*(g[f2]-g[f1])>y*(r[e2]-r[e1])
    then if r[e2]-r[e2-1]>r[e1+1]-r[e1]
         then e2:=e2-1
         else inc(e1)
    else if g[f2]-g[f2-1]>g[f1+1]-g[f1]
         then f2:=f2-1
         else inc(f1);
    inc(d);
  end;
  t:=r[


