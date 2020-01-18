var
  a:array[1..99,1..99] of longint;
  row,col,i,j,x,y:longint;
begin
  readln(row,col);
  for i:=1 to row do
    for j:=1 to col do
      if j=col then
        readln(a[i,j])
      else
        read(a[i,j]);
  for i:=1 to row+col-1 do
    if i<=col then
      begin
        y:=i;
        x:=1;
        while (x<=row) and (y>0) do
          begin
            writeln(a[x,y]);
            inc(x);
            y:=y-1;
          end;
      end
    else
      begin
        y:=col;
        x:=i-col+1;
        while (x<=row) and (y>0) do
          begin
            writeln(a[x,y]);
            inc(x);
            y:=y-1;
          end;
      end;
  readln;
end.
