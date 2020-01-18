program h_1889_zifuchuanbianhuan_2017_7_10;
var
  l,r,k:array[1..300] of longint;
  s,s1:ansistring;
  m,i,j,len:longint;
begin
  readln(s);
  readln(m);
  for i:=1 to m do
  begin
    readln(l[i],r[i],k[i]);
    len:=r[i]-l[i]+1;
    k[i]:=k[i] mod len;
    s1:='';
    for j:=l[i] to r[i] do s1:=s1+s[j];
    s1:=s1+s1;
    for j:=l[i] to r[i] do s[j]:=s1[len+j-l[i]+1-k[i]]
  end;
  writeln(s);
end.
