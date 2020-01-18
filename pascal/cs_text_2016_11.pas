program cs_textinputoutut_2016_11_7;
uses dos;
var
  s,m:string;
  f:text;
begin
  readln(s);
  assign(f,s);
  rewrite(f);
  writeln(f,s);
  close(f);
  m:='notepad '+s;
  writeln(m);
  exec('run.bat','');
end.
