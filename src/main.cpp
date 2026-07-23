#include <iostream>
#include "core/Buffer.hpp"
#include "core/Cursor.hpp"
#include "core/Editor.hpp"
#include "core/Terminal.hpp"
#include "core/Input.hpp"


int main() {
    Editor editor;

    if (!editor.openFile("test.txt")) {
        std::cout << "no se puede abrir\n";
        return 1;
    }

    Terminal::enableRawMode();
    std::cout << "RAW ACTIVADO\n";

    char key;

    editor.setMode(Mode::Normal);

    while (true) {
        editor.clearScreen();
        editor.render();

       
        key = getchar();

        if (!Input::handleKey(
                editor,
                key))
        {
            Terminal::disableRawMode();
            return 0;
        }
    }
}
