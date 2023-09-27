
#include <iostream>
#include <sstream>
using namespace std;

#include "Cinema.h"

//bool *screenSeats_1 = new bool[250]; // max screen size is 250
//bool *screenSeats_2 = new bool[250];
//bool *screenSeats_3 = new bool[250];
//bool *screenSeats_4 = new bool[250];
//bool *screenSeats_5 = new bool[250];
int main()
{
	Initialize_Seats();
//	for( int i = 0 ; i<250 ; i++ )
//	{
//		screenSeats_1[i] = false;screenSeats_2[i] = false;screenSeats_2[i] = false;screenSeats_4[i] = false;screenSeats_5[i] = false;
//	}
	int user = Get_User() ;
	if(user == MASTER)
	{
		while(1)
		{
			switch(Get_Master_Action())
			{
			case SWITCH_USER:
				Show_Screens_Details();
				while(1)
				{
					switch(Get_User_Action())
					{
					case BOOKING:
						Choose_Booking_Screen();
						break;
					case SHOW_SCHEDULE:
						ShowWeeklySchedule();
						break;
					case EXIT2:
						return 0;
					}
				}
				break;
			case EDIT_MOVIES:
				Edit_Movie_File();
				break;
			case EDIT_SCREENS:
				Edit_Screen_File();
				break;
			case EXIT:
				return 0; //close the application
				//break;
			}
		}
	}
	else if(user == USER)
	{
		Show_Screens_Details();
		while(1)
		{
			switch(Get_User_Action())
			{
			case BOOKING:
				Choose_Booking_Screen();
				break;
			case SHOW_SCHEDULE:
				ShowWeeklySchedule();
				break;
			case EXIT2:
				return 0;
			}
		}
	}
	else
	{
//		Time t1(10,15), duration(1,50);
//		Time t = t1+duration;
//		t.printNextTime();

		// Current TIME
//		time_t currentTime;
//		struct tm *localTime;
//
//		time( &currentTime );
//		localTime = localtime( &currentTime );  // Convert the current time to the local time
//		Time currentT(localTime->tm_hour, localTime->tm_min);
//		currentT.printNextTime();
		// Current TIME

//		auto now = std::chrono::system_clock::now();
//		std::time_t end_time = std::chrono::system_clock::to_time_t(now);
//
//		stringstream s(ctime(&end_time));
//	    string word;
//	    s>>word;
//		std::cout << "Current Time and Date: " << word << std::endl;
//
//		return 0;
	}
}
