program h_1960_shuduyanzheng_2017_8_5;
var
  a:array[1..9,1..9] of byte;
  v:array[1..9] of boolean;
  k,i,j,p,q,r:byte;
  b:boolean;
begin
  readln(k);
  for i:=1 to k do
  begin
    b:=false;
    for j:=1 to 9 do
      for p:=1 to 9 do read(a[j,p]);
    for j:=1 to 9 do
    begin
      fillchar(v,sizeof(v),false);
      for p:=1 to 9 do v[a[j,p]]:=true;
      for p:=1 to 9 do
        if not v[p] then
        begin
          b:=true;
          writeln('Wrong');
          break;
        end;
      if b then break;
    end;
    if b then continue;
    for j:=1 to 9 do
    begin
      fillchar(v,sizeof(v),false);
      for p:=1 to 9 do v[a[p,j]]:=true;
      for p:=1 to 9 do
        if not v[p] then
        begin
          b:=true;
          writeln('Wrong');
          break;
        end;
      if b then break;
    end;
    if b then continue;
    for j:=1 to 3 do
    begin
      for p:=1 to 3 do
      begin
        fillchar(v,sizeof(v),false);
        for q:=1 to 3 do
          for r:=1 to 3 do v[a[(j-1)*3+q,(p-1)*3+r]]:=true;
        for q:=1 to 9 do
          if not v[p] then
          begin
            b:=true;
            writeln('Wrong');
            break;
          end;
        if b then break;
      end;
      if b then break;
    end;
    if not b then writeln('Right');
  end;
end.