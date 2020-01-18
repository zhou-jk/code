program a15aa;
var
  a,b,c,d,e,f:extended;
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
    66,98:
      begin
        writeln(b:0:50,'KB  ');
        writeln(c:0:50,'MB  ');
        writeln(d:0:50,'GB  ');
        writeln(e:0:50,'TB');
      end;
    75,107:
      begin
        writeln(f:0:50,'B  ');
        writeln(c:0:50,'MB  ');
        writeln(d:0:50,'GB  ');
        writeln(e:0:50,'TB');
      end;
    77,109:
      begin
        writeln(f:0:50,'B  ');
        writeln(b:0:50,'KB  ');
        writeln(d:0:50,'GB  ');
        writeln(e:0:50,'TB');
      end;
    71,103:
      begin
        writeln(f:0:50,'B  ');
        writeln(b:0:50,'KB  ');
        writeln(c:0:50,'MB  ');
        writeln(e:0:50,'TB');
        end;
    84,116:
      begin
        writeln(b:0:50,'B  ');
        writeln(b:0:50,'KB  ');
        writeln(c:0:50,'MB  ');
        writeln(d:0:50,'GB');
      end;
  end;
end.
