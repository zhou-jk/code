program h_1964_suiying_2017_8_6;
var
  g,t,t1,h1,h:array[1..1000000] of longint;
  n,i:longint;
  s,ans:int64;
procedure mergesort(l,r:longint);
var m,i,j,k:longint;
begin
  if l=r then exit;
  m:=(l+r)div 2;
  mergesort(l,m); mergesort(m+1,r);
  i:=l; j:=m+1; k:=l;
  while (i<=m)and(j<=r) do
  begin
    if g[i]<=g[j]
    then begin
           t[k]:=g[i]; t1[k]:=h1[i];
           inc(i);
         end
    else begin
           t[k]:=g[j]; t1[k]:=h1[j];
           inc(j);
           inc(s,m-i+1);
         end;
    inc(k);
  end;
  while i<=m do
  begin
    t[k]:=g[i]; t1[k]:=h1[i];
    inc(i); inc(k);
  end;
  while j<=r do
  begin
    t[k]:=g[j]; t1[k]:=h1[j];
    inc(j); inc(k);
  end;
  for i:=l to r do
  begin
    g[i]:=t[i]; h1[i]:=t1[i];
  end;
end;
begin
  readln(n);
  for i:=1 to n do readln(g[i]);
  for i:=1 to n do h1[i]:=i;
  mergesort(1,n);
  for i:=1 to n do h[h1[i]]:=i;
  ans:=s;
  for i:=1 to n-1 do
  begin
    s:=s+(n-h[i])-(h[i]-1);
    //writeln('%',s);
    if s<ans then ans:=s;
  end;
  writeln(ans);
end.