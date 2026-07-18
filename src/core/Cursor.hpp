#pragma once

#include <cstddef>

class Cursor {
    public:
        void moveLeft();
        void moveRight(size_t lineLength);

        void moveUp();
        void moveDown(size_t maxLines);

        size_t row() const;
        size_t col() const;

    private:
        size_t m_row = 0;
        size_t m_col = 0;
};
