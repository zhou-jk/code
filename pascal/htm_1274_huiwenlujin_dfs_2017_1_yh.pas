program htm_1274_huiwenlujin_dfs_2017_1_24_yh;
var
  s:array[1..3,0..200000] of string;
  a:array[0..21] of string;
  b:string;
  ans,an,j,ans1,k,n,i:longint;
function find(ss:string):boolean;
var i,j,mid:longint;
begin
  i:=1; j:=k;
  while i<j do
  begin
    mid:=(i+j) div 2;
    if s[2,mid]>=ss
    then j:=mid
    else i:=mid+1;
  end;
  exit(s[2,j]=ss);
end;
procedure sort(l,r,p:longint);
var
  i,j:longint;
  x,y:string;
begin
  i:=l;
  j:=r;
  //writeln('%',l,' ',r);
  x:=s[p,(l+r) div 2];
  repeat
    while s[p,i]<x do inc(i);
    while x<s[p,j] do dec(j);
    //writeln('$',i,' ',j);
    if not(i>j) then
    begin
      y:=s[p,i];
      s[p,i]:=s[p,j];
      s[p,j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j,p);
  if i<r then sort(i,r,p);
end;
procedure dfs(x,y,t,p:longint);
begin
  if (x<1)or(x>n)or(y<1)or(y>n) then exit;
  b[t]:=a[x][y];
  if t=n then
  begin
    inc(an);
    //writeln(b);
    s[p,an]:=b;
    exit;
  end;
  if p=1
  then begin
         dfs(x+1,y,t+1,p);
         dfs(x,y+1,t+1,p);
       end
  else begin
         dfs(x-1,y,t+1,p);
         dfs(x,y-1,t+1,p);
       end;
end;
begin
  readln(n);
  {f[2]:=2;
  f:='';
  f:=f+'2';
  f:='dfasfa';
  f[2]:='a';}
  for i:=1 to n do b:=b+' ';
  //b[0]:=chr(n);
  for i:=1 to n do readln(a[i]);
  for i:=1 to n do
  begin
    an:=0;
    dfs(i,n-i+1,1,2);
    //writeln('$',i);
    sort(1,an,2);
    k:=an;
    an:=0;
    dfs(i,n-i+1,1,1);
    sort(1,an,1);
    for j:=1 to an do
    begin
      //writeln('#',i,' ',j);
      if ((j=1)or(s[1,j]<>s[1,j-1]))and(find(s[1,j])) then
      begin
        //writeln('*',i,' ',j);
        inc(ans);
        s[3,ans]:=s[1,j];
      end;
    end;
  end;
  //writeln('&',ans);
  sort(1,ans,3);
  for i:=1 to ans do
    if (i=1)or(s[3,i]<>s[3,i-1]) then inc(ans1);
  writeln(ans1);
end.
