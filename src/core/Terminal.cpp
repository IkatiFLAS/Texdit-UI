#include "Terminal.hpp"

#include <termios.h>
#include <unistd.h>

static struct termios original;

void Terminal::enableRawMode() {

    tcgetattr(STDIN_FILENO, &original);

    struct termios raw = original;

    raw.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(
        STDIN_FILENO,
        TCSAFLUSH,
        &raw
    );
}

void Terminal::disableRawMode() {

    tcsetattr(
        STDIN_FILENO,
        TCSAFLUSH,
        &original
    );
}
