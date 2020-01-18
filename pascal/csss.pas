var
  a,b:string;
  i:longint;
begin
  b:='a';
  a:='aaa';
  for i:=1 to length(a) do
    begin
      a:=a+b;
      writeln(a);
    end;
end.
