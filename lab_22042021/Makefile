# this will create a calk elf

calk_elf: calc_main.o calc_sum.o
	
	@gcc calc_main.o calc_sum.o  -o calk -pthread

calc_main.o: calc_main.c
	
	@gcc -c calc_main.c -o calc_main.o 

calc_sum.o: calc_sum.c
	
	@gcc -c calc_sum.c -o calc_sum.o 
