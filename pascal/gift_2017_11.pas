var
  sn:array[1..100000] of real;
  sc:array[1..100000] of char;
  r:array['1'..'9'] of real;
  i,tn,tc:longint;
  s:ansistring;
  n,c:char;
  a:real;
begin
  assign(input,'gift.in'); assign(output,'gift.out');
  reset(input); rewrite(output);
  readln(n);
  for c:='1' to n do read(r[c]);
  readln;
  readln(s);
  s:='('+s+')';
  for i:=1 to length(s) do
    if (s[i]>'0')and(s[i]<='9')
    then begin
           inc(tn);
           sn[tn]:=r[s[i]];
         end
    else if s[i]=')'
         then begin
                while sc[tc]<>'(' do
                begin
                  dec(tn);
                  case sc[tc] of
                    '-':sn[tn]:=sn[tn]+sn[tn+1];
                    '|':sn[tn]:=sn[tn]*sn[tn+1]/(sn[tn]+sn[tn+1]);
                  end;
                  dec(tc);
                end;
                dec(tc);
              end
         else if s[i]<>'R' then
              begin
                inc(tc);
                sc[tc]:=s[i];
              end;
  write(sn[1]:0:5);
  close(input); close(output);
end.