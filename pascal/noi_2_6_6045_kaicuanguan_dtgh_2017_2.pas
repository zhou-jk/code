program noi_2_6_6045_kaicanguan_dongtaiguihua_2017_2_5;
var
  m,p,f:array[1..100] of longint;
  t,n,i,j,k,s:longint;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n,s);
    for j:=1 to n do read(m[j]);
    for j:=1 to n do
    begin
      read(p[j]);
      if j=1
      then f[j]:=p[j]
      else f[j]:=f[j-1];
      if p[j]>f[j] then f[j]:=p[j];
      for k:=j-1 downto 1 do
        if (m[j]-m[k]>s)and(f[k]+p[j]>f[j]) then
        begin
          f[j]:=f[k]+p[j];
          break;
        end;
    end;
    writeln(f[n]);
  end;
end.