program a22;
var
  a,b,c,d,e,f,g,h,i:real;
begin
  e:=0;
  c:=0;
  f:=0;
  readln(a,d);
  if (d>0) and (a>0) then
    begin
      b:=a*60*20/d;
      repeat
        e:=e+1;
        c:=c+e+e;
        f:=f+0.5;
      until c>b;
      c:=c-e;
      if trunc(f)=f then
        f:=f-1;
      if c>b then
        begin
          c:=c-e;
          if trunc(f)<>f then
            begin
              h:=(trunc(f)-1)*2+1;
              i:=(trunc(f)-1)*2+2;
            end
          else
            begin
              h:=trunc(f)*2+1;
              i:=trunc(f)*2;
            end;
        end
      else
        begin
          g:=b-c;
          if trunc(f)<>f then
            begin
              h:=trunc(f)*2;
              i:=trunc(f)*2;
            end
          else
            begin
              h:=trunc(f)*2+1;
              i:=trunc(f)*2+1;
            end;
        end;
      writeln('shuliang',b:0:0,' zuidabanjing',f:0:0,' wanzhenzushuliang',c:0:0,' yushu',g:0:0,' zuidazhijing',h:0:0,' zuixiaozhijing',i:0:0);
    end
  else
    writeln('Error!');
end.




