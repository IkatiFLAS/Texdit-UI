#pragma once

#include <string>
#include <vector>

class Buffer {
public:
    bool open(const std::string& path);
    bool save(const std::string& path);

    std::string getLine(size_t row) const;
    size_t lineCount() const;

    void insertChar(
        size_t row,
        size_t col,
        char ch
    );

    void deleteChar(
        size_t row,
        size_t col
    );

private:
    std::vector<std::string> lines;
};
