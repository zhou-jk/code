program fenshuchaifen_2017_8_19_p2;
//PrayerOJ 1063
var k,x,a,t,s:longint;
begin
  read(k);
  for x:=k+1 to k*2 do
  begin
    t:=x*k; s:=x-k;
    if t mod s=0 then writeln('1/',k,'=1/',x,'+1/',t div s);
  end;
end.
