program codevs_1058hechangduixing_dongtaiguihua_2017_1_1;
var
  t,l,r:array[1..100] of integer;
  n,i,j,k,m,le,ri,ans:integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(t[i]);
    //if t[i]>m then m:=t[i];
  end;
  ans:=10000;
  for i:=1 to n do
  begin
    //if t[i]<m then continue;
    //writeln('#',i);
    l[1]:=1;
    for j:=2 to i do
    begin
      l[j]:=0;
      for k:=1 to j-1 do
        if (t[j]>t[k])and(l[k]>l[j]) then l[j]:=l[k];
      inc(l[j]);
    end;
    le:=l[i];
    //writeln('l',le);
    r[n]:=1;
    for j:=n-1 downto i do
    begin
      r[j]:=0;
      for k:=j+1 to n do
        if (t[j]>t[k])and(r[k]>r[j]) then r[j]:=r[k];
      inc(r[j]);
    end;
    ri:=r[i];
    //writeln('r',ri);
    if n-le-ri+1<ans then ans:=n-le-ri+1;
  end;
  writeln(ans);
end.
