//PrayerOJ 2009 PrayerOJ 1294 bianzhideniunai
var
  a,b:array[1..50,1..1000] of longint;
  n,m,d,s,p,k,t,i,j,tmp,ans:longint;
  f:array[1..50,1..50] of boolean;
  r,v:array[1..50] of longint;
  bo:array[1..50] of boolean;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure swap(var a,b:longint);
begin
  tmp:=a; a:=b; b:=tmp;
end;
procedure sort(k,l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[k,(l+r)div 2];
  repeat
    while a[k,i]<x do inc(i);
    while x<a[k,j] do dec(j);
    if i<=j then
    begin
      swap(a[k,i],a[k,j]); swap(b[k,i],b[k,j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(k,l,j);
  if i<r then sort(k,i,r);
end;
begin
  read(n,m,d,s);
  for i:=1 to d do
  begin
    read(p,k,t);
    inc(r[p]);
    a[p,r[p]]:=t; b[p,r[p]]:=k;
    f[p,k]:=true;
  end;
  for i:=1 to n do
    if r[i]>1 then sort(i,1,r[i]);
  for i:=1 to s do
  begin
    read(p,t);
    fillchar(bo,50,1);
    for j:=1 to r[p] do
    begin
      if a[p,j]>=t then break;
      if bo[b[p,j]] then
      begin
        inc(v[b[p,j]]);
        bo[b[p,j]]:=false;
      end;
    end;
  end;
  for i:=1 to m do
    if v[i]=s then
    begin
      tmp:=0;
      for j:=1 to n do
        if f[j,i] then inc(tmp);
      ans:=max(ans,tmp);
    end;
  write(ans);
end.