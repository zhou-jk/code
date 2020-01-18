var
  v:array[1..1000] of real;
  n,x0,y0,x,y,i,j,t,s:integer;
  b:boolean;
  tmp:real;
begin
  assign(input,'gun.in'); assign(output,'gun.out');
  reset(input); rewrite(output);
  read(n,x0,y0);
  for i:=1 to n do
  begin
    read(x,y);
    x:=abs(x-x0); y:=abs(y-y0);
    if y=0 then
    begin
      s:=1;
      continue;
    end;
    tmp:=x/y; b:=true;
    for j:=1 to t do
      if v[j]=tmp then
      begin
        b:=false;
        break;
      end;
    if b then
    begin
      inc(t);
      v[t]:=tmp;
    end;
  end;
  write(t+s);
  close(input); close(output);
end.
