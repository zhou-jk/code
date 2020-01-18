var
  i,n,k,j:longint;
  a,b:ansistring;
begin
  readln(n);
  i:=3;
  a:='moo';
  while i<n do
  begin
    inc(k);
    b:=a;
    a:=a+'m';
    for j:=1 to k+2 do
      a:=a+'o';
    a:=a+b;
    i:=i+k+3+i;
  end;
  writeln(a[n]);
  readln;
end.



