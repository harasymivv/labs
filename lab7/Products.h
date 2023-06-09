#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <string>
#include <Windows.h>

using namespace System::Windows::Forms;

class Products {
private:
    struct Product {
        std::string name;
        std::string expiryDate;
    };

    static const int MAX_PRODUCTS = 100;
    Product products[MAX_PRODUCTS];
    int numProducts;
    std::string filename;
    std::string date;
public:
    Products() : numProducts(0) {
    }

    const Product& getProduct(int index) const {
        if (index >= 0 && index < numProducts) 
           return products[index];
        else throw std::out_of_range("Invalid product index");
    }

    int getnumProducts() const {return numProducts;}
    void setFilename(const std::string& newFilename) {filename = newFilename; }
    void setDate(const std::string& Data) { date = Data; }

    std::string getFilename() { return filename ; }
    std::string getDate() { return date; }

    void clearProduct();

    void setFilename_txt();
    void loadFromFile();
    void saveFilename();
    void saveToFile(const std::string& name, const std::string& expiryDate);
    void clearFileData();
    void data_from_file_to_textbox(System::Windows::Forms::TextBox^ expired_product_textBox);
    void isValidDateFormat(const std::string& date);
    void isValidDate(const std::string& date);
    bool isExpired(const std::string& expiryDate);

};
