program a15;
var
  a,b,c,d,e,f:real;
  g:char;
begin
  readln(a);
  readln(g);
  case g of
    'b','B':b:=a/1024;
    'k','K','kb','KB':b:=a;
    'm','M','mb','MB':b:=a*1024;
    'g','G','gb','GB':b:=a*1024*1024;
    't','T','tb','TB':b:=a*1024*1024*1024;
  end;
  f:=b*1024;
  c:=b/1024;
  d:=c/1024;
  e:=d/1024;
  case g of
    'b','B':writeln(b:0:2,'KB',' ',c:0:2,'MB',' ',d:0:2,'GB',' ',e:0:2,'TB');
    'k','K','kb','KB':writeln(f:0:2,'B',' ',c:0:2,'MB',' ',d:0:2,'GB',' ',e:0:2,'TB');
    'm','M','mb','MB':writeln(f:0:2,'B',' ',b:0:2,'KB',' ',d:0:2,'GB',' ',e:0:2,'TB');
    'g','G','gb','GB':writeln(f:0:2,'B',' ',b:0:2,'KB',' ',c:0:2,'MB',' ',e:0:2,'TB');
    't','T','tb','TB':writeln(b:0:2,'B',' ',b:0:2,'KB',' ',c:0:2,'MB',' ',d:0:2,'GB');
  end;
end.
