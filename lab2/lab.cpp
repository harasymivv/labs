#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <conio.h>
#include "func.h"

using namespace std;


int main()
{

  string infilename;
  char check;
  cout << "Enter file name: ";
  cin >> infilename;
  string filename = infilename + ".bin";

   

  do
  {
    add_conversation(filename);

    cout << "\nDo you want to appent some text?" << endl;
    check = getch();

  } while (check == '\r');

  read_negotiations_from_file(filename);

  cout << "\nDaytime file: " << endl;
  cout << "-----------------------------------------------------------------" << endl;
  read_output_file("daytime_calls.bin");
  cout << "-----------------------------------------------------------------\n" << endl;
  cout << "Nighttime file: " << endl;
  cout << "-----------------------------------------------------------------" << endl;
  read_output_file("nighttime_calls.bin");
  cout << "-----------------------------------------------------------------\n" << endl;
  return 0;
}

