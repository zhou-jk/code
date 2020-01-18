var
  a:array[1..100] of int64;
  i:longint;
begin
  a[1]:=1;
  a[2]:=1;
  write(a[1],' ',a[2],' ');
  for i:=3 to 100 do
    begin
      a[i]:=a[i-1]+a[i-2];
      write(a[i],' ');
    end;
end.