program test_2011_3;
var
  sum:array[0..10,0..10] of integer;
  s,num:array[1..10] of integer;
  a,b,c,d,n,m,ans,now,i,j:integer;
begin
  readln(n,m);
  for i:=1 to 10 do
    for j:=0 to 10 do sum[i,j]:=0;
  for a:=1 to n do
  begin
    for b:=1 to m do
    begin
      read(num[b]);
      s[b]:=s[b]+num[b];
      sum[a,b]:=sum[a,b-1]+s[b];
    end;
    readln;
  end;
  ans:=-32766;
  for a:=1 to n do
    for b:=1 to m do
      for c:=a to n do
        for d:=b to m do
        begin
          now:=sum[c,d]-sum[a-1,d]-sum[c,b-1]+sum[a-1,b-1];
          if ans<now then ans:=now;
        end;
  writeln(ans);
end.


