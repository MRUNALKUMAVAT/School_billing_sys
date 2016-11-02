project: nn.o a.o


nn.o : nn.c nn.h
      	 cc -c nn.c -Wall

a.o : a.c a.h
	cc -c a.c -Wall	

	
