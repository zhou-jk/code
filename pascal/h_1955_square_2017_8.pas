program h_1955_square_2017_8_3_WA; //before:TLE
var
  v:array[1..250,1..250] of boolean;
  s:array[1..250,1..250] of char;
  ans:array[1..250] of word;
  n,i,j,k,p:integer;
  b:boolean;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do read(s[i,j]);
    readln;
  end;
  for i:=1 to n-1 do
    for j:=1 to n-1 do
      if not v[i,j] then
        for k:=1 to min(n-i+1,n-j+1) do
        begin
          b:=false;
          for p:=0 to k-1 do
            if (s[i+k-1,j+p]='0')or(s[i+p,j+k-1]='0') then
            begin
              b:=true;
              break;
            end;
          if b then break;
          for p:=0 to k-1-1 do
          begin
            v[i+k-1-1,j+p]:=true;
            v[i+p,j+k-1-1]:=true;
          end;
          for p:=1 to k-1 do ans[k-p+1]:=ans[k-p+1]+p*2-1;
        end;
  {writeln;
  for i:=1 to n do
  begin
    for j:=1 to n do write(byte(v[i,j]));
    writeln;
  end;}
  for i:=2 to n do
    if ans[i]>0 then writeln(i,' ',ans[i]);
end.
