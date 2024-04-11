#include "Edit.hpp"

Edit::Edit()
{
	content = "default text";
	colorVal = 0;
	length = 5;
	col = 0;
	row = 0;
}

Edit::Edit(const Edit& rhs)
{
	this->content = rhs.content;
	this->length = rhs.length;
	this->row = rhs.row;
	this->col = rhs.col;
	this->colorVal = rhs.colorVal;
}

void Edit::setPosition(int mCol, int mRow)
{
	col = mCol;
	row = mRow;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos;
	cursorPos.X = col;
	cursorPos.Y = row;
	
	SetConsoleCursorPosition(console, cursorPos);
}

void Edit::setLength(int mLength)
{
	length = mLength;
}

void Edit::setText(std::string mText)
{
	content = mText;
}

std::string Edit::getText()
{
	return content;
}

void Edit::userText()
{
	int mLength = length;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos;
	cursorPos.X = col;
	cursorPos.Y = row;
	char last = NULL;
	SetConsoleTextAttribute(console, colorVal);

	for (int i = 0; i < length; i++)
	{
		SetConsoleCursorPosition(console, cursorPos);
		std::cout << " ";
		cursorPos.X++;
	}

	int character = 0;
	int counter = 0;
	cursorPos.X = col;
	cursorPos.Y = row;
	SetConsoleCursorPosition(console, cursorPos);

	while (char(character) != 27)
	{
		character = _getch();

		if (char(character) == 'à')
		{
			char secondChar = _getch();

			if (secondChar == 81)
			{
				SetConsoleTextAttribute(console, 7);
				mLength = length;
				counter = 0;
				cursorPos.X = col;
				cursorPos.Y = row;
				system("cls");
				SetConsoleTextAttribute(console, colorVal);

				for (int i = 0; i < length; i++)
				{
					SetConsoleCursorPosition(console, cursorPos);
					std::cout << " ";
					cursorPos.X++;
				}

				cursorPos.X = col;
				cursorPos.Y = row;

				if (last != NULL)
				{
					SetConsoleCursorPosition(console, cursorPos);
					std::cout << char(last);
					cursorPos.X++;
				}
				else
				{
					SetConsoleCursorPosition(console, cursorPos);
				}
			}
		}
		else
		{
			last = character;
			std::cout << char(character);
			cursorPos.X++;
			counter++;
			if (counter == mLength)
			{
				cursorPos.X++;
				mLength++;
				std::cout << " ";
				cursorPos.X--;
				SetConsoleCursorPosition(console, cursorPos);
			}
			else
			{
				SetConsoleCursorPosition(console, cursorPos);
			}
		}
	}
	SetConsoleTextAttribute(console, 7);
	std::cout << "\n";
}

void Edit::setTextColor(Colors color)
{
	colorVal += color;
}

void Edit::setBackgroundColor(Colors color)
{
	colorVal += (color * 16);
}