program h_1005_zuiyouchengche_BFS_2017_5_14;
var
  g:array[1..500,0..499] of integer;
  ln,s:array[0..5000] of integer;
  b:array[1..500] of boolean;
  m,n,num,i,j,k:integer;
begin
  readln(m,n);
  for i:=1 to m do
  begin
    ln[0]:=0;
    while not eoln do
    begin
      read(num);
      for j:=1 to ln[0] do
      begin
        inc(g[ln[j],0]);
        g[ln[j],g[ln[j],0]]:=num;
      end;
      inc(ln[0]);
      ln[ln[0]]:=num;
    end;
    readln;
  end;
  ln[1]:=1; s[1]:=0; b[1]:=true; i:=0; j:=1;
  while i<j do
  begin
    inc(i);
    for k:=1 to g[ln[i],0] do
    begin
      if g[ln[i],k]=n then
      begin
        writeln(s[i]);
        exit;
      end;
      if not b[g[ln[i],k]] then
      begin
        inc(j);
        ln[j]:=g[ln[i],k]; s[j]:=s[i]+1; b[g[ln[i],k]]:=true;
      end;
    end;
  end;
  writeln('NO');
end.


