program htm_1041_FBItree_digui_2017_1_21;
var
  h:array[1..1024] of char;
  g,i,n:integer;
  k:char;
function FBI(a,b:longint):char;
var c,d:char;
begin
  if b=a then
    if h[b]='0'
    then begin write('B'); exit('B'); end
    else begin write('I'); exit('I'); end;
  c:=FBI(a,(a+b) div 2); d:=FBI((a+b) div 2+1,b);
  if (c='B')and(d='B') then begin write('B'); exit('B'); end;
  if (c='I')and(d='I') then begin write('I'); exit('I'); end;
  write('F'); exit('F');
end;
begin
  readln(g);
  n:=1;
  for i:=1 to g do n:=n*2;
  for i:=1 to n do read(h[i]);
  if n>0 then k:=FBI(1,n);
end.








