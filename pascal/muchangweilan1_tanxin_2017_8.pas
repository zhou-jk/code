//PrayerOJ 1420
type rec=record
           maxx,maxy,minx,miny:longint;
         end;
var
  x,y:array[1..50000] of word;
  a,b:array[0..50001] of rec;
  n,i,ans:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  a[0].minx:=maxlongint; a[0].miny:=maxlongint; b[n+1].minx:=maxlongint; b[n+1].miny:=maxlongint;
  for i:=1 to n do
  begin
    a[i].maxx:=max(a[i-1].maxx,x[i]);
    a[i].maxy:=max(a[i-1].maxy,y[i]);
    a[i].minx:=min(a[i-1].minx,x[i]);
    a[i].miny:=min(a[i-1].miny,y[i]);
  end;
  for i:=n downto 1 do
  begin
    b[i].maxx:=max(b[i+1].maxx,x[i]);
    b[i].maxy:=max(b[i+1].maxy,y[i]);
    b[i].minx:=min(b[i+1].minx,x[i]);
    b[i].miny:=min(b[i+1].miny,y[i]);
  end;
  ans:=maxlongint;
  for i:=1 to n do
    ans:=min(ans,(max(a[i-1].maxx,b[i+1].maxx)-min(a[i-1].minx,b[i+1].minx))
    *(max(a[i-1].maxy,b[i+1].maxy)-min(a[i-1].miny,b[i+1].miny)));
  write(ans);
end.