CC = gcc
CFLAG = -Wall
TARGET = us
OBJS = us1.o us2.o us3.o us4.o
LIBS = wiringPi`

us : us1.o us2.o us3.o us4.o
	gcc -o us us1.o us2.o us3.o us4.o -lwiringPi

us1.o : PWM.c
	gcc -c -o us1.o PWM.c
us2.o : Sound.c
	gcc -c -o us2.o Sound.c
us3.o : Trigger.c
	gcc -c -o us3.o Trigger.c
us4.o: Car.c
	gcc -c -o us4.o Car.c


d : 
	rm -f *.o

