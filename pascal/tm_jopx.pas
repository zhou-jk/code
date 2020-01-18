type arr=array[1..10] of longint;
var
  a:arr;
  i:longint;
procedure cl(var a,b,c:longint;d:longint);
  begin
    a:=d; inc(b); inc(c);
  end;
procedure px(s,t:longint;var k:arr);
  var
    m,j,g,h:longint;
    f:arr;
  begin
    if s>=t then exit;
    m:=(s+t) div 2;
    px(s,m,k);
    px(m+1,t,k);
    g:=s;
    j:=m+1;
    h:=s;
    while (g<=m) and (j<=t) do
      if k[g] mod 2=k[j] mod 2 then
        if k[g] mod 2=0 then
          if k[g]<=k[j] then
            cl(f[h],g,h,k[g])
          else
           cl(f[h],j,h,k[j])
        else
          if k[g]>=k[j] then
            cl(f[h],g,h,k[g])
          else
           cl(f[h],j,h,k[j])
      else
        if k[g] mod 2=1 then
          cl(f[h],g,h,k[g])
        else
          cl(f[h],j,h,k[j]);
    while g<=m do
      begin
        f[h]:=k[g]; inc(g); inc(h);
      end;
    while j<=t do
      begin
        f[h]:=k[j]; inc(j); inc(h);
      end;
    for i:=s to t do
      k[i]:=f[i];
  end;
begin
  for i:=1 to 10 do
    read(a[i]);
  px(1,10,a);
  for i:=1 to 10 do
    write(a[i],' ');
  writeln;
  readln;
end.



