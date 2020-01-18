program fenshuchaifen_2017_8_19;
//PrayerOJ 1989
var k,y,a,t:longint;
function gcd(a,b:longint):longint;
begin
  if b=0 then exit(a);
  exit(gcd(b,a mod b));
end;
begin
  read(k);
  for y:=k*2 downto K+1 do
  begin
    t:=y*k div gcd(y,k);
    if t mod(t div k-t div y)=0 then inc(a);
  end;
  write(a);
end.