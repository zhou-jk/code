program h_1220_sanjiaoxingmuchang_2017_3_4;
var
  f:array[0..1600,0..1600] of boolean;
  n,i,j,k,l,sum,ans:longint;
function p:boolean;
begin
  p:=(j+k>sum-j-k)and(sum-k>k)and(sum-j>j);
end;
function h:longint;
var p:real;
begin
  p:=sum/2;
  h:=trunc(sqrt(p*(p-j)*(p-k)*(-p+j+k))*100);
end;
begin
  readln(n);
  f[0,0]:=true;
  ans:=-1;
  for i:=1 to n do
  begin
    readln(l);
    inc(sum,l);
    for j:=sum downto 0 do
      for k:=sum downto 0 do
      begin
        if (j>=l)and(f[j-l,k]) then f[j,k]:=true;
        if (k>=l)and(f[j,k-l]) then f[j,k]:=true;
        if (f[j,k])and p and(h>ans) then ans:=h;
      end;
  end;
  writeln(ans);
end.

