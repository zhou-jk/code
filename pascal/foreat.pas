var
  n,m,m1,t,i,tmp,father,son:longint;
  a:array[1..100000] of longint;
function min(x,y:longint):longint;
begin
  if x<y then exit(x);
  exit(y);
end;
function max(x,y:longint):longint;
begin
  if (y>n)or(a[x]>a[y]) then exit(x);
  exit(y);
end;
procedure swap(x,y:longint);
begin
  tmp:=a[x]; a[x]:=a[y]; a[y]:=tmp;
end;
procedure up(k:longint);
begin
  father:=k div 2;
  while (k>1)and(a[father]<a[k]) do
  begin
    swap(father,k);
    k:=father; father:=k div 2;
  end;
  //writeln('*');
end;
procedure down(k:longint);
begin
  //writeln(t);
  son:=max(k*2,k*2+1);
  while (k*2<=n)and(a[son]>a[k]) do
  begin
    //writeln(son,' ',k);
    swap(k,son);
    k:=son; son:=max(k*2,k*2+1);
  end;
end;
begin
  assign(input,'foreat.in'); assign(output,'foreat.out');
  reset(input); rewrite(output);
  read(n,m);
  m1:=m-1;
  for i:=1 to n do
  begin
    //writeln(i);
    read(a[i]);
    up(i);
  end;
  //writeln('^');
  while a[1]>t do
  begin
    //writeln(t);
    tmp:=min((a[1]-a[max(2,3)])div m1+1,(a[1]-t)div m+1);
	//writeln(t);
    dec(a[1],tmp*m); inc(t,tmp);
    down(1);
  end;
  write(t);
  close(input); close(output);
end.