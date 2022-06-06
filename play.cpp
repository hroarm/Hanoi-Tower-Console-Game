#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include <fstream>
#include "input.hpp"

//size of the interface window of 'Play' section with disks and towers
const int height = 30;
const int length = 160;

//array of chars for the window of 'Play' section
char display[height][length];

void starting_position(int disks)
{
	//at first we will fill array with empty ' ' characters
        for(int i = 0 ; i < height ; ++i)
        {
                for(int j = 0 ; j < length ; ++j)
                {
                        display[i][j] = ' ';
                }
        }

	//we will have 4 borders for 3 towers
	const int first_border = 10;
	const int last_border = 130;
	const int distance_between_borders = 40;
	const int border_height = 25; 
	
        for(int i = height - border_height ; i < height ; ++i)
        {
                for(int j = first_border ; j <= last_border ; j += distance_between_borders)
                {
                        display[i][j] = '|';
                }
        }

        int length_of_half_disk = disks;
	const int center_of_first_tower = 30; 
	
	//putting disks on 1st tower, we start with biggest disk at the bottom
        for(int i = height - 1 ; i >= height - disks; --i)
        {
                for(int j = center_of_first_tower - length_of_half_disk ; j < center_of_first_tower + length_of_half_disk ; ++j)
                {
                        display[i][j] = '#';
                }
                --length_of_half_disk;
        }
}

//display of towers and disks
void printplay()
{
    	system("clear");
	for(int i = 0 ; i < height ; ++i)
	{
		for(int j = 0 ; j < length ; ++j)
		{
			std::cout << "\033[1;96m" << display[i][j] << "\033[0m";
		}
		std::cout << "\n";
	}
}

void move(int disks, int from, int to)
{
 	int sentinelone, sentineltwo, sentinelthree; //indexes of rows of the highest disks + 1
    	sentinelone = height;
    	sentineltwo = height;
    	sentinelthree = height;
    
    	int valueone, valuetwo, valuethree; //index of column of first # in a highest disk
    	const int max_number_of_disks = 12;
    	valueone = max_number_of_disks;
    	valuetwo = max_number_of_disks;
    	valuethree = max_number_of_disks;
        
	const int first_border = 10;
	const int second_border = 50;
	const int third_border = 90;
	const int last_border = 130;
	const int center_of_first_tower = 30;
	const int center_of_second_tower = 70;
	const int center_of_third_tower = 110;

    	for(int i = height - disks ; i < height ; ++i)
    	{
        	if(display[i][center_of_first_tower - 1] == '#') //in tower 1 the 29th column has at least one # if there is at least one disk;
        	{
        	    	sentinelone = i;
        	    	break;
        	}
    	}
    	
    	for(int j = first_border + 1 ; j < center_of_first_tower ; ++j)
    	{
        	if(display[sentinelone][j] == '#')
        	{
           		valueone = center_of_first_tower - j;
           		break;
        	}

    	}
    
    	for(int i = height - disks ; i < height ; ++i)
    	{
        	if(display[i][center_of_second_tower - 1] == '#') //in tower 2 the 69th column has at least one # if there is at least one disk;
        	{
            		sentineltwo = i;
            		break;
        	}
    	}
    
    	for(int j = second_border + 1 ; j < center_of_second_tower ; ++j)
    	{
        	if(display[sentineltwo][j] == '#')
        	{
            		valuetwo = center_of_second_tower - j;
            		break;
        	}
    	}
    
    	for(int i = height - disks ; i < height ; ++i)
    	{
        	if(display[i][center_of_third_tower - 1] == '#') //in tower 3 the 109th column has at least one # if there is at least one disk;
        	{
            		sentinelthree = i;
            		break;
        	}
    	}
    
    	for(int j = third_border + 1 ; j < center_of_third_tower ; ++j)
    	{
        	if(display[sentinelthree][j] == '#')
        	{
            		valuethree = center_of_third_tower - j;
            		break;
        	}
    	}
    	
    	if(from == 1)
    	{
        	switch (to) 
        	{
            		case 2:
                		if(valueone < valuetwo)
                		{
                    			//tower 1 is located between 11 and 49 columns
                    			//deleting the highest disk on 1st tower
                    			for(int j = first_border + 1 ; j < second_border - 1 ; ++j)
                    			{
                        			display[sentinelone][j] = ' ';
                    			}
                    
                    			//moving it to 2nd tower
                    			//2nd tower is located between 51st and 89th columns
                    			//in tower 2 the 69th column has at least one # if there is at least one disk;
                    			for(int j = center_of_second_tower - valueone; j < center_of_second_tower + valueone; ++j)
                    			{
                        			display[sentineltwo-1][j] = '#';
                    			}
                		}
				else
				{
					move(disks, to, from);
				}
                		break;
            		case 3:
                		if(valueone < valuethree)
                		{
                    			//tower 1 is located between 11 and 49 columns
                    			//deleting the highest disk on 1st tower
                    			for(int j = first_border + 1 ; j < second_border - 1 ; ++j)
                    			{
                        			display[sentinelone][j] = ' ';
                    			}
                
                    			//moving it to 3rd tower
                    			//3rd tower is located between 91st and 129th columns
                    			//in tower 3 the 109th column has at least one # if there is at least one disk; 
                    			for(int j = center_of_third_tower - valueone; j < center_of_third_tower + valueone; ++j)
                    			{
                        			display[sentinelthree-1][j] = '#';
                    			}
                		}
				else
				{
					move(disks, to, from);
				}
                		break;
            		default:
                		std::cout << "Error!";
                		break;
        	}
    	}

	else if (from == 2)
	{
		switch (to)
                {
                        case 1:
                                if(valuetwo < valueone)
                                {
                                        //tower 2 is located between 51 and 89 columns
                                        //deleting the highest disk on 1st tower
                                        for(int j = second_border + 1 ; j < third_border - 1 ; ++j)
                                        {
                                                display[sentineltwo][j] = ' ';
                                        }

                                        //moving it to 1st tower
                                        //1st tower is located between 11st and 49th columns
                                        //in tower 1 the 29th column has at least one # if there is at least one disk;
                                        for(int j = center_of_first_tower - valuetwo; j < center_of_first_tower + valuetwo; ++j)
                                        {
                                                display[sentinelone-1][j] = '#';
                                        }
                                }
				else
				{
					move(disks, to, from);
				}
                                break;
                        case 3:
                                if(valuetwo < valuethree)
                                {
                                        //tower 2 is located between 51 and 89 columns
                                        //deleting the highest disk on 1st tower
                                        for(int j = second_border + 1 ; j < third_border - 1 ; ++j)
                                        {
                                                display[sentineltwo][j] = ' ';
                                        }
					
					//moving it to 3rd tower
                                        //3rd tower is located between 91st and 129th columns
                                        //in tower 3 the 109th column has at least one # if there is at least one disk;
                                        for(int j = center_of_third_tower - valuetwo; j < center_of_third_tower + valuetwo; ++j)
                                        {
                                                display[sentinelthree-1][j] = '#';
                                        }
                                }
				else
				{
					move(disks, to, from);
				}
                                break;
                        default:
                                std::cout << "Error!";
                                break;
                }
	}
	
	else if (from == 3)
	{
		switch (to)
                {
                        case 1:
                                if(valuethree < valueone)
                                {
                                        //tower 3 is located between 91 and 129 columns
                                        //deleting the highest disk on 1st tower
                                        for(int j = third_border + 1 ; j < last_border - 1 ; ++j)
                                        {
                                                display[sentinelthree][j] = ' ';
                                        }

                                        //moving it to 1st tower
                                        //1st tower is located between 11st and 49th columns
                                        //in tower 1 the 29th column has at least one # if there is at least one disk;
                                        for(int j = center_of_first_tower - valuethree; j < center_of_first_tower + valuethree; ++j)
                                        {
                                                display[sentinelone-1][j] = '#';
                                        }
                                }
				else
				{
					move(disks, to, from);
				}
                                break;
                        case 2:
                                if(valuethree < valuetwo)
                                {
                                        //tower 3 is located between 91 and 129 columns
                                        //deleting the highest disk on 1st tower
                                        for(int j = third_border + 1 ; j < last_border - 1 ; ++j)
                                        {
                                                display[sentinelthree][j] = ' ';
                                        }

                                        //moving it to 2nd tower
                                        //2nd tower is located between 51st and 89th columns
                                        //in tower 2 the 69th column has at least one # if there is at least one disk;
                                        for(int j = center_of_second_tower - valuethree; j < center_of_second_tower + valuethree; ++j)
                                        {
                                                display[sentineltwo-1][j] = '#';
                                        }
                                }
				else
				{
					move(disks, to, from);
				}
                                break;
                        default:
                                std::cout << "Error!";
				break;
		}
	}
}

void move_disk(int disks, int from, int to)
{
 	int sentinelone, sentineltwo, sentinelthree; //indexes of rows of the highest disks + 1
    	sentinelone = height;
    	sentineltwo = height;
    	sentinelthree = height;
    
    	int valueone, valuetwo, valuethree; //index of column of first # in a highest disk
    	const int max_number_of_disks = 12;
    	valueone = max_number_of_disks;
    	valuetwo = max_number_of_disks;
    	valuethree = max_number_of_disks;
        
	const int first_border = 10;
	const int second_border = 50;
	const int third_border = 90;
	const int last_border = 130;
	const int center_of_first_tower = 30;
	const int center_of_second_tower = 70;
	const int center_of_third_tower = 110;

    	for(int i = height - disks ; i < height ; ++i)
    	{
        	if(display[i][center_of_first_tower - 1] == '#') //in tower 1 the 29th column has at least one # if there is at least one disk;
        	{
        	    	sentinelone = i;
        	    	break;
        	}
    	}
    	
    	for(int j = first_border + 1 ; j < center_of_first_tower ; ++j)
    	{
        	if(display[sentinelone][j] == '#')
        	{
           		valueone = center_of_first_tower - j;
           		break;
        	}

    	}
    
    	for(int i = height - disks ; i < height ; ++i)
    	{
        	if(display[i][center_of_second_tower - 1] == '#') //in tower 2 the 69th column has at least one # if there is at least one disk;
        	{
            		sentineltwo = i;
            		break;
        	}
    	}
    
    	for(int j = second_border + 1 ; j < center_of_second_tower ; ++j)
    	{
        	if(display[sentineltwo][j] == '#')
        	{
            		valuetwo = center_of_second_tower - j;
            		break;
        	}
    	}
    
    	for(int i = height - disks ; i < height ; ++i)
    	{
        	if(display[i][center_of_third_tower - 1] == '#') //in tower 3 the 109th column has at least one # if there is at least one disk;
        	{
            		sentinelthree = i;
            		break;
        	}
    	}
    
    	for(int j = third_border + 1 ; j < center_of_third_tower ; ++j)
    	{
        	if(display[sentinelthree][j] == '#')
        	{
            		valuethree = center_of_third_tower - j;
            		break;
        	}
    	}
    	
    	if(from == 1)
    	{
        	switch (to) 
        	{
            		case 2:
                		if(valueone < valuetwo)
                		{
                    			//tower 1 is located between 11 and 49 columns
                    			//deleting the highest disk on 1st tower
                    			for(int j = first_border + 1 ; j < second_border - 1 ; ++j)
                    			{
                        			display[sentinelone][j] = ' ';
                    			}
                    
                    			//moving it to 2nd tower
                    			//2nd tower is located between 51st and 89th columns
                    			//in tower 2 the 69th column has at least one # if there is at least one disk;
                    			for(int j = center_of_second_tower - valueone; j < center_of_second_tower + valueone; ++j)
                    			{
                        			display[sentineltwo-1][j] = '#';
                    			}
                		}
                		break;
            		case 3:
                		if(valueone < valuethree)
                		{
                    			//tower 1 is located between 11 and 49 columns
                    			//deleting the highest disk on 1st tower
                    			for(int j = first_border + 1 ; j < second_border - 1 ; ++j)
                    			{
                        			display[sentinelone][j] = ' ';
                    			}
                
                    			//moving it to 3rd tower
                    			//3rd tower is located between 91st and 129th columns
                    			//in tower 3 the 109th column has at least one # if there is at least one disk; 
                    			for(int j = center_of_third_tower - valueone; j < center_of_third_tower + valueone; ++j)
                    			{
                        			display[sentinelthree-1][j] = '#';
                    			}
                		}
                		break;
            		default:
                		std::cout << "Error!";
                		break;
        	}
    	}

	else if (from == 2)
	{
		switch (to)
                {
                        case 1:
                                if(valuetwo < valueone)
                                {
                                        //tower 2 is located between 51 and 89 columns
                                        //deleting the highest disk on 1st tower
                                        for(int j = second_border + 1 ; j < third_border - 1 ; ++j)
                                        {
                                                display[sentineltwo][j] = ' ';
                                        }

                                        //moving it to 1st tower
                                        //1st tower is located between 11st and 49th columns
                                        //in tower 1 the 29th column has at least one # if there is at least one disk;
                                        for(int j = center_of_first_tower - valuetwo; j < center_of_first_tower + valuetwo; ++j)
                                        {
                                                display[sentinelone-1][j] = '#';
                                        }
                                }
                                break;
                        case 3:
                                if(valuetwo < valuethree)
                                {
                                        //tower 2 is located between 51 and 89 columns
                                        //deleting the highest disk on 1st tower
                                        for(int j = second_border + 1 ; j < third_border - 1 ; ++j)
                                        {
                                                display[sentineltwo][j] = ' ';
                                        }
					
					//moving it to 3rd tower
                                        //3rd tower is located between 91st and 129th columns
                                        //in tower 3 the 109th column has at least one # if there is at least one disk;
                                        for(int j = center_of_third_tower - valuetwo; j < center_of_third_tower + valuetwo; ++j)
                                        {
                                                display[sentinelthree-1][j] = '#';
                                        }
                                }
                                break;
                        default:
                                std::cout << "Error!";
                                break;
                }
	}
	
	else if (from == 3)
	{
		switch (to)
                {
                        case 1:
                                if(valuethree < valueone)
                                {
                                        //tower 3 is located between 91 and 129 columns
                                        //deleting the highest disk on 1st tower
                                        for(int j = third_border + 1 ; j < last_border - 1 ; ++j)
                                        {
                                                display[sentinelthree][j] = ' ';
                                        }

                                        //moving it to 1st tower
                                        //1st tower is located between 11st and 49th columns
                                        //in tower 1 the 29th column has at least one # if there is at least one disk;
                                        for(int j = center_of_first_tower - valuethree; j < center_of_first_tower + valuethree; ++j)
                                        {
                                                display[sentinelone-1][j] = '#';
                                        }
                                }
                                break;
                        case 2:
                                if(valuethree < valuetwo)
                                {
                                        //tower 3 is located between 91 and 129 columns
                                        //deleting the highest disk on 1st tower
                                        for(int j = third_border + 1 ; j < last_border - 1 ; ++j)
                                        {
                                                display[sentinelthree][j] = ' ';
                                        }

                                        //moving it to 2nd tower
                                        //2nd tower is located between 51st and 89th columns
                                        //in tower 2 the 69th column has at least one # if there is at least one disk;
                                        for(int j = center_of_second_tower - valuethree; j < center_of_second_tower + valuethree; ++j)
                                        {
                                                display[sentineltwo-1][j] = '#';
                                        }
                                }
                                break;
                        default:
                                std::cout << "Error!";
				break;
		}
	}
}
		
void showRecords()
{
	std::fstream myFile("records.txt");
	std::string myText;
	while (std::getline (myFile, myText)) {
  		// Output the text from the file
		std::cout << "\033[1;93m" << myText << "\n";
	}

	myFile.close();
	cbreak();
}

void play(int disks)
{ 
	starting_position(disks);
	//printing the display
	printplay();
	
	int X, Y; //variables for 3 towers, X and Y can be from 1 to 3

	//column of the center of first tower = 30;
	//column of the center of second tower = 70;
	const int center_of_first_tower = 30;
	const int center_of_second_tower = 70;
	int count_of_moves = 0;

        //if there is a disk in 1st or in 2nd tower you have to play still
        while(display[height-1][center_of_first_tower] == '#' or display[height-1][center_of_second_tower] == '#')
        {
                std::cout << "\n\n\033[1;93m" << "Move disk from X to Y: " << "\033[0m";
                std::cin >> X >> Y;

                move_disk(disks, X, Y);
                ++count_of_moves;
                printplay();
                std::cout << "\n\t\t\t\t";
        }

	auto end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::fstream myFile("records.txt", std::ios::app);
	myFile << std::ctime(&end_time) << disks << " disks: " << count_of_moves << " moves\n";
        myFile.close();

	//else you won!
	if(display[height-1][center_of_first_tower] != '#' and display[height-1][center_of_second_tower] != '#')
	{
		system("clear");
		printplay();
		std::cout << "\n\n\n\t\t\t\033[1;92m" << "CONGRATS! YOU WIN! YOU ARE A GENIUS! PRESS ESC TO GO BACK TO MENU!\n" << "\033[0m";
		cbreak();	
	}
}

void solver(int disks)
{
	int moves = pow(2, disks) - 1; // total amount of moves
	
	sleep(1);
	printplay();

        if(disks % 2 == 0)
	{
		for(int k = 0 ; k < moves  ; ++k)
		{
			if(k % 3 == 0)
			{
				sleep(1);
				move(disks, 1, 2);
				printplay();
			}
			

			else if(k % 3 == 1)
			{
				sleep(1);
				move(disks, 1, 3);
				printplay();
		       	}
			
			else
			{
				sleep(1);
				move(disks, 2, 3);
				printplay();
			}
		}
	}

	else
	{
                for(int k = 0 ; k < moves  ; ++k)
                {
                        if(k % 3 == 0)
                        {
                                sleep(1);
                                move(disks, 1, 3);
                                printplay();
                        }


                        else if(k % 3 == 1)
                        {
                                sleep(1);
                                move(disks, 1, 2);
                                printplay();
                        }

                        else
                        {
                                sleep(1);
                                move(disks, 2, 3);
                                printplay();
                        }
                }
	}

	std::cout << "\n\n\033[1;92m" << "SOLVED! PRESS ESC TO GO BACK TO MENU!\n" << "\033[0m";
	cbreak();
}
