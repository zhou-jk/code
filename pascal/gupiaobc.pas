program chaogupiao;
uses crt,graph,sockets;
var
cc:array[0..1000,1..8] of real;i:integer;gn:array[0..1000] of string;backup:integer;
ac:char; money:real; bn:integer; cmoney:real; cg:longint; rg:longint; gec:longint;
day:longint;hour:longint;gp:integer;cpd:integer;cps:integer;pz,pd:integer;
null:real;  j:integer; exc:string; page:integer;
//graph dan yuan
var gd,gm:integer;
ptd:string;

//k xian tu
ksd:array[0..1000,1..10]of real;
kso:array[0..1000,1..84]of real;
kss:array[0..1000,1..84]of real;
ksh:array[0..1000,1..84]of real;
ksl:array[0..1000,1..84]of real;
kn:integer;
ksb:integer;
kgpc:integer;
drawb:integer;
outstring:string;
nullstring:string;
//save&load
save:text;
load:text;
fillname:string;
//extra
linec:integer;
sfqo:integer;
cj:array[1..50]of integer;
cjn:array[1..50]of string;
cjc:integer;
cj3e:integer;
rzc:integer;
rz4b:integer;
rz8b:integer;
tp:integer;
tpc:integer;
gps:string;
pname:string;
packname:string;
pack:text;
cho:string;
packnum:integer;
edition:string;
//bank
bday:integer;
gday:integer;
blv:real;
bmoney:real;
gmoney:real;
//lucky tickets
lts:array[1..7]of shortint;
ltg:array[1..7]of shortint;
ltgn:integer;
ltgb:integer;
label nextday,buy,sell,back,loading,turnp,tu1,tu2,tu3,tu4;
begin
textcolor(white);
edition:='v1.44';
linec:=0;
kn:=84;
gp:=16;
cjc:=6;
money:=1000000;
gn[1]:='����Ƽ�     #1  ';
gn[2]:='��������     #2  ';
gn[3]:='����ɷ�     #3  ';
gn[4]:='������     #4  ';
gn[5]:='��о�Ƽ�     #5  ';
gn[6]:='ʮ��Ĺ԰     #6  ';
gn[7]:='�й�ʯ��     #7  ';
gn[8]:='MOJANG       #8  ';
gn[9]:='��ͨ�ɷ�     #9  ';
gn[10]:='����Ͱ�    #10  ';
gn[11]:='��˼��      #11  ';
gn[12]:='��üɽA     #12  ';
gn[13]:='�ǻ���Դ    #13  ';
gn[14]:='��������    #14  ';
gn[15]:='������ͨ    #15  ';
gn[16]:='��������    #16  ';
cc[1,2]:=62.6;
cc[2,2]:=27.92;
cc[3,2]:=13.57;
cc[4,2]:=14.96;
cc[5,2]:=64.51;
cc[6,2]:=5.44;
cc[7,2]:=13.68;
cc[8,2]:=21.52;
cc[9,2]:=23.78;
cc[10,2]:=40.92;
cc[11,2]:=19.99;
cc[12,2]:=12.2;
cc[13,2]:=24.21;
cc[14,2]:=15.01;
cc[15,2]:=30.64;
cc[16,2]:=35.1;
cjn[1]:='���˶�:���Ʊʱ�����н�һ��';
cjn[2]:='�ĵ���ʦ:���浵��Ǯ�޸���2147483647';
cjn[3]:='�޶�����:�ڹ���ǰ����(0,1,2)�ֹɾ�Ϊ0';
cjn[4]:='����һ��:��ǮС��10';
cjn[5]:='�����ղ���:��������Ϊֹ��ȫ������';
cjn[6]:='?????????????????????????????';
page:=1;
clrscr;
writeln('�װ��Ĺ���,��ӭʹ��ͬ��˳');
readkey();
writeln('����Ѿ��д浵�˺��밴"L",���߰�������ע��');
ac:=readkey;
if(ac='l')then
  goto loading;
writeln('��������������?');
write('��������:');
readln(pname);
writeln('ע��ɹ�,�������п��ϻ����ֽ�100��');
readkey();
randomize;
for i:=1 to gp do
begin
cc[i,1]:=cc[i,2];
cc[i,7]:=0;
cc[i,8]:=9999;
cc[i,3]:=0;
end;
repeat
linec:=0;
nextday:
clrscr;
writeln('�汾:      ������Ϸ',edition,'   ######################################');
linec:=linec+1;
hour:=hour+1;
if gp>=220 then
begin
cj[5]:=1;
writeln('���ѻ�óɾ�:�����ղ���');
linec:=linec+1;
end;
if(money<10)then
begin
  cj[4]:=1;
  writeln('���ѻ�óɾ�:����һ��');
  linec:=linec+1;
end;
if(money=2147483647)then
begin
cj[2]:=1;
writeln('���ѻ�óɾ�:�ĵ���ʦ');
linec:=linec+1;
end;
if(hour=11)then
begin
day:=day+1;
if(day=3)then
for i:=1 to gp do
if cc[i,4]<>0 then
cj3e:=1;

if cj3e=0 then
begin
writeln('���ѻ�óɾ�:�޶�����');
linec:=linec+1;
cj[3]:=1;
end;
  for i:=1 to 6 do
  begin
    tu1:ltg[i]:=random(33)+1;
    if i>1 then
    for j:=i-1 downto 1 do
    if ltg[i]=ltg[j] then
    goto tu1;
  end;
ltg[7]:=random(16)+1;
ltgn:=0;
ltgb:=0;
for i:=1 to 6 do
  if(ltg[i]=lts[i])then
  ltgn:=ltgn+1;
if(ltg[7]=lts[7])then
  ltgb:=1;
  writeln('����:��Ʊ�ı��ڿ�������Ϊ    ',ltg[1],' ',ltg[2],' ',ltg[3],' ',ltg[4],' ',ltg[5],' ',ltg[6],' ',ltg[7]);
  linec:=linec+1;
  for i:=1 to 7 do
  if lts[i]<>0 then
  ltgn:=ltgn+1;
  if ltgn=0 then
  writeln('��û�����ڲ�Ʊ')
 else
  writeln('���ĺ���Ϊ                   ',lts[1],' ',lts[2],' ',lts[3],' ',lts[4],' ',lts[5],' ',lts[6],' ',lts[7]);
  linec:=linec+1;
if(ltgn<=2)and(ltgb=0)and(ltgn<>0)then
writeln('��ʲô��Ҳû��,�����')
else
if(ltgn<=2)and(ltgb=1)then
begin
  writeln('��ϲ������6�Ƚ�');
  writeln('����Ϊ50Ԫ');
  cj[1]:=1;
writeln('���ѻ�óɾ�:���˶�');
  money:=money+50;
end;
if(ltgn=3)and(ltgb=1)then
begin
  writeln('��ϲ������5�Ƚ�');
  writeln('����Ϊ100Ԫ');
  cj[1]:=1;
writeln('���ѻ�óɾ�:���˶�');
  money:=money+100;
end;
if(ltgn=4)and(ltgb=0)then
begin
  writeln('��ϲ������5�Ƚ�');
  writeln('����Ϊ100Ԫ');
  cj[1]:=1;
writeln('���ѻ�óɾ�:���˶�');
  money:=money+100;
end;
if(ltgn=4)and(ltgb=1)then
begin
  writeln('��ϲ������4�Ƚ�');
  writeln('����Ϊ2000Ԫ');
  cj[1]:=1;
writeln('���ѻ�óɾ�:���˶�');
  money:=money+2000;
end;
if(ltgn=5)and(ltgb=0)then
begin
  writeln('��ϲ������4�Ƚ�');
  writeln('����Ϊ2000Ԫ');
  cj[1]:=1;
writeln('���ѻ�óɾ�:���˶�');
  money:=money+1000;
end;
if(ltgn=5)and(ltgb=1)then
begin
  writeln('��ϲ������3�Ƚ�');
  writeln('����Ϊ30000Ԫ');
  cj[1]:=1;
writeln('���ѻ�óɾ�:���˶�');
  money:=money+3000;
end;
if(ltgn=6)and(ltgb=0)then
begin
  writeln('��ϲ������2�Ƚ�');
  writeln('����Ϊ1250000Ԫ');
  cj[1]:=1;
writeln('���ѻ�óɾ�:���˶�');
  money:=money+1250000;
end;
if(ltgn=6)and(ltgb=1)then
begin
  writeln('��ϲ������ͷ��!!!!!!!!');
  writeln('����Ϊ5000000Ԫ');
  cj[1]:=1;
writeln('���ѻ�óɾ�:���˶�');
  money:=money+5000000;
end;
 ltgn:=0;
   for i:=1 to 7 do
  lts[i]:=0;
linec:=linec+1;
for i:=1 to 7 do
lts[i]:=0;
if(day=gday)then
begin
money:=money-gmoney;
gday:=0;
end;
tp:=random(5);
if(tp=1)then
  begin
  tpc:=random(gp)+1;
    writeln('����:',gn[tpc],'�ɷ�������˾�ٿ��ɶ����,��ʱͣ��һ��');
    linec:=linec+1;
  end
else
  tpc:=0;
  for i:=1 to gp do
  for j:=1 to 10 do
  ksd[i,j]:=0;
  if(day<=kn)then
   for i:=1 to gp do
  begin
    kso[i,day]:=cc[i,1];
    kss[i,day]:=cc[i,2];
    ksh[i,day]:=cc[i,7];
    ksl[i,day]:=cc[i,8];//cc[i,8];
  end
 else
  begin
   for i:=0 to gp do
    begin
    for j:=1 to kn-1 do
    begin
      kso[i,j]:=kso[i,j+1];
      kss[i,j]:=kss[i,j+1];
      ksh[i,j]:=ksh[i,j+1];
      ksl[i,j]:=ksl[i,j+1];
    end;
    kso[i,kn]:=cc[i,1];
    kss[i,kn]:=cc[i,2];
    ksh[i,kn]:=cc[i,7];
    ksl[i,kn]:=cc[i,8];
    end;
  end;
  for i:=1 to gp do
  begin
    kso[0,day]:=kso[0,day]+kso[i,day];
    kss[0,day]:=kss[0,day]+kss[i,day];
    ksh[0,day]:=ksh[0,day]+ksh[i,day];
    ksl[0,day]:=ksl[0,day]+ksl[i,day];
  end;
  kso[0,day]:=kso[0,day]/gp;
  kss[0,day]:=kss[0,day]/gp;
  ksh[0,day]:=ksh[0,day]/gp;
  ksl[0,day]:=ksl[0,day]/gp;
  hour:=1;
for i:=1 to gp do
begin
cc[i,7]:=0;
cc[i,8]:=9999;
end;
// k xian shu ju shou ji
for i:=1 to gp do
  cc[i,1]:=cc[i,2];
cpd:=random(gp)+1;
repeat
  cps:=random(gp)+1;
until(cps<>cpd);
  cc[cpd,3]:=cc[cpd,3]+0.06;
  cc[cps,3]:=cc[cps,3]-0.06;
  writeln('���棺',gn[cpd],'�ɷ�������˾���г�ԭ��ӯ���޴�');
  writeln('���棺',gn[cps],'�ɷ�������˾��ͻ����⣬�ò���ʧ');
  linec:=linec+2;
pz:=random(5);
pd:=random(5);
if(pz=2)then
  begin
    writeln('���棺������ھ��÷����˳��ȫ������');
    linec:=linec+1;
    for i:=1 to gp do
      cc[i,3]:=cc[i,3]+0.02;
  end;
if(pd=2)then
  begin
    writeln('���棺���ھ��������ܴ죬�������������»������ɾ����»�');
    linec:=linec+1;
    for i:=1 to gp do
    begin
      cc[i,3]:=cc[i,3]-0.02;
    end;
  end;
end;
if money<=0 then
begin
linec:=linec+1;
writeln('���Ʋ���~~~~~');
readkey();
break;
end;
for i:=1 to gp do
begin
if(i<>tpc)and(hour<>1)then
begin
        cc[i,3]:=cc[i,3]+random(200)/10000-0.01;
  cc[i,2]:=cc[i,1]*(1+cc[i,3]);
end
else
if(hour=1)then
begin
  cc[i,2]:=cc[i,2]+(random(400)+1-200)/100;
  cc[i,3]:=(cc[i,2]-cc[i,1])/cc[i,1];
end
else
begin
  cc[i,3]:=cc[i,3];
  cc[i,2]:=cc[i,2];
end;
  ksd[i,hour]:=cc[i,2];
  cc[i,6]:=(cc[i,2]-cc[i,5])*cc[i,4];
  if(cc[i,7]<cc[i,2])then
    begin
      cc[i,7]:=cc[i,2];
    end;
  if(cc[i,8]>cc[i,2])and(cc[i,2]<>0)then
    begin
      cc[i,8]:=cc[i,2];
    end;
if(cc[i,3]>=0.1)then
begin
cc[i,3]:=0.1;
cc[i,2]:=cc[i,1]*1.1;
end;
if(cc[i,3]<=-0.1)then
begin
cc[i,3]:=-0.1;
cc[i,2]:=cc[i,1]*0.9;
end;
end;
for i:=1 to gp do
ksd[0,hour]:=ksd[0,hour]+ksd[i,hour];
ksd[0,hour]:=ksd[0,hour]/gp;
back:
gotoXY(5,linec+1);
write('��Ʊ����');
gotoXY(20,linec+1);
write('�ּ�');
gotoXY(35,linec+1);
write('�ǵ���(�뿪��)');
gotoXY(50,linec+1);
write('�ǵ�����');
gotoXY(65,linec+1);
write('�ֲ�');
gotoXY(80,linec+1);
write('�ֲ�(�ֽ�)');
gotoXY(95,linec+1);
write('���뵥��');
gotoXY(110,linec+1);
writeln('����ӯ��');
turnp:
if gp>page*19 then
for i:=page*19-18 to page*19 do
begin
write(gn[i]);
if(cc[i,1]>cc[i,2])then
Textcolor(GREEN);
if(cc[i,1]<cc[i,2])then
Textcolor(RED);
if(cc[i,1]=cc[i,2])then
Textcolor(WHITE);
gotoXY(20,i mod 20+linec+1);
write(cc[i,2]:2:2);
gotoXY(35,i mod 20+linec+1);
write(cc[i,3]*100:2:2,'%');
gotoXY(50,i mod 20+linec+1);
write((cc[i,2]-cc[i,1]):2:2);
gotoXY(65,i mod 20+linec+1);
write(cc[i,4]:2:2);
gotoXY(80,i mod 20+linec+1);
write((cc[i,4]*cc[i,2]):2:2);
gotoXY(95,i mod 20+linec+1);
write(cc[i,5]:2:2);
gotoXY(110,i mod 20+linec+1);
writeln(cc[i,6]:2:2);
Textcolor(WHITE);
end
else
for i:=page*19-18 to gp do
begin
write(gn[i]);
if(cc[i,1]>cc[i,2])then
Textcolor(GREEN);
if(cc[i,1]<cc[i,2])then
Textcolor(RED);
if(cc[i,1]=cc[i,2])then
Textcolor(WHITE);
gotoXY(20,i mod 20+linec+1);
write(cc[i,2]:2:2);
gotoXY(35,i mod 20+linec+1);
write(cc[i,3]*100:2:2,'%');
gotoXY(50,i mod 20+linec+1);
write((cc[i,2]-cc[i,1]):2:2);
gotoXY(65,i mod 20+linec+1);
write(cc[i,4]:2:2);
gotoXY(80,i mod 20+linec+1);
write((cc[i,4]*cc[i,2]):2:2);
gotoXY(95,i mod 20+linec+1);
write(cc[i,5]:2:2);
gotoXY(110,i mod 20+linec+1);
writeln(cc[i,6]:2:2);
Textcolor(WHITE);
end;
writeln('��',page,'ҳ      ��',(gp div 20)+1,'ҳ');
case hour of
1:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  9:30');
2:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  10:00');
3:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  10:30');
4:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  11:00');
5:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  11:30');
6:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  13:00');
7:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  13:30');
8:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  14:00');
9:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  14:30');
10:writeln('�����ֽ�:  $',money:2:2,'       �����ǵ�',day,'��  15:00');
end;
writeln('�����밴��"B",�����밴��"C",�鿴��ƱK��ͼ�밴"M",�鿴���������밴"I",�鿴���������밴"T"');
writeln('�����밴"S",�����밴"L",���ӹ����밴"E",��ҳ�밴"P"������������һʱ���밴������һ��');
ac:=readkey();
if (ac='p')then
begin
writeln('Ҫ�����ڼ�ҳ');
  readln(page);
  if(page>(gp div 20)+1) then
     begin
     writeln('û����һҳ');
     page:=1;
     readkey();
     clrscr;
     goto back;
     end;
     clrscr;
  writeln('�汾:      ������Ϸ',edition,'   ######################################');
  goto turnp;
end;
if(ac='b')then
begin
buy:clrscr;
writeln('��������֧��Ʊ(������,�˳�����"0")');
readln(bn);
if(bn>gp)or(bn<0)then
begin
writeln('û����֧��Ʊ');
readkey();
goto buy;
end
else
begin
if(bn=0)then
begin
clrscr;
goto back;
end
else
begin
cmoney:=money;
cg:=0;
repeat
cg:=cg+1;
cmoney:=cmoney-cc[bn,2];
until(cmoney<cc[bn,2]);
writeln('��Ҫ��Ĺ�Ʊ��:  ',gn[bn],'      ����ÿ�ɵ�����:  ',cc[bn,2]:2:2);
writeln('�������� ',money:2:2,'Ԫ     ��������',cg,'��    ��������ٹ�?');
readln(rg);
if(rg*cc[bn,2]>money)then
begin
writeln('���Ǯ������');
readkey();
goto buy;
end
else
if(rg<100)then
begin
writeln('��Ʊ��ͽ��׶�Ϊһ��(100��)');
readkey();
goto buy
end
else
begin
cc[bn,4]:=cc[bn,4]+rg;
money:=money-rg*cc[bn,2];
cc[bn,5]:=cc[bn,2];
writeln('��������ɷ�:  ',gn[bn],'   ',rg,'��');
readkey;
clrscr;
goto back;
end;
end;
end;
end;


if(ac='c')then
begin
sell:clrscr;
writeln('����������֧��Ʊ(������,�˳�����"0")');
readln(bn);
if(bn>gp)or(bn<0)then
begin
writeln('û����֧��Ʊ');
readkey();
goto sell;
end
else
begin
if(bn=0)then
begin
clrscr;
goto back;
end
else
  begin
  writeln('��Ҫ���Ĺ�Ʊ��:  ',gn[bn],'      ����ÿ�ɵ�����:  ',cc[bn,2]:2:2);
  writeln('�������� ',cc[bn,4]:2:2,'��    ���������ٹ�?');
  readln(rg);
if(rg>cc[bn,4])then
   begin
   writeln('��ĳֲֲ�����');
   readkey();
   goto sell;
   end
else
if(rg<100)then
begin
writeln('��Ʊ��ͽ��׶�Ϊһ��(100��)');
readkey();
goto sell;
end
else
   begin
    cc[bn,4]:=cc[bn,4]-rg;
    money:=money+rg*cc[bn,2];
    writeln('���������ɷ�:  ',gn[bn],'   ',rg,'��');
    writeln('�ܹ��ʲ��䶯:  ',cc[bn,6]:2:2);
    readkey();
    clrscr;
    goto back;
   end;
  end;
end;
end;
if(ac='m')then
begin
  writeln('����������鿴�Ĺ�Ʊ���(����������"0")');
  readln(kgpc);
  //graph chu shi hua
  writeln('��1~100�����밴1,��1~300�����밴2,��1~600�����밴3');
readln(exc);
  if (exc='1') then
  begin
  gd:=detect;
  gm:=0;
  ptd:='c:\pp\bgi';
  InitGraph(gd,gm,ptd);
  drawb:=20;
  line(10,10,10,600);
  line(10,600,1000,600);
  setcolor(yellow);
  outtextxy(0,600,'0');
  outtextxy(0,540,'10');
  outtextxy(0,480,'20');
  outtextxy(0,420,'30');
  outtextxy(0,360,'40');
  outtextxy(0,300,'50');
  outtextxy(0,240,'60');
  outtextxy(0,180,'70');
  outtextxy(0,120,'80');
  outtextxy(0,60,'90');
  outtextxy(0,0,'100');
  for i:=1 to kn do
  begin
  if kso[kgpc,i]>kss[kgpc,i] then
  begin
  setcolor(11);
    rectangle(drawb,trunc(600-kso[kgpc,i]*6),drawb+10,trunc(600-kss[kgpc,i]*6));
    line(drawb+5,trunc(600-ksh[kgpc,i]*6),drawb+5,trunc(600-ksl[kgpc,i]*6));
    end
  else
  begin
  setcolor(red);

    rectangle(drawb,trunc(600-kso[kgpc,i]*6),drawb+10,trunc(600-kss[kgpc,i]*6));
    line(drawb+5,trunc(600-ksh[kgpc,i]*6),drawb+5,trunc(600-ksl[kgpc,i]*6));
  end;
    drawb:=drawb+15;
  end;
  setcolor(yellow);
  outtextxy(10,630,gn[kgpc]);
  outtextxy(10,660,'����      �ǵ���(�뿪��)  �����ǵ�    �ֲ�    �ֲ��ֽ�    ���뵥��    ����ӯ��');

  str(cc[kgpc,2]:0:2,nullstring);
  outstring:=nullstring+'      ';
  str(cc[kgpc,3]*100:0:2,nullstring);
  outstring:=outstring+nullstring+'%         ';
  str((cc[kgpc,2]-cc[kgpc,1]):0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str(cc[kgpc,4]:0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str((cc[kgpc,4]*cc[kgpc,2]):0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,5]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,6]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  outtextxy(10,690,outstring);
   readln;
   closegraph;
clrscr;
goto back;
  end;
  if(exc='2')then
    begin
  gd:=detect;
  gm:=0;
  ptd:='c:\pp:\bgi';
  InitGraph(gd,gm,ptd);
  drawb:=20;
  line(10,10,10,600);
  line(10,600,1000,600);
  setcolor(yellow);
  outtextxy(0,600,'0');
  outtextxy(0,540,'30');
  outtextxy(0,480,'60');
  outtextxy(0,420,'90');
  outtextxy(0,360,'120');
  outtextxy(0,300,'150');
  outtextxy(0,240,'180');
  outtextxy(0,180,'210');
  outtextxy(0,120,'240');
  outtextxy(0,60,'270');
  outtextxy(0,0,'300');
  for i:=1 to kn do
  begin
  if kso[kgpc,i]>kss[kgpc,i] then
  begin
  setcolor(11);
    rectangle(drawb,trunc(600-kso[kgpc,i]*2),drawb+10,trunc(600-kss[kgpc,i]*2));
    line(drawb+5,trunc(600-ksh[kgpc,i]*2),drawb+5,trunc(600-ksl[kgpc,i]*2));
    end
  else
  begin
  setcolor(red);

    rectangle(drawb,trunc(600-kso[kgpc,i]*2),drawb+10,trunc(600-kss[kgpc,i]*2));
    line(drawb+5,trunc(600-ksh[kgpc,i]*2),drawb+5,trunc(600-ksl[kgpc,i]*2));
  end;
    drawb:=drawb+15;
  end;
  setcolor(yellow);
  outtextxy(10,630,gn[kgpc]);
  outtextxy(10,660,'����      �ǵ���(�뿪��)  �����ǵ�    �ֲ�    �ֲ��ֽ�    ���뵥��    ����ӯ��');

  str(cc[kgpc,2]:0:2,nullstring);
  outstring:=nullstring+'      ';
  str(cc[kgpc,3]*100:0:2,nullstring);
  outstring:=outstring+nullstring+'%         ';
  str((cc[kgpc,2]-cc[kgpc,1]):0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str(cc[kgpc,4]:0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str((cc[kgpc,4]*cc[kgpc,2]):0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,5]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,6]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  outtextxy(10,690,outstring);
   readln;
   closegraph;
clrscr;
goto back;
end;
if(exc='3')then
 begin
  gd:=detect;
  gm:=0;
  ptd:='c:\pp:\bgi';
  InitGraph(gd,gm,ptd);
  drawb:=20;
  line(10,10,10,600);
  line(10,600,1000,600);
  setcolor(yellow);
  outtextxy(0,600,'0');
  outtextxy(0,540,'60');
  outtextxy(0,480,'120');
  outtextxy(0,420,'180');
  outtextxy(0,360,'240');
  outtextxy(0,300,'300');
  outtextxy(0,240,'360');
  outtextxy(0,180,'420');
  outtextxy(0,120,'480');
  outtextxy(0,60,'540');
  outtextxy(0,0,'600');
  for i:=1 to kn do
  begin
  if kso[kgpc,i]>kss[kgpc,i] then
  begin
  setcolor(11);
    rectangle(drawb,trunc(600-kso[kgpc,i]),drawb+10,trunc(600-kss[kgpc,i]));
    line(drawb+5,trunc(600-ksh[kgpc,i]),drawb+5,trunc(600-ksl[kgpc,i]));
    end
  else
  begin
  setcolor(red);

    rectangle(drawb,trunc(600-kso[kgpc,i]),drawb+10,trunc(600-kss[kgpc,i]));
    line(drawb+5,trunc(600-ksh[kgpc,i]),drawb+5,trunc(600-ksl[kgpc,i]));
  end;
    drawb:=drawb+15;
  end;
  setcolor(yellow);
  outtextxy(10,630,gn[kgpc]);
  outtextxy(10,660,'����      �ǵ���(�뿪��)  �����ǵ�    �ֲ�    �ֲ��ֽ�    ���뵥��    ����ӯ��');

  str(cc[kgpc,2]:0:2,nullstring);
  outstring:=nullstring+'      ';
  str(cc[kgpc,3]*100:0:2,nullstring);
  outstring:=outstring+nullstring+'%         ';
  str((cc[kgpc,2]-cc[kgpc,1]):0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str(cc[kgpc,4]:0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str((cc[kgpc,4]*cc[kgpc,2]):0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,5]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,6]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  outtextxy(10,690,outstring);
   readln;
   closegraph;
clrscr;
goto back;
  end;
end;
  if(ac='s')then
  begin
    assign(save,'save.gpbcsavedata');
    rewrite(save);
    writeln(save,gp);
     for i:=0 to gp do
      for j:=1 to 84 do
      writeln(save,kso[i,j]);
      for i:=0 to gp do
      for j:=1 to 84 do
      writeln(save,kss[i,j]);
      for i:=0 to gp do
      for j:=1 to 84 do
      writeln(save,ksh[i,j]);
      for i:=0 to gp do
      for j:=1 to 84 do
      writeln(save,ksl[i,j]);
      for i:=1 to gp do
      for j:=1 to 8 do
      writeln(save,cc[i,j]);
      for i:=0 to gp do
      for j:=1 to 10 do
      writeln(save,ksd[i,j]);
      for i:=1 to gp do
      writeln(save,gn[i]);
      writeln(save,cjc);
      for i:=1 to cjc do
      writeln(save,cj[i]);
      writeln(save,money);
      writeln(save,day);
      writeln(save,hour);
      writeln(save,gp);
      writeln(save,gmoney);
      writeln(save,gday);
      writeln(save,bmoney);
    close(save);
    clrscr;
    writeln('����ɹ�');
    readkey();
    clrscr;
    goto back;
end;
if(ac='l')then
  begin
    loading:assign(load,'save.gpbcsavedata');
    reset(load);
    readln(load,gp);
    for i:=0 to gp do
      for j:=1 to 84 do
      readln(load,kso[i,j]);
      for i:=0 to gp do
      for j:=1 to 84 do
      readln(load,kss[i,j]);
      for i:=0 to gp do
      for j:=1 to 84 do
      readln(load,ksh[i,j]);
      for i:=0 to gp do
      for j:=1 to 84 do
      readln(load,ksl[i,j]);
      for i:=1 to gp do
      for j:=1 to 8 do
      readln(load,cc[i,j]);
      for i:=0 to gp do
      for j:=1 to 10 do
      readln(load,ksd[i,j]);
      for i:=1 to gp do
      readln(load,gn[i]);
      readln(load,cjc);
      for i:=1 to cjc do
      readln(load,cj[i]);
      readln(load,money);
      readln(load,day);
      readln(load,hour);
      readln(load,gp);
      readln(load,gmoney);
      readln(load,gday);
      readln(load,bmoney);
    close(load);
    clrscr;
    writeln('�����ɹ�');
    readkey();
    clrscr;
    goto back;
  end;

  if(ac='e')then
  begin
  clrscr;
  writeln('���ӹ���    ������Ų���');
  writeln('1���Զ����Ʊ');
  writeln('2���򲹶�');
  writeln('3�����н������');
  writeln('4�������Ʊ');
  writeln('�������������˻������');
  readln(exc);
    if(exc='939499625')and(sfqo=0) then
    begin
    clrscr;
    writeln('������úڰ�...');
    readkey();
    writeln('��..��ô�ж���������..');
    readkey();
    writeln('��ȥ������..');
    readkey();
    writeln('��!!!!!!!!!!!!!!!!!!!!!');
    readkey();
    writeln('��¥����һ��˽��Ǯ!!!!');
    readkey();
    clrscr;
    writeln('�㷢����¥����˽��Ǯ10000Ԫ!');
    writeln('���ѻ�óɾ�:������');
    money:=money+10000;
    cj[6]:=1;
    cjn[6]:='������:����¥����˽��Ǯ';
    sfqo:=1;
    readkey();
    clrscr;
    goto back;
    end;
    if(exc='1')then
    begin
    clrscr;
      gp:=gp+1;
      str(gp,gps);
      writeln('���ڿ�ʼ�Զ����Ʊ(���1000��),�������Ʊ����');
      readln(gn[gp]);
      gn[gp]:=gn[gp]+'    #'+gps+'  ';
      writeln('�������Ʊ���̼�');
      readln(cc[gp,1]);
      writeln('�Զ����Ʊ:  ',gn[gp],'  �ɹ�');
      readkey;
      clrscr;
      goto back;
    end;
    if(exc='2')then
    begin
      writeln('�����벹������');
      readln(fillname);
      assign(load,fillname);
      reset(load);
      readln(load,packname);
      readln(load,packnum);
      for i:=1 to packnum do
      begin
      gp:=gp+1;
      readln(load,gn[gp]);
      str(gp,gps);
      gn[gp]:=gn[gp]+'    #'+gps+'  ';
      readln(load,cc[gp,1]);
      end;
      writeln('�Ѱ�װ    ',packname);
      writeln('�����������');
      readkey();
      close(load);
      readkey;
      clrscr;
    goto back;
    end;
    if(exc='3')then
    begin
      writeln('��������Ǯ?');
      readln(bmoney);
      writeln('����輸��?');
      readln(bday);
      gday:=day;
      gday:=bday+gday;
      money:=money+bmoney;
      writeln('��������Ϊ1%һ��');
            gmoney:=bmoney+bmoney*0.01*bday;
      writeln('���ǽ��ڵ�',gday,'���Զ��۳�����Ϣ��',gmoney:0:2,'Ԫ');
      readkey;
      clrscr;
      goto back;
    end;
    if(exc='4')then
    if(money>100)then
    begin
      money:=money-100;
      writeln('��������Ҫ��ѡ������ѡ?');
      writeln('����1��ѡ,����������ѡ');
      readln(cho);
      if(cho='1')then
      begin
        for i:=1 to 6 do
        begin
        tu2:lts[i]:=random(33)+1;
        if i>1 then
        for j:=i-1 downto 1 do
        if lts[i]=lts[j] then
        goto tu2;
        end;
        lts[7]:=random(16)+1;
      writeln('���Ļ�ѡ����Ϊ:',lts[1],' ',lts[2],' ',lts[3],' ',lts[4],' ',lts[5],' ',lts[6],' ',lts[7]);
      writeln('ÿһ��ֻ����һ�Ų�Ʊ,������´���ͬһ�칺���Ʊ,���Ų�Ʊ�����ݽ�����');
      writeln('��������˻������');
      readkey();
      clrscr;
      goto back;
      end
      else
      begin
       tu3:writeln('��������������������(0~33),�Կո�ֿ�');
       readln(lts[1],lts[2],lts[3],lts[4],lts[5],lts[6]);
       for i:=1 to 6 do
        begin
        if i>1 then
        for j:=i-1 downto 1 do
        if lts[i]=lts[j] then
        begin
        writeln('����������,��Ʊ�ɲ���ѡ����һ���ĺ�Ŷ!');
        readkey;
        goto tu3;
        end;
        end;
       writeln('�������������');
       readln(lts[7]);
       writeln('��ѡ�ɹ�,�����������');
       writeln('ÿһ��ֻ����һ�Ų�Ʊ,������´���ͬһ�칺���Ʊ,���Ų�Ʊ�����ݽ�����');
       readkey();
       clrscr;
       goto back;
      end;
    end
    else
    begin
    writeln('����Ǯ������');
    readkey;
    clrscr;
    goto back;
    end;
    readkey;
    clrscr;
    goto back;
  end;
  if ac='i' then
  begin
    clrscr;
    writeln('�˻�:  ',pname);
    writeln('�ֽ�:  ',money:2:2);
    writeln('ӯ��:  ',money-1000000:2:2);
    writeln('����:  ',day,'��',hour,'��ʱ');
    if money<1000000 then
    writeln('�ȼ��� ����');
    if (money>=1000000)and(money<1010000)then
    writeln('�ȼ��� ��̳����');
    if (money>=1010000)and(money<1050000)then
    writeln('�ȼ��� רҵ��ʿ');
    if (money>=1050000)and(money<1200000)then
    writeln('�ȼ��� �������');
    if (money>=1300000)and(money<1500000)then
    writeln('�ȼ��� ���ִ�ʦ');
    if (money>=1500000)and(money<2000000)then
    writeln('�ȼ��� ���̸���');
    if (money>=2000000)and(money<2800000)then
    writeln('�ȼ��� �ɳ���Ӣ');
    if (money>=2800000)and(money<3600000)then
    writeln('�ȼ��� ���о�ͷ');
    if (money>=3600000)and(money<5000000)then
    writeln('�ȼ��� ����ת��');
    if (money>=5000000)and(money<7500000)then
    writeln('�ȼ��� ��������');
    if (money>=7500000)and(money<10000000)then
    writeln('�ȼ��� �������');
    if (money>=10000000)and(money<15000000)then
    writeln('�ȼ��� ���ഫ˵');
    if (money>=15000000)and(money<20000000)then
    writeln('�ȼ��� ���ഫ˵II��');
    if (money>=20000000)and(money<25000000)then
    writeln('�ȼ��� ���ഫ˵III��');
    if (money>=25000000)and(money<32000000)then
    writeln('�ȼ��� ���ഫ˵IV��');
    if (money>=32000000)and(money<40000000)then
    writeln('�ȼ��� ���ഫ˵V��');
    if (money>=40000000)and(money<50000000)then
    writeln('�ȼ��� ���ഫ˵VI��');
    if (money>=50000000)and(money<64000000)then
    writeln('�ȼ��� ���ഫ˵VII��');
    if (money>=64000000)and(money<80000000)then
    writeln('�ȼ��� ���ഫ˵VIII��');
    if (money>=80000000)then
    writeln('�ȼ��� ���ഫ˵IX��');
    write('�ɾ���');TextColor(red);write('δ���     ');
    TextColor(Green);writeln('�ѻ��');
    for i:=1 to cjc do
    begin
      if cj[i]=1 then
      textcolor(Green)
      else
      textcolor(red);
      writeln(cjn[i]);
    end;
    textcolor(white);
    writeln('����������������');
    if(gday<>0)then
    writeln('�������д���',bmoney:0:2,'���ڵ�',gday,'�쳥����Ϣ��',gmoney:0:2,'Ԫ,�����ذ��չ�������');
    readkey();
    clrscr;
    goto back;
  end;
  if ac='t' then
   begin
  writeln('����������鿴�Ĺ�Ʊ���(����������"0")');
  readln(kgpc);
  writeln('��1~100�����밴1,��1~300�����밴2,��1~600�����밴3');
  readln(exc);
  //graph chu shi hua
  if exc='1' then
  begin
  gd:=detect;
  gm:=0;
  ptd:='c:\pp:\bgi';
  InitGraph(gd,gm,ptd);
  drawb:=20;
  line(10,10,10,600);
  line(10,600,1000,600);
  setcolor(yellow);
  outtextxy(0,600,'0');
  outtextxy(0,540,'10');
  outtextxy(0,480,'20');
  outtextxy(0,420,'30');
  outtextxy(0,360,'40');
  outtextxy(0,300,'50');
  outtextxy(0,240,'60');
  outtextxy(0,180,'70');
  outtextxy(0,120,'80');
  outtextxy(0,60,'90');
  outtextxy(0,0,'100');
  for i:=1 to hour-1 do
  begin
  if ksd[kgpc,i]>ksd[kgpc,i+1] then
  begin
  setcolor(11);
    rectangle(drawb,trunc(600-ksd[kgpc,i]*6),drawb+20,trunc(600-ksd[kgpc,i+1]*6));
    end
  else
  begin
  setcolor(red);
    rectangle(drawb,trunc(600-ksd[kgpc,i+1]*6),drawb+20,trunc(600-ksd[kgpc,i]*6));
  end;
    drawb:=drawb+35;
  end;
  setcolor(yellow);
  outtextxy(10,630,gn[kgpc]);
  outtextxy(10,660,'����      �ǵ���(�뿪��)  �����ǵ�    �ֲ�    �ֲ��ֽ�    ���뵥��    ����ӯ��');
  str(cc[kgpc,2]:0:2,nullstring);
  outstring:=nullstring+'      ';
  str(cc[kgpc,3]*100:0:2,nullstring);
  outstring:=outstring+nullstring+'%         ';
  str((cc[kgpc,2]-cc[kgpc,1]):0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str(cc[kgpc,4]:0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str((cc[kgpc,4]*cc[kgpc,2]):0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,5]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,6]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  outtextxy(10,690,outstring);
  readln;
  closegraph;
clrscr;
goto back;
end;
  if exc='2' then
  begin
  gd:=detect;
  gm:=0;
  ptd:='c:\pp:\bgi';
  InitGraph(gd,gm,ptd);
  drawb:=20;
  line(10,10,10,600);
  line(10,600,1000,600);
  setcolor(yellow);
  outtextxy(0,600,'0');
  outtextxy(0,540,'30');
  outtextxy(0,480,'60');
  outtextxy(0,420,'90');
  outtextxy(0,360,'120');
  outtextxy(0,300,'150');
  outtextxy(0,240,'180');
  outtextxy(0,180,'210');
  outtextxy(0,120,'240');
  outtextxy(0,60,'270');
  outtextxy(0,0,'300');
  for i:=1 to hour-1 do
  begin
  if ksd[kgpc,i]>ksd[kgpc,i+1] then
  begin
  setcolor(11);
    rectangle(drawb,trunc(600-ksd[kgpc,i]*2),drawb+20,trunc(600-ksd[kgpc,i+1]*2));
    end
  else
  begin
  setcolor(red);
    rectangle(drawb,trunc(600-ksd[kgpc,i+1]*2),drawb+20,trunc(600-ksd[kgpc,i]*2));
  end;
    drawb:=drawb+35;
  end;
  setcolor(yellow);
  outtextxy(10,630,gn[kgpc]);
  outtextxy(10,660,'����      �ǵ���(�뿪��)  �����ǵ�    �ֲ�    �ֲ��ֽ�    ���뵥��    ����ӯ��');
  str(cc[kgpc,2]:0:2,nullstring);
  outstring:=nullstring+'      ';
  str(cc[kgpc,3]*100:0:2,nullstring);
  outstring:=outstring+nullstring+'%         ';
  str((cc[kgpc,2]-cc[kgpc,1]):0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str(cc[kgpc,4]:0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str((cc[kgpc,4]*cc[kgpc,2]):0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,5]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,6]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  outtextxy(10,690,outstring);
  readln;
  closegraph;
clrscr;
goto back;
end;
  if exc='3' then
  begin
  gd:=detect;
  gm:=0;
  ptd:='c:\pp:\bgi';
  InitGraph(gd,gm,ptd);
  drawb:=20;
  line(10,10,10,600);
  line(10,600,1000,600);
  setcolor(yellow);
  outtextxy(0,600,'0');
  outtextxy(0,540,'60');
  outtextxy(0,480,'120');
  outtextxy(0,420,'180');
  outtextxy(0,360,'240');
  outtextxy(0,300,'300');
  outtextxy(0,240,'360');
  outtextxy(0,180,'420');
  outtextxy(0,120,'480');
  outtextxy(0,60,'540');
  outtextxy(0,0,'600');
  for i:=1 to hour-1 do
  begin
  if ksd[kgpc,i]>ksd[kgpc,i+1] then
  begin
  setcolor(11);
    rectangle(drawb,trunc(600-ksd[kgpc,i]),drawb+20,trunc(600-ksd[kgpc,i+1]));
    end
  else
  begin
  setcolor(red);
    rectangle(drawb,trunc(600-ksd[kgpc,i+1]),drawb+20,trunc(600-ksd[kgpc,i]));
  end;
    drawb:=drawb+35;
  end;
  setcolor(yellow);
  outtextxy(10,630,gn[kgpc]);
  outtextxy(10,660,'����      �ǵ���(�뿪��)  �����ǵ�    �ֲ�    �ֲ��ֽ�    ���뵥��    ����ӯ��');
  str(cc[kgpc,2]:0:2,nullstring);
  outstring:=nullstring+'      ';
  str(cc[kgpc,3]*100:0:2,nullstring);
  outstring:=outstring+nullstring+'%         ';
  str((cc[kgpc,2]-cc[kgpc,1]):0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str(cc[kgpc,4]:0:2,nullstring);
  outstring:=outstring+nullstring+'        ';
  str((cc[kgpc,4]*cc[kgpc,2]):0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,5]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  str(cc[kgpc,6]:0:2,nullstring);
  outstring:=outstring+nullstring+'      ';
  outtextxy(10,690,outstring);
  readln;
  closegraph;
clrscr;
goto back;
end;
end;
  writeln('��ȴ�');
  delay(500);
until false;
end.
