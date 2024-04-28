g++ -o testgen testgen.cpp

./testgen    100      3 const > amb.01.in
./testgen  10000     12 const > amb.02.in
./testgen 100000     67 const > amb.03.in
./testgen 100000  10000 const > amb.04.in

./testgen 15 10 binary > amb.05.in
./testgen 20  3 binary > amb.06.in
./testgen 30 13 binary > amb.07.in

./testgen 20  3 normal > amb.08.in
./testgen 20  5 normal > amb.09.in
./testgen 20 16 normal > amb.10.in

./testgen 100 1 normal > amb.11.in
./testgen 100 2 normal > amb.12.in
./testgen 100 3 normal > amb.13.in

./testgen 0 0 restricted 1 > amb.14.in
./testgen 0 0 restricted 2 > amb.15.in
./testgen 0 0 restricted 3 > amb.16.in
./testgen 0 0 restricted 4 > amb.17.in
./testgen 0 0 restricted 5 > amb.18.in

./testgen 100000    300 normal > amb.19.in
./testgen 100000   8920 normal > amb.20.in
./testgen 100000     20 normal > amb.21.in
./testgen 100000  10000 normal > amb.22.in
./testgen 100000   2345 normal > amb.23.in

bash testsGen.sh
