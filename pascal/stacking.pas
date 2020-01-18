var
  c:array[-25000..25000] of longint;
  t:array[1..1000000] of integer;
  n,k,i,a,b,num,sum:longint;
begin
  assign(input,'stacking.in'); assign(output,'stacking.out');
  reset(input); rewrite(output);
  readln(n,k);
  for i:=1 to k do
  begin
    readln(a,b);
    inc(t[a]); dec(t[b+1]);
  end;
  for i:=1 to n do
  begin
    inc(num,t[i]); inc(c[num]);
  end;
  i:=-k;
  while sum<(n+1)div 2 do
  begin
    inc(i);
    inc(sum,c[i]);
  end;
  writeln(i);
  close(input); close(output);
end.
