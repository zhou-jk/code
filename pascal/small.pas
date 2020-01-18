program small(input,output);
var
  a:array[1..3,1..3] of longint;
  e,f:array[1..9] of longint;
  b,i,j,c,g:longint;
begin
  writeln('Please input a 3*3 number square.');
  for i:=1 to 3 do
    for j:=1 to 3 do
      if j mod 3=0 then
        readln(a[i,3])
      else
        read(a[i,j]);
  b:=a[1,1];
  for i:=1 to 3 do
    for j:=1 to 3 do
      if a[i,j]<b then
        begin
          b:=a[i,j];
          c:=1;
          e[1]:=i;
          f[1]:=j;
        end
      else
        if a[i,j]=b then
          begin
            c:=c+1;
            e[c]:=i;
            f[c]:=j;
          end;
  writeln();
  writeln('minimum:',b);
  for g:=1 to c do
    writeln('coordinate:(',f[g],',',e[g],')');
end.




