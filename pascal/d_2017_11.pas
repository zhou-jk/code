type n=array[0..100] of byte;
const c:array[1..3] of char=('L','P','R');
var
  a:array[1..10000] of integer;
  s:ansistring;
  i,j,l,t,t1,t2:integer;
  t3,ans,one:n;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  exit(b);
end;
function plus(a,b:n):n;
begin
  //fillchar(plus,sizeof(plus),0);
  t1:=max(a[0],b[0]);
  for i:=1 to t1 do
  begin
    plus[i]:=a[i]+b[i]+t2;
    t2:=plus[i]div 10;
    plus[i]:=plus[i]mod 10;
  end;
  plus[0]:=t1;
  if t2>0 then
  begin
    plus[0]:=t1+1;
    plus[plus[0]]:=t2;
  end;
end;
function x:n;
begin
  //fillchar(x,sizeof(x),0);
  //writeln('{');
  for i:=1 to t3[0] do
  begin
    //writeln('*',i);
    x[i]:=t3[i]*2+t2;
    //writeln('#1');
    t2:=x[i]div 10;
    //writeln('#2');
    x[i]:=x[i]mod 10;
  end;
  //writeln('*');
  x[0]:=t3[0];
  if t2>0 then
  begin
    inc(x[0]);
    x[x[0]]:=t2;
  end;
  //writeln('}');
end;
procedure solve;
var i:integer;
begin
  writeln('(');
  t3[0]:=1; t3[1]:=1;
  for i:=1 to l do
  begin
    case s[i] of
      'L':t3:=x;
      'R':t3:=plus(x,one);
    end;
    for j:=t3[0] downto 1 do write(t3[j]);
    writeln('&',l,' ',i);
  end;
  ans:=plus(ans,t3);
  writeln(')');
end;
procedure dfs(k:integer);
var i:byte;
begin
  //writeln(k);
  if k=t+1 then
  begin
    solve;
    exit;
  end;
  for i:=1 to 3 do
  begin
    s[a[k]]:=c[i];
    dfs(k+1);
  end;
end;
begin
  //assign(input,'d.in'); assign(output,'d.out');
  //reset(input); rewrite(output);
  readln(s);
  l:=length(s);
  writeln(l);
  for i:=1 to l do
    if s[i]='*' then
    begin
      inc(t);
      a[t]:=i;
    end;
  one[0]:=1; one[1]:=1; ans[0]:=1; ans[1]:=0;
  dfs(1);
  for i:=ans[0] downto 1 do write(ans[i]);
  //close(input); close(output);
end.