program a15;
var
  a,b,c,d,e,f:real;
  g:char;
begin
  readln(a,g);
  case g of
    'b':b:=a/1024;
    'B':b:=a/1024;
    'k':b:=a;
    'K':b:=a;
    'kb':b:=a;
    'KB':b:=a;
    'm':b:=a*1024;
    'M':b:=a*1024;
    'mb':b:=a*1024;
    'MB':b:=a*1024;
    'g':b:=a*1024*1024;
    'G':b:=a*1024*1024;
    'gb':b:=a*1024*1024;
    'GB':b:=a*1024*1024;
    't':b:=a*1024*1024*1024;
    'T':b:=a*1024*1024*1024;
    'tb':b:=a*1024*1024*1024;
    'TB':b:=a*1024*1024*1024;
  end;
  f:=b*1024;
  c:=b/1024;
  d:=c/1024;
  e:=d/1024;
  case g of
    'b':writeln(b:0:2,KB,' ',c:0:2,MB,' ',d:0:2,GB,' ',e:0:2,TB);
    'B':writeln(b:0:2,KB,' ',c:0:2,MB,' ',d:0:2,GB,' ',e:0:2,TB);
    'k':writeln(f:0:2,B,' ',c:0:2,MB,' ',d:0:2,GB,' ',e:0:2,TB);
    'K':writeln(f:0:2,B,' ',c:0:2,MB,' ',d:0:2,GB,' ',e:0:2,TB);
    'kb':writeln(f:0:2,B,' ',c:0:2,MB,' ',d:0:2,GB,' ',e:0:2,TB);
    'KB':writeln(f:0:2,B,' ',c:0:2,MB,' ',d:0:2,GB,' ',e:0:2,TB);
    'm':writeln(f:0:2,B,' ',b:0:2,KB,' ',d:0:2,GB,' ',e:0:2,TB);
    'M':writeln(f:0:2,B,' ',b:0:2,KB,' ',d:0:2,GB,' ',e:0:2,TB);
    'mb':writeln(f:0:2,B,' ',b:0:2,KB,' ',d:0:2,GB,' ',e:0:2,TB);
    'MB':writeln(f:0:2,B,' ',b:0:2,KB,' ',d:0:2,GB,' ',e:0:2,TB);
    'g':writeln(f:0:2,B,' ',b:0:2,KB,' ',c:0:2,MB,' ',e:0:2,TB);
    'G':writeln(f:0:2,B,' ',b:0:2,KB,' ',c:0:2,MB,' ',e:0:2,TB);
    'gb':writeln(f:0:2,B,' ',b:0:2,KB,' ',c:0:2,MB,' ',e:0:2,TB);
    'GB':writeln(f:0:2,B,' ',b:0:2,KB,' ',c:0:2,MB,' ',e:0:2,TB);
    't':writeln(b:0:2,B,' ',b:0:2,KB,' ',c:0:2,MB,' ',d:0:2,GB);
    'T':writeln(b:0:2,B,' ',b:0:2,KB,' ',c:0:2,MB,' ',d:0:2,GB);
    'tb':writeln(b:0:2,B,' ',b:0:2,KB,' ',c:0:2,MB,' ',d:0:2,GB);
    'TB':writeln(b:0:2,B,' ',b:0:2,KB,' ',c:0:2,MB,' ',d:0:2,GB);
  end;
end.
