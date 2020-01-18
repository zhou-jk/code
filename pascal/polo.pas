uses math;
var
  f:array[1..2000000]of longint;
  n,i,s,j,a:longint;
  ans,sum:int64;
begin
  assign(input,'polo.in'); assign(output,'polo.out');
  reset(input); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(a);
    inc(f[a]);
    s:=max(s,a);
  end;
  for i:=1 to s do
  begin
    sum:=0;
    for j:=1 to s div i do sum:=sum+f[i*j];
    if sum>1 then ans:=max(ans,sum*i);
  end;
  write(ans);
  close(input); close(output);
end.