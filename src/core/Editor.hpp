#pragma once

#include "Buffer.hpp"
#include "Cursor.hpp"
#include "Mode.hpp"

#include <string>

class Editor {
    public:
        bool openFile(const std::string& path);

        void moveLeft();
        void moveRight();

        void moveUp();
        void moveDown();

        void render() const;

        void clearScreen() const;

        size_t cursorRow() const;
        size_t cursorCol() const;

        size_t lineCount() const;

        Mode mode() const;

        void setMode(Mode mode);

        void insertChar(char ch);

        void deleteChar();
        
    private:
        Buffer m_buffer;
        Cursor m_cursor;
        Mode m_mode = Mode::Normal;
};


