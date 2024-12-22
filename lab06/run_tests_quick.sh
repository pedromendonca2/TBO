#!/bin/bash

# Diretórios de entrada e saída
INPUT_DIR="input"
OUTPUT_FILE="resultados.txt"
TIMEOUT_LIMIT=30 # Tempo limite em segundos para a execução de cada programa

# Limpa o arquivo de resultados anterior
> "$OUTPUT_FILE"

# Compila os executáveis (assumindo que o Makefile já está configurado)
make || { echo "Erro ao compilar os executáveis."; exit 1; }

# Executa cada executável para arquivos específicos de entrada
for exec in quick_{1..7}; do
    if [ ! -f "$exec" ]; then
        echo "Executável $exec não encontrado. Ignorando..." >> "$OUTPUT_FILE"
        continue
    fi

    echo "Resultados para $exec:" >> "$OUTPUT_FILE"
    for dir in "$INPUT_DIR"/*; do
        if [[ "$dir" == *"few_uniq"* ]]; then
            continue
        fi
        for input_file in "$dir"/100000.txt "$dir"/1000000.txt "$dir"/10000000.txt; do
            if [ -f "$input_file" ]; then
                echo "Executando $exec com $input_file..."
                
                # Executa o programa com limite de tempo
                timeout $TIMEOUT_LIMIT ./$exec "$input_file"
                exit_status=$?

                if [ $exit_status -eq 124 ]; then
                    # Timeout
                    echo "$(basename "$dir")/$(basename "$input_file"): Timeout após $TIMEOUT_LIMIT segundos" >> "$OUTPUT_FILE"
                elif [ $exit_status -ne 0 ]; then
                    # Outro erro
                    echo "$(basename "$dir")/$(basename "$input_file"): Erro de execução (status $exit_status)" >> "$OUTPUT_FILE"
                else
                    # Recupera o tempo do arquivo temporário e adiciona ao arquivo de resultados
                    if [ -f temp_result.txt ]; then
                        time_taken=$(cat temp_result.txt)
                        echo "$(basename "$dir")/$(basename "$input_file"): $time_taken segundos" >> "$OUTPUT_FILE"
                        rm -f temp_result.txt
                    else
                        echo "Erro: Arquivo temp_result.txt não encontrado para $(basename "$dir")/$(basename "$input_file")" >> "$OUTPUT_FILE"
                    fi
                fi
            else
                echo "Arquivo $(basename "$dir")/$(basename "$input_file") não encontrado." >> "$OUTPUT_FILE"
            fi
        done
    done
    echo "" >> "$OUTPUT_FILE"
done

# Limpa os arquivos temporários
echo "Removendo arquivos auxiliares..."
make clean

echo "Execução concluída. Resultados em $OUTPUT_FILE."