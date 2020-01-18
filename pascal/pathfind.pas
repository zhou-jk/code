var
  c,a:array[1..100,0..100] of byte;
  b:array[1..100] of boolean;
  s,d:array[1..100] of byte;
  n,m,i,j,l,r,max:byte;
begin
  assign(input,'pathfind.in'); assign(output,'pathfind.out');
  reset(input); rewrite(output);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do read(c[i,j]);
  l:=0; r:=1; s[1]:=m; b[m]:=true;
  while l<r do
  begin
    inc(l);
    for i:=1 to n do
      if not b[i]and(c[s[l],i]=1) then
      begin
        inc(r);
        s[r]:=i; b[i]:=true; d[i]:=d[s[l]]+1;
      end;
  end;
  for i:=1 to n do
    if i<>m then
    begin
      inc(a[d[i],0]);
      a[d[i],a[d[i],0]]:=i;
      if d[i]>max then max:=d[i];
    end;
  writeln(m);
  for i:=1 to max do
  begin
    for j:=1 to a[i,0] do write(a[i,j],' ');
    writeln;
  end;
  close(input); close(output);
end.

