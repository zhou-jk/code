var t,i,sa,sb,ta,tb:integer;
begin
  assign(input,'rank.in'); assign(output,'rank.out');
  reset(input); rewrite(output);
  for i:=1 to 6 do
  begin
    read(t);
    if t=50 then inc(ta);
    inc(sa,t);
  end;
  for i:=1 to 6 do
  begin
    read(t);
    if t=50 then inc(tb);
    inc(sb,t);
  end;
  if sa>sb
  then write(1)
  else if sb>sa
       then write(2)
       else if ta>tb
            then write(1)
            else if tb>ta
                 then write(2)
                 else write(0);
  close(input); close(output);
end.