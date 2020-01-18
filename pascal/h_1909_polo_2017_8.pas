program h_1909_polo_2017_8_4;
uses math;
var
  f:array[1..10000000]of longint;
  b:array[1..10000000]of boolean;
  n,i,s,j,a:longint;
  ans,sum:int64;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a);
    inc(f[a]);
    s:=max(s,a);
  end;
  for i:=1 to s do
    if not b[i] then
    begin
      sum:=0;
      for j:=1 to s div i do sum:=sum+f[i*j];
      if sum>1 then ans:=max(ans,sum*i);
      if sum=0 then continue;
      for j:=2 to s div i div sum do
      begin
        if i*sum*j>ans then break;
        b[i*j]:=true;
      end;
    end;
  write(ans);
end.
