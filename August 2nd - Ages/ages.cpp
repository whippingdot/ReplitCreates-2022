#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <thread>

char assignRandom(int randomNum);

int main()
{
	using namespace std::this_thread;
	using namespace std::chrono;
	using std::chrono::system_clock;

	time_t nTime;
	int random2 = 0;

	std::srand((unsigned)time(&nTime));
	random2 = std::rand();
	random2 = rand() % 25 + 1;

	int random = 0;
	int dividedRandom = 0;
	int remainderRandom = 0;
	int longCounter = 0;
	int renewCounter = 0;
	int foundCount = 0;

	char randomChar = assignRandom(random2);
	char grid[5][5] = { {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '} };
	char usedCharacters[25];
	char possibleCharacters[25] = { '=', '+', '-', '!', '@', '#', '$', '%', '^', '&', '*', '|', '\\', '\'', '\"', '_', ';', '.', ',', '<', '>', '~', '`', '?', '/' };
	char* found = std::find(std::begin(usedCharacters), std::end(usedCharacters), randomChar);

	bool completed[25] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };

	while (true)
	{
		random = std::rand() % 25;
		//std::cout << "Random: " << random << std::endl;
		dividedRandom = random / 5;
		remainderRandom = random % 5;

		//std::cout << "Divided: " << dividedRandom << "\nRemainder: " << remainderRandom << std::endl;

		if (found != std::end(usedCharacters) || completed[longCounter] == true)
		{
			for (int i = 0; i < 25; i++) {
				found = std::find(std::begin(possibleCharacters), std::end(possibleCharacters), usedCharacters[i]);
				if (found != std::end(possibleCharacters))
					foundCount++;
			}
			if (foundCount == 25) {
				std::cout << "Old Program :(\n";
				return 0;
			}
			foundCount = 0;
			random2 = std::rand() % 25 + 1;
			randomChar = assignRandom(random2);
			found = std::find(std::begin(usedCharacters), std::end(usedCharacters), randomChar);
		}
		if (completed[longCounter] == true)
		{
			longCounter++;
			while (found != std::end(usedCharacters))
			{
				random2 = std::rand() % 25 + 1;
				randomChar = assignRandom(random2);
				found = std::find(std::begin(usedCharacters), std::end(usedCharacters), randomChar);
			}
		}

		usedCharacters[longCounter] = randomChar;

		if (grid[dividedRandom][remainderRandom] == randomChar) {
			continue;
		}

		grid[dividedRandom][remainderRandom] = randomChar;

		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				std::cout << grid[x][y] << ' ';
				if (grid[x][y] == randomChar)
					renewCounter++;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int z = 0; z < longCounter + 1; z++) {
			std::cout << usedCharacters[z] << ": " << (1 + (z * 25)) << "-" << (25 + (z * 25)) << std::endl;
		}
		std::cout << "\n-----\n\n";
		sleep_for(1s);

		if (renewCounter == 25)
			completed[longCounter] = true;
		renewCounter = 0;
	}

	return 0;
}

char assignRandom(int randomNum)
{
	//std::cout << "Given Random: " << randomNum << std::endl;

	switch (randomNum)
	{
	case 1:
		return '+';
		break;

	case 2:
		return '-';
		break;

	case 3:
		return '=';
		break;

	case 4:
		return '\\';
		break;

	case 5:
		return '|';
		break;

	case 6:
		return '!';
		break;

	case 7:
		return '@';
		break;

	case 8:
		return '#';
		break;

	case 9:
		return '$';
		break;

	case 10:
		return '%';
		break;

	case 11:
		return '^';
		break;

	case 12:
		return '&';
		break;

	case 13:
		return '*';
		break;

	case 14:
		return '`';
		break;

	case 15:
		return '~';
		break;

	case 16:
		return '?';
		break;

	case 17:
		return ',';
		break;

	case 18:
		return '.';
		break;

	case 19:
		return '/';
		break;

	case 20:
		return '<';
		break;

	case 21:
		return '>';
		break;

	case 22:
		return '_';
		break;

	case 23:
		return ';';
		break;

	case 24:
		return '\'';
		break;

	case 25:
		return '\"';
		break;

	default:
		return 'e';
		break;
	}
}