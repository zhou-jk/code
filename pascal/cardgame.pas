type arr=array[1..50000] of longint;
var
  v:array[1..100000] of boolean;
  n,i,j,t,tmp,s,s1:longint;
  a,b:arr;
procedure sort(var a:arr;l,r:longint);
var
  i,j,x:longint;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]>x do inc(i);
    while x>a[j] do dec(j);
    if i<=j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(a,l,j);
  if i<r then sort(a,i,r);
end;
begin
  assign(input,'cardgame.in'); assign(output,'cardgame.out');
  reset(input); rewrite(output);
  read(n);
  s1:=n div 2;
  for i:=1 to n do
  begin
    read(a[i]);
    v[a[i]]:=true;
  end;
  for i:=1 to 2*n do
    if not v[i] then
    begin
      inc(t);
      b[t]:=i;
    end;
  sort(a,1,n); sort(b,1,n);
  i:=1;j:=1;
  while j<=s1 do
  begin
    while (j<=s1)and(a[j]>b[i]) do inc(j);
    if j<=s1 then
    begin
      inc(s); inc(i); inc(j);
    end;
  end;
  i:=n; j:=n;
  while j>s1 do
  begin
    while (j>s1)and(a[j]<b[i]) do dec(j);
    if j>s1 then
    begin
      inc(s); dec(i); dec(j);
    end;
  end;
  write(s);
  close(input); close(output);
end.