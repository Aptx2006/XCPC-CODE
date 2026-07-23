g++ -std=c++17 -O2 data.cpp -o gx
./gx  > $2.in
./run.sh $1 $2
cat out.txt
