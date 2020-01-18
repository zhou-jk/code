uses math;
var
  a,b,c,e:ansistring;
  i,lena,lenb,le:longint;
  flag:boolean;
procedure zh(var n:ansistring; var len:longint);
  var
    i,j,d:longint;
  begin
    n:=n+' ';
    d:=1;
    for i:=1 to length(n) do
      if n[i]<>' ' then
        begin
          n[d]:=n[i];
          inc(d);
        end;
    //for i:=255 downto j+1 do
      //n[i]:=;
    len:=d-1;
    n:=upcase(n);
  end;
begin
  readln(a);
  readln(b);
  zh(a,lena);
  zh(b,lenb);
  //writeln('###a',a);
  //writeln('***',lena,' ',lenb);
  //writeln(c,'c');
  //writeln(e,'e');
  le:=max(lena,lenb);
  flag:=true;
  for i:=1 to le do
        if a[i]<>b[i] then
        begin
          flag:=false;
          break;
        end;
  if flag then
    writeln('YES')
  else
    writeln('NO');
end.
