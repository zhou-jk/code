var
  a:array[1..10000] of longint;
  n,i,num:longint;
begin
  assign(input,'count.in'); assign(output,'count.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(num);
    inc(a[num]);
  end;
  for i:=1 to 10000 do
    if a[i]mod 2>0 then
    begin
      writeln(i);
      break;
    end;
  close(input); close(output);
end.