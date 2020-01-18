program test_sishewuru_jingdu_2017_8_7;
var
  i,a1,a2,a3,a4:longint;
  s1:real;
  s2:double;
  s3,t1,t2:extended;
begin
  s1:=2/3; s2:=2/3; s3:=2/3;
  for i:=1 to maxlongint do
  begin
    t1:=sqrt(i); t2:=t1*t1;
    if i<t2
    then begin
           inc(a1);
           if t2-i>=1 then inc(a3);
         end
    else if i=t2
         then inc(a2)
         else if i-t2>=1 then inc(a4);
  end;
  writeln(a1,' ',a2,' ',maxlongint-a1-a2,' ',a3,' ',a4); //>,<,= dou you ke neng,cha bu chao guo 1
  writeln(s1,' ',s2,' ',s3);
  writeln(2/3); //extended
  writeln(14.5:2:0); //si she wu ru
end.