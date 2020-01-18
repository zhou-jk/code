var
  a,b,c:string;
function zh(n:string):string;
  var
    i,j,d:longint;
  begin
    d:=length(n);
    for i:=1 to d do
      if n[i]=' ' then
        begin
          for j:=i+1 to length(n) do
            n[j-1]:=n[j];
          d:=d-1;
        end;
    n:=upcase(n);
    zh:=n;
  end;
begin
  readln(a);
  readln(b);
  c:=zh(a);
  writeln(c);
end.