program jg_nixudui_mergesort_2017_5_14;
var
  a,t:array[1..1000000] of longint;
  n,i:longint;
  ans:qword;
procedure mergesort(l,r:longint);
var m,i,j,k:longint;
begin
  if l=r then exit;
  m:=(l+r)div 2;
  mergesort(l,m); mergesort(m+1,r);
  i:=l; j:=m+1; k:=l;
  while (i<=m)and(j<=r) do
  begin
    if a[i]<=a[j]
    then begin
           t[k]:=a[i];
           inc(i);
         end
    else begin
           t[k]:=a[j];
           inc(j); inc(ans,m-i+1);
         end;
    inc(k);
  end;
  while i<=m do
  begin
    t[k]:=a[i];
    inc(i); inc(k);
  end;
  while j<=r do
  begin
    t[k]:=a[j];
    inc(j); inc(k);
  end;
  for i:=l to r do a[i]:=t[i];
end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  mergesort(1,n);
  writeln(ans);
end.