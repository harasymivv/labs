#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

struct Conversation
{
  char phone_number[20];
  char start_time[6];
  char end_time[6];
};

bool calc_minutes (char* startTime, char* endTime){

    char minutes_start[3];
    char minutes_end[3];
    minutes_start[0] = startTime[3];
    minutes_start[1] = startTime[4];
    minutes_start[2] = '\0';
    
    minutes_end[0] = endTime[3];
    minutes_end[1] = endTime[4];
    minutes_end[2] = '\0';

    int startMinute = atoi(minutes_start);
    int endMinute = atoi(minutes_end);

    if (startMinute > endMinute) {
        return true;
    }
    else if (startMinute < endMinute) {
        return false;
    }
    else {
        return true;
    }

}

bool calculate_time(char* startTime, char* endTime){
    int trashhold_1 = 20;
    int trashhold_2 = 6;
    char hours_start[3];
    char hours_end[3];

    hours_start[0] = startTime[0];
    hours_start[1] = startTime[1];
    hours_start[2] = '\0';

    hours_end[0] = endTime[0];
    hours_end[1] = endTime[1];
    hours_end[2] = '\0';

    int startHour = atoi(hours_start);
    int endHour = atoi(hours_end);

    int time_to_trashhold_start;
    int time_to_trashhold_end;

    if ((startHour >= 6 && startHour < 20) && (endHour >= 6 && endHour < 20)) return true;
    else if ((startHour >= 20 && endHour >= 20) || ((startHour < 6 && endHour < 6)) || 
    (startHour >= 20 && endHour < 6)) return false;

    else {

    if (startHour >= 6 && endHour >= 20){
        time_to_trashhold_start = abs(trashhold_1 - startHour);
        time_to_trashhold_end = abs(trashhold_1 - endHour);
    }
    else if (startHour >= 6 && endHour < 6){
        time_to_trashhold_start = abs(trashhold_1 - startHour);
        time_to_trashhold_end = endHour + 4 ;
    }  
    else if (startHour >= 20 && endHour >= 6){
        time_to_trashhold_end = (24 - startHour) + 6;
        time_to_trashhold_start = abs(trashhold_2 - endHour);

    }
    else if (startHour < 6 && endHour >= 6){
        time_to_trashhold_end = abs(trashhold_2 - startHour);
        time_to_trashhold_start = abs(trashhold_2 - endHour);

    }


    if (time_to_trashhold_start > time_to_trashhold_end) 
    return true;

    else if (time_to_trashhold_start < time_to_trashhold_end)
    return false;

    else return (calc_minutes(startTime, endTime));
    }
}

bool checkTimeFormat(char *input)
{
  // Check if input is of length 5 and the third character is a colon
  if (strlen(input) == 5 && input[2] == ':')
  {
    // Check if the first two characters are digits between 0 and 2
    if (input[0] >= '0' && input[0] <= '2' && isdigit(input[1]))
    {
      // Check if the last two characters are digits between 0 and 5
      if (input[3] >= '0' && input[3] <= '5' && isdigit(input[4]))
      {
        // Check if the time is within the valid range
        if (input[0] == '2')
        {
          // If the first digit is 2, the second digit cannot be greater than 3
          if (input[1] <= '3')
          {
            return true; // The input is in the correct format and range
          }
        }
        else
        {
          // If the first digit is 0 or 1, the second digit can be any digit
          return true; // The input is in the correct format and range
        }
      }
    }
  }
  return false; // The input is not in the correct format or range
}

void add_conversation(string filename)
{
  Conversation convo;

  do {

  cout << "\nEnter phone number: ";
  cin >> convo.phone_number;
  if (strlen(convo.phone_number) > 20){
    cout << "Too long phone number. Try again." << endl;
  }
  }while((strlen(convo.phone_number) > 20));

    cin.ignore();
    do
    {
      cout << "Enter start time (YY:XX): ";
      cin >> convo.start_time;
      if (!checkTimeFormat(convo.start_time))
      {
        cout << "Wrong input format. Try again." << endl;
      }
    } while (!checkTimeFormat(convo.start_time));

    do
    {
      cout << "Enter end time (YY:XX): ";
      cin >> convo.end_time;
      if (!checkTimeFormat(convo.end_time))
      {
        cout << "Wrong input format. Try again." << endl;
      }
    } while (!checkTimeFormat(convo.end_time));
    cin.ignore();


  ofstream outfile(filename, ios::binary | ios::app);
  if (outfile.is_open())
  {
    outfile.write((char *)&convo, sizeof(Conversation));
    outfile.close();
    cout << "Conversation added successfully.\n";
  }
  else
  {
    cout << "Error: Unable to open file.\n";
  }
}

void read_negotiations_from_file(string filename)
{

  ifstream file(filename, ios::binary);
  ofstream fout_day("daytime_calls.bin", ios::binary);
  ofstream fout_night("nighttime_calls.bin", ios::binary);
  if (!file)
  {
    cout << "Error: could not open file " << filename << endl;
    return;
  }

  Conversation negotiation;
  while (file.read((char *)&negotiation, sizeof(Conversation)))
  {

    if (calculate_time(negotiation.start_time, negotiation.end_time)){
     fout_day.write((char*)&negotiation, sizeof(Conversation));
     
     }
    else {
      fout_night.write((char*)&negotiation, sizeof(Conversation));
    }
    

  }

  file.close();
  fout_day.close();
  fout_night.close();
}

void read_output_file(const string& filename)

{
  ifstream infile(filename, ios::binary | ios::in);
  
  if (!infile)
  {
    cerr << "Error: could not open file " << filename << endl;
    return;
  }
  Conversation conv;
  while (infile.read(reinterpret_cast<char*>(&conv), sizeof(Conversation)))
  {
    cout << "| Phone number: " << conv.phone_number << " | Start time: " << conv.start_time << " | End time: " << conv.end_time << " |"<< endl;
  }

  infile.close();
}


