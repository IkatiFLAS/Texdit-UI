#pragma once

class Editor;

class Input {
    public:
        static bool handleKey(
            Editor& editor,
            char key
        );
};
