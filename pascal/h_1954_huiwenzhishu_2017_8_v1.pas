program h_1954_huiwenzhishu_2017_8_3_v1;
var
  a,b,i:longint;
function l(n:longint):longint;
begin
  l:=0;
  while n>0 do
  begin
    inc(l);
    n:=n div 10;
  end;
end;
function ip(n:longint):boolean;
var i:longint;
begin
  for i:=2 to trunc(sqrt(n)) do
    if n mod i=0 then exit(false);
  exit(true);
end;
procedure solve(l,k:longint;n,n1:string);
var
  num:longint;
  i:char;
begin
  //writeln(l,' ',k,' ',n,' ',n1);
  if k=l div 2+1 then
  begin
    if l mod 2=0
    then begin
           val(n+n1,num);
           if num>b then halt;
           if (num>=a)and ip(num) then writeln(num);
         end
    else for i:='0' to '9' do
         begin
           val(n+i+n1,num);
           if num>b then halt;
           if (num>=a)and ip(num) then writeln(num);
         end;
    exit;
  end;
  for i:='0' to '9' do solve(l,k+1,n+i,i+n1);
end;
begin
  readln(a,b);
  //writeln(l(a),' ',l(b));
  for i:=l(a) to l(b) do solve(i,1,'','');
end.