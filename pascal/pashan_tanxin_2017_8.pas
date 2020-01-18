//PrayerOJ 1317  luogu 1561 [USACO12JAN]pashan Mountain Climbing
var
  u,d,f,s:array[1..25000] of longint;
  n,i,tf,ts,sum,tmp:longint;
procedure sort1(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=u[f[(l+r)div 2]];
  repeat
    while u[f[i]]<x do inc(i);
    while x<u[f[j]] do dec(j);
    if i<=j then
    begin
      y:=f[i]; f[i]:=f[j]; f[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort1(l,j);
  if i<r then sort1(i,r);
end;
procedure sort2(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=d[s[(l+r)div 2]];
  repeat
    while d[s[i]]>x do inc(i);
    while x>d[s[j]] do dec(j);
    if i<=j then
    begin
      y:=s[i]; s[i]:=s[j]; s[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort2(l,j);
  if i<r then sort2(i,r);
end;
begin
  read(n);
  for i:=1 to n do
  begin
    read(u[i],d[i]);
    inc(sum,u[i]);
    if u[i]<d[i]
    then begin
           inc(tf);
           f[tf]:=i;
         end
    else begin
           inc(ts);
           s[ts]:=i;
         end;
  end;
  sort1(1,tf); sort2(1,ts);
  for i:=1 to tf do
  begin
    dec(tmp,u[f[i]]);
    if tmp<0 then tmp:=0;
    inc(tmp,d[f[i]]);
  end;
  for i:=1 to ts do
  begin
    dec(tmp,u[s[i]]);
    if tmp<0 then tmp:=0;
    inc(tmp,d[s[i]]);
  end;
  write(sum+tmp);
end.