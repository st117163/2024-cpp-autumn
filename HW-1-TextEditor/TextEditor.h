#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>

class TextEditor {
    public:
    TextEditor();
    TextEditor(const TextEditor &other);
    ~TextEditor();
    void addText(const std::string text);
    int deleteText(int k);
    std::string cursorLeft(int k);
    std::string cursorRight(int k);
    int cursorShiftR(int k);

    friend std::ostream &operator<<(std::ostream &stream, const TextEditor &text_e);

    private:
    int _cursor;
    std::string _text;
};

#endif