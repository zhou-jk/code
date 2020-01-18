program h_1356_zuidalianxuziduanhe_dongtaiguihua_2017_2_8;
var
  a,f,g:array[1..100000] of longint;
  n,i,ans,l:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  f[1]:=a[1]; g[1]:=1; ans:=a[1]; l:=1;
  for i:=2 to n do
  begin
    if f[i-1]>=0
    then begin
           f[i]:=f[i-1]+a[i];
           g[i]:=g[i-1]+1;
         end
    else begin
           f[i]:=a[i];
           g[i]:=1;
         end;
    if f[i]>ans then
    begin
      ans:=f[i];
      l:=g[i];
    end;
  end;
  writeln(ans,' ',l);
end.


