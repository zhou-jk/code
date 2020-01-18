//PrayerOJ 2090
var
  s:array[0..1000000] of longint;
  n,m,a,i,l,r,mid,ans:longint;
procedure insert(a:longint);
begin
  l:=0; r:=ans;
  while l<r do
  begin
    mid:=(l+r)>>1;
    if s[mid]>a
    then r:=mid
    else l:=mid+1;
  end;
  if (r>0)and(s[r]>a) then s[r]:=a;
end;
begin
  read(n,m);
  s[0]:=m;
  for i:=1 to n do
  begin
    read(a);
    if 2*a>=s[ans] then
    begin
      inc(ans);
      s[ans]:=2*a;
    end;
    insert(2*a); insert(a);
  end;
  //for i:=0 to ans do write(s[i],' ');
  //writeln;
  write(ans);
end.