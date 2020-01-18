var t,n,r,i,tmp,a:integer;
begin
  assign(input,'coin.in'); assign(output,'coin.out');
  reset(input); rewrite(output);
  read(t);
  for i:=1 to t do
  begin
    read(n,r);
    a:=1; tmp:=n;
    while (tmp mod 10<>r)and(tmp mod 10>0) do
    begin
      inc(tmp,n);
      inc(a);
    end;
    writeln(a);
  end;
  close(input); close(output);
end.