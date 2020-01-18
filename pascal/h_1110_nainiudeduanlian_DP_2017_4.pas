program h_1110_nainiudeduanlian_DP_2017_4_15;
var
  f:array[0..10000,0..500] of longint;
  sum:array[0..10000] of longint;
  n,m,d,i,j,k:integer;
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
begin
  readln(n,m);
  fillchar(f,sizeof(f),255);
  f[0,0]:=0;
  for i:=1 to n do
  begin
    readln(d); sum[i]:=sum[i-1]+d; f[i,0]:=f[i-1,0];
    for j:=max(0,i-m) to i-1 do
    begin
      f[i,i-j]:=f[j,0]+sum[i]-sum[j];
      f[i,0]:=max(f[i,0],f[j,i-j]);
    end;
  end;
  writeln(f[n,0]);
end.

