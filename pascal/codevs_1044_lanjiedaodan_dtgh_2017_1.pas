program codevs_1044_lanjiedaodan_dongtaiguihua_2017_1_21;
var
  a,f:array[1..20] of integer;
  i,j,k,ans:byte;
begin
   while not eof do
   begin
     inc(i);
     readln(a[i]);
   end;
   f[1]:=1; ans:=1;
   for j:=2 to i do
   begin
     for k:=1 to j-1 do
       if (a[k]>=a[j])and(f[k]>f[j]) then f[j]:=f[k];
     inc(f[j]);
     if f[j]>ans then ans:=f[j];
   end;
   writeln(ans);
end.
