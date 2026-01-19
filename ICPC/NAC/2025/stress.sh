g++ -std=c++20 -O2 gen.cpp -o gen
g++ -std=c++20 -O2 bad.cpp -o bad
g++ -std=c++20 -O2 good.cpp -o good

for i in `seq 1 10000`; do
    echo $i
    ./gen >input.txt
    ./bad <input.txt >bad_output.txt
    ./good <input.txt >good_output.txt

    diff bad_output.txt good_output.txt || break
done