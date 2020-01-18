var
  n,t,a,i,s:longint;
begin
  assign(input,'read.in'); assign(output,'read.out');
  reset(input); rewrite(output);
  read(n,t);
  for i:=1 to n do
  begin
    read(a);
    inc(s,86400-a);
    if s>=t then
    begin
      write(i);
      break;
    end;
  end;
  close(input); close(output);
end.