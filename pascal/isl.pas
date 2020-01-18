var
  h,s:array[1..100000] of longint;
  v:array[0..100001] of boolean;
  n,q,i,j,t,a:longint;
procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=h[(l+r)div 2];
  repeat
    while h[i]<x do inc(i);
    while x<h[j] do dec(j);
    if i<=j then
    begin
      swap(h[i],h[j]); swap(s[i],s[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'isl.in'); assign(output,'isl.out');
  reset(input); rewrite(output);
  read(n);
  for i:=1 to n do 
  begin
    read(h[i]);
	s[i]:=i;
  end;
  sort(1,n);
  read(q);
  j:=1; a:=1; v[0]:=true; v[n+1]:=true;
  for i:=1 to q do
  begin
    read(t);
	while (h[j]<=t)and(j<=n) do
	begin
	  v[s[j]]:=true;
	  if v[s[j]+1]and v[s[j]-1]
	  then dec(a)
	  else if not(v[s[j]-1]or v[s[j]+1]) then inc(a);
	  inc(j);
	 end;
	writeln(a);
  end;
  close(input); close(output);
end.