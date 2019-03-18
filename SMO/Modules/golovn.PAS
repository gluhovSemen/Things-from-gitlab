program glavn;
uses crt,Graph,funcmdle,grph,intfmdl; var
code : integer;
key : char;
Canvas : draw;
Main : menu;
Gen : generator;
Pribor : machine;
Sourse : integer;
Stream : integer;
Time, PrebTime1,PrebTime2,PrebTime3 : real; Byfer : buffer;
Grap : Draw;
count, kmin : integer;
   f : text;
   w:integer;
   otkz1,otkz2,otkz3:real;
BEGIN
   Canvas.Init;
   Main.Init;
   Code := 1;
   Main.DrawMenu(code);
   while key <> #27 do
   begin
      Key := ReadKey;
      case key of
      #72 : if code > 1 then
               code := code - 1;
      #80 : if code < 4 then
               code := code + 1;
      #13 : Main.Task(code);
   end;
      Main.DrawMenu(code);
end; END.