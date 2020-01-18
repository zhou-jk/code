var
  a,b:string;
  i,j,t:longint;
  c:boolean;
begin
  readln(a);
  readln(b);
  if length(a)>length(b) then
    for i:=1 to length(a)-length(b)+1 do
      begin
        t:=0;
        for j:=1 to length(b) do
          if a[i-1+j]=b[j] then
            t:=t+1;
        if t=length(b) then
          begin
            c:=true;
            writeln(b,' is substring of ',a);
          end;
      end
  else
    for i:=1 to length(b)-length(a)+1 do
      begin
        t:=0;
        for j:=1 to length(a) do
          if b[i-1+j]=a[j] then
            t:=t+1;
        if t=length(a) then
          begin
            c:=true;
            writeln(a,' is substring of ',b);
          end;
      end;
  if c=false then
    writeln('No substring');
  readln;
end.