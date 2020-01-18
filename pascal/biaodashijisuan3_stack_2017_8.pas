//PrayerOJ 1145
var
  sn:array[1..10] of longint;
  r:array['*'..'^'] of byte;
  sc:array[1..11] of char;
  i,j,tn,tc,t:longint;
  s:string;
begin
  r['+']:=1; r['-']:=1; r['*']:=2; r['/']:=2; r['^']:=3;
  readln(s);
  s:=s+'+';
  for i:=1 to length(s) do
    if (s[i]>='0')and(s[i]<='9')
    then t:=t*10+ord(s[i])-ord('0')
    else begin
           inc(tn);
           sn[tn]:=t;
           while (tc>0)and(r[sc[tc]]>=r[s[i]]) do
           begin
             dec(tn);
             case sc[tc] of
               '+':sn[tn]:=sn[tn]+sn[tn+1];
               '-':sn[tn]:=sn[tn]-sn[tn+1];
               '*':sn[tn]:=sn[tn]*sn[tn+1];
               '/':sn[tn]:=sn[tn]div sn[tn+1];
               '^':begin
                     t:=1;
                     for j:=1 to sn[tn+1] do t:=t*sn[tn];
                     sn[tn]:=t;
                   end;
             end;
             dec(tc);
           end;
           t:=0;
           inc(tc);
           sc[tc]:=s[i];
         end;
  write(sn[1]);
end.
