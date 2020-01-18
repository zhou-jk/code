var
  f:array[0..30,0..30] of longint;
  t,n,m,k,i,j,p,q:integer;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
function s(a,b:longint):longint;
begin
  s:=a div b;
  if a mod b>0 then inc(s);
end;
begin
  assign(input,'chocolate.in'); assign(output,'chocolate.out');
  reset(input); rewrite(output);
  readln(t);
  for i:=1 to t do
  begin
    readln(n,m,k);
    for j:=1 to n do
      for p:=1 to m do f[j,p]:=maxlongint div 2;
    for j:=1 to k do
      if k mod j=0 then
      begin
        f[j,k div j]:=0;
        f[k div j,j]:=0;
      end;
    for j:=1 to n do
      for p:=s(k,j) to m do
      begin
        for q:=s(k,j) to p do f[j,p]:=min(f[j,p],f[j,q]+j*j);
        for q:=s(k,p) to j do f[j,p]:=min(f[j,p],f[q,p]+p*p);
      end;
    writeln(f[n,m]);
  end;
  close(input); close(output);
end.