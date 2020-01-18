program htm_zhuangzaiwenti_shengsolianxi_2016_10_25;
var
  n,c,sum,ans,i:integer;
  w,a:array[1..30] of integer;
  b:array[1..30] of boolean;
//procedure
  procedure ss(k:integer);
  var
    i:integer;
  begin
    i:=0;
    if k=n+1 then
    begin
      while sum<=c do
      begin
        inc(i);
        inc(sum,a[i]);
      end;
      dec(sum,a[i]);
      if sum>ans then ans:=sum;
      sum:=0;
      exit;
    end;
    for i:=1 to n do
      if not b[i] then
      begin
        b[i]:=true; a[k]:=w[i];
        ss(k+1);
        b[i]:=false;
      end;
  end;
//main
  begin
    readln(n,c);
    for i:=1 to n do
      read(w[i]);
    ss(1);
    writeln(ans);
  end.


