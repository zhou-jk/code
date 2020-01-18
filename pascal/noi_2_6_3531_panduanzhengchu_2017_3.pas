program noi_2_6_3531_panduanzhengchu_2017_3_18;
var
  f,g:array[0..99]of boolean;
  n,k,i,j,num:integer;
begin
  readln(n,k);
  g[0]:=true;
  for i:=1 to n do
  begin
    read(num);
    for j:=0 to k-1 do
      if g[j] then
      begin
        f[(j+num)mod k]:=true;
        f[((j-num)mod k+k)mod k]:=true;
      end;
    g:=f;
    fillchar(f,sizeof(f),false);
  end;
  if g[0]
  then writeln('YES')
  else writeln('NO');
end.



