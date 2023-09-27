
#include <limits>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <ctime>
#include <algorithm>

#include "Cinema.h"
using namespace std;
using namespace std::chrono;

// public variables
const float adults = 9.5, children = 5.5, seniorCitizens = 6.50 , students = 7.0;// ticket prices
//extern bool *screenSeats_1;
//extern bool *screenSeats_2;
//extern bool *screenSeats_3;
//extern bool *screenSeats_4;
//extern bool *screenSeats_5;

int Get_User(void)
{
	system("cls");
	int user = 0;
	cout << "Choose Which User You want?\n1- MASTER\n2- USER"<<endl;
	cin >>user;
	while( (user != MASTER && user != USER) )
	{
	    if (!cin)
	    {
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	    system("cls");
		cout << "Wrong Input! \nPlease Try Again\n\n\n";
		cout << "Choose Which User You want?\n1- MASTER\n2- USER"<<endl;
		cin >>user;
	}
	return user;
}

int Get_Master_Action(void)
{
	int action = 0;
	cout << "\n\nChoose your action:\n1- SWITCH USER\n2- EDIT MOVIES\n3- EDIT SCREENS\n4- EXIT"<<endl;
	cin >>action;
	while( (action != SWITCH_USER && action != EDIT_MOVIES && action != EDIT_SCREENS && action != EXIT))
	{
	    if (!cin)
	    {
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	    system("cls");
		cout << "Wrong Input! \nPlease Try Again\n\n\n";
		cout << "Choose your action:\n1- SWITCH USER\n2- EDIT MOVIES\n3- EDIT SCREENS\n4- EXIT"<<endl;
		cin >>action;
	}

	return action;
}

void Edit_Movie_File(void)
{
	system("cls");
	int new_or_stored_movies = 0;
	cout << "Would you show stored movies or insert new ones?\n1- add NEW\n2- show STORED"<<endl;
	cin >>new_or_stored_movies;
	while( (new_or_stored_movies != NEW_MOVIES && new_or_stored_movies != STORED_MOVIES))
	{
	    if (!cin)
	    {
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	    system("cls");
		cout << "Wrong Input! \nPlease Try Again\n\n\n";
		cout << "Would you use stored movies or insert new ones?\n1- NEW\n2- STORED"<<endl;
		cin >>new_or_stored_movies;
	}

	if( new_or_stored_movies == NEW_MOVIES )
	{
		Movie newMovie[5];
		// 5 movies each per screen
		cin.ignore();
		for( int i = 0 ; i < 5 ; i++)
		{
			system("cls");
			cout << endl;
			cout << "Movie Number ";
			cout << (i+1) << endl;
			// title
			cout << "Title:";
//			cin.ignore();
			getline(cin , newMovie[i].title);
			replace( newMovie[i].title.begin(), newMovie[i].title.end(), ',', ' ');
			// description
			cout << "Description:";
//			cin.ignore();
			getline(cin , newMovie[i].description);
			replace( newMovie[i].description.begin(), newMovie[i].description.end(), ',', ' ');
			// genre
			cout << "Genre:";
//			cin.ignore();
			getline(cin , newMovie[i].genre);
			replace( newMovie[i].genre.begin(), newMovie[i].genre.end(), ',', ' ');
			// running time
			cout << "Running Time (xx.xx):";
			cin >>newMovie[i].runningTime;
			while( !cin )
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input! \nPlease Try Again\n\n\n";
				cout << "Running Time:";
				cin >>newMovie[i].runningTime;
			}
//			newMovie[i].runningTime += 0.42;
			// main star
			cout << "Main Star:";
			cin.ignore();
			getline(cin , newMovie[i].mainStar);
			replace( newMovie[i].mainStar.begin(), newMovie[i].mainStar.end(), ',', ' ');
			// release date
			cout << "Release Date (dd/mm/yyyy):";
//			cin.ignore();
			getline(cin , newMovie[i].releaseDate);
			replace( newMovie[i].releaseDate.begin(), newMovie[i].releaseDate.end(), ',', ' ');
		}
		ofstream myFile("storedMovies.csv"); // open or create file
		for( int i = 0 ; i < 5 ; i++ )
		{
			myFile << newMovie[i].title;
			myFile << ",";
			myFile << newMovie[i].description;
			myFile << ",";
			myFile << newMovie[i].genre;
			myFile << ",";
			myFile << newMovie[i].runningTime;
			myFile << ",";
			myFile << newMovie[i].mainStar;
			myFile << ",";
			myFile << newMovie[i].releaseDate;
			if( i != 4 )
			{
			myFile << "\n"; // avoid adding new line at the end
			}
		}
		myFile.close(); // close after a complete data entry
		cout << endl;
	}
	else if( new_or_stored_movies == STORED_MOVIES )
	{
		system("cls");
		cout << "Stored Movies List:" << endl;
	    // File pointer
	    fstream myFile;
	    myFile.open("storedMovies.csv", ios::in);

	    vector<string> row;
	    string line, word;
		for( int i = 0 ; i < 5 ; i++)
		{
			row.clear();
	        getline(myFile, line); // read row as a line
	        stringstream s(line);  // breaking words
	        while (getline(s, word, ','))
	        {
	            row.push_back(word); // make a vector
	        }

	        cout << "\nMovie number "; cout << (i+1); cout << ":\n";
	        cout << "\nTitle 	   	: "; 		cout << row[0];
	        cout << "\nDescription 	: "; 		cout << row[1];
	        cout << "\nGenre 		: "; 		cout << row[2];
	        cout << "\nRunningTime 	: "; 		cout << row[3];
	        cout << "\nMainStar 	: ";		cout << row[4];
	        cout << "\nReleaseDate 	: ";		cout << row[5] << endl;
		}
		myFile.close(); // close file
	}
	cout << "DONE ^_^";
	cin.ignore();cin.get();
}

void Edit_Screen_File(void)
{
	system("cls");
	int edit_current_movies_or_screen_details = 0;
	cout << "Would you edit current movies or edit screens details?\n1- Edit current showing screens MOVIES\n2- Edit Screen Details"<<endl;
	cin >>edit_current_movies_or_screen_details;
	while( (edit_current_movies_or_screen_details != EDIT_SCREENS_MOVIES && edit_current_movies_or_screen_details != EDIT_SCREENS_DETAILS))
	{
	    if (!cin)
	    {
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	    system("cls");
		cout << "Wrong Input! \nPlease Try Again\n\n\n";
		cout << "Would you edit current movies or edit screens details?\n1- Edit current showing screens MOVIES\n2- Edit Screen Details"<<endl;
		cin >>edit_current_movies_or_screen_details;
	}
	if( edit_current_movies_or_screen_details == EDIT_SCREENS_MOVIES )
	{
		system("cls");
		Movie movies[5];
	// read stored movies
	    // File pointer
	    fstream myFile;
	    myFile.open("storedMovies.csv", ios::in);

	    vector<string> row;
	    string line, word;
		for( int i = 0 ; i < 5 ; i++)
		{
			row.clear();
	        getline(myFile, line); // read row as a line
	        stringstream s(line);  // breaking words
	        while (getline(s, word, ','))
	        {
	            row.push_back(word); // make a vector
	        }
	        movies[i].title = row[0];
	        movies[i].description = row[1];
	        movies[i].genre = row[2];
	        movies[i].runningTime = stof(row[3]);
	        movies[i].mainStar = row[4];
	        movies[i].releaseDate = row[5];
		}
		myFile.close(); // close file

	// store movies to each screen
		cout << "Stored Movies List:" << endl;
		cout << "1- " << movies[0].title<<endl;
		cout << "2- " << movies[1].title<<endl;
		cout << "3- " << movies[2].title<<endl;
		cout << "4- " << movies[3].title<<endl;
		cout << "5- " << movies[4].title<<endl;
		int movieNo[5] = {0};
		for( int i = 0 ; i < 5 ; i++ )
		{
//			system("cls");
			cout << "Screen ( " << (i+1) << " ) Movie : ";
			cin >>movieNo[i];
			while( !cin || movieNo[i] > 5 || movieNo[i] < 1)
			{
				system("cls");
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong Input! \nPlease Try Again\n\n\n";
				cout << "Screen ( " << (i+1) << " ) Movie : ";
				cin >>movieNo[i];
			}
		}
		ofstream storedScreensCurrentMovies("storedScreensCurrentMovies.csv"); // open or create file
		for( int i = 0 ; i < 5 ; i++ )
		{
			storedScreensCurrentMovies << movies[movieNo[i]-1].title;
			storedScreensCurrentMovies << ",";
			storedScreensCurrentMovies << movies[movieNo[i]-1].description;
			storedScreensCurrentMovies << ",";
			storedScreensCurrentMovies << movies[movieNo[i]-1].genre;
			storedScreensCurrentMovies << ",";
			storedScreensCurrentMovies << movies[movieNo[i]-1].runningTime;
			storedScreensCurrentMovies << ",";
			storedScreensCurrentMovies << movies[movieNo[i]-1].mainStar;
			storedScreensCurrentMovies << ",";
			storedScreensCurrentMovies << movies[movieNo[i]-1].releaseDate;
			if( i != 4 )
			{
				storedScreensCurrentMovies << "\n"; // avoid adding new line at the end
			}
		}
		storedScreensCurrentMovies.close(); // close after a complete data entry
		cout << endl;
	}
	else if ( edit_current_movies_or_screen_details == EDIT_SCREENS_DETAILS )
	{
		system("cls");
		Screen screens[5];
		cin.ignore();
		for( int i = 0 ; i < 5 ; i++ )
		{
			system("cls");
			cout << "\nScreen ( " << (i+1) << " ) :\n";
			cout << "ID : "		; getline(cin , screens[i].id);replace( screens[i].id.begin(), screens[i].id.end(), ',', ' ');
			cout << "Seats : "	; cin >> screens[i].seats;
			while( !cin || screens[i].seats > 250 || screens[i].seats < 100 )
			{
				if(!cin)
				{
					cout << "Wrong Input! \nPlease Try Again\n" << endl;
				}
				else if( screens[i].seats > 250 || screens[i].seats < 100 )
				{
					cout << "Sorry! seats number is from 100 to 250\n" << endl;
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Seats : "	; cin >> screens[i].seats;
			}
			cout << "screenFacility : "; cin.ignore();getline(cin , screens[i].screenFacility);replace( screens[i].screenFacility.begin(), screens[i].screenFacility.end(), ',', ' ');
		}
		ofstream storedScreens("storedScreens.csv"); // open or create file
		for( int i = 0 ; i < 5 ; i++ )
		{
			storedScreens << screens[i].id;
			storedScreens << ",";
			storedScreens << screens[i].seats;
			storedScreens << ",";
			storedScreens << screens[i].screenFacility;
			if( i != 4 )
			{
				storedScreens << "\n"; // avoid adding new line at the end
			}
		}
		storedScreens.close(); // close after a complete data entry
		cout << endl;
	}
	cout << "DONE ^_^";
	cin.ignore();cin.get();
}

int  Get_User_Action(void)
{
	int action = 0;
	cout << "\n\nChoose your action:\n1- BOOKING\n2- SHOW SCHEDULE\n3- EXIT"<<endl;
	cin >>action;
	while( (action != BOOKING && action != SHOW_SCHEDULE && action != EXIT2))
	{
	    if (!cin)
	    {
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	    system("cls");
		cout << "Wrong Input! \nPlease Try Again\n\n\n";
		cout << "\n\nChoose your action:\n1- BOOKING\n2- SHOW SCHEDULE\n3- EXIT"<<endl;
		cin >>action;
	}
	return action;
}

void Show_Screens_Details(void)
{
	system("cls");
	cout << "This Week Movies : " << endl;
	Movie movies[5];
	Screen screens[5];
	fstream storedScreens;
	fstream storedScreensCurrentMovies;
	storedScreens.open("storedScreens.csv", ios::in);
	storedScreensCurrentMovies.open("storedScreensCurrentMovies.csv", ios::in);

	vector<string> row, row2;
	string line, word, line2, word2;
	for( int i = 0 ; i < 5 ; i++ )
	{
		row.clear();
		row2.clear();
		getline(storedScreens, line); // read row as a line
		stringstream s(line);  // breaking words
		while (getline(s, word, ','))
		{
			row.push_back(word); // make a vector
		}
		getline(storedScreensCurrentMovies, line2); // read row as a line
		stringstream s2(line2);  // breaking words
		while (getline(s2, word2, ','))
		{
			row2.push_back(word2); // make a vector
		}
		screens[i].id 				= row[0];
		screens[i].seats 			= stof(row[1]);
		screens[i].screenFacility 	= row[2];
		movies [i].title			= row2[0];
		movies [i].description		= row2[1];
		movies [i].genre			= row2[2];
		movies [i].runningTime		= stof(row2[3]);
		movies [i].mainStar			= row2[4];
		movies [i].releaseDate		= row2[5];
	}
	storedScreens.close(); // close file
	storedScreensCurrentMovies.close(); // close file
	time_t dateTime = system_clock::to_time_t(system_clock::now());
	cout << "Date Time for Now : " << ctime(&dateTime);
	for( int i = 0 ; i < 5 ; i++ )
	{
		cout << " " <<endl;
		cout << "Screen " << (i+1) << " id : " << screens[i].id << " (" << screens[i].seats << " )" << endl;
		cout << "  " << screens[i].screenFacility << endl;
		cout << "  " << movies[i].title << endl;
		cout << "  " << movies[i].description << endl;
		cout << "  " << movies[i].genre << endl;
		cout << "  " << movies[i].runningTime << endl;
		cout << "  " << movies[i].mainStar << endl;
		cout << "  " << movies[i].releaseDate << endl;
	}
	cin.ignore();cin.get();
}

void Initialize_Seats(void)
{
// get seats number
	Screen screens[5];
	fstream storedScreens;
	storedScreens.open("storedScreens.csv", ios::in);
	vector<string> row;
	string line, word;
	for( int i = 0 ; i < 5 ; i++ )
	{
		row.clear();
		getline(storedScreens, line); // read row as a line
		stringstream s(line);  // breaking words
		while (getline(s, word, ','))
		{
			row.push_back(word); // make a vector
		}
		screens[i].id 				= row[0];
		screens[i].seats 			= stof(row[1]);
		screens[i].screenFacility 	= row[2];
	}
	storedScreens.close(); // close file
// get seats number
	ofstream screenBookedSeats("screenBookedSeats.csv"); // open or create file
	for( int i = 0 ; i < 5 ; i++ )
	{
		for( int j = 0; j < screens[i].seats; j++)
		{
			screenBookedSeats << 0;
			screenBookedSeats << ",";
		}
		if( i != 4 )
		{
			screenBookedSeats << "\n"; // avoid adding new line at the end
		}
	}
	screenBookedSeats.close();
}

void Choose_Booking_Screen(void)
{
	system("cls");
	int concertNo = 0;
	int screenNumber = 0;
	Movie movies[5];
	Screen screens[5];
	bool *screenSeats = new bool[250];
	fstream storedScreens;
	fstream storedScreensCurrentMovies;
	fstream screenBookedSeats;
	fstream screenBookedSeatsTemp2;
	storedScreens.open("storedScreens.csv", ios::in);
	storedScreensCurrentMovies.open("storedScreensCurrentMovies.csv", ios::in);

	vector<string> row, row2, row3;
	string line, word, line2, word2, line3, word3;
	for( int i = 0 ; i < 5 ; i++ )
	{
		row.clear();
		row2.clear();
		getline(storedScreens, line); // read row as a line
		stringstream s(line);  // breaking words
		while (getline(s, word, ','))
		{
			row.push_back(word); // make a vector
		}
		getline(storedScreensCurrentMovies, line2); // read row as a line
		stringstream s2(line2);  // breaking words
		while (getline(s2, word2, ','))
		{
			row2.push_back(word2); // make a vector
		}
		screens[i].id 				= row[0];
		screens[i].seats 			= stof(row[1]);
		screens[i].screenFacility 	= row[2];
		movies [i].title			= row2[0];
		movies [i].description		= row2[1];
		movies [i].genre			= row2[2];
		movies [i].runningTime		= stof(row2[3]);
		movies [i].mainStar			= row2[4];
		movies [i].releaseDate		= row2[5];
	}
	storedScreens.close(); // close file
	storedScreensCurrentMovies.close(); // close file

	cout << "\n\nChoose a Screen (1-5) :"<<endl;
	cin >>screenNumber;
	while( (screenNumber != SCREEN_1 && screenNumber != SCREEN_2 && screenNumber != SCREEN_3 && screenNumber != SCREEN_4 && screenNumber != SCREEN_5))
	{
	    if (!cin)
	    {
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	    system("cls");
		cout << "Wrong Input! \nPlease Try Again\n\n\n";
		cout << "\n\nChoose a Screen (1-5) :"<<endl;
		cin >>screenNumber;
	}
// Current TIME
	time_t currentTime;
	struct tm *localTime;
	time( &currentTime );
	localTime = localtime( &currentTime );  // Convert the current time to the local time
	Time currentT(localTime->tm_hour, localTime->tm_min);
// Current TIME

// Get next available concert
	float timeNow = localTime->tm_hour + localTime->tm_min/ 60.0 ;
	if( ( timeNow - OPENING_TIME ) < 0 || timeNow > CLOSING_TIME)
	{
		cout << "Concert number ( 1 ) is Available" << endl;
		if(timeNow > CLOSING_TIME)
		{
			cout << "  			For Tomorrow" << endl;
		}
	}
	else
	{
		concertNo = ( (timeNow - OPENING_TIME) / (movies[screenNumber-1].runningTime + 0.417) ) + 2; // calculate concert number with adding gap between two shows
		cout << "Concert number ( " << concertNo << " ) is Available" << endl;
	}
// Get next available concert

// Get stored bookings
	screenBookedSeats.open("screenBookedSeats.csv", ios::in);
	for ( int i = 0 ; i < 5 ; i++ )
	{
		int j = 0;
		row3.clear();
		getline(screenBookedSeats, line3); // read row as a line
		stringstream s3(line3);  // breaking words
		while (getline(s3, word3, ','))
		{
			if(i == (screenNumber - 1))
			{
				row3.push_back(word3); // make a vector
				screenSeats[j] = stoi(row3[j]);
			}
			j++;
		}
	}
	screenBookedSeats.close(); // close file
// Get stored bookings

// Print Screen Seats
	int columns = 10;
	int availableSeats = 0;
	cout << "                         -------------THEATER-------------\n                     ----------------------------------------" << endl << endl;
	for (int i = 1; i <= screens[screenNumber-1].seats; i++)
	{
		if (screenSeats[i-1])
		{
			cout << setw(5) << i << ",X" << "\t";
		}
		else
		{
			cout << setw(5) << i << ",O" << "\t";
			availableSeats ++;
		}
		if (!(i % columns)) cout << endl;
	}
	cout << "                     ----------------------------------------\n                          -------------BACK-------------" << endl;
// Print Screen Seats


// save old bookings in temp
	screenBookedSeats.open("screenBookedSeats.csv", ios::in);
	ofstream screenBookedSeatsTemp("screenBookedSeatsTemp.csv"); // open or create file
	vector<string> rowTemp;
	string lineTemp, wordTemp;
	for( int i = 0 ; i < 5 ; i++ )
	{
		rowTemp.clear();
		getline(screenBookedSeats, lineTemp); // read row as a line
		stringstream sTemp(lineTemp);  // breaking words
		int j = 0;
		while (getline(sTemp, wordTemp, ','))
		{
			rowTemp.push_back(wordTemp); // make a vector
			screenBookedSeatsTemp << stof(rowTemp[j]);
			screenBookedSeatsTemp << ",";
			j++;
		}
		if( i != 4 )
		{
			screenBookedSeatsTemp << "\n"; // avoid adding new line at the end
		}
	}
	screenBookedSeats.close();
	screenBookedSeatsTemp.close(); // close file
// save old bookings in temp

// booking tickets
	int ticketNumber = 0;
	float total = 0;
	cout << "Available seats : " << availableSeats << endl;
	cout << "What is the number of tickets? (from 1 to 10)"<<endl;
	cin >>ticketNumber;
	while( ticketNumber < 1 || ticketNumber > 10 )
	{
	    if (!cin)
	    {
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
		cout << "Wrong Input! \nPlease Try Again\n\n\n";
		cout << "What is the number of tickets? (from 1 to 10)"<<endl;
		cin >>ticketNumber;
	}
    system("cls");

	Ticket newTicket[ticketNumber];
	for( int i = 0 ; i < ticketNumber ; i++)
	{
		// running time
		cout << "Seat ( " << (i+1) <<" ) number: ";
		cin >>newTicket[i].seatNo;
		if(cin)
		{
			for ( int ii = 0; ii < i; ii++ )
			{
				if( newTicket[i].seatNo == newTicket[ii].seatNo )
				{
					newTicket[i].seatNo = 0;
					break;
				}
			}
		}
		while( !cin || (screenSeats[newTicket[i].seatNo - 1] == 1) || newTicket[i].seatNo < 1 || newTicket[i].seatNo > screens[screenNumber-1].seats)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if( screenSeats[newTicket[i].seatNo - 1] == 1 || newTicket[i].seatNo < 1 || newTicket[i].seatNo > screens[screenNumber-1].seats )
			{
				cout << "Seat is not available! \nPlease! Make another choice\n\n\n";
				cout << "Seat ( " << (i+1) <<" ) number: ";
			}
			else
			{
				cout << "Wrong Input! \nPlease Try Again\n\n\n";
				cout << "Seat ( " << (i+1) <<" ) number: ";
			}
			cin >>newTicket[i].seatNo;
			if(cin)
			{
				for ( int ii = 0; ii < i; ii++ )
				{
					if( newTicket[i].seatNo == newTicket[ii].seatNo )
					{
						newTicket[i].seatNo = 0;
						break;
					}
				}
			}
		}
		cout << endl;
		cout << "Ticket Category :\n1- Adults\n2- Children\n3- Senior Citizens\n4- Students" << endl;
		cin >>newTicket[i].category;
		while( newTicket[i].category < 1 || newTicket[i].category > 4 )
			{
			    if (!cin)
			    {
			      cin.clear();
			      cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    }
			    system("cls");
				cout << "Wrong Input! \nPlease Try Again\n\n\n";
				cout << "Ticket Category :\n1- Adults\n2- Children\n3- Senior Citizens\n4- Students" << endl;
				cin >>newTicket[i].category;
			}
		switch (newTicket[i].category) {
			case 1:
				total += adults;
				break;
			case 2:
				total += children;
				break;
			case 3:
				total += seniorCitizens;
				break;
			case 4:
				total += students;
				break;
		}
	}
	int payment = 0;
	cout << "Choose Which payment type You want?\n1- CASH\n2- CARD"<<endl;
	cin >>payment;
	while( (payment != CASH && payment != CARD) )
	{
	    if (!cin)
	    {
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	    system("cls");
		cout << "Wrong Input! \nPlease Try Again\n\n\n";
		cout << "Choose Which payment type You want?\n1- CASH\n2- CARD"<<endl;
		cin >>payment;
	}
	float concertTime = OPENING_TIME + ( concertNo - 1 ) * ( movies[screenNumber-1].runningTime + 0.417 ) ;
	time_t dateTime = system_clock::to_time_t(system_clock::now());
    system("cls");
	cout << "Date and Time for booking : " << ctime(&dateTime);
	cout << "Movie : " << movies[screenNumber-1].title << endl;
	cout << "Concert Time : " <<  ( (int) concertTime ) << ":" << (int) ( ( concertTime - ( (int) concertTime ) ) * 60 ) << endl;
	cout << "Screen number ( " << screenNumber << " ) : " << screens[screenNumber-1].id << endl;
	cout << "Payment : ";
	if(payment == CASH) cout << "CASH" <<endl; else if(payment == CARD) cout << "CARD" << endl;
	cout << "Total : " << total << endl;
	cout << "  ^_^" << endl;

// saving booking (update)
	screenBookedSeatsTemp2.open("screenBookedSeatsTemp.csv", ios::in);
	ofstream screenBookedSeats_2("screenBookedSeats.csv"); // open or create file
	vector<string> rowTemp2;
	string lineTemp2, wordTemp2;
	for( int i = 0 ; i < 5 ; i++ )
	{
		rowTemp2.clear();
		getline(screenBookedSeatsTemp2, lineTemp2); // read row as a line
		stringstream sTemp2(lineTemp2);  // breaking words
		int j = 0;
		while (getline(sTemp2, wordTemp2, ','))
		{
			rowTemp2.push_back(wordTemp2); // make a vector
			if( (screenNumber - 1) == i )
			{
				int tempo = 0;
				for ( int z = 0 ; z < ticketNumber; z++)
				{
					if( ( newTicket[z].seatNo - 1 ) == j) { tempo += 1; screenBookedSeats_2 << tempo; }
					else { screenBookedSeats_2 << stof(rowTemp2[j]); }
				}
//				screenBookedSeats_2 << tempo;
			}
			else
			{
				screenBookedSeats_2 << stof(rowTemp2[j]);
			}
			screenBookedSeats_2 << ",";
			j++;
		}
		if( i != 4 )
		{
			screenBookedSeats_2 << "\n"; // avoid adding new line at the end
		}
	}
	screenBookedSeats_2.close();
	screenBookedSeatsTemp2.close(); // close file
// saving booking (update)
// booking tickets
	cin.ignore();cin.get();
}

void ShowWeeklySchedule(void)
{
	Show_Screens_Details();
	int dayNow = 0;
	fstream storedMovies;
	string dayStr = "";
	time_t dateTime = system_clock::to_time_t(system_clock::now());
	for(int i = 0; i < 3; i++)
	{
		dayStr += ctime(&dateTime)[i];
	}
	if(dayStr == "Thu"){dayNow=Thu;} else if(dayStr == "Fri"){dayNow=Fri;} else if(dayStr == "Sat"){dayNow=Sat;} else if(dayStr == "Sun"){dayNow=Sun;} else if(dayStr == "Mon"){dayNow=Mon;} else if(dayStr == "Tue"){dayNow=Tue;} else if(dayStr == "Wed"){dayNow=Wed;}
	if(dayNow > 5) cout << "Warning: you're about to start a new week. \nMake sure you have added your new movies into the system." << endl;
	cout << "Stored Next Week Movies: " << endl;

	storedMovies.open("storedMovies.csv", ios::in);
    vector<string> row;
    string line, word;
	for( int i = 0 ; i < 5 ; i++)
	{
		row.clear();
        getline(storedMovies, line); // read row as a line
        stringstream s(line);  // breaking words
        while (getline(s, word, ','))
        {
            row.push_back(word); // make a vector
        }

        cout << "\nMovie number "; cout << (i+1); cout << ":\n";
        cout << "\nTitle 	   	: "; 		cout << row[0];
        cout << "\nDescription 	: "; 		cout << row[1];
        cout << "\nGenre 		: "; 		cout << row[2];
        cout << "\nRunningTime 	: "; 		cout << row[3];
        cout << "\nMainStar 	: ";		cout << row[4];
        cout << "\nReleaseDate 	: ";		cout << row[5] << endl;
	}
	storedMovies.close(); // close file
	cin.ignore();cin.get();
}
