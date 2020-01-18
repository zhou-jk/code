program noi_2_6_6252_daitongpeifudezifuchuanpipei_DP_2017_4_29_v1;
var
  f:array[0..20,0..20] of boolean;
  s,s1:string;
  i,j,k:byte;
begin
  readln(s);
  readln(s1);
  f[0,0]:=true;
  for i:=1 to length(s) do
    for j:=0 to length(s1) do
      if (j>0)and((s[i]=s1[j])or(s[i]='?'))
      then f[i,j]:=f[i-1,j-1]
      else if s[i]='*' then
             for k:=0 to j do
               if f[i-1,j-k] then
               begin
                 f[i,j]:=true;
                 break;
               end;
  if f[length(s),length(s1)]
  then writeln('matched')
  else writeln('not matched');
end.
