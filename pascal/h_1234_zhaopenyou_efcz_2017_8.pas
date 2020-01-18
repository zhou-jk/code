program h_1234_zhaopengyou_erfenchazhao_2017_8_16;
var
  p:array[1..100000] of string;
  n,m,i,l,r,mid:longint;
  s:string;
begin
  readln(n);
  for i:=1 to n do readln(p[i]);
  readln(m);
  for i:=1 to m do
  begin
    readln(s);
    l:=1; r:=n;
    while l<=r do
    begin
      mid:=(l+r)div 2;
      if p[mid]=s then
      begin
        writeln(s);
        break;
      end;
      if p[mid]>s
      then r:=mid-1
      else l:=mid+1;
    end;
  end;
end.
