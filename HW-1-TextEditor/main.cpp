#include"TextEditor.h"

int main(int argc, char* argv[])
{
	TextEditor text;

    //Добавим текст Hello, World!
	text.addText("Hello, World!");
	std::cout << text << '\n';

    //Передвинем курсор вправо на 5
	std::cout << text.cursorRight(5) << '\n';

    //Удалим 5 символов
	std::cout << text.deleteText(5) << '\n';
	std::cout << text << '\n';

    //Сдвинем курсор влево на -1
	std::cout << text.cursorLeft(-1) << '\n';

    //Сдвинем курсор влево на 2
	std::cout << text.cursorLeft(2) << '\n';

    //Сдвинем вправо на 1
    std::cout << text.cursorRight(1) << '\n';

    //Сдвинем вправо на -2
	std::cout << text.cursorRight(-1) << '\n';

    //Удалим 5 символов
	std::cout << text.deleteText(5) << '\n';
	std::cout << text << '\n';

    //Добавим текст
	text.addText("Goodbye");
	std::cout << text << '\n';

	return EXIT_SUCCESS;
}