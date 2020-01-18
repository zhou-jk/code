var
  x,r,c,a,b:array[1..1000] of longint;
  n,k,i,j:longint;
function calc(a,b:longint):longint;
begin
  calc:=b-a;
  if calc<0 then inc(calc,n);
end;
begin
  assign(input,'table.in'); assign(output,'table.out');
  reset(input); rewrite(output);
  read(n,k);
  for i:=1 to k do
  begin
    read(x[i],r[i],c[i]);
	a[i]:=(x[i]-1)div n+1; b[i]:=(x[i]-1)mod n+1;
  end;
  for i:=1 to k do
  begin
    writeln(calc(a[i],r[i])+calc(b[i],c[i]));
	for j:=i+1 to k do
    begin
           if a[i]=a[j] then b[j]:=(b[j]+calc(b[i],c[i])-1)mod n+1;
	   if c[i]=b[j] then a[j]:=(a[j]+calc(a[i],r[i])-1)mod n+1;
    end;
  end;
  close(input); close(output);
end.
