program h_1182_tuixiaoyuan_DP_2017_8_4;
var
  f:array[0..2000,0..2000] of longint;
  s,a:array[1..2000] of longint;
  n,i,j,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  readln(n);
  for i:=1 to n do read(s[i]);
  for i:=1 to n do read(a[i]);
  // haven't need
  fillchar(f,sizeof(f),255); //$80 very small
  for i:=0 to n do f[i,0]:=0;
  //
  for i:=1 to n do
    for j:=1 to i do f[i,j]:=max(f[i-1,j],f[i-1,j-1]+a[i]);
  for i:=1 to n do
  begin
    ans:=-maxlongint;
    for j:=i to n do ans:=max(ans,a[j]+2*s[j]+f[j-1,i-1]);
    writeln(ans);
  end;
end.