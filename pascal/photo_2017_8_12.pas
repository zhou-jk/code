type u=array[-1..1000] of longint;
var
  s:array[1..2000] of u;
  n,k,a,b,t,i,j,t1,ans:longint;
  va,vb:boolean;
procedure sort(l,r:longint);
var
  i,j,x:longint;
  y:u;
begin
  i:=l; j:=r; x:=s[(l+r)div 2,-1];
  repeat
    while s[i,-1]<x do inc(i);
    while x<s[j,-1] do dec(j);
    if i<=j then
    begin
      y:=s[i]; s[i]:=s[j]; s[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
function pd(t,m:longint):boolean;
var i:longint;
begin
  for i:=1 to s[m,0] do
    if (s[m,i]<s[m,-1])and(s[m,i]>=t) then exit(false);
  exit(true);
end;
begin
  assign(input,'photo.in'); assign(output,'photo.out');
  reset(input); rewrite(output);
  readln(n,k);
  for i:=1 to k do
  begin
    readln(a,b);
    va:=false; vb:=false;
    for j:=1 to t do
    begin
      if s[j,-1]=a then
      begin
        inc(s[j,0]);
        s[j,s[j,0]]:=b;
        va:=true;
      end;
      if s[j,-1]=b then
      begin
        inc(s[j,0]);
        s[j,s[j,0]]:=a;
        vb:=true;
      end;
      if va and vb then break;
    end;
    if not va then
    begin
      inc(t);
      s[t,-1]:=a; s[t,0]:=1; s[t,1]:=b;
    end;
    if not vb then
    begin
      inc(t);
      s[t,-1]:=b; s[t,0]:=1; s[t,1]:=a;
    end;
  end;
  sort(1,t);
  {for i:=1 to t do
  begin
    writeln('%',s[i,-1]);
	for j:=1 to s[i,0] do write(s[i,j],' ');
	writeln;
  end;}
  t1:=1;
  while t1<=t do
  begin
    inc(ans);
    //writeln(ans);
    for j:=t1+1 to t do
	  if not pd(s[t1,-1],j) then break;
	if (j=t)and pd(s[t1,-1],j) then break;
	//writeln('$',j);
	t1:=j;
  end;
  writeln(ans);
  close(input); close(output);
end.