program h_1006_zuiduanlujingSHOPTH_Floyed_2017_5_13;
var
  g:array[1..80,1..80] of integer;
  n,v0,i,j,k:byte;
  s:string;
  c:char;
begin
  readln(n);
  readln(v0);
  fillchar(g,sizeof(g),127);
  for i:=1 to n do
  begin
    for j:=1 to n-1 do
    begin
      s:='';
      read(c);
      while c<>' ' do s:=s+c;
      delete(s,length(s),1);
      if s<>'-' then val(s,g[i,j]);
    end;
    readln;
  end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if g[i,k]+g[k,j]<g[i,j] then g[i,j]:=g[i,k]+g[k,j];
  for i:=1 to n do
    if i<>v0 then writeln('(',v0,' -> ',i,')',' = ',g[i,j]);
end.




