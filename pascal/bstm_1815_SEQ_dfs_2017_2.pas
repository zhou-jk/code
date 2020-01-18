program bstm_1815_SEQ_dfs_2017_2_4;
var
  a:array[1..100000] of longint;
  sum1,sum2,ans:int64;
  n,i,j,k,l:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
  begin
    sum1:=0;
    for j:=i to n-1 do
    begin
      inc(sum1,a[j]);
      for k:=j+1 to n do
      begin
        sum2:=0;
        for l:=k to n do
        begin
          inc(sum2,a[l]);
          if sum1+sum2>ans then ans:=sum1+sum2;
        end;
      end;
    end;
  end;
  writeln(ans);
end.


