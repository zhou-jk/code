var
  n,c,sum,ans,i:integer;
  w,a:array[1..30] of integer;
  b:array[1..30] of boolean;
//procedure
  procedure ss(k:integer;sum:integer);
  var
    i:integer;
  begin
    i:=0;
    if sum=c then
    begin
      writeln(c);
      halt;
    end;
    if sum>c then
    begin
      dec(sum,a[k-1]);
      if sum>ans then ans:=sum;
      exit;
    end;
    for i:=1 to n do
      if not b[i] then
      begin
        b[i]:=true; a[k]:=w[i];
        ss(k+1,sum+a[k]);
        b[i]:=false;
      end;
  end;
//main
  begin
    readln(n,c);
    for i:=1 to n do
    begin
      read(w[i]);
      inc(sum,w[i]);
    end;
    if sum<=c
    then ans:=sum
    else ss(1,0);
    writeln(ans);
  end.


