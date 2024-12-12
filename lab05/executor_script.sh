#!/bin/bash

# Define directories and output file
INPUT_DIR="input"
OUTPUT_FILE="resultados.txt"
EXECUTABLES=(merge_1 merge_2 merge_3 merge_4 merge_5 merge_6 merge_7)

# Clear the output file
> "$OUTPUT_FILE"

# Loop through each executable
for exe in "${EXECUTABLES[@]}"; do
    # Check if the executable exists
    if [ ! -f "$exe" ]; then
        echo "Executável $exe não encontrado. Ignorando..." >> "$OUTPUT_FILE"
        continue
    fi

    # Loop through each folder in the input directory
    for folder in "$INPUT_DIR"/*; do
        if [ -d "$folder" ]; then
            folder_name=$(basename "$folder")

            # Loop through each file in the folder
            for file in "$folder"/*.txt; do
                if [ -f "$file" ]; then
                    file_name=$(basename "$file")

                    # Execute the program and capture the time
                    ./$exe "$file"

                    # Append the results to the output file
                    if [ -f "temp_result.txt" ]; then
                        time=$(cat temp_result.txt)
                        echo "$exe, $folder_name/$file_name, $time" >> "$OUTPUT_FILE"
                        rm temp_result.txt
                    else
                        echo "$exe, $folder_name/$file_name, Erro ao capturar o tempo" >> "$OUTPUT_FILE"
                    fi
                fi
            done
        fi
    done

done