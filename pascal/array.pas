const divisor=1000000007;
var
  n,k,x,i,j,count,father,son,tmp:longint;
  a:array[1..200000] of longint;
  ans:int64;
function min(x,y:longint):longint;
begin
  if (y>n)or(abs(a[x])<abs(a[y])) then exit(x);
  exit(y);
end;
procedure swap(x,y:longint);
begin
  tmp:=a[x]; a[x]:=a[y]; a[y]:=tmp;
end;
procedure up(k:longint);
begin
  father:=k div 2;
  while (k>1)and(abs(a[father])>abs(a[k])) do
  begin
    swap(father,k);
	k:=father; father:=k div 2;
  end;
end;
procedure down(k:longint);
begin
  son:=min(k*2,k*2+1);
  while (k<=n div 2)and(abs(a[son])<abs(a[k])) do
  begin
    swap(son,k);
	k:=son; son:=min(k*2,k*2+1);
  end;
end;
procedure change(x:longint);
begin
  if a[1]<0 
  then begin
         dec(count);
		 dec(a[1],x);
	   end
  else inc(a[1],x);
  if a[1]<0 then inc(count);
  down(1);
end;
begin
  assign(output,'array.out');
  rewrite(output);
  read(n,k,x);
  for i:=1 to n do
  begin
    read(a[i]);
	if a[i]<0 then inc(count);
	up(i);
  end;
  for i:=1 to k do
  begin
    //for j:=1 to n do write(a[j],' ');
	//writeln;
    if count mod 2=1
	then change(x)
	else change(-x);
  end;
  //for i:=1 to n do write(a[i],' ');
  //writeln;
  ans:=1;
  for i:=1 to n do ans:=ans*a[i]mod divisor;
  write((ans+divisor)mod divisor);
  close(output);
end.