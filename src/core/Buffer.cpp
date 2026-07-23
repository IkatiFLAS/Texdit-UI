#include "Buffer.hpp"

#include <fstream>

bool Buffer::open(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open())
        return false;

    lines.clear();

    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return true;
}

bool Buffer::save(const std::string& path) {
    std::ofstream file(path);

    if (!file.is_open())
        return false;

    for (const auto& line : lines)
        file << line << '\n';

    return true;
}

std::string Buffer::getLine(size_t row) const {
    if (row >= lines.size())
        return "";

    return lines[row];
}

size_t Buffer::lineCount() const {
    return lines.size();
}

void Buffer::insertChar(
    size_t row,
    size_t col,
    char ch
){
    if (row >= lines.size())
        return;

    if (col > lines[row].size())
        return;

    lines[row].insert(
        lines[row].begin() + col,
        ch
    );
}

void Buffer::deleteChar(
    size_t row,
    size_t col
) {
    if (row >= lines.size())
        return;

    if (col == 0)
        return;

    if (col > lines[row].size())
        return;

    lines[row].erase(col - 1, 1);
}
