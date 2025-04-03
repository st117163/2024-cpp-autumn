#include <gtest/gtest.h>
#include "TextEditor.h"

TEST(TextEditorTest, AddText)
{
    TextEditor text;
    text.addText(" World!");
    text.addText("Hello,");// "*Hello, World!", * - позиция курсора
    std::string result = text.cursorRight(0); //"*Hello, World!", result = "Hello, World!"
    EXPECT_EQ(result, "Hello, World!");
    text.addText("");
    result = text.cursorRight(0);
    EXPECT_EQ(result, "Hello, World!");
}

TEST(TextEditorTest, DeleteText)
{
    TextEditor text;
    text.addText("Hello, World!");
    text.cursorRight(6);// "Hello,* World!"
    int deletedCount = text.deleteText(0);
    EXPECT_EQ(deletedCount, 0);
    deletedCount = text.deleteText(-1); // "Hello,* World!"
    EXPECT_EQ(deletedCount, 0);
    deletedCount = text.deleteText(5); // "H* World!"
    EXPECT_EQ(deletedCount, 5);
    deletedCount = text.deleteText(42); // "* World!"
    EXPECT_EQ(deletedCount, 1);
    std::string result = text.cursorLeft(-8); //" World!*", result = " World!"
    EXPECT_EQ(result, " World!");
}

TEST(TextEditorTest, CursorLeft) 
{
    TextEditor text;
    text.addText("Hello, World!");
    std::string result = text.cursorLeft(-13); //"Hello, World!*", result = "Hello, World!"
    EXPECT_EQ(result, "Hello, World!");
    result = text.cursorLeft(8); //"Hello*, World!", result = "Hello"
    EXPECT_EQ(result, "Hello");
    result = text.cursorLeft(0); //"Hello*, World!", result = "Hello"
    EXPECT_EQ(result, "Hello");
    result = text.cursorLeft(42); //"*Hello, World!", result = ""
    EXPECT_EQ(result, "");
    result = text.cursorLeft(-17); //"Hello, World!*", result = "Hello, World!"
    EXPECT_EQ(result, "Hello, World!");
}

TEST(TextEditorTest, CursorRight)
{
    TextEditor text;
    text.addText("Hello, World!");
    std::string result = text.cursorRight(13); //"Hello, World!*", result = ""
    EXPECT_EQ(result, "");
    result = text.cursorRight(-6); //"Hello*, World!", result = "World!"
    EXPECT_EQ(result, "World!");
    result = text.cursorRight(0); //"Hello*, World!", result = "World!"
    EXPECT_EQ(result, "World!");
    result = text.cursorRight(42); //"Hello, World!*", result = ""
    EXPECT_EQ(result, "");
    result = text.cursorRight(-17); //"*Hello, World!", result = "Hello, World!"
    EXPECT_EQ(result, "Hello, World!");
}

TEST(TextEditorTest, OutputTest) {
    TextEditor text;
    text.addText("Hello");
    testing::internal::CaptureStdout();
    std::cout << text << std::endl;
    text.cursorRight(5);
    text.addText(", World!");
    std::cout << text << std::endl;
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "Hello\nHello, World!\n");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv); // Инициализация Google Test
    return RUN_ALL_TESTS(); // Запуск всех тестов
}