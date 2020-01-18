program h_1251_dancipaisheng_Prim_2017_6_13;
var
  g:array[1..2000,1..2000] of byte;
  v:array[1..2000] of boolean;
  s:array[1..2000] of string;
  d:array[1..2000] of byte;
  n,i,j,k,a:integer;
begin
  readln(n);
  while n>0 do
  begin
    for i:=1 to n do
    begin
      readln(s[i]);
      for j:=1 to i-1 do
      begin
        g[i,j]:=0;
        for k:=1 to 7 do
          if s[i,k]<>s[j,k] then inc(g[i,j]);
        g[j,i]:=g[i,j];
      end;
    end;
    fillbyte(d,2000,255);
    fillchar(V,2000,0);
    d[1]:=0;
    for i:=1 to n do
    begin
      k:=-1;
      for j:=1 to n do
        if not v[j]and((k=-1)or(d[j]<d[k])) then k:=j;
      if k=-1 then break;
      v[k]:=true; inc(a,d[k]);
      for j:=1 to n do
        if not v[j]and(g[k,j]<d[j]) then d[j]:=g[k,j];
    end;
    writeln('The highest possible quality is 1/',a,'.');
    readln(n);
  end;
end.

