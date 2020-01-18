program h_1952_jianhua_Kruskal_2017_8_3_WA;
var
  a,b,c:array[0..100000] of longint;
  f1:array[1..1000000] of byte;
  f:array[1..40000] of longint;
  n,m,i,t,x,y,l,s,count:longint;
function gf1(k:longint):longint;
begin
  if f[k]=k then exit(k);
  exit(gf1(f[k]));
end;
function gf(k:longint):longint;
begin
  if f[k]=k then exit(k);
  f[k]:=gf(f[k]);
  exit(f[k]);
end;
procedure dfs(s,p,k:longint);
var x,y:longint;
begin
  //writeln(s,' ',p,' ',k);
  if s=0 then
  begin
    inc(count);
    exit;
  end;
  //writeln('%');
  if c[p+k]<>c[p] then exit;
  //writeln('%');
  x:=gf1(a[p+k]); y:=gf1(b[p+k]);
  if x<>y then
  begin
    f[x]:=y;
    dfs(s-1,p,k+1);
    f[x]:=x;
  end;
  dfs(s,p,k+1);
end;
procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:longint);
var i,j,x:longint;
begin
  i:=l; j:=r; x:=c[(l+r)div 2];
  repeat
    while c[i]<x do inc(i);
    while x<c[j] do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]); swap(b[i],b[j]); swap(c[i],c[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n,m);
  for i:=1 to m do readln(a[i],b[i],c[i]);
  for i:=1 to n do f[i]:=i;
  sort(1,m);
  i:=0;
  while t<n-1 do
  begin
    inc(i);
    x:=gf(a[i]); y:=gf(b[i]);
    if x<>y then
    begin
      f[x]:=y;
      inc(t); inc(f1[c[i]]);
      l:=(l+c[i])mod 1000000007;
    end;
  end;
  for i:=1 to n do f[i]:=i;
  i:=0; t:=0; s:=1;
  while t<n-1 do
  begin
    inc(i);
    //writeln('%',i,' ',t);
    if c[i]>c[i-1] then
    begin
      count:=0;
      dfs(f1[c[i]],i,0);
      s:=s*count mod 1000000007;
    end;
    //writeln('%',i,' ',t);
    x:=gf(a[i]); y:=gf(b[i]);
    if x<>y then
    begin
      f[x]:=y;
      inc(t);
    end;
  end;
  writeln(l,' ',s);
end.

