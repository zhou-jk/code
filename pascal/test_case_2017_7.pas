program test_case_2017_7_4;
var a:integer;
procedure p;
begin
  writeln(a);
  inc(a);
end;
begin
  a:=1;
  case a of
    1:begin
        writeln(a);
        inc(a);
      end;
    2:p;
    3:p;
  end;
end.