var
  h,c,f,f1:array[0..100000] of longint;
  g:array[1..500] of longint;
  n,n1,i,j,t,s,s1,sc,a:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure swap(var a,b:longint);
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
      swap(h[i],h[j]); swap(c[i],c[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'house.in'); assign(output,'house.out');
  reset(input); rewrite(output);
  read(n);
  for i:=1 to n do 
  begin
    read(h[i],c[i]);
	inc(f[h[i]]); inc(f1[h[i]],c[i]); inc(s,c[i]);
  end;
  sort(1,n);
  a:=maxlongint;
  for i:=1 to n do
  begin
    if h[i]>h[i-1] then
	begin
	  n1:=i-1; j:=0; sc:=0;
	  while n1>=f[h[i]] do
	  begin
	    //writeln(j);
	    inc(j);
		t:=min(g[j],n1-f[h[i]]+1);
		dec(n1,t); inc(sc,t*j);
	  end;
	  a:=min(a,sc+s-(s1+f1[h[i]]));
	  //writeln(a);
	end;
    inc(g[c[i]]); inc(s1,c[i]);
  end;
  write(a);
  close(input); close(output);
end.