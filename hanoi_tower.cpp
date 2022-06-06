#include <iostream>
#include <fstream>
#include "input.hpp"
#include "menu.hpp"
#include "play.hpp"

void print_instructions()
{
	std::cout << "\033[1;93mThe objective of the puzzle is to move the entire stack to the last rod, obeying the following rules: \n";

    	std::cout << "\t1) Only one disk may be moved at a time.\n";
	std::cout << "\t2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.\n";
	std::cout << "\t3) No disk may be placed on top of a disk that is smaller than it.\n";
	std::cout << "\n\nPress ESC to go back to menu!\033[0m\n";
}

int main()
{
	int position_of_arrow = 1; //position of arrow can be 1-5 because our menu has 5 sections
	int disks; //amount of disks

	menu(position_of_arrow);
	cbreak();

	while (true) {
		const char key = keypress();
		switch (key) {
		case 'w': case 'W':
			if(position_of_arrow != 1) // you can't go to 0 section (1-5)
                        {
                                --position_of_arrow;
                                menu(position_of_arrow);
                        }
			break;
		case 's': case 'S':
			if(position_of_arrow != 5) // you can't go to 6 section (1-5)
			{
				++position_of_arrow;
				menu(position_of_arrow);
			}		
			break;
		case 'i': case 'I': case 10: //10 is 'Enter'
			if(position_of_arrow == 1)
			{
				normal();
				std::cout << "\033[1;93m Input the amount of disks[1 - 12]: \033[0m" ;
				std::cin >> disks;
				play(disks);
			}
			
			else if(position_of_arrow == 2)
                        {
                                normal();
                                std::cout << "\033[1;93m Input the amount of disks[1 - 12]: \033[0m" ;
                                std::cin >> disks;
				starting_position(disks);
                                solver(disks);
                        }

			else if(position_of_arrow == 3)
			{
				normal();
				system("clear");
				showRecords();
			}

			else if(position_of_arrow == 4)
			{
				normal();
				system("clear");
				print_instructions();
				cbreak();
			}

			else
			{
				goto EXIT;
			}
			break;
		case 27: //ESC button
			system("clear");
			position_of_arrow = 1;
			menu(position_of_arrow);
			break;
		}
	}
EXIT:
	normal();

	return 0;
}
