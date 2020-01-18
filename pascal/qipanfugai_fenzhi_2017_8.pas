//PrayerOJ 1350
var
  b:array[1..64,1..64] of integer;
  h:array[0..4096] of integer;
  v:array[0..4096] of boolean;
  n,sx,sy,t,i,j:integer;
procedure solve(x,y,sx,sy,n:integer);
var o,s,t1,t2:integer;
begin
  if n=1 then exit;
  o:=t; inc(t); s:=n div 2; t1:=x+s; t2:=y+s;
  if (sx<t1)and(sy<t2)
  then solve(x,y,sx,sy,s)
  else begin
         b[t1-1,t2-1]:=o;
         solve(x,y,t1-1,t2-1,s);
       end;
  if (sx<t1)and(sy>=t2)
  then solve(x,t2,sx,sy,s)
  else begin
         b[t1-1,t2]:=o;
         solve(x,t2,t1-1,t2,s);
       end;
  if (sx>=t1)and(sy<t2)
  then solve(t1,y,sx,sy,s)
  else begin
         b[t1,t2-1]:=o;
         solve(t1,y,t1,t2-1,s);
       end;
  if (sx>=t1)and(sy>=t2)
  then solve(t1,t2,sx,sy,s)
  else begin
         b[t1,t2]:=o;
         solve(t1,t2,t1,t2,s);
       end;
end;
begin
  read(n,sx,sy);
  t:=1;
  solve(1,1,sx,sy,n);
  v[0]:=true; t:=0;
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      if not v[b[i,j]] then
      begin
        inc(t);
        h[b[i,j]]:=t; v[b[i,j]]:=true;
      end;
      write(h[b[i,j]],' ');
    end;
    writeln;
  end;
end.