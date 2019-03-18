unit grph;
INTERFACE
uses
Graph; type
Draw = object{объект для рисования}
Gd, Gm, x0, y0, x, y, xLeft, yLeft, xRight, yRight, n: integer;
a, b, fmin, fmax, x1, y1, mx, my, dx, dy, num: real;
s: string;
constructor Init;{инициализация}
procedure Time_MakeUp(finish,inc:real); {подготовка вывода среднего времени
ожидания заявок от каждого источника в буфере}
procedure Denied_MakeUp(finish,inc:real);{подготовка вывода процентов
отказов для каждого источника}
procedure Time_Draw(time, lambda : real);{вывод времени ожидания} procedure Denied_Draw(d1, d2, d3, lambda : real);{вывод поцентов отказов} end;
IMPLEMENTATION
  constructor Draw.Init;
  begin
Приложение 4. Исходный код графического модуля GRPH.tpu
12
   x0 := 0;
   Gd := Detect;
   InitGraph(Gd, Gm, '');
   xLeft := 50;
   yLeft := 50;
   xRight := GetMaxX - 50;
   yRight := GetMaxY - 50;
   clearviewport;
end;
procedure Draw.Time_MakeUp;
var i : integer;
    c,d:real;
begin
a := 0; b := finish ;
if inc<0.2 then dx := 0.2;
if inc>=0.2 then dx:=inc;
fmin := 0; fmax := 40; dy := 10;
mx := (xRight - xLeft) / (b - a);
my := (yRight - yLeft) / (fmax - fmin);
x0 := trunc(abs(a) * mx) + xLeft;
y0 := yRight - trunc(abs(fmin) * my);
setcolor(2);
line(xLeft, y0, xRight + 10, y0);
line(x0, yLeft - 10, x0, yRight);
setcolor(2);
setlinestyle(1,0,1);
c:=xLeft;
d:=xRight;
i:=1;
line(x0+89, yLeft-10, x0+89, yRight);
line(x0+179, yLeft-10, x0+179, yRight);
line(x0+269, yLeft-10, x0+269, yRight);
line(x0+359, yLeft-10, x0+359, yRight);
line(x0+449, yLeft-10, x0+449, yRight);
line(x0+539, yLeft-10, x0+539, yRight);
line(x0, yLeft, x0+550, yLeft);
line(x0, yLeft+95, x0+550, yLeft+95);
line(x0, yLeft+190, x0+550, yLeft+190);
line(x0, yLeft+285, x0+550, yLeft+285);
SetColor(3);
SetTextStyle(1, 0, 1);
OutTextXY(xRight + 15, y0 - 15, 'Prb');
OutTextXY(x0 - 15, yLeft - 35, 'Vremya preb. v sisteme'); SetColor(3);
n := round((b - a) / dx) + 1;
for i := 1 to n do
begin
  num := a + (i - 1) * dx;
  x := xLeft + trunc(mx * (num - a));
  Line(x, y0 - 3, x, y0 + 3);
  str(Num:0:1, s);
  if abs(num) > 1E-15 then
    OutTextXY(x - TextWidth(s) div 2, y0 + 10, s)
end;
n := round((fmax - fmin) / dy) + 1; for i :=1ton do
begin
num := fMin + (i - 1) * dy;
y := yRight - trunc(my * (num - fmin)); Line(x0 - 3, y, x0 + 3, y);
str(num:0:0, s);
if abs(num) > 1E-15 then
OutTextXY(x0 -23, y - TextHeight(s) div 2, s)
13

  end;
  OutTextXY(x0 - 10, y0 + 10, '0');
  x1 := a;
end;
procedure Draw.Time_Draw(time, lambda : real); begin
   x1 := lambda;
   y1 := time;
   x := x0 + round(x1 * mx);
   y := y0 - round(y1 * my);
   Circle(x, y, 2);
end;
procedure Draw.Denied_MakeUp;
  var i : integer;
  begin
a := 0; b := finish;
if inc<0.2 then dx := 0.2;
if inc>=0.2 then dx:=inc;
fmin := 0; fmax := 100; dy := 10;
mx := (xRight - xLeft) / (b - a);
my := (yRight - yLeft) / (fmax - fmin);
x0 := trunc(abs(a) * mx) + xLeft;
y0 := yRight- trunc(abs(fmin) * my); setcolor(2);
line(xLeft, y0, xRight + 10, y0);
line(x0, yLeft - 10, x0, yRight); setlinestyle(1,0,1);
line(x0+35, yLeft-10, x0+35, yRight);
for i:=1 to 14 do
line(x0+35+36*i, yLeft-10, x0+35+36*i, yRight); line(x0, yLeft, x0+550, yLeft);
for i:=1 to 9 do
line(x0, yLeft+38*i, x0+550, yLeft+38*i); SetColor(3);
SetTextStyle(1, 0, 1);
OutTextXY(xRight + 15, y0 - 15, 'Prb'); OutTextXY(x0 - 15, yLeft - 35, 'Proc. Otk.'); SetColor(3);
n := round((b - a) / dx) + 1;
  for i := 1 to n do
  begin
    num := a + (i - 1) * dx;
    x := xLeft + trunc(mx * (num - a));
    Line(x, y0 - 3, x, y0 + 3);
    str(Num:0:1, s);
    if abs(num) > 1E-15 then
      OutTextXY(x - TextWidth(s) div 2, y0 + 10, s)
  end;
  n := round((fmax - fmin) / dy) + 1;
  for i := 1 to n do
  begin
num := fMin + (i - 1) * dy;
y := yRight - trunc(my * (num - fmin)); Line(x0 - 3, y, x0 + 3, y);
str(num:0:0, s);
if abs(num) > 1E-15 then
OutTextXY(x0 -32, y - TextHeight(s) div 2, s)
  end;
  OutTextXY(x0 - 10, y0 + 10, '0');
  x1 := a;
end;
procedure Draw.Denied_Draw(d1, d2, d3, lambda : real); begin
14

end;
BEGIN
END.
x1 := lambda;
y1 := d1;
x := x0 + round(x1 * mx);
y := y0 - round(y1 * my);
SetColor(4);
Circle(x, y, 2);
y1 := d2;
x := x0 + round(x1 * mx);
y := y0 - round(y1 * my);
SetColor(6);
Circle(x, y, 2);
y1 := d3;
x := x0 + round(x1 * mx);
y := y0 - round(y1 * my);
SetColor(5);
Circle(x, y, 2);