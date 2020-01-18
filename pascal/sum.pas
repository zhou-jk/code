var
  f:array[1..100,-1000..1000] of longint;
  n,i,j,min,max:longint;
begin
  //assign(input,'sum.in'); assign(output,'sum.out');
  //reset(input); rewrite(output);
  readln(n);
  f[1,-1]:=1; min:=-1; max:=-1;
  for i:=2 to n-1 do
    for j:=min to max do
    begin
      //writeln(i,' ',j,' ',f[i,j]);
      f[i,j+i]:=f[i,j+i]+f[i-1,j];
      f[i,j-i]:=f[i,j-i]+f[i-1,j];
      if (j+i>max)and(f[i,j+i]>0) then max:=j+i;
      if (j-i<min)and(f[i,j-i]>0) then min:=j-i;
    end;
  writeln(f[n-1,n]);
  //close(input); close(output);
end.