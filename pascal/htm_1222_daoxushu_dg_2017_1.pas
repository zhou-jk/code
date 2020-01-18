program htm_1222_daoxushu_digui_2017_1_22;
var
  i,j:byte;
  //n:string;
  n:longint;
  a:char;

procedure dfs(n:longint); //di'gui
begin
  if n=0 then exit;
  write(n mod 10);
  dfs(n div 10);
end;

begin
  readln(n);
  {i:=1; j:=length(n); //pu'tong
  while i<j do
  begin
    a:=n[i];
    n[i]:=n[j];
    n[j]:=a;
    inc(i); dec(j);
  end;
  writeln(n);}
  dfs(n);
end.

