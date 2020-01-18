var
  t:array[1..40001] of longint;
  s:array[1..40000] of boolean;
  n,x,y,z,i,j,a,b,ans:longint;
procedure sort(l,r:longint);
var
  i,j,x,y:longint;
  b:boolean;
begin
  i:=l; j:=r; x:=t[(l+r)div 2];
  repeat
    while t[i]<x do inc(i);
    while x<t[j] do dec(j);
    if i<=j then
    begin
      y:=t[i]; t[i]:=t[j]; t[j]:=y;
      b:=s[i]; s[i]:=s[j]; s[j]:=b;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'milktemp.in'); assign(output,'milktemp.out');
  reset(input); rewrite(output);
  readln(n,x,y,z);
  for i:=1 to n do
  begin
    readln(t[i*2-1],t[i*2]);
    s[i*2-1]:=true;
    inc(t[i*2]);
  end;
  sort(1,2*n);
  ans:=n*x; t[2*n+1]:=maxlongint;
  for i:=1 to 2*n do
  begin
    if s[i]
    then inc(a)
    else begin
           dec(a);
           inc(b);
         end;
    if (t[i]<t[i+1])and(a*y+b*z+(n-a-b)*x>ans) then ans:=a*y+b*z+(n-a-b)*x;
  end;
  writeln(ans);
  close(input); close(output);
end.


