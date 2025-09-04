#!/bin/bash

g++ testi.cpp -o testi
g++ i.cpp -o i 
g++ brutei.cpp -o brutei 
g++ icheck.cpp -o icheck



for (( i = 0; i < 65536; i+=1)) do
	echo "" > bruteout
	echo "" > out 
	echo "" > gen
	./testi $i >> gen

	./i < gen >> out
	./brutei < gen >> bruteout

	di=$(diff ./bruteout ./out)
	if [ -n "$di" ]; then
		echo "" > genout
		cat gen >> genout
		cat out >> genout
		isbad=$(./icheck < genout)
 		if [ "$isbad" != "" ]; then
			echo $isbad
			echo $i
			echo "gen:" 
			cat gen
			echo "normal:" 
			cat out
			echo "brute:" 
			cat bruteout
			break
		fi
	fi
	echo $i
done

echo "" > genout 
