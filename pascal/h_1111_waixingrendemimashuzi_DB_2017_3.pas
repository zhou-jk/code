program h_1111_waixingrendemimashuzi_DB_2017_3_25;
var
  s:array['a'..'z']of byte;
  f:array[1..255]of byte;
  i,j,k,p,ans:integer;
  n:ansistring;
begin
  readln(n);
  for i:=1 to length(n) do s[n[i]]:=i;
  readln(n);
  j:=1;
  for i:=1 to length(n) do
    if (i=length(n))or(n[i+1]=' ') then
    begin
      fillchar(f,sizeof(f),0);
      f[j]:=1; ans:=1;
      for k:=j+1 to i do
      begin
        for p:=j to k-1 do
          if (s[n[p]]<=s[n[k]])and(f[p]>f[k]) then f[k]:=f[p];
        inc(f[k]);
        if f[k]>ans then ans:=f[k];
      end;
      write(ans);
      j:=i+2;
    end;
  writeln;
end.




