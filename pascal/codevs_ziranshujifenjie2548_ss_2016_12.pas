program codevs_ziranshujifenjie2548_shenso_2016_12_8;
var
  n,m,ans,i,n1,n2,n3,n4,n5,n6,ans1,ans2,ans3,ans4:longint;
procedure dfs(old,n:longint);
var
  i:longint;
begin
  if m=n then begin inc(ans); exit; end;
  if n mod m<>0 then exit;
  for i:=old to n div m do
  begin
    if n mod i<>0 then continue;
    m:=m*i;
    dfs(i,n);
    m:=m div i;
  end;
end;
begin
  readln(n);
  for i:=trunc(sqrt(n)) downto 1 do
    if n mod i=0 then
    begin
      n1:=i; n2:=n div i;
    end;
  for i:=trunc(sqrt(n1)) downto 1 do
    if n1 mod i=0 then
    begin
      n3:=i; n4:=n1 div i;
    end;
  for i:=trunc(sqrt(n2)) downto 1 do
    if n2 mod i=0 then
    begin
      n5:=i; n6:=n2 div i;
    end;
  m:=1;
  dfs(2,n3);
  ans1:=ans; ans:=0;
  dfs(2,n4);
  ans2:=ans; ans:=0;
  dfs(2,n5);
  ans3:=ans; ans:=0;
  dfs(2,n6);
  ans4:=ans; ans:=0;
  writeln(ans1*ans2*ans3*ans4);
end.
