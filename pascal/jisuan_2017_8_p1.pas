//PrayerOJ 1140
var
  sn:array[1..100] of longint;
  r:array['('..'^'] of byte;
  sc:array[1..100] of char;
  i,j,t,tn,tc:longint;
  b:boolean;
  s:string;
procedure pc;
begin
  inc(tc);
  sc[tc]:=s[i];
end;
begin
  r[')']:=1; r['+']:=1; r['-']:=1; r['*']:=2; r['/']:=2; r['^']:=3;
  read(s);
  s:='('+s+')';
  for i:=1 to length(s) do
    if (s[i]>='0')and(s[i]<='9')
    then begin
           t:=t*10+ord(s[i])-ord('0');
           b:=true;
         end
    else begin
           if b then
           begin
             inc(tn);
             sn[tn]:=t;
             b:=false;
           end;
           if s[i]='('
           then pc
           else begin
                  while r[sc[tc]]>=r[s[i]] do
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
                  if s[i]=')'
                  then dec(tc)
                  else pc;
                end;
           t:=0;
         end;
  write(sn[1]);
end.