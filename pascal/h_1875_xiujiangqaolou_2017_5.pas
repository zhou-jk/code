program h_1875_xiujiangaolou_2017_5_6;
var
  p,h:array[1..2000] of integer;
  t,n,i,j,k,s,max,m,num:longint;
begin
  readln(t,n);
  for i:=1 to t do
  begin
    s:=0;
    for j:=1 to n do
    begin
      read(h[j]);
      p[h[j]]:=j;
    end;
    for j:=1 to n-2 do
      for k:=j+1 to n-1 do
      begin
        num:=2*h[k]-h[j];
        if (num>0)and(num<=n)and(p[num]>k) then inc(s);
      end;
    if s>max then
    begin
      m:=i;
      max:=s;
    end;
  end;
  writeln(m,' ',max);
end.

