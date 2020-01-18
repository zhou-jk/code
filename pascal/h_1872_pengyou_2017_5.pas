program h_1872_pengyou_2017_5_6;
var
  f:array[1..100,1..100] of boolean;
  pe:array[1..100] of string;
  n,m,i,j,p,p1,p2,m1,fm,ans:integer;
  s,s1,s2:string;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(s);
    p:=pos(' ',s); s1:=copy(s,1,p-1); s2:=copy(s,p+1,255); p1:=0; p2:=0;
    for j:=1 to m1 do
    begin
      if pe[j]=s1 then p1:=j;
      if pe[j]=s2 then p2:=j;
    end;
    if p1=0 then
    begin
      inc(m1);
      p1:=m1; pe[p1]:=s1;
    end;
    if p2=0 then
    begin
      inc(m1);
      p2:=m1; pe[p2]:=s2;
    end;
    f[p1,p2]:=true; f[p2,p1]:=true;
  end;
  for i:=1 to n do
  begin
    fm:=0;
    for j:=1 to n do
      if f[i,j] then inc(fm);
    if fm>ans then ans:=fm;
  end;
  writeln(ans);
end.

