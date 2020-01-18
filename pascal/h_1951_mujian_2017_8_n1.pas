program h_1961_mujian_2017_8_5_n1;
var
  b,v:array[1..200000] of boolean;
  a:array[1..200000] of longint;
  m,n,s,i,j,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure stop;
begin
  writeln(0);
  halt;
end;
procedure sort(l,r:longint);
var
  i,j,x,y:longint;
  t:boolean;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      t:=b[i]; b[i]:=b[j]; b[j]:=t;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(m,n);
  if m>n then stop;
  s:=m+n;
  for i:=1 to m do
  begin
    readln(a[i]);
    b[i]:=true;
  end;
  for i:=m+1 to s do readln(a[i]);
  sort(1,s);
  for i:=1 to s do
    if b[i] then
    begin
      j:=max(i+1,j+1);
      if j>s then stop;
      while (a[j]=a[i])or b[j] do
      begin
        inc(j);
        if j>s then stop;
      end;
      v[j]:=true;
    end;
  for i:=1 to s do
    if not b[i]and not v[i] then inc(ans,a[i]);
  writeln(ans);
end.
