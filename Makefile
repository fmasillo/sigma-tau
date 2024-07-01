all: hp hc hp_prime


hp:
	gcc -O3 hp.c -o hp

hc:
	gcc -O3 hc.c -o hc

hp_prime:
	gcc -O3 hp_prime.c -o hp_prime
