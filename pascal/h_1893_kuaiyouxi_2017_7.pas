program h_1893_kuaiyouxi_2017_7_12;
var
  a,l,r:array['a'..'z'] of integer;
  n,i,j:byte;
  s:string;
  c:char;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  max:=b;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    j:=1;
    fillchar(l,52,0); fillchar(r,52,0);
    while s[j]<>' ' do
    begin
      inc(l[s[j]]);
      inc(j);
    end;
    for j:=j+1 to length(s) do inc(r[s[j]]);
    for c:='a' to 'z' do a[c]:=a[c]+max(l[c],r[c]);
  end;
  for c:='a' to 'z' do writeln(a[c]);
end.




