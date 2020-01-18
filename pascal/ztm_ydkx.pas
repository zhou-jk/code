uses math;
var
  a,b:array[1..10000] of longint;
  c:array[1..10000] of longint;
  n,m,i,j,f,g:longint;
  t:int64;
  e:boolean;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    readln(a[i]);
    t:=t+a[i];
  end;
  t:=t div m;
  i:=1;
  while i<=m do
  begin
    e:=true;
    while (j<=n)and(abs(t-b[i])>abs(b[i]+a[j]-t)) do
    begin
      b[m]:=b[i]+a[j];
      if (a[j]<c[i])or e then
      begin
        c[i]:=a[j];
        e:=false;
      end;
      inc(j);
    end;
    inc(i);
  end;
  f:=1;
  while j<n do
  begin
    for i:=1 to m do
      if b[i]<b[f] then
        f:=i;
    inc(j);
    b[f]:=b[f]+a[j];
  end;
  f:=1;
  while i<m do
  begin
    for j:=1 to m do
      if b[i]>b[f] then
        f:=i;
    inc(i);
    b[f]:=b[f]-c[f];
    b[i]:=b[i]+c[f];
    g:=0;
    while g=0 do
    begin
      g:=1;
      for j:=1 to m do
       if b[i]>b[f] then
          f:=i;
      if abs(t-(b[f]-c[f]))+abs(t-(b[i]+c[f]))<abs(t-b[f])+abs(t-b[i]) then
      begin
        b[f]:=b[f]-c[f];
        b[i]:=b[i]+c[f];
        g:=0;
      end;
    end;
  end;
  for j:=1 to m do
    if b[i]>b[f] then
      f:=i;
  if abs(t-(b[f]-c[f]))+abs(t-(b[m]+c[f]))<abs(t-b[f])+abs(t-b[m]) then
  begin
    b[f]:=b[f]-c[f];
    b[i]:=b[m]+c[f];
  end;
  for j:=1 to m do
    if b[i]>b[f] then
      f:=i;
  writeln(f);
  readln;
end.













