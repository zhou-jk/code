uses math;
var
  x,y,m,m_:integer;
  f:boolean;
function mj(m1:longint):integer;
begin
  mj:=0;
  if f then exit;
  if m1<x then begin mj:=m1; exit; end;
  if (m1 mod x=0)or(m1 mod y=0) then begin f:=true; exit; end;
  if m1>y
  then mj:=min(mj(m1-x),mj(m1-y))
  else mj:=mj(m1-x);
end;
begin
  readln(x,y,m);
  if (m mod x=0)or(m mod y=0)
  then m_:=m
  else m_:=m-mj(m);
  writeln(m_);
end.
