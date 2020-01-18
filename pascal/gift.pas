type doll=record
            price,id:longint;
		  end;
     price_array=array[1..100000] of doll;
var
  pp,cc,heap:array[1..100000] of longint;
  vis:array[1..100000] of boolean;
  n,k,i,j,q,t,son:longint;
  p,c:price_array;
  m:int64;
function min(a,b:longint):longint;
begin
  if (b>k)or(heap[a]<heap[b]) then exit(a);
  exit(b);
end;  
procedure down(p:longint);
begin
  son:=min(p*2,p*2+1);
  while (p<=k div 2)and(heap[son]<heap[p]) do
  begin
    t:=heap[son]; heap[son]:=heap[p]; heap[p]:=t;
	p:=son; son:=min(p*2,p*2+1);
  end;
end;
procedure sort(var a:price_array;l,r:longint);
var 
  i,j,x:longint;
  y:doll;
begin
  i:=l; j:=r; x:=a[(l+r)div 2].price;
  repeat
    while a[i].price<x do inc(i);
    while x<a[j].price do dec(j);
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
  //assign(input,'gift.in'); assign(output,'gift.out');
  //reset(input); rewrite(output);
  read(n,k,m);
  for i:=1 to n do
  begin
    read(pp[i],cc[i]);
	p[i].price:=pp[i]; c[i].price:=cc[i]; p[i].id:=i; c[i].id:=i;
  end;
  sort(p,1,n); sort(c,1,n);
  j:=1; q:=1;
  for i:=1 to n do
  begin
    while vis[p[j].id] do inc(j);
	while vis[c[q].id] do inc(q);
	t:=c[q].price+heap[1];
	if t<p[j].price
	then begin
	       dec(m,t);
		   t:=c[q].id; vis[t]:=true; heap[1]:=pp[t]-cc[t];
		   down(1);
		 end
    else begin
	       dec(m,p[j].price);
		   vis[p[j].id]:=true;
		 end;
    if m<=0 then break;
  end;
  if m<0
  then write(i-1)
  else write(i);
  //close(input); close(output);
end.