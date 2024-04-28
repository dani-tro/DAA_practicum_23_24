g++ -o my_sol my_sol.cpp
g++ -o slow_sol slow_sol.cpp
g++ -o gen gen.cpp
for(( ; ; )) do
	echo $i
	./gen 10 3 10 > test
	./my_sol < test > my_out
	./slow_sol < test > slow_out
	diff -w my_out slow_out || break
done
