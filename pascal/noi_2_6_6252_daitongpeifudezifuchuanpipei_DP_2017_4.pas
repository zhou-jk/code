program noi_2_6_6252_daitongpeifudezifuchuanpipei_DP_2017_4_29_X;
var
  b,c:boolean;
  s,s1:string;
  i,j,k,p,p1,l,m:byte;
begin
  readln(s);
  readln(s1);
  p1:=1; p:=1; l:=1; s:=s+'*';
  for i:=1 to length(s) do
    if s[i]='*' then inc(m);
  for i:=1 to length(s) do
    if s[i]='*' then
    begin
      dec(m);
      c:=true;
      for j:=p to l do
      begin
        b:=true;
        for k:=1 to i-p1 do
          if s[i-k]<>s1[j+i-p1-k] then
          begin
            b:=false;
            break;
          end;
        if b then
        begin
          c:=false;
          break;
        end;
      end;
      if c then
      begin
        writeln('not matched');
        exit;
      end;
      p:=j+i-p1; p1:=i+1; l:=length(s1)-length(s)+p1-1+m;
    end;
  writeln('matched');
end.
