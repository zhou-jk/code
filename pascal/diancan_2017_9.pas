//PrayerOJ 1288
var
  v,a:array[1..20] of integer;
  s:array[1..4] of byte;
  k,x,t,tmp,ans,i:integer;
begin
  read(k);
  for i:=1 to k do read(v[i]);
  read(x);
  for i:=1 to 4 do read(s[i]);
  read(t);
  for i:=1 to t do
  begin
   read(tmp);
   inc(a[tmp]);
  end;
  repeat
    tmp:=0;
    for i:=1 to 4 do
      if a[s[i]]>0 then inc(tmp,v[s[i]]);
    if tmp>x then
    begin
      inc(ans,x);
      for i:=1 to 4 do
        if a[s[i]]>0 then dec(a[s[i]]);
    end;
  until tmp<=x;
  for i:=1 to 20 do inc(ans,v[i]*a[i]);
  write(ans);
end.