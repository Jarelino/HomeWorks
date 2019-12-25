#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(66, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Сортировка по модулю";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(205, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Вход";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(367, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Выход";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(66, 130);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(180, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(370, 130);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(199, 20);
			this->textBox2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(426, 226);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 41);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(247, 226);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(143, 41);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Сортировка по возрастанию";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 353);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Array ^ arr = this->textBox1->Text->Split(' ');

		arr->Sort(arr);
		String^ str;

		for (int i = 0; i < arr->Length; i++)
		{
			str += arr->GetValue(i)->ToString() + " ";
		}

		this->textBox2->Text = str;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Array^ arr = this->textBox1->Text->Split(' ');
		
		for (int i = 0; i < arr->Length; i++)
		{
			for (int j = i + 1; j < arr->Length; j++)
			{
				if (Convert::ToInt32(arr->GetValue(j)) < Convert::ToInt32(arr->GetValue(i)))
				{
					Object ^ t = arr->GetValue(j);
					arr->SetValue(arr->GetValue(i), j);
					arr->SetValue(t, i);
				}
			}
		}

		String^ str;
		for (int i = 0; i < arr->Length; i++)
		{
			str += arr->GetValue(i) + " ";
		}

		this->textBox2->Text = str;
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBox1->Text = "";
	this->textBox2->Text = "";
}
};
}
