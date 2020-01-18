program h_1874_aihaoshuxuedeguowang_2017_5_13;
var
  t,n,i,j,n1,mp:longint;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n); n1:=n;
    if n=1 then
    begin
      writeln(0);
      continue;
    end;
    for j:=2 to trunc(sqrt(n)) do
      while n mod j=0 do
      begin
        mp:=j;
        n:=n div j;
      end;
    if n>1 then mp:=n;
    writeln(n1 div mp);
  end;
end.


