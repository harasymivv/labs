#include <iostream>
#include <cstring>
#include "class.h"

using namespace std;

BooleanVector::BooleanVector(int n)
{
  data = new bool[n];
  size = n;
  for (int i = 0; i < n; i++)
  {
    data[i] = (i % 2 == 0);
  }
}

BooleanVector::BooleanVector(bool *input_data, int n)
{
  data = new bool[n];
  size = n;
  for (int i = 0; i < n; i++)
  {
    data[i] = input_data[i];
  }
}

BooleanVector::BooleanVector()
{
  data = nullptr;
  size = 0;
}

BooleanVector::~BooleanVector()
{
  delete[] data;
}

int BooleanVector::getSize() const
{
  return size;
}

bool BooleanVector::getComponent(int index) const
{
  return data[index];
}

void BooleanVector::setComponent(int index, bool value)
{
  data[index] = value;
}

int BooleanVector::getWeight() const
{
  int weight = 0;
  for (int i = 0; i < size; i++)
  {
    if (data[i])
    {
      weight++;
    }
  }
  return weight;
}

void BooleanVector::print_array()
{
  cout << "| ";
  for (int i = 0; i < size; i++)
  {
    cout << data[i] << " ";
  }
  cout << "|" << endl;
}

BooleanVector &BooleanVector::operator&(const BooleanVector &other)
{
  for (int i = 0; i < size; i++)
  {
    data[i] = data[i] && other.data[i];
  }
  return *this;
}

BooleanVector &BooleanVector::operator~()
{
  for (int i = 0; i < size; i++)
  {
    data[i] = !data[i];
  }
  return *this;
}

bool *get_data_from_user(int &size)
{

  do
  {
    cout << "Enter number of elements: ";
    cin >> size;

    if (size <= 0)
    {
      cout << "Invalid input. Size must be positive." << endl;
      cin.clear();
      cin.ignore();
    }
  } while (size <= 0);
  bool *array = new bool[size];

  cout << "Enter elements of boolean vector (0, 1), where 0 - False, 1 - True.\n" << endl;
  for (int i = 0; i < size; i++)
  {
    bool element;
    bool valid_input = false;
    do
    {
      cout << "Enter element number " << i + 1 << ": ";
      if (cin >> element)
      {
        valid_input = true;
      }
      else
      {
        cout << "Invalid input. Please enter either 0 or 1.\n";
        cin.clear();
        cin.ignore();
      }
    } while (!valid_input);
    array[i] = element;
  }
  return array;
}