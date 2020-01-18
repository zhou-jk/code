var
  a:array[1..10000] of integer;
  n,i,b:integer;
  sum,ans:longint;
begin
  assign(input,'haybales.in');
  assign(output,'haybales.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do begin readln(a[i]); inc(sum,a[i]); end;
  b:=sum div n;
  for i:=1 to n do
    if a[i]>b then inc(ans,a[i]-b);
  writeln(ans);
  close(input);
  close(output);
end.
