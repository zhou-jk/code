var
  a:array[1..39,1..39] of longint;
  n,t,i,j,x,y:longint;
begin
  readln(n);
  t:=n*2-1;
  x:=1;
  y:=t div 2+1;
  a[x,y]:=1;
  for i:=2 to t*t do
    begin
      if (x<>1) and (y<>t) then
        if a[x-1,y+1]<>0 then
          begin
            inc(x);
            a[x,y]:=i;
            continue;
          end;
      if (x=1) and (y=t) then
        begin
          inc(x);
          a[x,y]:=i;
          continue;
        end;
      if x=1 then
        begin
          x:=t;
          inc(y);
          a[x,y]:=i;
          continue;
        end;
      if y=t then
        begin
          y:=1;
          x:=x-1;
          a[x,y]:=i;
          continue;
        end
      else
        begin
          x:=x-1;
          inc(y);
          a[x,y]:=i;
        end;
    end;
  for i:=1 to t do
    begin
      for j:=1 to t do
        write(a[i,j],' ');
      writeln;
    end;
  readln;
end.