#pragma once

#include "Buffer.hpp"
#include "Cursor.hpp"

#include <string>

class Editor {
    public:
        bool openFile(const std::string& path);

        void moveLeft();
        void moveRight();

        void moveUp();
        void moveDown();

        void render() const;

        size_t cursorRow() const;
        size_t cursorCol() const;

        size_t lineCount() const;
        
    private:
        Buffer m_buffer;
        Cursor m_cursor;
};


