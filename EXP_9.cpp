#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main()
{
	char str[200];
	int i, line, word, ch;
	line = word = ch = 0;

	cout << "Enter a string in multiple lines :\n";
	fgets(str, 200, stdin);
	str[strcspn(str, "\n")] = 0;

	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == '.' || str[i] == '?' || str[i] == '!')
		{
			line++;
		}
		else
		{
			if(str[i] == ' ')
			{
				word++;
			}
		}
		ch++;
	}

	cout << "\nCharacter counts = " << ch;
	cout << "\nWord counts = " << word + 1;
	cout << "\nLine counts = " << line;

	return 0;
}
