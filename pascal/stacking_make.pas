var i,b:longint;
begin
  randomize;
  assign(output,'stacking.in');
  rewrite(output);
  writeln(1000000,' ',25000);
  for i:=1 to 25000 do
  begin
    b:=random(1000000)+1;
    writeln(random(b-1)+1,' ',b);
  end;
end.