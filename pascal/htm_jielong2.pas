var
  i,n,k,j,c:longint;
  a,b:array[1..1000000000] of char;
begin
  readln(n);
  i:=3;
  k:=0;
  a[1]:='m';
  a[2]:='o';
  a[3]:='o';
  while i<n do
  begin
    inc(k);
    for j:=1 to c do
      b[j]:=a[j];
    inc(i);
    a[i]:='m';
    for i:=i+1 to i+k+2 do
      a[i]:='o';
    j:=0;
    for i:=i+1 to i+c do
    begin
      inc(j);
      a[i]:=b[j];
      if i=n then break;
    end;
    c:=i;
  end;
  writeln(a[n]);
  readln;
end.



