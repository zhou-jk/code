program h_1181_jiuzhenqushuyouxigaojingduban_DP_2017_4_15;
type num=array[0..100] of longint;
var
  f:array[0..81,0..81] of num;
  a:array[1..80] of integer;
  n,m,i,j,k:byte;
  ans:num;
procedure o(a:num);
var i:byte;
begin
  for i:=a[0] downto 1 do write(a[i]);
  writeln;
end;
function max(a,b:num):num;
var i:byte;
begin
  if a[0]>b[0] then exit(a);
  if b[0]>a[0] then exit(b);
  for i:=a[0] downto 1 do
  begin
    if a[i]>b[i] then exit(a);
    if b[i]>a[i] then exit(b);
  end;
  max:=b;
end;
function max1(a,b:byte):byte;
begin
  if a>b then exit(a);
  max1:=b;
end;
function plus(a,b:num):num;
var i,t:byte;
begin
  t:=0; fillchar(plus,sizeof(plus),0);
  for i:=1 to max1(a[0],b[0]) do
  begin
    plus[i]:=a[i]+b[i]+t;
    t:=plus[i]div 10;
    plus[i]:=plus[i]mod 10;
  end;
  plus[0]:=i;
  if t>0 then
  begin
    plus[i+1]:=t;
    inc(plus[0]);
  end;
end;
function plus1(a:integer;b:num):num;
var i:byte;
begin
  fillchar(plus1,sizeof(plus1),0);
  i:=0; plus1:=b;
  while a>0 do
  begin
    inc(i);
    plus1[i]:=b[i]+a;
    a:=plus1[i]div 10;
    plus1[i]:=plus1[i]mod 10;
  end;
  plus1[0]:=max1(i,b[0]);
end;
function x(a:num;b:integer):num;
var i,t:integer;
begin
  t:=0; fillchar(x,sizeof(x),0);
  if (b=0)or(a[0]=1)and(a[1]=0) then
  begin
    x[0]:=1;
    exit;
  end;
  for i:=1 to a[0] do
  begin
    x[i]:=a[i]*b+t;
    t:=x[i]div 10;
    x[i]:=x[i]mod 10;
  end;
  while t>0 do
  begin
    inc(i);
    x[i]:=t mod 10;
    t:=t div 10;
  end;
  x[0]:=i;
end;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[j]);
    fillchar(f,sizeof(f),0);
    for j:=m downto 1 do
      for k:=j to m do
        f[j,k]:=x(max(plus1(a[j],f[j+1,k]),plus1(a[k],f[j,k-1])),2);
    ans:=plus(ans,f[1,m]);
  end;
  o(ans);
end.



