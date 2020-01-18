program codevs_3657_kuohaoxulie_2017_4_29_v1;
var
  f:array[1..101,0..100] of byte;
  i,j,k,l:byte;
  s:string;
function min(a,b:byte):byte;
begin
  if a<b then exit(a);
  min:=b;
end;
begin
  readln(s);
  l:=length(s);
  for i:=l downto 1 do
    for j:=i to l do
    begin
      f[i,j]:=255;
      if (s[i]='(')and(s[j]=')')or(s[i]='[')and(s[j]=']') then f[i,j]:=f[i+1,j-1];
      if (s[i]='(')or(s[i]='[') then f[i,j]:=min(f[i,j],f[i+1,j]+1);
      if (s[i]=')')or(s[i]=']') then f[i,j]:=min(f[i,j],f[i,j-1]+1);
      for k:=i to j-1 do f[i,j]:=min(f[i,j],f[i,k]+f[k+1,j]);
    end;
  writeln(f[1,l]);
end.



