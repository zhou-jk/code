program codevs_3278_zuixiaoMduanhewenti_DP_2017_4_9;
uses math;
var
  f:array[0..1000,0..1000] of longint;
  sum:array[0..1000] of longint;
  n,m,num,i,j,k:integer;
{function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;}
begin
  readln(n,m);
  for i:=1 to n do
  begin
    read(num);
    sum[i]:=sum[i-1]+num; f[i,1]:=sum[i];
    for j:=2 to m do
    begin
      f[i,j]:=maxlongint;
      for k:=j-1 to i-1 do f[i,j]:=min(f[i,j],max(f[k,j-1],sum[i]-sum[k]));
    end;
  end;
  writeln(f[n,m]);
end.
