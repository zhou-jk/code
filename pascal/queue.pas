var
  s1,s2:array[1..50000]of longint;
  n,i,ans,sum:longint;
procedure sort(l,r:longint);
var  i,j,x,y:longint;
begin
  i:=l; j:=r; x:=s1[(l+r) div 2]+s2[(l+r) div 2];
  repeat
    while s1[i]+s2[i]<x do inc(i);
    while x<s1[j]+s2[j] do dec(j);
    if i<=j then
    begin
      y:=s2[i]; s2[i]:=s2[j]; s2[j]:=y;
      y:=s1[i]; s1[i]:=s1[j]; s1[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
  assign(input,'queue.in'); assign(output,'queue.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do readln(s1[i],s2[i]);
  sort(1,n);
  ans:=-maxlongint;
  for i:=1 to n do
  begin
    if sum-s2[i]>ans then ans:=sum-s2[i];
    inc(sum,s1[i]);
  end;
  writeln(ans);
  close(input); close(output);
end.
