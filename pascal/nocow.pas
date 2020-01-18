type
  w=array[1..101] of string;
var
  l:array[1..30] of longint;
  a:array[1..30] of string;
  adj,b:array[1..30] of w;
  n,k,i,j,t1,tmp:longint;
  s:ansistring;
  t:string;
function calc(x,y:longint):longint;
var check,i,j:longint;
begin
  calc:=1; a[x]:=adj[x,y];
  for i:=x+1 to t1 do calc:=calc*l[i];
  for i:=1 to n do
  begin
    check:=1;
	for j:=1 to x do
	  if a[j]<>b[j,i] then
	  begin
	    check:=0;
		break;
	  end;
	calc:=calc-check;
  end;
end;
procedure sort(var a:w;l,r:longint);
var
  i,j:longint;
  x,y:string;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(a,l,j);
  if i<r then sort(a,i,r);
end;
begin
  assign(input,'nocow.in'); assign(output,'nocow.out');
  reset(input); rewrite(output);
  readln(n,k);
  for i:=1 to n do
  begin
    readln(s);
    delete(s,1,19); delete(s,length(s)-3,4);
    j:=0; t1:=0;
    while j<length(s) do
    begin
      inc(j);
      t:='';
      while s[j]<>' ' do
      begin
        t:=t+s[j];
        inc(j);
      end;
      inc(t1);
      adj[t1,i]:=t;
    end;
  end;
  b:=adj;
  for i:=1 to t1 do
  begin
     sort(adj[i],1,n);
     for j:=1 to n do
       if adj[i,j]<>adj[i,j+1] then
       begin
         inc(l[i]);
         adj[i,l[i]]:=adj[i,j];
       end;
  end;
  for i:=1 to t1 do
  begin
    for j:=1 to l[i] do
	begin
	  tmp:=calc(i,j);
	  if tmp<k //后面还不够消掉k
	  then k:=k-tmp
	  else break; //可以保证j大于等于1
	end;
	a[i]:=adj[i,j];
  end;
  for i:=1 to t1 do write(a[i],' ');
  close(input); close(output);
end.