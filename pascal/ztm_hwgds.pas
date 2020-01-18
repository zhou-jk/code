var
  a,r:array[1..100000] of longint;
  i,j,n1,n2,c,d,mid:longint;
  b:boolean;
procedure px(s,t:longint);
var
  m,,i,j,k:longint;
begin
  if s>=t then exit;
  m:=(s+t) div 2;
  px(s,m);
  px(m+1,t);
  i:=s;
  j:=m+1;
  k:=s;
  while (i<=m)and(j<=t) do
    if a[i]<=a[j]
    then begin r[k]:=a[i]; inc(i); inc(k); end
    else begin r[k]:=a[j]; inc(j); inc(k); end;
  while i<=m do
  begin r[k]:=a[i]; inc(i); inc(k) end;
  while j<=t do
  begin r[k]:=a[j]; inc(j); inc(k) end;
  for i:=s to t do
    a[i]:=r[i];
end;
begin
  readln(n1);
  for i:=1 to n1 do
    read(a[i]);
  readln(n2);
  px(1,n1);
  for i:=1 to n1 do
  begin
    c:=1; d:=n1;
    while c<=d do
    begin
       mid:=(c+d) div 2;
       if mid<>i then
         if a[mid]+a[i]=n2
         then begin b:=true; writeln(a[i],' ',a[mid]); break; end
         else if n2>a[mid]+a[i]
              then c:=mid+1
              else d:=mid-1
       else if a[mid]+a[i]=n2
            then break
            else if n2>a[mid]+a[i]
                 then c:=mid+1
                 else d:=mid-1;
    end;
    if b then break;
  end;
  if b=false then
    writeln('No');
  readln;
end.



