## What is AssaultCube?
AssaultCube is a **FREE**, multiplayer, first-person shooter game, based on the
[CUBE engine](http://cubeengine.com/cube.php).

Taking place in realistic environments, with fast, arcade gameplay,
it's addictive and fun!

With efficient bandwidth usage, it's low-latency and can even run over a 56 Kbps
connection. It's tiny too, weighing in at a lightweight about 50 MB package
available for [Windows, Linux, Mac](https://assault.cubers.net/download.html).
On the correct settings, it can even run on old hardware (Pentium III and above).

## Features in a nutshell:

 * It's **FREE**.
 * Source code is available under a zlib-like open source license.
 * Low latency, it can even run across a 56 Kbps connection!
 * Lightweight size, only about 50 MB to download, plus additional maps
 average 20 KB each!
 * With the correct settings, it can run on old hardware
 (Pentium III and above).
 * Officially runs on most major systems (Windows: 2000/XP/Vista/7/8/10, Linux,
 Mac OS X: 10.6+), and maybe even some
 [non-major ones](https://assault.cubers.net/docs/getstarted.html)?
 * Has a built in, in-game map editor to help players create their own maps and
 allows for co-operative editmode in realtime with others!
 * Features a single-player bot system.
 * Supports recording of your game by the "demo" system.
 * Contains many multiplayer game modes, including: Deathmatch, Survivor,
 Capture the Flag, Hunt the Flag, Keep the Flag, Pistol Frenzy, Last Swiss
 Standing & One-Shot One-Kill (plus team versions of these modes).
 * Comes pre-packaged with several dozen different maps!

## More info:

Most of this README was directly copied from the
[AssaultCube Homepage](https://assault.cubers.net), which should have everything
you need in relation to AssaultCube.

## Original redistribution:

You may redistribute AssaultCube in any way the license permits, such as the
free unmodified distribution of AssaultCube's source and binaries. If you have
any doubts, you can look at the
[license](https://assault.cubers.net/docs/license.html).

## Изменения, внесённые этой модификацией:

  *  Бесконечные патроны
  *  Быстрая перезарядка
  *  Всё оружие автоматическое
  *  Можно выбрать любое оружие
  *  Отключена отдача
  *  Можно ускорить стрельбу(не работает в мультиплеере)(GUNWAITHACK=yes при компиляции)
  *  Всё оружие имеет прицелы, как у снайперской винтовки
  *  Увеличена скорость передвижения
  *  Можно включать editor в мультиплеере
  *  Можно летать(FLYHACK=yes при компиляции)
  *  Можно высоко прыгать(FLYHACK=no при компиляции)
  *  Можно сделать свет на 100%(LIGHTHACK=yes при компиляции)
  *  На карте отображаются враги
  *  Можно включить автоматическую стрельбу по врагам(autoshot)
  *  Можно спамить в чат сменой команды(spamteamswitch)
  *  Можно спамить самоубийством(spamsuicide)

## Сборка под linux

 * `git clone https://github.com/gnu9d/Absolutely-hacked-AssaultCube.git`
 * `cd Absolutely-hacked-AssaultCube/source/src`
 * {GUNWAITHACK=yes, LIGHTHACK=yes и другие} `make -j` {количество потоков в вашем процессоре + 1}
 * Можно установить с помощью `make install` или запускать из директории Absolutely-hacked-AssaultCube с помощью `source/src/ac_client`
## Лицензия этой модификации

Сама игра распространяется по собственной [лицензии](https://assault.cubers.net/docs/license.html).
Все изменения этой модификации распространяются по лицензии GPL 3 версии
