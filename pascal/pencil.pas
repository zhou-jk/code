var n,i,ans,t,a1,a2:longint;
begin
  assign(input,'pencil.in');
  assign(output,'pencil.out');
  reset(input);
  rewrite(output);
  readln(n);
  ans:=maxlongint;
  for i:=1 to 3  do
  begin
    readln(a1,a2);
    t:=n div a1;
    if n mod a1>0 then inc(t);
    if t*a2<ans then ans:=t*a2;
  end;
  writeln(ans);
  close(input);
  close(output);
end.