uses dos;
var i:longint;
begin
  for i:=1 to 100 do
    exec('cmd.exe','/c color 3e');
  exec('cmd.exe','/c echo 1');
end.
