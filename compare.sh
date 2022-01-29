#!/bin/bash

cd robotcar
sourceFiles=$(ls *.cpp *.h)

for f in ${sourceFiles}; do
	echo "============ " $f " ============"
	diff $f ../../arduino/robotcar/$f
done
