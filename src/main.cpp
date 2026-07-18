#include <iostream>
#include "core/Buffer.hpp"
#include "core/Cursor.hpp"
#include "core/Editor.hpp"

int main() {
//    Buffer buffer;
//
//    if(!buffer.open("test.txt")) {
//        std::cout << "No se puede abrir el archivo\n";
//        return 1;
//    }
//
//    for (size_t i = 0; i < buffer.lineCount(); i++) {
//        std::cout << buffer.getLine(i) << '\n';
//    }
//
//    Cursor cursor;
//    cursor.moveRight(100);
//    cursor.moveRight(100);
//    cursor.moveRight(100);
//
//    cursor.moveDown(20);
//
//    std::cout << "row: " << cursor.row() << '\n';
//    std::cout << "col: " << cursor.col() << '\n';

    Editor editor;

    editor.openFile("test.txt");

    editor.moveRight();
    editor.moveRight();

    bool opened = editor.openFile("test.txt");


    std::cout << "Fila: "
              << editor.cursorRow()
              << '\n';

    std::cout << "Columna: "
              << editor.cursorCol()
              << '\n';

    return 0;
}
