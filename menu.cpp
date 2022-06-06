#include <iostream>

void menu(int k)
{
	//Size of Menu window
	const int menu_height = 30;
	const int menu_length = 160;

	char menu_array[menu_height][menu_length];

	//Filling menu with ' ' characters at first
	for(int i = 0 ; i < menu_height ; ++i)
	{
		for(int j = 0 ; j < menu_length ; ++j)
		{
			menu_array[i][j] = ' ';
		}
	}
	
	//trying to make a big "HANOI" with dollars in menu display
	//starting with letter H
	for(int i = 3 ; i < 13 ; ++i)
	{
		for(int j = 61; j < 63; ++j)
		{
			menu_array[i][j] = '$';
		}
	}

	menu_array[7][63] = '$';
	menu_array[7][64] = '$';
	menu_array[7][65] = '$';
	menu_array[8][63] = '$';
	menu_array[8][64] = '$';
	menu_array[8][65] = '$';

	for(int i = 3 ; i < 13 ; ++i)
        {
                for(int j = 66; j < 68; ++j)
                {
                        menu_array[i][j] = '$';
                }
        }
	//This was the letter H

	//Then letter A
	for(int i = 3 ; i < 13 ; ++i)
	{
		for(int j = 70 ; j < 72 ; ++j)
		{
			menu_array[i][j] = '$';
		}
	}
	
	menu_array[3][72] = '$';
        menu_array[3][73] = '$';
        menu_array[3][74] = '$';
        menu_array[4][72] = '$';
        menu_array[4][73] = '$';
        menu_array[4][74] = '$';
	menu_array[7][72] = '$';
        menu_array[7][73] = '$';
        menu_array[7][74] = '$';
        menu_array[8][72] = '$';
        menu_array[8][73] = '$';
        menu_array[8][74] = '$';

	for(int i = 3 ; i < 13 ; ++i)
        {
                for(int j = 75 ; j < 77 ; ++j)
                {
                        menu_array[i][j] = '$';
                }
        }
	//This was the letter A

	//Then letter N
	for(int i = 3 ; i < 13 ; ++i)
	{
		for(int j = 79 ; j < 81 ; ++j)
		{
			menu_array[i][j] = '$';
		}
	}

	menu_array[3][81] = '$';
        menu_array[4][81] = '$';
        menu_array[4][82] = '$';
        menu_array[5][82] = '$';
        menu_array[5][83] = '$';
        menu_array[6][83] = '$';
        menu_array[6][84] = '$';
        menu_array[7][84] = '$';
        menu_array[7][85] = '$';
        menu_array[8][85] = '$';
        menu_array[8][86] = '$';
        menu_array[9][86] = '$';
	menu_array[9][87] = '$';
        menu_array[10][87] = '$';
        menu_array[10][88] = '$';
        menu_array[11][88] = '$';
	
	for(int i = 3 ; i < 13 ; ++i)
        {
                for(int j = 89 ; j < 91 ; ++j)
                {
                        menu_array[i][j] = '$';
                }
        }
	//This was the letter N
	
	//Then letter O
	for(int i = 3 ; i < 13 ; ++i)
        {
                for(int j = 93 ; j < 95 ; ++j)
                {
                        menu_array[i][j] = '$';
                }
        }

	menu_array[3][95] = '$';
        menu_array[3][96] = '$';
        menu_array[3][97] = '$';
        menu_array[4][95] = '$';
        menu_array[4][96] = '$';
        menu_array[4][97] = '$';
        menu_array[11][95] = '$';
        menu_array[11][96] = '$';
        menu_array[11][97] = '$';
        menu_array[12][95] = '$';
        menu_array[12][96] = '$';
        menu_array[12][97] = '$';
	
	for(int i = 3 ; i < 13 ; ++i)
        {
                for(int j = 98 ; j < 100 ; ++j)
                {
                        menu_array[i][j] = '$';
                }
        }
	//This was the letter O
	
	//Then letter I
	for(int i = 3 ; i < 13 ; ++i)
        {
                for(int j = 102 ; j < 105 ; ++j)
                {
                        menu_array[i][j] = '$';
                }
        }
	//This was the letter I
	
	//Printing five sections (Play, Solver, Instructions, Records, Quit
	menu_array[20][80] = 'P';
	menu_array[20][81] = 'l';
	menu_array[20][82] = 'a';
	menu_array[20][83] = 'y';

	menu_array[22][80] = 'S';
	menu_array[22][81] = 'o';
	menu_array[22][82] = 'l';
	menu_array[22][83] = 'v';
	menu_array[22][84] = 'e';
	menu_array[22][85] = 'r';
	
	menu_array[24][80] = 'R';
	menu_array[24][81] = 'e';
	menu_array[24][82] = 'c';
	menu_array[24][83] = 'o';
	menu_array[24][84] = 'r';
	menu_array[24][85] = 'd';
	menu_array[24][86] = 's';

	menu_array[26][80] = 'I';
	menu_array[26][81] = 'n';
	menu_array[26][82] = 's';
	menu_array[26][83] = 't';
	menu_array[26][84] = 'r';
	menu_array[26][85] = 'u';
	menu_array[26][86] = 'c';
	menu_array[26][87] = 't';
	menu_array[26][88] = 'i';
	menu_array[26][89] = 'o';
	menu_array[26][90] = 'n';
	menu_array[26][91] = 's';

	menu_array[28][80] = 'Q';
	menu_array[28][81] = 'u';
	menu_array[28][82] = 'i';
	menu_array[28][83] = 't';	
	
	//Creating a little arrow to select categories and first starting position of it
	const char arrow_1 = '=';
	const char arrow_2 = '>';
	
	switch(k)
	{
		case 1:
			menu_array[20][77] = arrow_1;
			menu_array[20][78] = arrow_2;
			for(int i = 22 ; i < 29 ; ++i)
                 	{
                                menu_array[i][77] = ' ';
                                menu_array[i][78] = ' ';
                        }
			break;
		case 2:
			menu_array[22][77] = arrow_1;
                        menu_array[22][78] = arrow_2;
                        for(int i = 20 ; i < 29 ; ++i)
                        {
                                if(i != 22)
                                {
                                        menu_array[i][77] = ' ';
                                        menu_array[i][78] = ' ';
                                }
                        }
			break;
		case 3: 
			menu_array[24][77] = arrow_1;
                        menu_array[24][78] = arrow_2;
                        for(int i = 20 ; i < 29 ; ++i)
                        {
                                if(i != 24)
                                {
                                        menu_array[i][77] = ' ';
                                        menu_array[i][78] = ' ';
                                }
                        }
			break;
		case 4:
			menu_array[26][77] = arrow_1;
                        menu_array[26][78] = arrow_2;
			for(int i = 20 ; i < 29 ; ++i)
			{
				if(i != 26)
				{
					menu_array[i][77] = ' ';
					menu_array[i][78] = ' ';
				}
			}
                        break;
		case 5:
			menu_array[28][77] = arrow_1;
                        menu_array[28][78] = arrow_2;
                        for(int i = 20 ; i < 27 ; ++i)
                        {
                                menu_array[i][77] = ' ';
                                menu_array[i][78] = ' ';
                        }
			break;
		default:
			break;
	}

	//Printing menu
	system("clear");
	for(int i = 0 ; i < menu_height ; ++i)
	{
	        for(int j = 0 ; j < menu_length ; ++j)
	        {
			std::cout << "\033[1;93m" << menu_array[i][j] << "\033[0m";
	        }
		std::cout << "\n";
	}
}
