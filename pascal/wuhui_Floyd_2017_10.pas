//PrayerOJ 2001
var
  g:array[1..200,1..200] of boolean;
  v:array[1..200] of boolean;
  n,t,i,j,k,a:byte;
begin
  read(n);
  for i:=1 to n do
  begin
    read(t);
    while t>0 do
    begin
      g[i,t]:=true;
      read(t);
    end;
  end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if g[i,k]and g[k,j] then g[i,j]:=true;
  for i:=1 to n do
   if not v[i] then
   begin
     v[i]:=true;
     inc(a);
     for j:=1 to n do
       if g[i,j]and g[j,i] then v[j]:=true;
   end;
  write(a);
end.

