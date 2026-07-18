#include "Buffer.hpp"

#include <fstream>

bool Buffer::open(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open())
        return false;

    lines.clear();

    std::string line;

    while (std::getline(file, line))
        lines.push_back(line);

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
