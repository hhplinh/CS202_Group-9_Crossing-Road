#include <ScreenMenu.hpp>

bool ScreenMenu::checkStrEng(std::string &str)
{
	int length = str.size();
	if (length > 100 || length == 0)
		return false;

	for (char &c : str)
		if (c >= 'A' && c <= 'Z')
			c += 'a' - 'A';

	for (int j = 0; j < length; ++j)
		if (str[j] < 'a' || str[j] > 'z')
			return false;

	return true;
}

bool ScreenMenu::checkStrViet(std::string &str)
{
	int length = str.size();
	if (length > 100 || length == 0)
		return false;

	for (char &c : str)
		if (c >= 'A' && c <= 'Z')
			c += 'a' - 'A';

	for (int j = 0; j < length; ++j)
		if (!((str[j] >= 'a' && str[j] <= 'z') || str[j] == ' '))
			return false;

	return true;
}

std::unique_ptr<ScreenMenu> HomeMenu::render()
{
    
}
