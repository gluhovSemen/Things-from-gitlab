unit intfmdl;
interface
uses Graph, crt, grph, funcmdle;
type
Menu = object{объект для работы с интерфейсом}
kmin : integer;{минимальное кол - во заявок от каждого источника}
Start, Inc, Finish : real;{начальная и конечная лямбда, инкремент лямбды} constructor Init;{Инициализация}
procedure DrawMenu(kod : integer);{Рисование основного меню}
procedure Task(kod : integer);
procedure Increment(kod : integer);{увеличение значений в настройках и
проверка их корректности}
procedure Decrement(kod : integer);{уменьшение значений в настройках и
проверка их корректности}
   end;
procedure Output(ButtCode : integer; kmin : integer; start, inc, finish : real);{вывод результатов}
procedure convert(var s:string);{преобразование букв}
implementation
procedure Table(s : string);{вывод результатов на экран} var f : text;
       i : integer;
   begin
Assign(f, s);
Reset(f);
setcolor(green);
line(3, 5, getmaxx-5, 5);
line(3, 75, getmaxx-5,75);
line(3, 135, getmaxx-5, 135);
line(3, getmaxy-3, getmaxx-5, getmaxy-3); line(3, 5, 3, getmaxy-3);
line(getmaxx-5, 5, getmaxx-5, getmaxy-3); line(98, 5, 98, getmaxy-3);
line(370, 5, 370, getmaxy-3);
line(183, 75, 183, getmaxy-3);
      line(280, 75, 280 , getmaxy-3);
      line(465, 75, 465, getmaxy-3);
      line(550, 75, 550, getmaxy-3);
      Settextstyle(1,0,3);
      Setcolor(blue);
      OutTextXY(5 ,30,'Lambda');
15
OutTextXY(200 ,30,'Отказ');
OutTextXY(440 ,30,'В системе');
SetTextStyle(1, 0, 3);
setcolor(magenta);
OutTextXY(130 ,90, '1');
OutTextXY(220 ,90, '2');
OutTextXY(315 ,90, '3');
OutTextXY(420 ,90, '1');
OutTextXY(495 ,90, '2');
OutTextXY(580 ,90, '3');
i := 1;
while not eof(f) do
begin
setcolor(red);
   Readln(f, s);
   OutTextXY(20 ,(120 + 30 * i), s);
   Readln(f, s);
   OutTextXY(110 ,(120 + 30 * i), s);
   Readln(f, s);
   OutTextXY(390 ,(120 + 30 * i), s);
   i := i + 1;
   end;
   setcolor(white);
   Close(f);
   SetTextStyle(1, 0, 4);
end;
constructor Menu.Init;
begin
   Start := 2;
   Inc := 0.1;
   Finish := 3;
   kmin := 1500;
end;
procedure Menu.DrawMenu(kod
var
: integer);
MainCode, AddCode, MButtX, MButtY : integer;
   SizeX, SizeY, i : integer;
begin
SetTextStyle(1, 0, 4);
setcolor(green);
Outtextxy(10,10,'Главное меню');
SetColor(White);
if kod = 1 then
   SetColor(Red);
OutTextXY(10,75,'Построить график'); SetColor(White);
if kod = 2 then
   SetColor(Red);
OutTextXY(10, 140,'Настройки');
SetColor(White);
if kod = 3 then
SetColor(Red);
OutTextXY(10, 205,'Таблица с результатами'); SetColor(White);
if kod = 4 then
   SetColor(Red);
OutTextXY(10, 270,'Помощь');
SetColor(White);
end;
procedure Menu.Increment(kod : integer); var
koef : real;
16

   begin
      koef := 0.1;
     ClearViewPort;
     case kod of
         1 : kmin := kmin + 100;
         2 : if (start < finish - koef) then
start := start + koef;
3 : if (finish - start > inc) then
inc := inc + koef;
4 : if (trunc(finish - start) >= trunc(inc)) and (trunc(finish) >=
trunc(inc)) then
             finish :=  finish + koef;
end; end;
procedure Menu.Decrement(kod : integer); var koef : real;
begin
      koef := 0.1;
      ClearViewPort;
      case kod of
         1 : if kmin > 100 then
             kmin := kmin - 100;
         2 : if (start > koef) then
             start := start - koef;
3 : if (finish - start > koef) and (inc > 2*koef) then inc := inc - 0.1;
4 : if (finish - start > inc) and (finish > inc) then
             finish :=  finish - koef;
      end;
   end;
   procedure convert(var s:string);
   var i:integer;
   begin
   for i:=1 to length(s) do
if ord(s[i]) in [192..239] then s[i]:=chr(ord(s[i])-64)
else if ord(s[i]) in [240..255] then s[i]:=chr(ord(s[i])-16)
else if ord(s[i]) =168 then s[i]:=chr(ord(240)) else if ord(s[i]) =184 then s[i]:=chr(ord(241));
   end;
   procedure Menu.Task(kod : integer);
   var Butt : char;
       s : string;
       t : text;
       i:integer;
   begin
   ClearViewPort;
case kod of
1:
begin
While (Butt <> #27) do begin
Setcolor(Green);
OutTextXY(10,10,'Выберите график'); setcolor(white);
if kod = 1 then
SetColor(Red);
OutTextXY(10,75,'Процент отказов'); SetColor(White);
if kod = 2 then
SetColor(Red);
OutTextXY(10,140,'Среднее время в системе'); SetColor(White);
17

if kod = 3 then
SetColor(Red);
OutTextXY(10,205,'Просто
SetColor(White);
Butt := ReadKey;
case Butt of
промоделируйте');
      #72 : if kod > 1 then
               kod := kod - 1;
      #80 : if kod < 3 then
               kod := kod + 1;
      #13 : begin
               ClearViewPort;
               Output(kod, kmin, Start, Inc, Finish);
Break; end;
#27 : break;
end; end;
   ClearViewPort;
end;
2:
begin
While (Butt <> #27) do begin
Setcolor(Green); OutTextXY(10,20,'Изменение параметров'); setcolor(white);
if kod = 1 then
SetColor(Red);
OutTextXY(10,100,'Kmin'); SetColor(White);
Str(kmin, s);
OutTextXY(200, 100, s);
if kod = 2 then
SetColor(Red); OutTextXY(10,140,'Start'); SetColor(White);
Str(Start : 1 : 1, s); OutTextXY(200,140, s);
if kod = 3 then
SetColor(Red); OutTextXY(10,180,'Lambda'); SetColor(White);
Str(Inc : 1 : 1, s);
OutTextXY(200,180, s);
if kod = 4 then
SetColor(Red); OutTextXY(10,220,'Finish'); SetColor(White);
Str(Finish : 1 : 1, s); OutTextXY(200,220, s);
Butt := ReadKey;
case Butt of
      #72 : if kod > 1 then
               kod := kod - 1;
      #80 : if kod < 4 then
               kod := kod + 1;
      #77 : Increment(kod);
      #75 : Decrement(kod);
      #27 : break;
      end;
end;
   ClearViewPort;
18

   end;
procedure
real); var
Output(ButtCode : integer; kmin : integer; start, inc, finish :
end; 3 : begin
       ClearViewPort;
       Table('output.txt');
       readkey;
       ClearViewPort;
end; 4 : begin
        ClearViewPort;
        assign(t,'C:\\24\HelpMe.txt');
        reset(t);
        settextstyle(1,0,3);
        setcolor(green);
        i:=0;
        while not eof(t) do begin
              Readln(t, s);
              convert(s);
              OutTextXY(10 ,10+20*i,s);
              i:=i+1 ;
        end;
        close(t);
        readkey;
        clearviewport;
end; end;
   Gen : generator;
   Pribor : machine;
   Sourse : integer;
   Stream : integer;
   Time, HammerTime : real;
   Byfer : buffer;
count : integer;
f : text;
Canvas : draw; PrebTime1,PrebTime2,PrebTime3:real;
begin
Canvas.Init;
Gen.Init;
Byfer.Init;
Assign(f, 'output.txt'); Rewrite(f);
Pribor.Start := Start;
Pribor.Inc := Inc;
Pribor.Edge := Finish; Byfer.GetPriborTime(Pribor.Edge);
while (Byfer.total_1 < kmin) or (Byfer.total_2 < kmin) or (Byfer.total_3 < kmin) do
   begin
      Gen.giveorder(Stream, Time);
      Byfer.AddToBuffer(Stream, Time);
end;
Byfer.Init;
if ButtCode = 2 then
begin
Canvas.Time_MakeUp(Pribor.Edge, Pribor.Inc); while Pribor.Start < Pribor.Edge do
   begin
   randomize;
19

   if Pribor.Edge < Pribor.start then
      break;
Byfer.GetPriborTime(Pribor.Start);
while (Byfer.total_1 < kmin) or (Byfer.total_2 < kmin) kmin) do
   begin
      Gen.giveorder(Stream, Time);
      Byfer.AddToBuffer(Stream, Time);
end;
PrebTime1:=Byfer.totaltime1/(Byfer.total_1- Byfer.denied_1)+Pribor.Start+(Gen.TGen[1]/Byfer.total_1);
PrebTime2:=Byfer.totaltime2/(Byfer.total_2- Byfer.denied_2)+Pribor.Start+(Gen.TGen[2]/Byfer.total_2);
PrebTime3:=Byfer.totaltime3/(Byfer.total_3- Byfer.denied_3)+Pribor.Start+(Gen.TGen[3]/Byfer.total_3);
or (Byfer.total_3 <
setcolor(red);
Canvas.Time_Draw(PrebTime1, Pribor.Start); setcolor(6);
Canvas.Time_Draw(PrebTime2, Pribor.Start); setcolor(5);
Canvas.Time_Draw(PrebTime3, Pribor.Start); Writeln(f, Pribor.start : 1 : 3);
Write(f, Byfer.denied_1/Byfer.total_1 : 1 : Write(f, Byfer.denied_2/Byfer.total_2 : 1 : Writeln(f, Byfer.denied_3/Byfer.total_3 : 1 Write(f, PrebTime1 : 1 : 3, ' ');
Write(f, PrebTime2 : 1 : 3, ' '); Writeln(f, PrebTime3 : 1 : 3, ' '); Byfer.Init;
Pribor.next;
end;
readln;
end;
if ButtCode = 1 then
begin
Canvas.Denied_MakeUp(Pribor.Edge, Pribor.Inc); while Pribor.Start < Pribor.Edge do
begin
3, '   ');
3, '   ');
: 3, '   ');
randomize;
Byfer.GetPriborTime(Pribor.Start);
while (Byfer.total_1 < kmin) or (Byfer.total_2 < kmin) or (Byfer.total_3 <
kmin) do
   begin
      Gen.giveorder(Stream, Time);
      Byfer.AddToBuffer(Stream, Time);
   end;
Canvas.Denied_Draw(Byfer.denied_1/Byfer.total_1 * 100, Byfer.denied_2/Byfer.Total_2 * 100,
Byfer.denied_3/Byfer.total_3 * 100, Pribor.Start); Writeln(f, Pribor.start : 1 : 3);
Write(f, Byfer.denied_1/Byfer.total_1 : 1 : Write(f, Byfer.denied_2/Byfer.total_2 : 1 : Writeln(f, Byfer.denied_3/Byfer.total_3 : 1 PrebTime1:=Byfer.totaltime1/(Byfer.total_1-
3, '   ');
3, '   ');
: 3, '   ');
Byfer.denied_1)+Pribor.Start+(Gen.TGen[1]/Byfer.total_1); PrebTime2:=Byfer.totaltime2/(Byfer.total_2-
Byfer.denied_2)+Pribor.Start+(Gen.TGen[2]/Byfer.total_2); PrebTime3:=Byfer.totaltime3/(Byfer.total_3-
Byfer.denied_3)+Pribor.Start+(Gen.TGen[3]/Byfer.total_3); Write(f, PrebTime1 : 1 : 3, ' ');
Write(f, PrebTime2 : 1 : 3, ' ');
Writeln(f, PrebTime3 : 1 : 3, ' ');
Byfer.Init;
20

Pribor.next;
end;
readln; end;
if ButtCode = 3 then
begin
SetTextStyle(1, 0, 4);
setcolor(green);
OutTextXY(round(GetMaxX/3) + 20, round(GetMaxY/3) + 20, 'Њ®¤Ґ«ЁагҐ¬...'); setcolor(white);
while (Pribor.Start < Pribor.Edge ) do
begin
   if Pribor.Edge < Pribor.Start then
      break;
randomize;
Byfer.GetPriborTime(Pribor.Start);
while (Byfer.total_1 < kmin) or (Byfer.total_2 < kmin)
kmin) do
   begin
      Gen.giveorder(Stream, Time);
      Byfer.AddToBuffer(Stream, Time);
   end;
PrebTime1:=Byfer.totaltime1/(Byfer.total_1- Byfer.denied_1)+Pribor.Start+(Gen.TGen[1]/Byfer.total_1);
PrebTime2:=Byfer.totaltime2/(Byfer.total_2- Byfer.denied_2)+Pribor.Start+(Gen.TGen[2]/Byfer.total_2);
PrebTime3:=Byfer.totaltime3/(Byfer.total_3- Byfer.denied_3)+Pribor.Start+(Gen.TGen[3]/Byfer.total_3);
or (Byfer.total_3 <
Writeln(f, Pribor.start : 1 : 3);
Write(f, Byfer.denied_1/Byfer.total_1 : 1 : 3, ' '); Write(f, Byfer.denied_2/Byfer.total_2 : 1 : 3, ' '); Writeln(f, Byfer.denied_3/Byfer.total_3 : 1 : 3, ' '); Write(f, PrebTime1 : 1 : 3, ' ');
Write(f, PrebTime2 : 1 : 3, ' ');
Writeln(f, PrebTime3 : 1 : 3, ' ');
Byfer.Init;
Pribor.next;
end;
ClearViewPort;
setcolor(green);
OutTextXY(round(GetMaxX/3) + 60, round(GetMaxY/3) + 20, 'ѓ®в®ў®'); Delay(500);
setcolor(white);
end;
Close(f);
end;
begin END.