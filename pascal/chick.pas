var
  s:array[-9999..10000] of byte;
  n,t,x,ti,i,j,tmp,a:integer;
begin
  assign(input,'chick.in'); assign(output,'chick.out');
  reset(input); rewrite(output);
  read(n,t,x);
  if x>t then
  begin
    write(-1);
    close(input); close(output);
    exit;
  end;
  for i:=1 to n do
  begin
    read(ti);
	tmp:=0;
	for j:=ti-t to ti-1 do inc(tmp,s[j]);
    while tmp<x do
	begin
	  if s[j]=0 then
	  begin
	    s[j]:=1;
		inc(tmp); inc(a);
	  end;
	  dec(j);
	end;
  end;
  write(a);
  close(input); close(output);
end.