#ifndef _EDIT_HPP_
#define _EDIT_HPP_

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

class Edit
{
private:
	std::string content;
	int length, col, row, colorVal;
	
public:
	/// <summary>
	/// Creates text area on set position and set length for user to write in, 
	/// allows for background color and text color customization
	/// </summary>
	/// <param name="content"> A comment put it by the user outside the text area </param>
	/// <param name="length"> The length of a text area </param>
	/// <param name="col"> Starting column for a text area to appear in </param>
	/// <param name="row"> Starting row for a text area to appear in </param>
	/// <param name="colorVal"> The color value of background color and text color combined </param>
	/// <param name="Colors"> List of all possible colors (background and text) available for user to choose </param>

	enum Colors
	{
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Yellow = 6,
		White = 7,
		Gray = 8,
		LBlue = 9,
		LGreen = 10,
		LCyan = 11,
		LRed = 12,
		LMagenta = 13,
		LYellow = 14,
		LWhite = 15
	};

	// Basic constructor, sets default values for all object's variables
	Edit();

	// Copying constructor that copies all object's values from one to another
	Edit(const Edit& rhs);

	// Method that defines starting position of a text area (sets the value of col and row variables)
	void setPosition(int mCol, int mRow);

	// Method that sets the length of a text area
	void setLength(int mLength);

	// Method that allows user to put in whatever comment they want inside comment variable
	void setText(std::string mText);

	// Method that prints out the comment
	std::string getText();

	// Method that creates a text area with specific parameters set by user,
	// When the text area reaches its max capacity it will automatically expand as the user will input the characters
	// When user clicks Page Down button it will create a new, fresh text area that contains 
	// the last character used (if anything has been put in) by user in the previous text area. 
	// The method stops receiving input when user click the Escape button
	void userText();

	// Method that sets the value responsible for text color in the text area
	void setTextColor(Colors color);

	// Method that sets the value responsible for background color in the text area
	void setBackgroundColor(Colors color);
};

#endif // _EDIT_HPP_