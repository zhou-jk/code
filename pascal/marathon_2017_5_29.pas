var
  f:array[1..500,0..500] of longint;
  x,y:array[1..500] of integer;
  n,k,i,j,p:integer;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
begin
  assign(input,'marathon.in'); assign(output,'marathon.out');
  reset(input); rewrite(output);
  readln(n,k);
  for i:=1 to n do readln(x[i],y[i]);
  fillchar(f,sizeof(f),127);
  f[1,0]:=0;
  for i:=2 to n do
    for j:=0 to min(i-2,k) do
      for p:=i-j-1 to i-1 do
        f[i,j]:=min(f[i,j],f[p,j-i+p+1]+abs(x[i]-x[p])+abs(y[i]-y[p]));
  writeln(f[n,k]);
  close(input); close(output);
end.
