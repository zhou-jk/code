program codevs_2102_shiziguibing2_DB_2017_4_2;
var
  f,g:array[1..200,1..200] of longint;
  w:array[1..200] of integer;
  n,i,j,k,p,ans,ans1:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;
function sum(l,r:byte):longint;
var i:byte;
begin
  sum:=0;
  for i:=l to r do inc(sum,w[i]);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(w[i]);
    w[i+n]:=w[i];
  end;
  for i:=2 to 2*n-1 do
    for j:=1 to 2*n-i do
    begin
      k:=j+i-1; f[j,k]:=maxlongint;
      for p:=j to k-1 do
      begin
        f[j,k]:=min(f[j,k],f[j,p]+f[p+1,k]); g[j,k]:=max(g[j,k],g[j,p]+g[p+1,k]);
      end;
      inc(f[j,k],sum(j,k)); inc(g[j,k],sum(j,k));
    end;
  ans:=maxlongint;
  for i:=1 to n do
  begin
    ans:=min(ans,f[i,i+n-1]); ans1:=max(ans1,g[i,i+n-1]);
  end;
  writeln(ans); writeln(ans1);
end.
