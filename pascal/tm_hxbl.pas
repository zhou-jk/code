var
  a:array[1..99,1..99] of longint;
  row,col,i,j,t,f,b:longint;
  c:boolean;
begin
  readln(row,col);
  for i:=1 to row do
    for j:=1 to col do
      begin
        if j=col
        then readln(a[i,j])
        else read(a[i,j]);
      end;
  t:=row;
  f:=col;
  i:=1;
  j:=1;
  while (t>0) and (f>0) do
    begin
      c:=false;
      inc(b);
      while (b mod 4=1) and (j<=f+(col-f) div 2) do
        begin
          writeln(a[i,j]);
          inc(j);
          c:=true;
        end;
      if c then
        begin
          inc(i);
          t:=t-1;
          j:=j-1;
          continue;
        end;
      while (b mod 4=2) and (i<=t+(row-t) div 2+1) do
        begin
          writeln(a[i,j]);
          inc(i);
          c:=true;
        end;
      if c then
        begin
          j:=j-1;
          f:=f-1;
          i:=i-1;
          continue;
        end;
      while (b mod 4=3) and (j>(col-f) div 2) do
        begin
          writeln(a[i,j]);
          j:=j-1;
          c:=true;
        end;
      if c then
        begin
          i:=i-1;
          t:=t-1;
          j:=j+1;
          continue;
        end;
      while (b mod 4=0) and (i>(row-t) div 2) do
        begin
          writeln(a[i,j]);
          i:=i-1;
          c:=true;
        end;
      if c then
        begin
          inc(i);
          f:=f-1;
          j:=j+1;
          continue;
        end;
    end;
  readln;
end.

