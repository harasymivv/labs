#pragma once

namespace lab7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ filename_textBox;
	protected:

	private: System::Windows::Forms::Button^ save_date_button;
	private: System::Windows::Forms::TextBox^ name_of_product_textBox;
	protected:



	private: System::Windows::Forms::Label^ label_for_filename;
	private: System::Windows::Forms::Label^ label_name_of_product;
	private: System::Windows::Forms::Label^ label_expiry_date;

	private: System::Windows::Forms::Label^ label_data;
	private: System::Windows::Forms::TextBox^ expiry_date_textBox;



	private: System::Windows::Forms::TextBox^ date_textBox;

	private: System::Windows::Forms::Button^ save_filename_button;
	private: System::Windows::Forms::Button^ save_product_button;
	private: System::Windows::Forms::Label^ label_filedata;
	private: System::Windows::Forms::TextBox^ filedata_textBox;
	private: System::Windows::Forms::TextBox^ expired_products_textBox;
	private: System::Windows::Forms::Label^ expired_products_label;
	private: System::Windows::Forms::Button^ clear_file_button;
	private: System::Windows::Forms::Button^ get_expiry_prod_button;
	private: System::Windows::Forms::Button^ output_file_content_button;
	private: System::Windows::Forms::Label^ label1;







	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->filename_textBox = (gcnew System::Windows::Forms::TextBox());
			this->save_date_button = (gcnew System::Windows::Forms::Button());
			this->name_of_product_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label_for_filename = (gcnew System::Windows::Forms::Label());
			this->label_name_of_product = (gcnew System::Windows::Forms::Label());
			this->label_expiry_date = (gcnew System::Windows::Forms::Label());
			this->label_data = (gcnew System::Windows::Forms::Label());
			this->expiry_date_textBox = (gcnew System::Windows::Forms::TextBox());
			this->date_textBox = (gcnew System::Windows::Forms::TextBox());
			this->save_filename_button = (gcnew System::Windows::Forms::Button());
			this->save_product_button = (gcnew System::Windows::Forms::Button());
			this->label_filedata = (gcnew System::Windows::Forms::Label());
			this->filedata_textBox = (gcnew System::Windows::Forms::TextBox());
			this->expired_products_textBox = (gcnew System::Windows::Forms::TextBox());
			this->expired_products_label = (gcnew System::Windows::Forms::Label());
			this->clear_file_button = (gcnew System::Windows::Forms::Button());
			this->get_expiry_prod_button = (gcnew System::Windows::Forms::Button());
			this->output_file_content_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// filename_textBox
			// 
			this->filename_textBox->Location = System::Drawing::Point(26, 107);
			this->filename_textBox->Name = L"filename_textBox";
			this->filename_textBox->Size = System::Drawing::Size(176, 20);
			this->filename_textBox->TabIndex = 0;
			// 
			// save_date_button
			// 
			this->save_date_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->save_date_button->Location = System::Drawing::Point(267, 145);
			this->save_date_button->Name = L"save_date_button";
			this->save_date_button->Size = System::Drawing::Size(127, 33);
			this->save_date_button->TabIndex = 1;
			this->save_date_button->Text = L"Save date";
			this->save_date_button->UseVisualStyleBackColor = true;
			this->save_date_button->Click += gcnew System::EventHandler(this, &MyForm::save_date_button_Click);
			// 
			// name_of_product_textBox
			// 
			this->name_of_product_textBox->Location = System::Drawing::Point(26, 318);
			this->name_of_product_textBox->Name = L"name_of_product_textBox";
			this->name_of_product_textBox->Size = System::Drawing::Size(176, 20);
			this->name_of_product_textBox->TabIndex = 2;
			// 
			// label_for_filename
			// 
			this->label_for_filename->AutoSize = true;
			this->label_for_filename->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_for_filename->Location = System::Drawing::Point(22, 73);
			this->label_for_filename->Name = L"label_for_filename";
			this->label_for_filename->Size = System::Drawing::Size(120, 20);
			this->label_for_filename->TabIndex = 4;
			this->label_for_filename->Text = L"Enter filename: ";
			// 
			// label_name_of_product
			// 
			this->label_name_of_product->AutoSize = true;
			this->label_name_of_product->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_name_of_product->Location = System::Drawing::Point(22, 280);
			this->label_name_of_product->Name = L"label_name_of_product";
			this->label_name_of_product->Size = System::Drawing::Size(180, 20);
			this->label_name_of_product->TabIndex = 5;
			this->label_name_of_product->Text = L"Enter name of product:  ";
			// 
			// label_expiry_date
			// 
			this->label_expiry_date->AutoSize = true;
			this->label_expiry_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_expiry_date->Location = System::Drawing::Point(263, 280);
			this->label_expiry_date->Name = L"label_expiry_date";
			this->label_expiry_date->Size = System::Drawing::Size(136, 20);
			this->label_expiry_date->TabIndex = 9;
			this->label_expiry_date->Text = L"Enter expiry date: ";
			// 
			// label_data
			// 
			this->label_data->AutoSize = true;
			this->label_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_data->Location = System::Drawing::Point(263, 73);
			this->label_data->Name = L"label_data";
			this->label_data->Size = System::Drawing::Size(92, 20);
			this->label_data->TabIndex = 8;
			this->label_data->Text = L"Enter date: ";
			// 
			// expiry_date_textBox
			// 
			this->expiry_date_textBox->Location = System::Drawing::Point(267, 318);
			this->expiry_date_textBox->Name = L"expiry_date_textBox";
			this->expiry_date_textBox->Size = System::Drawing::Size(127, 20);
			this->expiry_date_textBox->TabIndex = 7;
			// 
			// date_textBox
			// 
			this->date_textBox->Location = System::Drawing::Point(267, 107);
			this->date_textBox->Name = L"date_textBox";
			this->date_textBox->Size = System::Drawing::Size(127, 20);
			this->date_textBox->TabIndex = 6;
			// 
			// save_filename_button
			// 
			this->save_filename_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->save_filename_button->Location = System::Drawing::Point(26, 145);
			this->save_filename_button->Name = L"save_filename_button";
			this->save_filename_button->Size = System::Drawing::Size(78, 48);
			this->save_filename_button->TabIndex = 10;
			this->save_filename_button->Text = L"Save filename";
			this->save_filename_button->UseVisualStyleBackColor = true;
			this->save_filename_button->Click += gcnew System::EventHandler(this, &MyForm::save_filename_button_Click);
			// 
			// save_product_button
			// 
			this->save_product_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->save_product_button->Location = System::Drawing::Point(267, 357);
			this->save_product_button->Name = L"save_product_button";
			this->save_product_button->Size = System::Drawing::Size(127, 33);
			this->save_product_button->TabIndex = 11;
			this->save_product_button->Text = L"Save product";
			this->save_product_button->UseVisualStyleBackColor = true;
			this->save_product_button->Click += gcnew System::EventHandler(this, &MyForm::save_product_button_Click);
			// 
			// label_filedata
			// 
			this->label_filedata->AutoSize = true;
			this->label_filedata->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_filedata->Location = System::Drawing::Point(536, 73);
			this->label_filedata->Name = L"label_filedata";
			this->label_filedata->Size = System::Drawing::Size(179, 20);
			this->label_filedata->TabIndex = 12;
			this->label_filedata->Text = L"The contents of the file: ";
			// 
			// filedata_textBox
			// 
			this->filedata_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->filedata_textBox->Location = System::Drawing::Point(540, 107);
			this->filedata_textBox->Multiline = true;
			this->filedata_textBox->Name = L"filedata_textBox";
			this->filedata_textBox->ReadOnly = true;
			this->filedata_textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->filedata_textBox->Size = System::Drawing::Size(375, 153);
			this->filedata_textBox->TabIndex = 13;
			// 
			// expired_products_textBox
			// 
			this->expired_products_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->expired_products_textBox->Location = System::Drawing::Point(540, 318);
			this->expired_products_textBox->Multiline = true;
			this->expired_products_textBox->Name = L"expired_products_textBox";
			this->expired_products_textBox->ReadOnly = true;
			this->expired_products_textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->expired_products_textBox->Size = System::Drawing::Size(375, 154);
			this->expired_products_textBox->TabIndex = 15;
			// 
			// expired_products_label
			// 
			this->expired_products_label->AutoSize = true;
			this->expired_products_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->expired_products_label->Location = System::Drawing::Point(536, 284);
			this->expired_products_label->Name = L"expired_products_label";
			this->expired_products_label->Size = System::Drawing::Size(136, 20);
			this->expired_products_label->TabIndex = 14;
			this->expired_products_label->Text = L"Expired products: ";
			// 
			// clear_file_button
			// 
			this->clear_file_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->clear_file_button->Location = System::Drawing::Point(122, 145);
			this->clear_file_button->Name = L"clear_file_button";
			this->clear_file_button->Size = System::Drawing::Size(80, 48);
			this->clear_file_button->TabIndex = 16;
			this->clear_file_button->Text = L"Clear file";
			this->clear_file_button->UseVisualStyleBackColor = true;
			this->clear_file_button->Click += gcnew System::EventHandler(this, &MyForm::clear_file_button_Click);
			// 
			// get_expiry_prod_button
			// 
			this->get_expiry_prod_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->get_expiry_prod_button->Location = System::Drawing::Point(267, 427);
			this->get_expiry_prod_button->Name = L"get_expiry_prod_button";
			this->get_expiry_prod_button->Size = System::Drawing::Size(127, 45);
			this->get_expiry_prod_button->TabIndex = 17;
			this->get_expiry_prod_button->Text = L"Get expired products";
			this->get_expiry_prod_button->UseVisualStyleBackColor = true;
			this->get_expiry_prod_button->Click += gcnew System::EventHandler(this, &MyForm::get_expiry_prod_button_Click);
			// 
			// output_file_content_button
			// 
			this->output_file_content_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->output_file_content_button->Location = System::Drawing::Point(26, 357);
			this->output_file_content_button->Name = L"output_file_content_button";
			this->output_file_content_button->Size = System::Drawing::Size(176, 33);
			this->output_file_content_button->TabIndex = 18;
			this->output_file_content_button->Text = L"Output the content of the file";
			this->output_file_content_button->UseVisualStyleBackColor = true;
			this->output_file_content_button->Click += gcnew System::EventHandler(this, &MyForm::output_file_content_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(22, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(304, 20);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Enter all dates in this format (dd.mm.yyyy) ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1153, 580);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->output_file_content_button);
			this->Controls->Add(this->get_expiry_prod_button);
			this->Controls->Add(this->clear_file_button);
			this->Controls->Add(this->expired_products_textBox);
			this->Controls->Add(this->expired_products_label);
			this->Controls->Add(this->filedata_textBox);
			this->Controls->Add(this->label_filedata);
			this->Controls->Add(this->save_product_button);
			this->Controls->Add(this->save_filename_button);
			this->Controls->Add(this->label_expiry_date);
			this->Controls->Add(this->label_data);
			this->Controls->Add(this->expiry_date_textBox);
			this->Controls->Add(this->date_textBox);
			this->Controls->Add(this->label_name_of_product);
			this->Controls->Add(this->label_for_filename);
			this->Controls->Add(this->name_of_product_textBox);
			this->Controls->Add(this->save_date_button);
			this->Controls->Add(this->filename_textBox);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void save_filename_button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void clear_file_button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void save_date_button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void save_product_button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void get_expiry_prod_button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void output_file_content_button_Click(System::Object^ sender, System::EventArgs^ e);
};
}
