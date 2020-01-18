program noi2_6_4977guaidaojidedehuaxiangyi_dongtaiguihua_2017_1_21;
var
  d,f1,f2,f:array[1..1000] of integer;
  k,n,i,j,l:integer;
  ans:longint;
begin
  readln(k);
  for i:=1 to k do
  begin
    readln(n);
    for j:=1 to n do read(d[j]);
    f1[1]:=1; f2[1]:=1;
    for j:=2 to n do
    begin
      f1[j]:=0; f2[j]:=0;
      for l:=1 to j-1 do
        if (d[l]>d[j])and(f1[l]>f1[j]) then f1[j]:=f1[l];
      for l:=1 to j-1 do
        if (d[l]<d[j])and(f2[l]>f2[j]) then f2[j]:=f2[l];
      inc(f1[j]); inc(f2[j]);
      if f1[j]>f2[j] then f[j]:=f1[j]
                     else f[j]:=f2[j];
      //writeln('#',f[j]);
    end;
    ans:=f[1];
    for j:=2 to n do if f[j]>ans then ans:=f[j];
    writeln(ans);
  end;
end.

