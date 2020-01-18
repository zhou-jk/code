program noi_2_6_8464_gupiaomaimai_dongtaiguihua_2017_1_8;
var
  //f:array[1..100000,1..100000] of longint;
  a:array[1..100000] of longint;
  n,j,k,l,m,m1,m2:longint;
  t,i:integer;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n);
    for j:=1 to n do read(a[j]);
    //writeln('*');
    {for j:=1 to n-1 do
      for k:=j+1 to n do
        if a[k]>a[j] then f[j,k]:=a[k]-a[j];}
    //writeln('#');
    m:=0;
    for j:=1 to n do
    begin
      m1:=0;
      for k:=1 to j-1 do if a[j]-a[k]>m1 then begin {writeln('#',j,' ',k);} m1:=a[j]-a[k]; end;
      m2:=0;
      for k:=j to n do
        for l:=k+1 to n do if a[l]-a[k]>m2 then begin {writeln('*',l,' ',k);} m2:=a[l]-a[k]; end;
      if m1+m2>m then m:=m1+m2;
    end;
    writeln(m);
  end;
end.
