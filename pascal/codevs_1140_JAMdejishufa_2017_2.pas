program codevs_1140_JAMdejishufa_2017_2_5;
var
  s,t,w,i:byte;
  n:string;
procedure next(k:byte);
var c:char;
begin
  c:=succ(n[k]);
  if ord(c)-96+w-k>t then
  begin
    if k=1 then halt;
    next(k-1);
    c:=succ(n[k-1]);
  end;
  n[k]:=c;
end;
begin
  readln(s,t,w);
  readln(n);
  for i:=1 to 5 do
  begin
    next(w);
    writeln(n);
  end;
end.
