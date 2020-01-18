program htm_1131_jielong_digui_2017_2_3_yh_h;
var
  l:array[-1..27] of longint;
  n,i:longint;
procedure solve(n,k:longint);
begin
  if n>l[k-1]+k+3
  then solve(n-(l[k-1]+k+3),k-1)
  else if n>l[k-1]
       then begin
              if n-l[k-1]=1
              then writeln('m')
              else writeln('o');
              exit;
            end
       else solve(n,k-1);
end;
begin
  readln(n);
  l[0]:=3;
  while l[i]<n do
  begin
    inc(i);
    l[i]:=2*l[i-1]+i+3;
  end;
  solve(n,i);
end.