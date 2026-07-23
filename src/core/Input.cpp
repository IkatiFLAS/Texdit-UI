#include "Input.hpp"
#include "Editor.hpp"

bool Input::handleKey(
    Editor& editor,
    char key
) {

    if (editor.mode() == Mode::Insert) {
        if (key == 27) {
            editor.setMode(
                Mode::Normal
            );
            return true;
        }

    editor.insertChar(key);
    return true;
    }


    switch (key) {
        case 'h':
            editor.moveLeft();
            break;
        
        case 'j':
            editor.moveDown();
            break;

        case 'k':
            editor.moveUp();
            break;

        case 'l':
            editor.moveRight();
            break;

        case 'i':
            editor.setMode(Mode::Insert);
            break;

        case 'v':
            editor.setMode(Mode::Visual);
            break;

        case 'n':
            editor.setMode(Mode::Normal);
            break;

        case 'q':
            return false;
    }

    return true;
}
