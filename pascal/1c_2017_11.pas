//PrayerOJ 2079
var
  f:array[1..5000,0..1000] of longint;
  l:array[1..5000] of integer;
  t,k,n,i,j,p:integer;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  read(t);
  for i:=1 to t do
  begin
    read(k,n);
	inc(k,8);
	for j:=1 to n do read(l[n-j+1]);
	fillchar(f,sizeof(f),127);
	for j:=1 to n do f[j,0]:=0;
	for j:=1 to n do
	  for p:=1 to min(k,j div 3) do
	  begin
	    f[j,p]:=min(f[j-1,p],f[j-2,p-1]+sqr(l[j-1]-l[j]));
	    //writeln(j,' ',p,' ',f[j,p],' ',f[j-1,p],' ',f[j-2,p-1],' ',sqr(l[j]-l[j-1]));
	  end;
    writeln(f[n,k]);
  end;
end.