#!/bin/bash

echo "Začenjam testiranje..."

# Primer simuliranega testa:
if [ -f main.cpp ]; then
    echo "✅ main.cpp obstaja"
    exit 0
else
    echo "❌ main.cpp manjka"
    echo "main.cpp manjka" > napaka.txt
    exit 1
fi
