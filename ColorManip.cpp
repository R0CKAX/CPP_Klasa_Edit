#include "ColorManip.hpp"

ColorManip::ColorManip(WORD attributes) : attributes(attributes) {}

std::ostream& ColorManip::operator()(std::ostream& out) const {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, attributes);
    return out;
}

std::ostream& operator<<(std::ostream& out, const ColorManip& color) {
    return color(out);
}

ColorManip setColor(WORD attributes) {
    return ColorManip(attributes);
}

std::ostream& black(std::ostream& out) { return out << setColor(0); }
std::ostream& blue(std::ostream& out) { return out << setColor(FOREGROUND_BLUE); }
std::ostream& green(std::ostream& out) { return out << setColor(FOREGROUND_GREEN); }
std::ostream& cyan(std::ostream& out) { return out << setColor(FOREGROUND_GREEN | FOREGROUND_BLUE); }
std::ostream& red(std::ostream& out) { return out << setColor(FOREGROUND_RED); }
std::ostream& magenta(std::ostream& out) { return out << setColor(FOREGROUND_RED | FOREGROUND_BLUE); }
std::ostream& yellow(std::ostream& out) { return out << setColor(FOREGROUND_RED | FOREGROUND_GREEN); }
std::ostream& defcolor(std::ostream& out) { return out << setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); }
std::ostream& gray(std::ostream& out) { return out << setColor(FOREGROUND_INTENSITY); }
std::ostream& lblue(std::ostream& out) { return out << setColor(FOREGROUND_INTENSITY | FOREGROUND_BLUE); }
std::ostream& lgreen(std::ostream& out) { return out << setColor(FOREGROUND_INTENSITY | FOREGROUND_GREEN); }
std::ostream& lcyan(std::ostream& out) { return out << setColor(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); }
std::ostream& lred(std::ostream& out) { return out << setColor(FOREGROUND_INTENSITY | FOREGROUND_RED); }
std::ostream& lmagenta(std::ostream& out) { return out << setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE); }
std::ostream& lyellow(std::ostream& out) { return out << setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); }
std::ostream& lwhite(std::ostream& out) { return out << setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); }