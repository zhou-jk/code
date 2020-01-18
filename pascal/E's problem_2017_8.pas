//Tyvj 4748
var
  n,a,i,s25,s50,s100,t25,t50,ans:longint;
procedure dfs(k:byte);
begin
  if k=n+1 then
  begin
    inc(ans); ans:=ans mod 1000000007;
    exit;
  end;
  if s25>0 then
  begin
    dec(s25); inc(t25);
    dfs(k+1);
    inc(s25); dec(t25);
  end;
  if (s50>0)and(t25>0) then
  begin
    dec(s50); dec(t25); inc(t50);
    dfs(k+1);
    inc(s50); inc(t25); dec(t50);
  end;
  if (s100>0) then
  begin
    dec(s100);
    if (t25>0)and(t50>0)
    then begin
           dec(t25); dec(t50);
           dfs(k+1);
           inc(t25); inc(t50);
         end
    else if t25>=3 then
         begin
           dec(t25,3);
           dfs(k+1);
           inc(t25,3);
         end;
    inc(s100);
  end;
end;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a);
    case a of
      25:inc(s25);
      50:inc(s50);
      100:inc(s100);
    end;
  end;
  dfs(1);
  write(ans);
end.