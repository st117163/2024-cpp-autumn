#include <gtest/gtest.h>
#include "Dataset.h"

// Тест 1: Чтение файла с разделителем "|", заголовком и индексом
TEST(DatasetTest, ReadPipeDelimitedWithHeader) {
    Dataset ds("mixed_data.txt", '|', true, false);
    
    EXPECT_EQ(ds.get_size(), 2 * 4); // 2 строки данных, 4 колонки

    // Проверка названий столбцов
    EXPECT_EQ(ds[0][0], "1"); // Первая строка данных
    EXPECT_EQ(ds[0][1], "Books");
    EXPECT_EQ(ds[0][2], "4.5");
    EXPECT_EQ(ds[0][3], "Yes");
}

// Тест 2: Чтение CSV без заголовка с автоматическими именами
TEST(DatasetTest, ReadNoHeaderWithAutoNames) {
    Dataset ds("no_header.csv", ',', false, true);
    
    EXPECT_EQ(ds.get_column_name(1), "col1");
    EXPECT_EQ(ds[1][2], "");      // Пустая ячейка
}

// Тест 3: Проверка табуляции и числовых данных
TEST(DatasetTest, TabDelimitedWithNumericCheck) {
    Dataset ds("products.txt", '\t', true, false);
    
    // Проверка статистики для цены
    testing::internal::CaptureStdout();
    ds.describe("price");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Mean:     799.99") != std::string::npos);
}

// Тест 4: Вставка и удаление строк
TEST(DatasetTest, InsertAndRemoveRows) {
    Dataset ds("simple_data.csv", ',', true, true);
    
    // Исходный размер
    size_t original_size = ds.get_size();
    
    // Вставка новой строки
    ds.insert(1, {"Olga", "25", "48000"});
    EXPECT_EQ(ds.get_size(), original_size + 3); // 3 новых значения (id уже есть)
    
    // Удаление строки
    ds.remove(0);
    EXPECT_EQ(ds[0][0], "Olga"); // Проверка, что первая строка изменилась
}

// Тест 5: Обработка ошибок
TEST(DatasetTest, ErrorHandling) {
    // Несуществующий файл
    EXPECT_THROW(Dataset("ghost_file.txt", '\t'), std::runtime_error);
    
    // Неверное количество столбцов при вставке
    Dataset ds("mixed_data.txt", '|', true, false);
    EXPECT_THROW(ds.insert(0, {"Extra", "Data"}), std::runtime_error);
}

// Тест 6: Проверка оператора доступа
TEST(DatasetTest, AccessOperator) {
    Dataset ds("simple_data.csv", ',', true, true);
    
    std::vector<std::string> first_row = ds[0];
    EXPECT_EQ(first_row[0], "Ivan");
    EXPECT_EQ(first_row[1], "28");
    EXPECT_EQ(first_row[2], "50000");
}

// Тест 7: Кастомные имена столбцов
TEST(DatasetTest, CustomColumnNames) {
    Dataset ds(
        "no_header.csv", 
        ',', 
        false, 
        true, 
        {"Product", "Price", "Stock"}
    );
    
    testing::internal::CaptureStdout();
    ds.head(1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Product") != std::string::npos);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}