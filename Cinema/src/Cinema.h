
#ifndef CINEMA_H_
#define CINEMA_H_

#include <string>
using namespace std;

#define OPEN_DURATION 13.25
#define OPENING_TIME  10.25
#define CLOSING_TIME  23.5

#define ADULT			9.5
#define CHILDREN		5.5
#define SENIO_CITIZEN	6.5
#define STUDENT			7.0



// enums
enum userType
{
	MASTER = 1,
	USER   = 2
};
enum newOrDefaultMovies
{
	NEW_MOVIES 		= 1,
	STORED_MOVIES 	= 2
};
enum masterOptions
{
	SWITCH_USER 	= 1,
	EDIT_MOVIES 	= 2,
	EDIT_SCREENS 	= 3,
	EXIT			= 4
};
enum userOptions
{
	BOOKING = 1,
	SHOW_SCHEDULE = 2,
	EXIT2 = 3
};
enum screenOptions
{
	EDIT_SCREENS_MOVIES	 = 1,
	EDIT_SCREENS_DETAILS = 2
};
enum screenNumber
{
	SCREEN_1 = 1,
	SCREEN_2 = 2,
	SCREEN_3 = 3,
	SCREEN_4 = 4,
	SCREEN_5 = 5,
};
enum payment{
	CASH = 1,
	CARD = 2
};
enum weekDays
{
	Thu = 1,
	Fri = 2,
	Sat = 3,
	Sun = 4,
	Mon = 5,
	Tue = 6,
	Wed = 7
};
// classes
class Movie {
  public:
    string title;
    string description;
    string genre;
    float  runningTime;
    string mainStar;
    string releaseDate;
};
class Screen {
  public:
    string 	id;
    int     seats;
    string 	screenFacility;
};
class Time {
private:
	int hours, minutes;
public:
	Time(int h = 0, int m = 0) {hours = h; minutes = m;}

	Time operator + (Time const &obj){
		Time res;
		res.hours 	= hours + obj.hours + (minutes + obj.minutes) / 60;
		res.minutes = (minutes + obj.minutes) % 60;
		return res;
	}
	void printNextTime(){ cout << "h : " << hours << " m : " << minutes ; };
};
class Ticket{
	public:
		int seatNo;
		int category;
};
// Functions Prototypes
// MASTER
int  Get_User			(void);
int  Get_Master_Action	(void);
void Edit_Movie_File	(void);
void Edit_Screen_File	(void);
// USER
int  Get_User_Action		(void);
void Show_Screens_Details	(void);
void Initialize_Seats		(void);
void Choose_Booking_Screen	(void);
void ShowWeeklySchedule 	(void);

#endif /* CINEMA_H_ */
