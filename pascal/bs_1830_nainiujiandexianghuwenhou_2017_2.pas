program bs_1830_nainiujiandexianghuwenhou_2017_2_8;
var
  bk,ek:array[0..100003] of longint;
  bc,ec:array[0..100003] of char;
  b,e,i,bi,ei,bp,ep,ans,o:longint;
  t,f,s:boolean;
  c:char;
begin
  readln(b,e);
  for bi:=1 to b do readln(bk[bi],c,bc[bi]);
  for ei:=1 to e do readln(ek[ei],c,ec[ei]);
  bi:=1; ei:=1;
  while (bi<=b)or(ei<=e) do
  begin
    if bi<=b then
    begin
      if bc[bi]='R'
      then inc(bp)
      else dec(bp);
      dec(bk[bi]);
      if bk[bi]=0 then inc(bi);
    end;
    if ei<=e then
    begin
      if ec[ei]='R'
      then inc(ep)
      else dec(ep);
      dec(ek[ei]);
      if ek[ei]=0 then inc(ei);
    end;
    //inc(i);
    //writeln('#',i,' ',bp,' ',ep);
    //if t and(bp<>ep) then inc(ans);
    //if f and(bp>ep) then inc(ans);
    //if s and(bp<ep) then inc(ans);
    //t:=false; f:=false; s:=false;
    if bp=ep
    then begin
           if not t then inc(ans);
           t:=true;
         end
    else t:=false;
    //if bp<ep then f:=true;
    //if bp>ep then s:=true;
    //if ans>o then writeln(i);
    //o:=ans;
  end;
  if t then inc(ans);
  writeln(ans);
end.



