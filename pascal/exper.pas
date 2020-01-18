var
  a:array[1..1000000] of longint;
  n,i:longint;
  ans:int64;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  assign(input,'exper.in'); assign(output,'exper.out');
  reset(input); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=2 to n do inc(ans,max(a[i],a[i-1]));
  write(ans);
  close(input); close(output);
end.