program h_1937_shuzichuan_2017_7_30;
var
  a,b:array[1..200000] of longint;
  n,m,i,l,r,mid,s:longint;
function pd(l:longint):boolean;
begin
  fillchar(b,sizeof(b),0);
  s:=m;
  for i:=1 to l do
  begin
    if b[a[i]]=0 then dec(s);
    inc(b[a[i]]);
  end;
  if s=0 then exit(true);
  for i:=1 to n-l do
  begin
    dec(b[a[i]]);
    if b[a[i]]=0 then inc(s);
    if b[a[i+l]]=0 then dec(s);
    inc(b[a[i+l]]);
    if s=0 then exit(true);
  end;
  exit(false);
end;
begin
  readln(n,m);
  if (m>n)or(m>100000) then
  begin
    writeln('NO');
    exit;
  end;
  s:=m;
  for i:=1 to n do
  begin
    read(a[i]);
    if b[a[i]]=0 then dec(s);
    inc(b[a[i]]);
  end;
  if s>0 then
  begin
    writeln('NO');
    exit;
  end;
  l:=m; r:=n;
  while l<=r do
  begin
    mid:=(l+r)div 2;
    if pd(mid)
    then r:=mid-1
    else l:=mid+1;
  end;
  writeln(l)
end.
