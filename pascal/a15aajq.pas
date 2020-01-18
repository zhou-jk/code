program a15aa;
var
  a,b,c,d,e,f:real;
  h:integer;
  g,i:char;
begin
  readln(a,i,g);
  h:=ord(g);
  case h of
    66,98:b:=a/1024;
    75,107:b:=a;
    77,109:b:=a*1024;
    71,103:b:=a*1024*1024;
    84,116:b:=a*1024*1024*1024;
  end;
  f:=b*1024;
  c:=b/1024;
  d:=c/1024;
  e:=d/1024;
  case h of
    66,98:writeln(b:0:5,'KB','  ',c:0:8,'MB','  ',d:0:11,'GB','  ',e:0:14,'TB');
    75,107:writeln(f:0:2,'B','  ',c:0:8,'MB','  ',d:0:11,'GB','  ',e:0:14,'TB');
    77,109:writeln(f:0:2,'B','  ',b:0:5,'KB','  ',d:0:11,'GB','  ',e:0:14,'TB');
    71,103:writeln(f:0:2,'B','  ',b:0:5,'KB','  ',c:0:8,'MB','  ',e:0:14,'TB');
    84,116:writeln(b:0:2,'B','  ',b:0:5,'KB','  ',c:0:8,'MB','  ',d:0:11,'GB');
  end;
end.
