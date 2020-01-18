program h_1955_square_DP_2017_8_3_AC;
var
  f:array[1..250,1..250,1..250] of word;
  s:array[1..250,1..250] of char;
  ans:array[2..250] of word;
  n,i,j,k:byte;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do read(s[i,j]);
    readln;
  end;
  for i:=1 to n do
  begin
    if s[1,i]='1' then f[1,i,1]:=1;
    if s[i,1]='1' then f[i,1,1]:=1;
  end;
  for i:=2 to n do
    for j:=2 to n do
    begin
      if s[i,j]='0' then continue;
      f[i,j,1]:=1;
      for k:=2 to min(i,j) do
      begin
        if (s[i-k+1,j]='0')or(s[i,j-k+1]='0') then break;
        f[i,j,k]:=f[i-1,j-1,k-1]; ans[k]:=ans[k]+f[i,j,k];
        //writeln(i,' ',j,' ',k,' ',f[i,j,k]);
      end;
    end;
  for i:=2 to n do
    if ans[i]>0 then writeln(i,' ',ans[i]);
end.