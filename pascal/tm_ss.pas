const
  n=1000000;
var
  a:array[1..n] of boolean;
  prime:array[1..n] of longint;
  i,j,c,num:longint;
  b:boolean;
begin
  a[1]:=true;
  num:=0;
  for i:=2 to n do
    begin
      if a[i]=false then
      begin
        inc(num);
        prime[num]:=i;
      end;
      j:=1;
      while (i*prime[j]<=n) and (j<=num) do
          begin
            a[i*prime[j]]:=true;
            if i mod prime[j]=0 then
                break;
            inc(j);
          end;
    end;
  for i:=2 to n do
    if a[i]=false then
      write(i,' ');
  writeln;
  readln;
end.
