program codevs_3095heixindeshizhang_dongtaiguihua_2017_1_6;
var
  l:array[1..500,1..3] of longint;
  f:array[1..500] of int64;
  m,i,j:integer;
  n,ans:int64;
procedure jh(var a,b:longint);
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
    for j:=1 to m-i do
      if l[j,1]>l[j+1,1] then
      begin
        jh(l[j,1],l[j+1,1]);
        jh(l[j,2],l[j+1,2]);
        jh(l[j,3],l[j+1,3]);
        b:=false;
      end;
    inc(i);
  until b;
end;
begin
  readln(n,m);
  for i:=1 to m do readln(l[i,1],l[i,2],l[i,3]);
  px;
  f[1]:=l[1,3]; ans:=l[1,3];
  for i:=2 to m do
  begin
    for j:=1 to i-1 do
      if (l[j,2]<=l[i,1])and(f[j]>f[i]) then f[i]:=f[j];
    inc(f[i],l[i,3]);
    if f[i]>ans then ans:=f[i];
  end;
  writeln(ans);
end.



