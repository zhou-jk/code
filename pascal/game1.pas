program xiangqi;
var
x:array[1..10,1..9]of integer;
zf,yf:string;
z,y,xf:boolean;
c,d,x1,y1,x2,y2:integer;
procedure beginner;
begin
writeln('�󷽣�');
readln(zf);
writeln('�ҷ���');
readln(yf);
writeln('��ʼ!');
end;
procedure first;
var a,b:integer;
begin
for a:=1 to 10 do
for b:=1 to 9 do
x[a,b]:=0;
x[1,1]:=5;x[1,2]:=4;x[1,3]:=3;x[1,4]:=2;x[1,5]:=1;x[1,6]:=2;x[1,7]:=3;x[1,8]:=4;x[1,9]:=5;x[3,2]:=6;x[3,8]:=6;x[4,1]:=7;x[4,3]:=7;x[4,5]:=7;x[4,7]:=7;x[4,9]:=7;x[10,1]:=5+7;x[10,2]:=4+7;x[10,3]:=3+7;x[10,4]:=2+7;x[10,5]:=1+7;x[10,6]:=2+7;x[10,7]:=3+7;x[10
,8]:=4+7;x[10,9]:=5+7;x[8,2]:=6+7;x[8,8]:=6+7;x[7,1]:=7+7;x[7,3]:=7+7;x[7,5]:=7+7;x[7,7]:=7+7;x[7,9]:=7+7;
end;
procedure writer;
var a,b:integer;
begin
writeln;
writeln(' 1 2 3 4 5 6 7 8 9');
for a:=1 to 10 do
begin
write(a:2,' ');
for b:=1 to 9 do
case x[a,b] of
0:write(' ');
1:write('��');
2:write('ʿ');
3:write('��');
4:write('��');
5:write('��');
6:write('��');
7:write('��');
8:write('˧');
9:write('��');
10:write('��');
11:write('��');
12:write('��');
13:write('��');
14:write('��');
end;
writeln;
end;
writeln;
end;
{function k:boolean;begink:=true;if xfthenif x[x1,y1]<8thenbegink:=false;exit;endelseif x[x1,y1]>7thenbegink:=false;exit;end;end;}
begin
while true do
begin
beginner;
first;
xf:=true;
repeat
writer;
if xf
then write('��:')
else write('�ҷ�:');
readln(x1,y1,x2,y2);
{while not(k) dobeginwriteln('�Բ��𣬲����������£��������£�');readln(x1,y1,x2,y2);end;}
x[x2,y2]:=x[x1,y1];
x[x1,y1]:=0;
z:=false;
y:=false;
for c:=1 to 10 do
for d:=1 to 9 do
begin
if x[c,d]=1 then z:=true;
if x[c,d]=8 then y:=true;
end;
xf:=not(xf);
until (not(z))or(not(y));
if z
then write(zf,'Ӯ��')
else write(yf,'Ӯ��');
writeln;
end;
end.
