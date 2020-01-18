//PrayerOJ 1248
var
  sn:array[1..1000] of longint;
  r:array['('..'-'] of byte;
  sc:array[1..1000] of char;
  i,j,t,tn,tc:longint;
  b:boolean;
  s:ansistring;
procedure pc;
begin
  inc(tc);
  sc[tc]:=s[i];
end;
begin
  r[')']:=1; r['+']:=1; r['-']:=1; r['*']:=2;
  read(s);
  s:='('+s+')';
  i:=2;
  while i<length(s) do
  begin
    if ((s[i]='-')or(s[i]='+'))and(s[i-1]<>')')and(s[i-1]<'0') then
    begin
      insert('(0',s,i);
      inc(i,3); j:=i+1;
      while (j<=length(s))and(s[j]>='0') do inc(j);
      insert(')',s,j);
    end;
    inc(i);
  end;
  for i:=1 to length(s) do
    if s[i]>='0'
    then begin
           t:=t*10+ord(s[i])-ord('0');
           b:=true;
         end
    else begin
           if b then
           begin
             inc(tn);
             sn[tn]:=t;
             t:=0; b:=false;
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
                    end;
                    dec(tc);
                  end;
                  if s[i]=')'
                  then dec(tc)
                  else pc;
                end;
         end;
  write(sn[1]);
end.