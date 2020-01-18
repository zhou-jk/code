program h_1946_number_2017_8_1;
const
  s:array[1..4,1..2] of longint=((1,2),(3,4),(5,6),(7,0));
  a1:array[1..7] of char=('I','V','X','L','C','D','M');
var
  a2:array[1..7] of longint;
  n,i,j,t,t1:longint;
begin
  readln(n);
  //i:=n;
  for i:=1 to n do
  begin
    t:=i; j:=0;
    while t>0 do
    begin
      inc(j);
      t1:=t mod 10;
      if t1<=3
      then a2[s[j,1]]:=a2[s[j,1]]+t1
      else if t1<=5
           then inc(a2[s[j,2]])
           else if t1<=8
                then begin
                       inc(a2[s[j,2]]); a2[s[j,1]]:=a2[s[j,1]]+t1-5;
                     end
                else inc(a2[s[j+1,1]]);
      if (t1=4)or(t1=9) then inc(a2[s[j,1]]);
      t:=t div 10;
      //writeln(i,' ',j,' ',t,' ',t1);
    end;
  end;
  for i:=1 to 7 do
    if a2[i]>0 then writeln(a1[i],' ',a2[i]);
end.