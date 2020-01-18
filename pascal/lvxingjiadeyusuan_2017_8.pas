//PrayerOJ 1233
const oo=100000000;
var
  d,p:array[0..11] of real;
  d1,c,d2,p1,a,d3,l:real;
  n,i,j,s:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  read(d1,c,d2,p1,n);
  for i:=1 to n do read(d[i],p[i]);
  inc(n);
  d[0]:=0; p[0]:=p1; d[n]:=d1; p[n]:=-oo;
  i:=0; j:=1;
  while i<n do
  begin
    l:=d3+c*d2; s:=j;
    while (d[j]<=l)and(p[j]>=p[i]) do
    begin
      if p[j]<p[s] then s:=j;
      inc(j);
    end;
    if d[j]>l
    then begin
           if s=j then
           begin
             write('No Solution');
             exit;
           end;
           a:=a+c*p[i]; d3:=l;
           i:=s
         end
    else begin
           a:=a+(d[j]-d3)/d2*p[i]; d3:=d[j];
           i:=j;
           inc(j);
         end;
  end;
  write(a:0:2);
end.