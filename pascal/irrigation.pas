var
  x,y:array[1..2000] of integer;
  n,c,i,j,t,min,ans:longint;
begin
  assign(input,'irrigation.in'); assign(output,'irrigation.out');
  reset(input); rewrite(output);
  readln(n,c);
  for i:=1 to n do readln(x[i],y[i]);
  for i:=2 to n do
  begin
    min:=maxlongint;
    for j:=1 to i-1 do
    begin
      t:=sqr(x[j]-x[i])+sqr(y[j]-y[i]);
      if t=c then
      begin
        min:=c;
        break;
      end;
      if (t>c)and(t<min) then min:=t;
    end;
    inc(ans,min);
  end;
  writeln(ans);
  close(input); close(output);
end.
