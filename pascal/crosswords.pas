var
  b:array[1..50,1..50] of boolean;
  a:array[0..52,0..52] of char;
  n,m,i,j,ans:integer;
begin
  assign(input,'crosswords.in'); assign(output,'crosswords.out');
  reset(input); rewrite(output);
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j]='.' then
      begin
        if (a[i,j-1]<>'.')and(a[i,j+1]='.')and(a[i,j+2]='.') then
        begin
          inc(ans);
          b[i,j]:=true;
          continue;
        end;
        if (a[i-1,j]<>'.')and(a[i+1,j]='.')and(a[i+2,j]='.') then
        begin
          inc(ans);
          b[i,j]:=true;
        end;
      end;
  writeln(ans);
  for i:=1 to n do
    for j:=1 to m do
      if b[i,j] then writeln(i,' ',j);
  close(input); close(output);
end.

