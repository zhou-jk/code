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
gn[1]:='航天科技     #1  ';
gn[2]:='江苏有线     #2  ';
gn[3]:='隧道股份     #3  ';
gn[4]:='红星橡胶     #4  ';
gn[5]:='振芯科技     #5  ';
gn[6]:='十陵墓园     #6  ';
gn[7]:='中国石油     #7  ';
gn[8]:='MOJANG       #8  ';
gn[9]:='恒通股份     #9  ';
gn[10]:='阿里巴巴    #10  ';
gn[11]:='立思辰      #11  ';
gn[12]:='峨眉山A     #12  ';
gn[13]:='智慧能源    #13  ';
gn[14]:='天银机电    #14  ';
gn[15]:='亿阳信通    #15  ';
gn[16]:='东凌粮油    #16  ';
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
cjn[1]:='幸运儿:买彩票时意外中奖一次';
cjn[2]:='改档大师:将存档金钱修改至2147483647';
cjn[3]:='无动于衷:在股市前三天(0,1,2)持股均为0';
cjn[4]:='命悬一线:金钱小于10';
cjn[5]:='补丁收藏者:打满至今为止的全部补丁';
cjn[6]:='?????????????????????????????';
page:=1;
clrscr;
writeln('亲爱的股民,欢迎使用同花顺');
readkey();
writeln('如果已经有存档账号请按"L",或者按其他键注册');
ac:=readkey;
if(ac='l')then
  goto loading;
writeln('请问您的名字是?');
write('输入名字:');
readln(pname);
writeln('注册成功,您的银行卡上还有现金100万');
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
writeln('版本:      炒股游戏',edition,'   ######################################');
linec:=linec+1;
hour:=hour+1;
if gp>=220 then
begin
cj[5]:=1;
writeln('您已获得成就:补丁收藏者');
linec:=linec+1;
end;
if(money<10)then
begin
  cj[4]:=1;
  writeln('您已获得成就:命悬一线');
  linec:=linec+1;
end;
if(money=2147483647)then
begin
cj[2]:=1;
writeln('您已获得成就:改档大师');
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
writeln('您已获得成就:无动于衷');
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
  writeln('公告:彩票的本期开奖号码为    ',ltg[1],' ',ltg[2],' ',ltg[3],' ',ltg[4],' ',ltg[5],' ',ltg[6],' ',ltg[7]);
  linec:=linec+1;
  for i:=1 to 7 do
  if lts[i]<>0 then
  ltgn:=ltgn+1;
  if ltgn=0 then
  writeln('您没有买本期彩票')
 else
  writeln('您的号码为                   ',lts[1],' ',lts[2],' ',lts[3],' ',lts[4],' ',lts[5],' ',lts[6],' ',lts[7]);
  linec:=linec+1;
if(ltgn<=2)and(ltgb=0)and(ltgn<>0)then
writeln('你什么奖也没中,别灰心')
else
if(ltgn<=2)and(ltgb=1)then
begin
  writeln('恭喜你中了6等奖');
  writeln('奖金为50元');
  cj[1]:=1;
writeln('您已获得成就:幸运儿');
  money:=money+50;
end;
if(ltgn=3)and(ltgb=1)then
begin
  writeln('恭喜你中了5等奖');
  writeln('奖金为100元');
  cj[1]:=1;
writeln('您已获得成就:幸运儿');
  money:=money+100;
end;
if(ltgn=4)and(ltgb=0)then
begin
  writeln('恭喜你中了5等奖');
  writeln('奖金为100元');
  cj[1]:=1;
writeln('您已获得成就:幸运儿');
  money:=money+100;
end;
if(ltgn=4)and(ltgb=1)then
begin
  writeln('恭喜你中了4等奖');
  writeln('奖金为2000元');
  cj[1]:=1;
writeln('您已获得成就:幸运儿');
  money:=money+2000;
end;
if(ltgn=5)and(ltgb=0)then
begin
  writeln('恭喜你中了4等奖');
  writeln('奖金为2000元');
  cj[1]:=1;
writeln('您已获得成就:幸运儿');
  money:=money+1000;
end;
if(ltgn=5)and(ltgb=1)then
begin
  writeln('恭喜你中了3等奖');
  writeln('奖金为30000元');
  cj[1]:=1;
writeln('您已获得成就:幸运儿');
  money:=money+3000;
end;
if(ltgn=6)and(ltgb=0)then
begin
  writeln('恭喜你中了2等奖');
  writeln('奖金为1250000元');
  cj[1]:=1;
writeln('您已获得成就:幸运儿');
  money:=money+1250000;
end;
if(ltgn=6)and(ltgb=1)then
begin
  writeln('恭喜你中了头奖!!!!!!!!');
  writeln('奖金为5000000元');
  cj[1]:=1;
writeln('您已获得成就:幸运儿');
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
    writeln('公告:',gn[tpc],'股份所属公司召开股东大会,暂时停牌一天');
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
  writeln('公告：',gn[cpd],'股份所属公司因市场原因，盈利巨大');
  writeln('公告：',gn[cps],'股份所属公司因客户问题，得不偿失');
  linec:=linec+2;
pz:=random(5);
pd:=random(5);
if(pz=2)then
  begin
    writeln('公告：最近国内经济风调雨顺，全盘上涨');
    linec:=linec+1;
    for i:=1 to gp do
      cc[i,3]:=cc[i,3]+0.02;
  end;
if(pd=2)then
  begin
    writeln('公告：国内经济连连受挫，各方面产量大大下滑，各股均有下滑');
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
writeln('您破产啦~~~~~');
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
write('股票名称');
gotoXY(20,linec+1);
write('现价');
gotoXY(35,linec+1);
write('涨跌幅(与开盘)');
gotoXY(50,linec+1);
write('涨跌单价');
gotoXY(65,linec+1);
write('持仓');
gotoXY(80,linec+1);
write('持仓(现金)');
gotoXY(95,linec+1);
write('买入单价');
gotoXY(110,linec+1);
writeln('单股盈亏');
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
writeln('第',page,'页      共',(gp div 20)+1,'页');
case hour of
1:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  9:30');
2:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  10:00');
3:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  10:30');
4:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  11:00');
5:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  11:30');
6:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  13:00');
7:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  13:30');
8:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  14:00');
9:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  14:30');
10:writeln('您的现金:  $',money:2:2,'       现在是第',day,'天  15:00');
end;
writeln('买入请按下"B",卖出请按下"C",查看股票K线图请按"M",查看个人资料请按"I",查看今日走势请按"T"');
writeln('保存请按"S",读档请按"L",附加功能请按"E",翻页请按"P"不操作跳到下一时间请按其他键一次');
ac:=readkey();
if (ac='p')then
begin
writeln('要跳到第几页');
  readln(page);
  if(page>(gp div 20)+1) then
     begin
     writeln('没有这一页');
     page:=1;
     readkey();
     clrscr;
     goto back;
     end;
     clrscr;
  writeln('版本:      炒股游戏',edition,'   ######################################');
  goto turnp;
end;
if(ac='b')then
begin
buy:clrscr;
writeln('您想买哪支股票(输入编号,退出请输"0")');
readln(bn);
if(bn>gp)or(bn<0)then
begin
writeln('没有这支股票');
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
writeln('您要买的股票是:  ',gn[bn],'      现在每股单价是:  ',cc[bn,2]:2:2);
writeln('您现在有 ',money:2:2,'元     最多可以买',cg,'股    您想买多少股?');
readln(rg);
if(rg*cc[bn,2]>money)then
begin
writeln('你的钱不够诶');
readkey();
goto buy;
end
else
if(rg<100)then
begin
writeln('股票最低交易额为一手(100股)');
readkey();
goto buy
end
else
begin
cc[bn,4]:=cc[bn,4]+rg;
money:=money-rg*cc[bn,2];
cc[bn,5]:=cc[bn,2];
writeln('您已买入股份:  ',gn[bn],'   ',rg,'股');
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
writeln('您想卖出哪支股票(输入编号,退出请输"0")');
readln(bn);
if(bn>gp)or(bn<0)then
begin
writeln('没有这支股票');
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
  writeln('您要卖的股票是:  ',gn[bn],'      现在每股单价是:  ',cc[bn,2]:2:2);
  writeln('您现在有 ',cc[bn,4]:2:2,'股    您想卖多少股?');
  readln(rg);
if(rg>cc[bn,4])then
   begin
   writeln('你的持仓不够诶');
   readkey();
   goto sell;
   end
else
if(rg<100)then
begin
writeln('股票最低交易额为一手(100股)');
readkey();
goto sell;
end
else
   begin
    cc[bn,4]:=cc[bn,4]-rg;
    money:=money+rg*cc[bn,2];
    writeln('您已卖出股份:  ',gn[bn],'   ',rg,'股');
    writeln('总共资产变动:  ',cc[bn,6]:2:2);
    readkey();
    clrscr;
    goto back;
   end;
  end;
end;
end;
if(ac='m')then
begin
  writeln('请输入您想查看的股票编号(大盘请输入"0")');
  readln(kgpc);
  //graph chu shi hua
  writeln('看1~100缩略请按1,看1~300缩略请按2,看1~600缩略请按3');
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
  outtextxy(10,660,'单价      涨跌幅(与开盘)  单价涨跌    持仓    持仓现金    买入单价    单股盈亏');

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
  outtextxy(10,660,'单价      涨跌幅(与开盘)  单价涨跌    持仓    持仓现金    买入单价    单股盈亏');

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
  outtextxy(10,660,'单价      涨跌幅(与开盘)  单价涨跌    持仓    持仓现金    买入单价    单股盈亏');

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
    writeln('保存成功');
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
    writeln('读档成功');
    readkey();
    clrscr;
    goto back;
  end;

  if(ac='e')then
  begin
  clrscr;
  writeln('附加功能    输入序号操作');
  writeln('1、自定义股票');
  writeln('2、打补丁');
  writeln('3、银行借贷还贷');
  writeln('4、购买彩票');
  writeln('输入其他数字退回主面板');
  readln(exc);
    if(exc='939499625')and(sfqo=0) then
    begin
    clrscr;
    writeln('唔，这里好黑啊...');
    readkey();
    writeln('恩..怎么有东西在闪光..');
    readkey();
    writeln('过去看看吧..');
    readkey();
    writeln('哇!!!!!!!!!!!!!!!!!!!!!');
    readkey();
    writeln('是楼主的一堆私房钱!!!!');
    readkey();
    clrscr;
    writeln('你发现了楼主的私房钱10000元!');
    writeln('您已获得成就:发现者');
    money:=money+10000;
    cj[6]:=1;
    cjn[6]:='发现者:发现楼主的私房钱';
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
      writeln('现在开始自定义股票(最多1000个),请输入股票名称');
      readln(gn[gp]);
      gn[gp]:=gn[gp]+'    #'+gps+'  ';
      writeln('请输入股票开盘价');
      readln(cc[gp,1]);
      writeln('自定义股票:  ',gn[gp],'  成功');
      readkey;
      clrscr;
      goto back;
    end;
    if(exc='2')then
    begin
      writeln('请输入补丁名称');
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
      writeln('已安装    ',packname);
      writeln('按任意键继续');
      readkey();
      close(load);
      readkey;
      clrscr;
    goto back;
    end;
    if(exc='3')then
    begin
      writeln('您想借多少钱?');
      readln(bmoney);
      writeln('您想借几天?');
      readln(bday);
      gday:=day;
      gday:=bday+gday;
      money:=money+bmoney;
      writeln('银行利率为1%一天');
            gmoney:=bmoney+bmoney*0.01*bday;
      writeln('我们将在第',gday,'天自动扣除您本息共',gmoney:0:2,'元');
      readkey;
      clrscr;
      goto back;
    end;
    if(exc='4')then
    if(money>100)then
    begin
      money:=money-100;
      writeln('请问您是要机选还是自选?');
      writeln('输入1机选,输入其他自选');
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
      writeln('您的机选号码为:',lts[1],' ',lts[2],' ',lts[3],' ',lts[4],' ',lts[5],' ',lts[6],' ',lts[7]);
      writeln('每一天只能买一张彩票,如果您下次在同一天购买彩票,这张彩票的数据将作废');
      writeln('按任意键退回主面板');
      readkey();
      clrscr;
      goto back;
      end
      else
      begin
       tu3:writeln('请依次输入红球号码六个(0~33),以空格分开');
       readln(lts[1],lts[2],lts[3],lts[4],lts[5],lts[6]);
       for i:=1 to 6 do
        begin
        if i>1 then
        for j:=i-1 downto 1 do
        if lts[i]=lts[j] then
        begin
        writeln('请重新输入,彩票可不能选两个一样的号哦!');
        readkey;
        goto tu3;
        end;
        end;
       writeln('请输入蓝球号码');
       readln(lts[7]);
       writeln('自选成功,按任意键返回');
       writeln('每一天只能买一张彩票,如果您下次在同一天购买彩票,这张彩票的数据将作废');
       readkey();
       clrscr;
       goto back;
      end;
    end
    else
    begin
    writeln('您的钱都不够');
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
    writeln('账户:  ',pname);
    writeln('现金:  ',money:2:2);
    writeln('盈亏:  ',money-1000000:2:2);
    writeln('股龄:  ',day,'天',hour,'半时');
    if money<1000000 then
    writeln('等级： 菜鸟');
    if (money>=1000000)and(money<1010000)then
    writeln('等级： 股坛新星');
    if (money>=1010000)and(money<1050000)then
    writeln('等级： 专业人士');
    if (money>=1050000)and(money<1200000)then
    writeln('等级： 资深股手');
    if (money>=1300000)and(money<1500000)then
    writeln('等级： 股林大师');
    if (money>=1500000)and(money<2000000)then
    writeln('等级： 操盘高手');
    if (money>=2000000)and(money<2800000)then
    writeln('等级： 股场精英');
    if (money>=2800000)and(money<3600000)then
    writeln('等级： 股市巨头');
    if (money>=3600000)and(money<5000000)then
    writeln('等级： 股神转世');
    if (money>=5000000)and(money<7500000)then
    writeln('等级： 股神真人');
    if (money>=7500000)and(money<10000000)then
    writeln('等级： 超神存在');
    if (money>=10000000)and(money<15000000)then
    writeln('等级： 不朽传说');
    if (money>=15000000)and(money<20000000)then
    writeln('等级： 不朽传说II段');
    if (money>=20000000)and(money<25000000)then
    writeln('等级： 不朽传说III段');
    if (money>=25000000)and(money<32000000)then
    writeln('等级： 不朽传说IV段');
    if (money>=32000000)and(money<40000000)then
    writeln('等级： 不朽传说V段');
    if (money>=40000000)and(money<50000000)then
    writeln('等级： 不朽传说VI段');
    if (money>=50000000)and(money<64000000)then
    writeln('等级： 不朽传说VII段');
    if (money>=64000000)and(money<80000000)then
    writeln('等级： 不朽传说VIII段');
    if (money>=80000000)then
    writeln('等级： 不朽传说IX段');
    write('成就栏');TextColor(red);write('未获得     ');
    TextColor(Green);writeln('已获得');
    for i:=1 to cjc do
    begin
      if cj[i]=1 then
      textcolor(Green)
      else
      textcolor(red);
      writeln(cjn[i]);
    end;
    textcolor(white);
    writeln('按任意键返回主面板');
    if(gday<>0)then
    writeln('您与银行贷款',bmoney:0:2,'将在第',gday,'天偿还本息共',gmoney:0:2,'元,请慎重把握股市行情');
    readkey();
    clrscr;
    goto back;
  end;
  if ac='t' then
   begin
  writeln('请输入您想查看的股票编号(大盘请输入"0")');
  readln(kgpc);
  writeln('看1~100缩略请按1,看1~300缩略请按2,看1~600缩略请按3');
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
  outtextxy(10,660,'单价      涨跌幅(与开盘)  单价涨跌    持仓    持仓现金    买入单价    单股盈亏');
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
  outtextxy(10,660,'单价      涨跌幅(与开盘)  单价涨跌    持仓    持仓现金    买入单价    单股盈亏');
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
  outtextxy(10,660,'单价      涨跌幅(与开盘)  单价涨跌    持仓    持仓现金    买入单价    单股盈亏');
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
  writeln('请等待');
  delay(500);
until false;
end.
