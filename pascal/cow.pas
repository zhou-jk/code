var
  c:array[1..100000] of byte;
  n,k,i,l,a:longint;
begin
  assign(input,'cow.in'); assign(output,'cow.out');
  reset(input); rewrite(output);
  read(n,k);
  for i:=1 to n do
  begin
    read(c[i]);
    if c[i]=0 then dec(k);
    if k=-1 then
    begin
      inc(l);
      while c[l]=1 do inc(l);
      inc(k);
    end;
    if i-l>a then a:=i-l;
  end;
  write(a);
  close(input); close(output);
end.