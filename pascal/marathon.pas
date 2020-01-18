var
  x,y,f:array[1..100000] of integer;
  n,i,sum,an,ans:longint;
begin
  assign(input,'marathon.in'); assign(output,'marathon.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  for i:=2 to n do
  begin
    f[i]:=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
    inc(sum,f[i]);
  end;
  ans:=sum;
  for i:=2 to n-1 do
  begin
    an:=sum-f[i]-f[i+1]+abs(x[i+1]-x[i-1])+abs(y[i+1]-y[i-1]);
    if an<ans then ans:=an;
  end;
  writeln(ans);
  close(input); close(output);
end.

