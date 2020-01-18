program h_1898_nainiuxinhao1_2017_7_14;
var
  s,s1:string[100];
  m,n,k,i,j,p:byte;
begin
  readln(m,n,k);
  for i:=1 to m do
  begin
    readln(s);
    s1:='';
    for j:=1 to n do
      for p:=1 to k do s1:=s1+s[j];
    for j:=1 to k do writeln(s1);
  end;
end.


