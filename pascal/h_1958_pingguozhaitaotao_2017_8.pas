program h_1958_pingguozhaitaotao_2017_8_3;
var
  a,t:array[0..10000] of longint;
  b:array[1..10000] of boolean;
  n,m,i,j,tmp,ans:longint;
begin
  readln(n,m);
  for i:=1 to n do readln(a[i]);
  for i:=1 to m do readln(t[i]);
  ans:=m;
  for i:=1 to n do
  begin
    tmp:=0;
    for j:=1 to m do
      if not b[j]and(t[j]<=a[i])and(t[j]>t[tmp]) then
      begin
        tmp:=j;
        if t[j]=a[i] then break;
      end;
    if tmp<>0 then
    begin
      b[tmp]:=true;
      dec(ans);
    end;
  end;
  writeln(ans);
end.
