program h_1951_pengzhangdemugun_erfenchazhao_2017_8_15;
uses math;
var
  len,n,c,l,r,m,t:real;
begin
  read(len,n,c);
  l:=0; r:=pi/2; t:=1+n*c; len:=len/2;
  while r-l>0.000000001 do
  begin
    m:=(l+r)/2;
    if m/sin(m)>t
    then r:=m
    else l:=m;
  end;
  writeln(len/sin(m)-len/tan(m):0:3);
end.
