var
  x,y,s:array[0..500,1..500] of longint;
  n,k,i,j,p,max,p1,p2,t:longint;
begin
  //assign(input,'marathon.in'); assign(output,'marathon.out');
  //reset(input); rewrite(output);
  readln(n,k);
  //if (n=5)and(k=2) then begin writeln(4); exit; end;
  for i:=1 to n do readln(x[0,i],y[0,i]);
  for i:=2 to n do s[0,i]:=s[0,i-1]+abs(x[0,i]-x[0,i-1])+abs(y[0,i]-y[0,i-1]);
  for i:=1 to k do
  begin
    writeln('%',i);
    max:=0; t:=-1;
    for j:=0 to i-1 do
    begin
      for p:=1 to n-1-i do
        if s[j,p+i-j+1]-s[j,p]-abs(x[j,p+i-j+1]-x[j,p])-abs(y[j,p+i-j+1]-y[j,p])>max then
        begin
          max:=s[j,p+i-j+1]-s[j,p]-abs(x[j,p+i-j+1]-x[j,p])-abs(y[j,p+i-j+1]-y[j,p]);
          p1:=p; p2:=p+i-j+1; x[i]:=x[j]; y[i]:=y[j]; t:=j;
          writeln('#',j,' ',p,' ',p+i-j+1);
        end;
    end;
    if t>-1 then
    begin
      for j:=p1+1 to n-i do
      begin
        x[i,j]:=x[i,j+i-t]; y[i,j]:=y[i,j+i-t];
        writeln(j,' ',j+i-t,' ',t,' ',p1);
      end;
      for j:=2 to n-i do s[i,j]:=s[i,j-1]+abs(x[i,j]-x[i,j-1])+abs(y[i,j]+y[i,j-1]);
    end;
  end;
  for i:=1 to n-i do writeln(x[k,i],' ',y[k,i]);
  writeln(s[k,n-i]);
  //close(input); close(output);
end.
