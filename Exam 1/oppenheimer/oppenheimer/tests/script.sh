g++ -o testgen testgen.cpp

./testgen 1000 500  900 1 > oppenheimer.01.in
./testgen 1000 250  250 2 > oppenheimer.02.in
./testgen 1000  69  789 3 > oppenheimer.03.in
./testgen 1000 777 1000 4 > oppenheimer.04.in
./testgen 1000 321  666 5 > oppenheimer.05.in

./testgen 100000 89899 100000 1 > oppenheimer.06.in
./testgen 100000 66699 100000 2 > oppenheimer.07.in
./testgen 100000     5      8 3 > oppenheimer.08.in
./testgen 100000   123  43221 4 > oppenheimer.09.in
./testgen 100000 32145 100000 5 > oppenheimer.10.in

bash testsGen.sh
