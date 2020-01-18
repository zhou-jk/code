var
  a,b,a1,b1:array[1..100] of longint;
  c:array[1..100] of boolean;
  n,i,s,l,ll:longint;
procedure stop;
begin
  close(input); close(output);
  halt;
end;
procedure p;
begin
  for i:=1 to n do
    if a[i]<>b[i] then exit;
  writeln(-1);
  stop;
end;
procedure dfs(k:longint);
begin
  //write(k,' ');
  if c[k] then exit;
  inc(ll); c[k]:=true;
  dfs(b1[a[k]]);
end;
begin
  assign(input,'reorder.in'); assign(output,'reorder.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    readln(a[i]);
    a1[a[i]]:=i;
  end;
  for i:=1 to n do
  begin
    readln(b[i]);
    b1[b[i]]:=i;
  end;
  p;
  for i:=1 to n do
    if not c[i] then
    begin
      ll:=0;
      dfs(i);
      if ll>1 then inc(s);
      if ll>l then l:=ll;
      //writeln;
    end;
  writeln(s,' ',l);
  stop;
end.
