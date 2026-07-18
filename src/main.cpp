#include <iostream>
#include "core/Buffer.hpp"
#include "core/Cursor.hpp"
#include "core/Editor.hpp"

int main() {
    Editor editor;

    bool opened = editor.openFile("test.txt");

    std::cout << "Archivo Abierto: " << opened << '\n';
    std::cout << "Lineas: " << editor.lineCount() << '\n';

    editor.moveRight();
    editor.moveRight();

    std::cout << "Fila: " << editor.cursorRow() << '\n';

    std::cout << "Columna: " << editor.cursorCol() << '\n';

    return 0;
}
