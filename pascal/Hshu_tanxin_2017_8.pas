//PrayerOJ 1154 luogu 1748
var
  h:array[1..10000] of int64;
  n,i,l2,l3,l5,l7:integer;
function min(a,b:int64):int64;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  read(n);
  h[1]:=1; l2:=1; l3:=1; l5:=1; l7:=1;
  for i:=2 to n do
  begin
    h[i]:=h[l2]*2;
    h[i]:=min(h[i],h[l3]*3);
    h[i]:=min(h[i],h[l5]*5);
    h[i]:=min(h[i],h[l7]*7);
    if h[i]=h[l2]*2 then inc(l2);
    if h[i]=h[l3]*3 then inc(l3);
    if h[i]=h[l5]*5 then inc(l5);
    if h[i]=h[l7]*7 then inc(l7);
  end;
  write(h[n]);
end.

