#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cctype>

struct Column {
    std::string name;
    std::vector<std::string> values;
    bool is_numeric;
};

class Dataset {
public:
    // Основной конструктор с указанием разделителя
    Dataset(const std::string& file_path, 
            char delimiter = '\t',  // По умолчанию табуляция
            bool has_header = true, 
            bool has_index = true,
            const std::vector<std::string>& custom_col_names = {});

    // Вывод первых n строк (по умолчанию 5)
    void head(int n = 5) const;
    
    // Вывод последних n строк (по умолчанию 5)
    void tail(int n = 5) const;
    
    // Вставка новой строки по индексу
    void insert(size_t index, const std::vector<std::string>& row);
    
    // Удаление строки по индексу
    void remove(size_t index);
    
    // Статистика по указанному столбцу
    void describe(const std::string& column_name) const;
    
    // Доступ к строке по индексу
    std::vector<std::string> operator[](size_t index) const;
    
    // Получение количества строк
    size_t get_size() const { return size; }
    // Получение названия столбца по индексу
    std::string get_column_name(size_t index) const { return data[index].name; }

private:
    std::vector<Column> data;
    size_t size;
    

    // Чтение файла
    void read_file(const std::string& file_path, char delimiter, bool has_header, bool has_index);
    
    // Конвертация строки в число
    double to_double(const std::string& s) const;
    

    // Разбиение строки
    std::vector<std::string> split(std::string line, char delimiter);
};

#endif // DATASET_H