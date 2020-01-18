var
  n:integer;
begin
  assign(input,'train.in'); assign(output,'train.out');
  reset(input); rewrite(output);
  readln(n);
  while n<>1 do
    if n mod 2=0
    then begin
           writeln(n,'/2=',n div 2);
           n:=n div 2;
         end
    else begin
           writeln(n,'*3+1=',n*3+1);
           n:=n*3+1;
         end;
  close(input); close(output);
end.
