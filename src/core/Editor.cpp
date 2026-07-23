#include "Editor.hpp"
#include <algorithm>
#include <iostream>

bool Editor::openFile(const std::string& path) {
    return m_buffer.open(path);
}

void Editor::moveLeft() {
    m_cursor.moveLeft();
}

void Editor::moveRight() {
    auto line =
        m_buffer.getLine(m_cursor.row());

    m_cursor.moveRight(line.size());
}

void Editor::moveUp() {
    m_cursor.moveUp();

    auto line =
        m_buffer.getLine(m_cursor.row());

    if (m_cursor.col() > line.size()) {
        while (m_cursor.col() > line.size()) {
            m_cursor.moveLeft();
        }
    }
}

void Editor::moveDown() {
    m_cursor.moveDown(
            m_buffer.lineCount());

    auto line = 
        m_buffer.getLine(m_cursor.row());

    while (m_cursor.col() > line.size()) {
        m_cursor.moveLeft();
    }
}

void Editor::render() const {

    std::cout << "\n";

    for (size_t row = 0;
         row < m_buffer.lineCount();
         ++row)
    {
        auto line =
            m_buffer.getLine(row);

        std::cout << line << '\n';

        if (row == m_cursor.row()) {

            for (size_t i = 0;
                 i < m_cursor.col();
                 ++i)
            {
                std::cout << ' ';
            }

            std::cout << "^\n";
        }
    }

    std::cout << '\n';

    std::cout << '\n';
    std::cout << "--------------------\n";


    switch (m_mode) {
        case Mode::Normal:
            std::cout << "NORMAL";
            break;

        case Mode::Insert:
            std::cout << " INSERT ";
            break;

        case Mode::Visual:
            std::cout << " VISUAL ";
            break;
    }
}

void Editor::clearScreen() const {
    std::cout << "\033[2J\033[H";
}


size_t Editor::cursorRow() const {
    return m_cursor.row();
}

size_t Editor::cursorCol() const {
    return m_cursor.col();
}

size_t Editor::lineCount() const {
    return m_buffer.lineCount();
}

Mode Editor::mode() const {
    return m_mode;
}

void Editor::setMode(Mode mode) {
    m_mode = mode;
}

void Editor::insertChar(char ch) {
    m_buffer.insertChar(
        m_cursor.row(),
        m_cursor.col(),
        ch
    );

    m_cursor.moveRight(
        m_buffer.getLine(
            m_cursor.row()
        ).size()
    );
}
