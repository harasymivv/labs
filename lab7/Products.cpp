#include "Products.h"
#include "MyForm.h"



void Products::clearProduct()
{   
    numProducts = 0; 

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i].name = "";
        products[i].expiryDate = "";
    }
}


void Products::setFilename_txt()
{
    filename = filename + ".txt";
}

void Products::loadFromFile() {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Unable to open file.");
    }

    file.seekg(0, std::ios::end);
    if (file.tellg() == 0) {
        MessageBox::Show("File is empty");
    }
    file.seekg(std::ios::end, 0);

    std::string line;

    while (std::getline(file, line)) {
        if (numProducts >= MAX_PRODUCTS) {
            throw std::overflow_error("Too many products, max num of products = 100");;
            break;
        }

        std::istringstream iss(line);
        std::string name_of_product;
        std::string date;

        if (std::getline(iss, name_of_product, ',') && std::getline(iss, date)) {
            products[numProducts] = { name_of_product, date };
            numProducts++;
        }
    }


    file.close();

}

void Products::saveFilename()
{
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        throw std::runtime_error("Unable to open file.");
    }

    file.close();
    MessageBox::Show("File successfully created");
    
}

void Products::saveToFile(const std::string& name, const std::string& expiryDate) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        throw std::runtime_error("Unable to open file.");
    }


    file << name << "," << expiryDate << "\n";
    

    file.close();
}

void Products::clearFileData() {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file) {
        file.close();
        MessageBox::Show("File data cleared.");
    }
    else {
        throw std::runtime_error("Failed to open the file.");
    }
}


void Products::data_from_file_to_textbox(System::Windows::Forms::TextBox^ expired_products_textBox)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file.");
        return;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        throw std::logic_error("This file is empty");
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word1, word2;
        if (std::getline(iss, word1, ',') && std::getline(iss, word2)) {

            expired_products_textBox->AppendText(gcnew System::String(word1.c_str()) + ": " + gcnew System::String(word2.c_str()) + "\r\n");
        }
    }
}

void Products::isValidDateFormat(const std::string& date) {

    if (date.length() != 10) {
        throw std::invalid_argument("Incorrect length of date");
    }

    if (date[2] != '.' || date[5] != '.') {
        throw std::invalid_argument("Invalid punctuation, ");
    }
}

void Products::isValidDate(const std::string& date) {

    for (char c : date) {
        if (!isdigit(c) && !ispunct(c)) {
            throw std::invalid_argument("Wrong type of value, enter only integer");
            return;
        }
    }

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));


    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1000) {
        throw std::invalid_argument("Invalid date");
    }


    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int daysInMonth;
    switch (month) {
    case 2: // February
        daysInMonth = isLeapYear ? 29 : 28;
        break;
    case 4: // April
    case 6: // June
    case 9: // September
    case 11: // November
        daysInMonth = 30;
        break;
    default:
        daysInMonth = 31;
        break;
    }

    if (day > daysInMonth) {
        throw std::invalid_argument("Invalid date in month");
    }


}

bool Products::isExpired(const std::string& expiryDate) {
    int expiryDay = std::stoi(expiryDate.substr(0, 2));
    int expiryMonth = std::stoi(expiryDate.substr(3, 2));
    int expiryYear = std::stoi(expiryDate.substr(6, 4));

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));


    if (expiryYear < year) {
        return true;
    }
    else if (expiryYear == year) {
        if (expiryMonth < month) {
            return true;
        }
        else if (expiryMonth == month && expiryDay < day) {
            return true;
        }
    }

    return false;
}