program codevs_1297_yingbi_wanquanbeibao_2017_2_19;
var
  f:array[0..100,0..2500] of boolean;
  t,mi,ma:array[1..7] of integer;
  w,n,i,j,k,p,ans:integer;
begin
  readln(w);
  readln(n);
  f[0,0]:=true;
  for i:=1 to n do readln(t[i],mi[i],ma[i]);
  for i:=1 to w do
    for j:=1 to n do
      for k:=t[j] to 2500 do
      begin
        if f[i,k] then continue;
        for p:=mi[j] to ma[j] do
          if i-p>=0 then
            if f[i-p,k-t[j]] then
            begin
              f[i,k]:=true;
              break;
            end;
      end;
  for i:=0 to 2500 do
    if f[w,i] then inc(ans);
  writeln(ans);
end.
