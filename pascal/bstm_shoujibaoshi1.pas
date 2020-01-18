var
  a:array[1..1000] of longint;
  b:array[1..10000] of longint;
  i,j,n,k,c,d:longint;
begin
  readln(n,k);
  for i:=1 to n do
    readln(a[i]);
  for i:=1 to n do
    inc(b[a[i]]);
  j:=1;
  for i:=1 to 10000 do
    while b[i]>0 do begin a[j]:=i; inc(j); b[i]:=b[i]-1; end;
  for i:=1 to n do
  begin
    c:=1;
    for j:=i+1 to n do
      if a[j]-a[i]<=k
      then inc(c)
      else break;
    if c>d then
      d:=c;
  end;
  writeln(d);
end.



