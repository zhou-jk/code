program htm_1077_caishuzi_dfs_2017_1_25;
var
  a:array[1..11] of int64;
  s,s1:array[0..9] of integer;
  n,jc,i:longint;
  m:int64;
procedure js;
var
  sum,x:int64;
  xx:string;
  i,j:integer;
begin
  sum:=-m;
  //writeln('&',sum);
  for i:=1 to n do
    for j:=1 to 9 do {begin} sum:=sum+j*jc*a[i]*s[j]; {writeln('$',j*a[i],' ',s[j],' ',jc); end;}
  //writeln('#',sum);
  if sum<0 then exit;
  x:=sum;
  fillchar(s1,sizeof(s1),0);
  for i:=1 to n do
  begin
    inc(s1[sum mod 10]);
    sum:=sum div 10;
  end;
  for i:=0 to 9 do
    if s1[i]<>s[i] then exit;
  str(x,xx);
  if length(xx)>n then exit;
  for i:=1 to n-length(xx) do write(0);
  writeln(x);
  halt;
end;
procedure dfs(k,t:integer);
var i:integer;
begin
  if t=0 then
  begin
    js;
    exit;
  end;
  if k=9 then
  begin
    s[9]:=t;
    dfs(10,0);
    s[9]:=0;
    exit;
  end;
  for i:=0 to t do
  begin
    s[k]:=i;
    dfs(k+1,t-i);
    s[k]:=0;
  end;
end;
begin
  //assign(output,'aacaishuzi.out');
  //rewrite(output);
  readln(n);
  readln(m);
  jc:=1;
  for i:=2 to n-1 do jc:=jc*i;
  //writeln('%',jc);
  a[1]:=1;
  for i:=2 to n do a[i]:=a[i-1]*10;
  dfs(0,n);
  //close(output);
end.


