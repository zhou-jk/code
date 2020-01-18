program h_1177_zuqiuliansai_2017_7_23;
var
  a:array[1..50] of longint;
  n,i,j:longint;
  c:char;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      read(c);
      if c='W' then a[i]:=a[i]+3;
      if c='D' then
      begin
        inc(a[i]); inc(a[j]);
      end;
      if c='L' then a[j]:=a[j]+3;
    end;
  readln;
  end;
  for i:=1 to n-1 do write(a[i],' ');
  writeln(a[n]);
end.
