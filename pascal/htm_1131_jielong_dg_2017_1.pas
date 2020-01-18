program htm_1131_jielong_digui_2017_1_22;
var
  n,k,l,r,le:longint;
procedure f(l,r,k:longint);
begin
  //if k=-100 then halt;
  if (n>l)and(n<r) then
  begin
    if n=l+1
    then writeln('m')
    else writeln('o');
    halt;
  end;
  //writeln('<=l',l,' r',r,' k',k,' n',n);
  if n>=r then
  begin
    //writeln('>=l',l,' r',r,' k',k,' n',n);
    n:=n-r+1;
  end;
  f((l-k-2) div 2,(l-k-2) div 2+k+3,k-1);
end;
begin
  readln(n);
  le:=3; l:=0; r:=4; k:=0;
  while le<n do
  begin
    inc(k);
    l:=le;
    r:=le+k+4;
    le:=2*le+k+3;
  end;
  //writeln('#',l,' ',r,' ',le);
  f(l,r,k);
end.



