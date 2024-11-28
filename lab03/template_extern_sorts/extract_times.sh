#!/bin/bash

# Arquivo de saída consolidado
output_file="resultados/consolidated_times.txt"

# Limpa ou cria o arquivo de saída
> "$output_file"

# Loop pelos arquivos .out na pasta resultados
for out_file in resultados/*.out; do
    # Extrai a linha com o tempo de execução (Elapsed time)
    elapsed_time=$(grep "Elapsed time" "$out_file")
    
    # Formata a saída: Nome do arquivo + tempo
    echo "$(basename "$out_file"): $elapsed_time" >> "$output_file"
done

echo "Consolidação concluída. Resultados em $output_file"
