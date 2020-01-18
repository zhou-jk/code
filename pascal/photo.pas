var
  a:array[1..5,1..20000] of integer;
  ans:array[1..20000] of integer;
  n,i,j,t:integer;
  b:boolean;
function p(b,c:integer):boolean;
var i,j,b1:integer;
begin
  b1:=0; p:=false;
  for i:=1 to 5 do
  begin
    if a[i,b]<a[i,c] then inc(b1);
    if b1=3 then exit(true);
  end;
end;
begin
  assign(input,'photo.in');
  assign(output,'photo.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do begin readln(ans[i]); a[1,ans[i]]:=i; end;
  for i:=2 to 5 do
    for j:=1 to n do begin readln(t); a[i,t]:=j; end;
  for i:=2 to n do
  begin
    j:=i-1; t:=ans[i];
    while (j>0)and p(t,ans[j]) do
    begin
      ans[j+1]:=ans[j];
      dec(j);
    end;
    ans[j+1]:=t;
  end;
  for i:=1 to n do writeln(ans[i]);
  close(input);
  close(output);
end.
