program noi_2_6_1808_gonggongzixulie_DP_2017_4_22;
var
  f:array[0..200,0..200] of byte;
  t,s,s1,s2:ansistring;
  i,j,k,l1,l2:integer;
function max(a,b:byte):byte;
begin
  if a>b then exit(a);
  max:=b;
end;
begin
  while not seekeof do
  begin
    readln(t);
    s:='';
    for i:=1 to length(t) do
      if (t[i] in['a'..'z']){or(t[i] in['0'..'9'])or(t[i] in['A'..'Z'])}or(t[i]=' ') then s:=s+t[i];
    //while s[1]=' ' do delete(s,1,1);
    //while s[length(s)]=' ' do delete(s,length(s),1);
    while pos('  ',s)>0 do delete(s,pos('  ',s),1);
    k:=pos(' ',s); s1:=copy(s,1,k-1); s2:=copy(s,k+1,255); l1:=length(s1); l2:=length(s2);
    for i:=1 to l1 do
      for j:=1 to l2 do
        if s1[i]=s2[j]
        then f[i,j]:=f[i-1,j-1]+1
        else f[i,j]:=max(f[i,j-1],f[i-1,j]);
    writeln(f[l1,l2]);
  end;
end.




