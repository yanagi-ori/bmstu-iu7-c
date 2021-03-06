## Содержание
1. [Задание 6](#task6)
2. [Задание 7](#task7)

## Задание 6 <a name="task6"></a>

|Количество повторов (N)|Размер массива|a[i]|*a(a+i)|Работа с указателями|
|-----|-----|-----|-----|-----|
|10000|10|0.1033|0.1998|0.0994|
|10000|100|9.8732|9.8734|8.5797|
|10000|1000|289.1873|291.6421|283.7582|
|10000|10000|1485.4818|1514.8845|1477.884|
|1000000|10|0.120518|0.105203|0.111242|
|1000000|100|9.169606|9.355897|8.848895|
|1000000|1000|289.365645|291.981679|282.881769|  
  
  
1. Размер массива влияет на количество операций, которые необходимо произвести. Следовательно, обработка более большого массива занимает больше времени.
2. Несколько замеров необходимо выполнять для повышения точночти результатов. 
3. Исходя из результатов тестирования, самым производительным вариантом оказалась работа с указателями. Я ссвязываю это с тем, что при работе с укзателями, мы манипулируем данными напряму, без лишних посредников, что повышает скорость работы программы.

## Задание 7 <a name="task7"></a>
* Я увличил размер массива до 100000 элементов, после чего скомпилировал программу с дополнительными ключами для профилирования:  
```$ gcc -std=c99 -Wall -Werror -g -pg main.c -o main.exe```
* После этого я написал программу на языке Python для генерации необходимого количества случайных чисел. Код программы приведен ниже:
    ```Python
    import random

    f = open('data.txt', 'w')
    f.write('1000\n')
    for i in range(1000):
        f.write(str(random.randint(-10000, 10000)) + " ")
    f.close
    ```
* Затем я запустил программу с перенаправленным вводом выводом:
```./main.exe < data.txt```
* Программа успешно вывела отсортированный массив
* Я экспортировал данные профилирования командой ```gprof main.exe > report```

1. Мои представления о времени работы совпали с тем, что я получил на практике. В отчете нет данных по функции main, это нет данных по данной фунции.
2. После увеличения массива до 10000 элементов в отчете появилась функция main.
    ```
    %   cumulative   self              self     total           
    time   seconds   seconds    calls  ps/call  ps/call  name    
    52.17      0.12     0.12                             _mcount_private
    26.09      0.18     0.06                             __fentry__
    17.39      0.22     0.04                             main
    4.35      0.23     0.01 25089968   398.57   398.57  swap


    index % time    self  children    called     name
                                                 <spontaneous>
    [1]     52.2    0.12    0.00                 _mcount_private [1]
    -----------------------------------------------
                                                 <spontaneous>
    [2]     26.1    0.06    0.00                 __fentry__ [2]
    -----------------------------------------------
                                                 <spontaneous>
    [3]     21.7    0.04    0.01                 main [3]
                   0.01    0.00 25089968/25089968     swap [4]
    -----------------------------------------------
                    0.01    0.00 25089968/25089968     main [3]
    [4]      4.3    0.01    0.00 25089968         swap [4]
    -----------------------------------------------
    ```
3. После уменьшения массива до 10 элементов пропали вспомогательные функции профилирования:
    ```
    Each sample counts as 0.01 seconds.
    no time accumulated

    %   cumulative   self              self     total           
    time   seconds   seconds    calls  Ts/call  Ts/call  name    
    0.00      0.00     0.00       24     0.00     0.00  swap


                Call graph (explanation follows)

    granularity: each sample hit covers 4 byte(s) no time propagated

    index % time    self  children    called     name
                    0.00    0.00      24/24          main [49]
    [1]      0.0    0.00    0.00      24         swap [1]
    -----------------------------------------------
    ```
4. Из отчета пропала функция swap, осталась только функция main. К сожаленю, никаких различий между различными ключами O не было замечено.