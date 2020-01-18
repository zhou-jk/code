program codevs_zuixiaoshuhezuidashu1201_2016_12_14;
var
  a,max,min:longint;
  n,i:integer;
begin
  readln(n);
  min:=maxlongint; max:=-maxlongint;
  for i:=1 to n do begin read(a); if a>max then max:=a; if a<min then min:=a; end;
  writeln(min,' ',max);
end.