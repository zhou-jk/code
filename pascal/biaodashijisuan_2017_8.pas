//PrayerOJ 1143
var
  sn:array[1..750] of longint;
  i,t,tn:longint;
  s:ansistring;
begin
  readln(s);
  s:=s+'+';
  for i:=1 to length(s) do
    if s[i]>='0'
    then t:=t*10+ord(s[i])-ord('0')
    else begin
           inc(tn);
           sn[tn]:=t;
           t:=0;
           if tn>=2 then
           begin
             dec(tn);
             sn[tn]:=sn[tn]+sn[tn+1];
           end;
         end;
  write(sn[1]);
end.