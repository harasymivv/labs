#pragma once
#include <string>

using namespace std;

void name_of_file(string& filename);
void removeSingleCharWords(string& str, int& count);
void removeSequentialPunctuation(string& result, int& spacesRemoved, int& commasRemoved, int& periodsRemoved);
void removeSingleCharWordWithPunctuation(string& str, int& removedWordsWithpunct);
void removeSpace(string &result, int &spacesRemoved);
void removeSingleCharWordsFromFile(const string& filename, int& removedWords, int& removedWordsWithpunct, int& spacesRemoved, int& commasRemoved, int& periodsRemoved);
void writeToOutputFile(string filename, int removedWords, int removedWordsWithpunct, int spacesRemoved, int commasRemoved, int periodsRemoved);
void append_text_to_file(string filename);
void create_text_file(string filename);

void name_of_file(char* filename);
void removeSingleCharWords(char *str, int *count);
void removeSequentialPunctuation(char *result, int *spacesRemoved, int *commasRemoved, int *periodsRemoved);
void removeSpace(char *result, int& spacesRemoved);
void removeSingleCharWordWithPunctuation(char* str, int* num_deleted);
void remove_last_character(char* str, int& count);
void removeSingleCharWordsFromFile(const char* filename, int* removedWords, int* removedWordsWithpunct, int* spacesRemoved, int* commasRemoved, int* periodsRemoved);
void writeToOutputFile(const char* filename, int removedWords, int removedWordsWithpunct, int spacesRemoved, int commasRemoved, int periodsRemoved);
void append_text_to_file(const char* filename);
void create_text_file(const char* filename);


void printFileContents();
bool isMode(const char *modeValue, int argc, char *argv[]);