var
  i,j:longint;
  a:array[0..1000] of string;
  b:boolean;
  f:text;
begin
  assign(f,'d:\Ascll.txt');
  rewrite(f);
  for i:=0 to 1000 do
  begin
    b:=true;
    for j:=0 to 1000 do
      if a[j]=chr(i) then
        b:=false;
    if b then
    begin
      a[i]:=chr(i);
      writeln(f,i,' ',a[i]);
    end;
  end;
  writeln('end');
  close(f);
  readln;
end.
