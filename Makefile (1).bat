@echo off

set caminho=%cd%

gcc "%caminho%"\src\main.c -o "%caminho%"\src\main


for /l %%x in (0, 1, 3) do (

"%caminho%"\src\main < "%caminho%"\tests\test0%%x.in > "%caminho%"\tests\test0%%x.test
 
fc "%caminho%"\tests\test0%%x.out  "%caminho%"\tests\test0%%x.test >NUL && Echo Teste 0%%x passou || Echo Teste 0%%x diferente

del "%caminho%"\tests\test0%%x.test

)

pause