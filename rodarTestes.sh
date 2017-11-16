#!/bin/bash

echo 'Iniciando Testes...'
g++ src/testes.cpp src/realiza_jogadas.cpp -o testes ; 
./testes;
