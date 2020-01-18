//PrayerOJ 1149
var
  sn:array[1..10001] of longint;
  sc:array[1..10000] of char;
  r:array['*'..'+'] of byte;
  i,j,t,tn,tc:longint;
  s:ansistring;
  b:boolean;
  a:string;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  r['+']:=1; r['*']:=2;
  read(s);
  s:=s+'+';
  for i:=1 to length(s) do
    if s[i]>='0'
    then t:=t*10+ord(s[i])-ord('0')
    else begin
           inc(tn);
           sn[tn]:=t;
           t:=0; b:=false;
           while (tc>0)and(r[sc[tc]]>=r[s[i]]) do
           begin
             dec(tn);
             case sc[tc] of
               '+':sn[tn]:=sn[tn]+sn[tn+1];
               '*':sn[tn]:=sn[tn]*sn[tn+1];
             end;
             str(sn[tn],a);
             val(copy(a,max(length(a)-3,1),4),sn[tn]);
             dec(tc);
           end;
           inc(tc);
           sc[tc]:=s[i];
         end;
  str(sn[1],a);
  val(copy(a,max(length(a)-3,1),4),sn[1]);
  write(sn[1]);
end.
