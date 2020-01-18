program h_1660_fuzadeanniu_2017_7_24;
var
  l,r,a,s,ind:array[1..30000] of longint;
  g:array[1..1000000] of longint;
  n,m,b,i,j,t:longint;
function min(k1,k2:longint):longint;
begin
  if (k2>t)or(a[k1]<a[k2]) then exit(k1);
  exit(k2);
end;
procedure swap(k1,k2:longint);
var t:longint;
begin
  t:=s[k1]; s[k1]:=s[k2]; s[k2]:=t;
end;
procedure up(k:longint);
var f:longint;
begin
  f:=k div 2;
  while (k>1)and(s[f]>s[k]) do
  begin
    swap(f,k);
    k:=f; f:=k div 2;
  end;
end;
procedure down(k:longint);
var son:longint;
begin
  while k<=t div 2 do
  begin
    son:=min(k*2,k*2+1);
    if s[son]<s[k] then
    begin
      swap(son,k);
      k:=son;
    end
    else exit;
  end;
end;
procedure add_(u:longint);
begin
  inc(t);
  s[t]:=u;
  up(t);
end;
procedure del;
begin
  s[1]:=s[t];
  dec(t);
  down(1);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(m);
    l[i]:=t+1;
    for j:=1 to m do
    begin
      inc(t);
      read(g[t]);
      inc(ind[g[t]]);
    end;
    r[i]:=t;
  end;
  t:=0;
  for i:=1 to n do
    if ind[i]=0 then
    begin
      inc(t);
      s[t]:=i;    //add_(i) Chinese:本来就有序
    end;
  for i:=1 to n do
  begin
    if t=0 then
    begin
      writeln('no solution');
      exit;
    end;
    a[i]:=s[1];
    del;
    for j:=l[a[i]] to r[a[i]] do
    begin
      dec(ind[g[j]]);
      if ind[g[j]]=0 then add_(g[j]);
    end;
  end;
  writeln(n);
  for i:=1 to n do write(a[i],' ');
end.
