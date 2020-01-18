program test_noip_cs_2009_4_2017_7_19;
var
  a:array[0..5] of integer;
  sum,n,max,i,j,k:integer;
  cover:array[0..22000] of boolean;
begin
  read(a[5],a[4],a[3],a[2],a[1],a[0]);
  if ((a[5]=0)and(a[3]=0)and(a[1]=0)) then
  begin
    a[5]:=a[4]; a[4]:=a[2]; a[3]:=a[0]; a[2]:=0; a[0]:=0;
  end;
  for i:=0 to 5 do
    if (a[i]>10) then a[i]:=10+(a[i]mod 2);
  sum:=0;
  for i:=0 to 5 do sum:=sum+a[i]*(6-i);
  if ((sum mod 2)<>0) then
  begin
    writeln('Can''t be divided.');
    exit;
  end;
  sum:=sum div 2; max:=0; cover[0]:=true;
  for i:=1 to sum*2 do cover[i]:=false;
  for i:=0 to 5 do
  begin
    j:=0;
    while (j<a[i]) do
    begin
      for k:=max downto 0 do
      begin
        if (cover[k]) then cover[k+6-i]:=true;
      end;
      max:=max+6-i; j:=j+1;
    end;
  end;
  if (cover[sum])
  then writeln('Can be divided.')
  else writeln('Can''t be divided');
end.