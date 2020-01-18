var
  g:array[1..1000,1..1000] of longint;
  q,s,f:array[1..1000] of longint;
  n,e,d,a,t1,t2,i,j,k,ans:longint;
procedure swap(var a,b:longint);
begin
  t2:=a; a:=b; b:=t2;
end;
procedure min(var a:longint;b:longint);
begin
  if b<a then a:=b;
end;
procedure max(var a:longint;b:longint);
begin
  if b>a then a:=b;
end;
procedure sort(l,r:longint);
var
  i,j:longint;
begin
  i:=l; j:=r; t1:=q[(l+r)div 2];
  repeat
    while q[i]<t1 do inc(i);
    while t1<q[j] do dec(j);
    if i<=j then
    begin
      swap(q[i],q[j]); swap(s[i],s[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'buffet.in'); assign(output,'buffet.out');
  reset(input); rewrite(output);
  read(n,e);
  fillchar(g,sizeof(g),63);
  for i:=1 to n do
  begin
    s[i]:=i;
    read(q[i],d);
    for j:=1 to d do
    begin
      read(a);
      g[i,a]:=e;
    end;
  end;
  sort(1,n);
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do min(g[i,j],g[i,k]+g[k,j]);
  for i:=2 to n do
  begin
    for j:=1 to i-1 do max(f[i],f[j]-g[s[j],s[i]]);
    inc(f[i],q[i]);
    max(ans,f[i]);
  end;
  write(ans);
  close(input); close(output);
end.