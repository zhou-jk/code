var
  s:array[0..1000000,1..3] of longint;
  n,q,k,a,b,i:longint;
begin
  assign(input,'bcout.in'); assign(output,'bcout.out');
  reset(input); rewrite(output);
  read(n,q);
  for i:=1 to n do
  begin
    read(k);
    s[i]:=s[i-1];
    inc(s[i,k]);
  end;
  for i:=1 to q do
  begin
    read(a,b);
    writeln(s[b,1]-s[a-1,1],' ',s[b,2]-s[a-1,2],' ',s[b,3]-s[a-1,3]);
  end;
  close(input); close(output);
end.