#!/bin/bash

# Lista de algoritmos e diretórios de teste
algorithms=("bubble_sort" "insert_sort" "select_sort" "shaker_sort")
test_dirs=("nearly_sorted" "reverse_sorted" "sorted" "unif_rand")

# Compilação dos algoritmos com o cliente
for algo in "${algorithms[@]}"; do
    gcc -o "$algo" client.c "$algo.c"
done

# Criação de um diretório para salvar os resultados
mkdir -p resultados

# Loop pelos algoritmos e casos de teste
for algo in "${algorithms[@]}"; do
    for dir in "${test_dirs[@]}"; do
        for test_case in "../in/$dir"/*.txt; do
            test_name=$(basename "$test_case" .txt)
            echo "Executando $algo com $dir/$test_name"
            
            # Execução e redirecionamento dos resultados
            ./"$algo" $(wc -l < "$test_case") < "$test_case" > "resultados/${algo}_${dir}_${test_name}.out"
        done
    done
done

echo "Todos os testes foram executados. Resultados em ./resultados/"
