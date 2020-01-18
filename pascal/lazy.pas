var
  g1,f:array[0..1000000] of longint;
  n,k,i,min,g,x,max,sum,ans:longint;
function ma(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
function mi(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  assign(input,'lazy.in'); assign(output,'lazy.out');
  reset(input); rewrite(output);
  readln(n,k);
  min:=maxlongint;
  for i:=1 to n do
  begin
    readln(g,x);
    g1[x]:=g;
    max:=ma(x,max); min:=mi(x,min);
  end;
  for i:=min to max do f[i]:=f[i-1]+g1[i];
  for i:=min to max do
  begin
    sum:=f[mi(i+k,max)]-f[ma(i-k-1,min-1)];
    if sum>ans then ans:=sum;
  end;
  writeln(ans);
  close(input); close(output);
end.
