#include "MyForm.h"
#include "Products.h"
#include <msclr/marshal_cppstd.h>



Products product;


int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew lab7::MyForm());
    return 0;
}

System::Void lab7::MyForm::save_filename_button_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ filename_input = filename_textBox->Text;
    if (String::IsNullOrWhiteSpace(filename_input)) {
        MessageBox::Show(gcnew String("Filename field is empty, please enter something"), "Error");
        return;
    }

    product.setFilename(msclr::interop::marshal_as<std::string>(filename_input));
    product.setFilename_txt();
    product.saveFilename();
    //MessageBox::Show("Filename was successfully saved");
    std::cout << product.getFilename() << std::endl;
    return System::Void();
}

System::Void lab7::MyForm::clear_file_button_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        product.clearFileData();
    }
    catch (const std::exception& e) {
        MessageBox::Show(gcnew String(e.what()), "Error");
    }
    return System::Void();
}

System::Void lab7::MyForm::save_date_button_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ date_input = date_textBox->Text;
    if (String::IsNullOrWhiteSpace(date_input)) {
        MessageBox::Show(gcnew String("Date field is empty, please enter something"), "Error");
        return;
    }

    bool exceptionOccurred = false;
    std::string date_input_str = msclr::interop::marshal_as<std::string>(date_input);

    try {
        product.isValidDateFormat(date_input_str);
        product.isValidDate(date_input_str);
    }

    catch (const std::exception& e) {
        MessageBox::Show(gcnew String(e.what()), "Error");
        exceptionOccurred = true;
    }

    if (!exceptionOccurred){
        product.setDate(date_input_str);
        MessageBox::Show("Date was successfully saved");
    
    }
    return System::Void();
}

System::Void lab7::MyForm::save_product_button_Click(System::Object^ sender, System::EventArgs^ e)
{
    
    System::String^ name_input = name_of_product_textBox->Text;
    System::String^ expiryDate_input = expiry_date_textBox->Text;



    if (String::IsNullOrWhiteSpace(name_input)) {
        MessageBox::Show(gcnew String("Name of product field is empty, please enter something"), "Error");
        return;
    }
    if (String::IsNullOrWhiteSpace(expiryDate_input)) {
        MessageBox::Show(gcnew String("Expiry date of product field is empty, please enter something"), "Error");
        return;
    }

    bool exceptionOccurred = false;
    std::string name_of_prod = msclr::interop::marshal_as<std::string>(name_input);
    std::string expiryDate_of_prod = msclr::interop::marshal_as<std::string>(expiryDate_input);



    try {
        product.isValidDateFormat(expiryDate_of_prod);
        product.isValidDate(expiryDate_of_prod);
    }

    catch (const std::exception& e) {
        MessageBox::Show(gcnew System::String(e.what()), "Error");
        exceptionOccurred = true;
    }

    if (!exceptionOccurred) {
        try{
        product.saveToFile(name_of_prod, expiryDate_of_prod);
        }
        catch (const std::exception& e) {
            MessageBox::Show(gcnew System::String(e.what()), "Error");
            return;
        }

        MessageBox::Show("Product saved successfully.", "Success");
        name_of_product_textBox->Clear();
        expiry_date_textBox->Clear();
    }



    return System::Void();
}

System::Void lab7::MyForm::get_expiry_prod_button_Click(System::Object^ sender, System::EventArgs^ e)
{

    std::cout << product.getDate() << std::endl;
    if (product.getDate().empty()) {
        MessageBox::Show("Date field is empty, please enter something");
        return;
    }
    expired_products_textBox->Clear();
    
    int count = 0;
    try {
    product.loadFromFile();

    } catch (const std::exception& e) {
        MessageBox::Show(gcnew String(e.what()), "Error");
    }

    try {
        for (int i = 0; i < product.getnumProducts(); i++) {
            if (product.isExpired(product.getProduct(i).expiryDate)) {
                expired_products_textBox->AppendText(gcnew String(product.getProduct(i).name.c_str()) + "\r\n");
                count += 1;
            }
        }

    

    }
    catch (const std::exception& e) {
        MessageBox::Show(gcnew String(e.what()), "Error");
    }
    if (count == 0) {
        MessageBox::Show("There are no expiry product in this file");
    }
    product.clearProduct();

    return System::Void();
}

System::Void lab7::MyForm::output_file_content_button_Click(System::Object^ sender, System::EventArgs^ e)
{

    filedata_textBox->Clear();
    try{
    product.data_from_file_to_textbox(filedata_textBox);
    }
    catch (const std::exception& e) {
        MessageBox::Show(gcnew String(e.what()), "Error");
    }
    return System::Void();
}
