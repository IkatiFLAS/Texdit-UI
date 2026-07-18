#pragma once

#include <string>
#include <vector>

class Buffer {
public:
    bool open(const std::string& path);
    bool save(const std::string& path);

    std::string getLine(size_t row) const;
    size_t lineCount() const;

private:
    std::vector<std::string> lines;
};
