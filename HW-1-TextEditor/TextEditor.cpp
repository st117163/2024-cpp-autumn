#include "TextEditor.h"

TextEditor::TextEditor() : _cursor(0), _text("") {}

TextEditor::TextEditor(const TextEditor &other)
{
    _cursor = other._cursor;
    _text = other._text;
}

TextEditor::~TextEditor()
{
}

void TextEditor::addText(std::string text)
{
    _text.insert(_cursor, text);
}

int TextEditor::deleteText(int k)
{
    if (_cursor == 0 || k <= 0)
	{
		return 0;
	}
	if (_cursor < k)
	{
		_text.erase(0, _cursor);
        int temp = 0;
		temp = _cursor;
		_cursor = 0;
		return temp;
	}
	_text.erase(_cursor - k, k);
	_cursor -= k;
	return k;
}

int TextEditor::cursorShiftR(int k)// сдвигает курсор (вправо, если k>=0; влево, если k<0) и передает новую позицию курсора
{
    if (_cursor + k < 0)
    {
         _cursor = 0;
        return _cursor;
    }
    if (_cursor + k > _text.length())
    {
         _cursor = _text.length();
        return _cursor;
    }
    _cursor += k;
    return _cursor;
}

std::string TextEditor::cursorLeft(int k)
{
    cursorShiftR(-k);
	return _text.substr(0, _cursor);
}

std::string TextEditor::cursorRight(int k)
{
    cursorShiftR(k);
	return _text.substr(_cursor, _text.length() - _cursor);
}

std::ostream& operator<<(std::ostream& stream,const TextEditor& text_e)
{
	stream << text_e._text;
	return stream;
}