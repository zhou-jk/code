program h_1949_qianzhui_2017_8_1;
var
  f:array[0..2000000] of boolean;
  s1:array[1..2000000] of char;
  w:array[0..301] of string;
  t,i,j,l,r,m,ans,t1:longint;
  s,tmp:string;
  b:boolean;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure sort(l,r:longint);
var
  i,j:longint;
  x,y:string;
begin
  i:=l; j:=r; x:=w[(l+r)div 2];
  repeat
    while w[i]<x do inc(i);
    while x<w[j] do dec(j);
    if i<=j then
    begin
      y:=w[i]; w[i]:=w[j]; w[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(s);
  while s<>'.' do
  begin
    s:=s+' '; i:=0;
    while i<length(s) do
    begin
      inc(i);
      tmp:='';
      while s[i]<>' ' do
      begin
        tmp:=tmp+s[i];
        inc(i);
      end;
      if tmp<>'' then
      begin
        inc(t);
        w[t]:=tmp;
      end;
    end;
    readln(s);
  end;
  while not eof do
  begin
    readln(s);
    for i:=1 to length(s) do
    begin
      inc(t1);
      s1[t1]:=s[i];
    end;
  end;
  sort(1,t);
  f[0]:=true;
  for i:=1 to t1 do
  begin
    //writeln(i);
    tmp:=''; b:=true;
    for j:=1 to min(i,10) do
    begin
      tmp:=s1[i-j+1]+tmp;
      if f[i-j] then
      begin
        b:=false;
        l:=1; r:=t;
        while l<=r do
        begin
          m:=(l+r)div 2;
          if w[m]=tmp then break;
          if w[m]>tmp then r:=m-1;
          if w[m]<tmp then l:=m+1;
        end;
        if w[m]=tmp then
        begin
          f[i]:=true; ans:=i;
          break;
        end;
      end;
    end;
    if b then break;
  end;
  writeln(ans);
end.

