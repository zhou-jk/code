program h_1245_mapengwenti_DB_2017_3_18;
var
  f:array[0..500,0..500]of longint;
  a,b:array[0..500]of integer;
  n,m,c,i,j,k:integer;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
begin
  readln(n,m);
  for i:=1 to n do f[i,0]:=1000000000;
  for i:=1 to m do f[0,i]:=1000000000;
  for i:=1 to n do
  begin
    readln(c);
    a[i]:=a[i-1]; b[i]:=b[i-1];
    if c=0
    then inc(a[i])
    else inc(b[i]);
    for j:=1 to m do
    begin
      f[i,j]:=maxlongint;
      for k:=1 to i do f[i,j]:=min(f[i,j],f[i-k,j-1]+(a[i]-a[i-k])*(b[i]-b[i-k]));
    end;
  end;
  writeln(f[n,m]);
end.
