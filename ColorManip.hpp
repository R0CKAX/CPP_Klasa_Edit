#ifndef _COLOR_MANIP_HPP_
#define _COLOR_MANIP_HPP_

#include <iostream>
#include <Windows.h>

class ColorManip {
private:
    WORD attributes;

public:
    /// <summary>
    /// A set of manipulators used to change the color of text and/or background for the output stream
    /// </summary>
    /// <param name="attributes"> Variable responsible for containing the color parameters </param>

    // Constructor that initizalizes the value of attributes variable used for defining the text/background color
    ColorManip(WORD attributes);

    // operator overload used whenever we use () marks that sets the text and/or background color to a set value
    std::ostream& operator()(std::ostream& out) const;

    // Operator overload that transfers the output to the output stream
    friend std::ostream& operator<<(std::ostream& out, const ColorManip& color);
};

// Method used for setting the color to a set value using FOREGROUND and/or BACKGROUND system defined values
ColorManip setColor(WORD attributes);

// Manipulators used to dynamically change the text color in the output stream
std::ostream& black(std::ostream& out);
std::ostream& blue(std::ostream& out);
std::ostream& green(std::ostream& out);
std::ostream& cyan(std::ostream& out);
std::ostream& red(std::ostream& out);
std::ostream& magenta(std::ostream& out);
std::ostream& yellow(std::ostream& out);
std::ostream& defcolor(std::ostream& out);
std::ostream& gray(std::ostream& out);
std::ostream& lblue(std::ostream& out);
std::ostream& lgreen(std::ostream& out);
std::ostream& lcyan(std::ostream& out);
std::ostream& lred(std::ostream& out);
std::ostream& lmagenta(std::ostream& out);
std::ostream& lyellow(std::ostream& out);
std::ostream& lwhite(std::ostream& out);

#endif // _COLOR_MANIP_HPP_