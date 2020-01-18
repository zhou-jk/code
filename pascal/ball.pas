var
  v,t,id,s:array[1..500000] of longint;
  n,k,i,len,tmp,l,r,m:longint;
procedure swap(var a,b:longint);
begin
  tmp:=a; a:=b; b:=tmp;
end;
procedure sort(l,r:longint);
var i,j,x:longint;
begin
  i:=l; j:=r; x:=v[(l+r)div 2];
  repeat
    while v[i]<x do inc(i);
    while x<v[j] do dec(j);
    if i<=j then
    begin
      swap(v[i],v[j]); swap(id[i],id[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'ball.in'); assign(output,'ball.out');
  reset(input); rewrite(output);
  read(n,k);
  for i:=1 to n do
  begin
    read(v[i]);
    id[i]:=i;
  end;
  sort(1,n);
  for i:=1 to n do t[id[i]]:=(i-1)div k+1;
  len:=1; s[1]:=t[1];
  for i:=2 to n do
  begin
    if s[len]<=t[i] then
    begin
      inc(len);
      s[len]:=t[i];
      continue;
    end;
    l:=1; r:=len;
    while l<=r do
    begin
      m:=(l+r)div 2;
      if s[m]>t[i]
      then r:=m-1
      else l:=m+1;
    end;
    s[l]:=t[i];
  end;
  write(n-len);
  close(input); close(output);
end.