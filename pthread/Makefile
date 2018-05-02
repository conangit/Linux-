app1 = p_tid.elf
app1_src = p_tid.c
app2 = p_exit.elf
app2_src = p_exit.c
app3 = p_mutex.elf
app3_src = p_mutex.c


all:
	gcc $(app1_src) -o $(app1) -lpthread 
	gcc $(app2_src) -o $(app2) -lpthread
	gcc $(app3_src) -o $(app3) -lpthread


clean:
	rm -rf $(app1) $(app2) $(app3) 
