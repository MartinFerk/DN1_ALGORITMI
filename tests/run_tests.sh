#!/bin/bash

echo "🔧 Test 1: Prevajanje main.cpp"
g++ main.cpp -o program
if [ $? -ne 0 ]; then
    echo "Napaka pri prevajanju!" > napaka.txt
    exit 1
fi

echo "✅ Test 2: Zagon programa"
./program

echo "✅ Vsi testi uspešni."
exit 0

