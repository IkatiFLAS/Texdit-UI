#include "Cursor.hpp"
#include <iostream>

void Cursor::moveLeft(){
    if (m_col > 0)
        --m_col;
}

void Cursor::moveRight(size_t lineLength) {
    if (m_col < lineLength)
        ++m_col;
}

void Cursor::moveUp() {
    if (m_row > 0)
        --m_row;
}

void Cursor::moveDown(size_t maxLines) {
    if (m_row + 1 < maxLines)
        ++m_row;
}

size_t Cursor::row() const {
    return m_row;
}

size_t Cursor::col() const {
    return m_col;
}
