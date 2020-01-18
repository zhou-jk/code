var
  a:array[1..1000] of longint;
  n,i,j,min,max,t,ans:longint;
begin
  assign(input,'skidesign.in'); assign(output,'skidesign.out');
  reset(input); rewrite(output);
  readln(n);
  min:=maxlongint;
  for i:=1 to n do
  begin
    readln(a[i]);
    if a[i]<min then min:=a[i];
    if a[i]>max then max:=a[i];
  end;
  ans:=maxlongint;
  for i:=min to max-17 do
  begin
    t:=0;
    for j:=1 to n do
	begin
	  if a[j]<i then t:=t+sqr(i-a[j]);
	  if a[j]>i+17 then t:=t+sqr(a[j]-i-17);
	end;
	if t<ans then ans:=t;
  end;
  writeln(ans);
  close(input); close(output);
end.
