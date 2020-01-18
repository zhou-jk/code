program cs_zhizheng_2016_10_6;
var
  p:^char;
  c:char;
begin
  c:='a';
  p:=@c;
  inc(p^);
  inc(c);
  writeln(p,c);
end.
