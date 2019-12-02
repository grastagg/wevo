#!/bin/bash

cmake -DCMAKE_BUILD_TYPE=Release ..
make

timestamp=$(date -d "today" +"%Y%m%d%H%M%S")
inputs="./inputs-$timestamp"
results="results-$timestamp.csv"
echo "size,runtime,oltime,evtime,coll-evs,dom-evs,edge-evs,inv-coll-evs,inv-dom-evs,inv-edge-evs" > "$results"
mkdir "$inputs"

for i in {8..15}; do
	lower=$((2 ** $i))
	upper=$((2 ** ($i + 1)))
	python gen_inputs.py -n 50 -l "$lower" -u "$upper" -f "$inputs"
done

for entry in "$inputs"/*.pnts; do
	./mwvd --input-file "$entry" --csv-file "$results"
done
