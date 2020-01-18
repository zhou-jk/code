program codevs_1214xianduanfugai_dongtaiguihua_2017_1_6;
var
  l:array[1..100,1..2] of integer;
  f:array[1..100] of integer;
  n,i,j,ans:integer;
procedure jh(var a,b:integer);
begin
  inc(a,b);
  b:=a-b;
  a:=a-b;
end;
procedure px;
var b:boolean;
begin
  i:=1;
  repeat
    b:=true;
    for j:=1 to n-i do
      if l[j,1]>l[j+1,1] then
      begin
        jh(l[j,1],l[j+1,1]);
        jh(l[j,2],l[j+1,2]);
        b:=false;
      end;
    inc(i);
  until b;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(l[i,1],l[i,2]);
    if l[i,1]>l[i,2] then jh(l[i,1],l[i,2]);
  end;
  px;
  f[1]:=1; ans:=1;
  for i:=2 to n do
  begin
    for j:=1 to i-1 do
      if (l[j,2]<=l[i,1])and(f[j]>f[i]) then f[i]:=f[j];
    inc(f[i]);
    if f[i]>ans then ans:=f[i];
  end;
  writeln(ans);
end.



