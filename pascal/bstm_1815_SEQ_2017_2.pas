program bstm_1815_SEQ_2017_2_4;
var
  a:array[1..100000] of longint;
  n,i,j,k,l:longint;
  sum,sum1,sum2,sumo,ans:int64;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
  begin
    if (i>1)and(a[i]<=a[i-1]) then continue;
    sum1:=0; sum:=0;
    for j:=i downto 1 do
    begin
      inc(sum,a[j]);
      if sum>sum1 then sum1:=sum;
    end;
    if sum1<=sumo then continue;
    sumo:=sum1;
    if l<=i then
    begin
      sum2:=0;
      for j:=i+1 to n do
      begin
        sum:=0;
        for k:=j downto i+1 do
        begin
          inc(sum,a[k]);
          if sum>sum2 then
          begin
            sum2:=sum;
            l:=k;
          end;
        end;
      end;
    end;
    if sum1+sum2>ans then ans:=sum1+sum2;
  end;
  writeln(ans);
end.

