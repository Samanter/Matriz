#pragma once
#include "Matrix.h"
#include "QR.h"
#include <iostream>
#include <iomanip>

namespace Matriz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form {
	private:
		Matrix* a = new Matrix();
		Mundo* qr;
		int n;
		bool generated = false;
		bool rExists = false;
		bool qExists = false;

		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::DataGridView^  dataGridView3;
		private: System::Windows::Forms::DataGridView^  dataGridView2;
		private: System::Windows::Forms::Panel^  panel3;
		private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel4;

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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button2;









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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(44, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(153, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(281, 53);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Orden de la matriz";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(203, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Generar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"n:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(34, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"n debe ser un valor entre 4 y 10.";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(12, 106);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(281, 317);
			this->panel1->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(133, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"A";
			this->label6->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(3, 275);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 12;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(107, 246);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Factorizar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataGridView1->Location = System::Drawing::Point(0, 29);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView1->Size = System::Drawing::Size(210, 200);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1427, 406);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(57, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Salir";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(-8, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 109);
			this->label3->TabIndex = 6;
			this->label3->Text = L"=";
			this->label3->Visible = false;
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->AllowUserToResizeColumns = false;
			this->dataGridView3->AllowUserToResizeRows = false;
			this->dataGridView3->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView3->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView3->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->ColumnHeadersVisible = false;
			this->dataGridView3->Location = System::Drawing::Point(0, 29);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->ReadOnly = true;
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView3->Size = System::Drawing::Size(210, 200);
			this->dataGridView3->TabIndex = 8;
			this->dataGridView3->Visible = false;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->ColumnHeadersVisible = false;
			this->dataGridView2->Location = System::Drawing::Point(0, 29);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView2->Size = System::Drawing::Size(210, 200);
			this->dataGridView2->TabIndex = 7;
			this->dataGridView2->Visible = false;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->dataGridView3);
			this->panel3->Location = System::Drawing::Point(840, 106);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(644, 317);
			this->panel3->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(325, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(15, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"R";
			this->label8->Visible = false;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->dataGridView2);
			this->panel2->Location = System::Drawing::Point(380, 106);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(454, 317);
			this->panel2->TabIndex = 9;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(225, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(15, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Q";
			this->label7->Visible = false;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label3);
			this->panel4->Location = System::Drawing::Point(286, 106);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(74, 288);
			this->panel4->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(618, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(543, 73);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Factorización QR";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1496, 441);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void CenterGrid(DataGridView^ dataGridView, Panel^ panel, int width) {
			dataGridView->Size = System::Drawing::Size(width * n, 20 * n);
			dataGridView->Location = System::Drawing::Point(panel->Width / 2 - dataGridView->Width / 2, panel->Height / 2 - dataGridView->Height / 2 - 30);
		}

		void toDataTable(Matrix* matrix, DataGridView^ dataGridView, int precision) {
			DataTable^ dt = gcnew DataTable();
			array<String^>^ aux_arr = { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
			Array::Resize(aux_arr, n);
			int decimal_start;
			String^ aux_num;

			for (int i = 0; i < n; i++) {
				dt->Columns->Add(i.ToString(), Type::GetType("System.Double"));
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					aux_arr[j] = matrix->get(j, i).ToString();
					decimal_start = 0;

					if (aux_arr[j]->Contains(".")) {
						while (!aux_arr[j]->Substring(decimal_start)->StartsWith(".")) {
							decimal_start++;
						}
						decimal_start++;
						if (aux_arr[j]->Substring(decimal_start)->ToCharArray()->Length > precision) {
							aux_arr[j] = aux_arr[j]->Substring(0, decimal_start + precision);
						}
					}
				}

				dt->Rows->Add(aux_arr);
			}

			dataGridView->DataSource = dt;
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (generated) {
			generated = false;
			button3->Visible = false;
			label3->Visible = false;
			dataGridView2->Visible = false;
			dataGridView3->Visible = false;
			label7->Visible = false;
			label8->Visible = false;
		}

		if (!System::String::IsNullOrEmpty(this->textBox1->Text) && !generated) {
			int aux = System::Int32::Parse(this->textBox1->Text);
			n = aux;

			if (n >= 4 && n <= 10) {
				Matrix* matrix = new Matrix(n, n);
				matrix->Randomize();

				toDataTable(matrix, dataGridView1, 0);
				CenterGrid(dataGridView1, panel1, 23);

				a = matrix;
				generated = true;
				dataGridView1->Visible = true;
				button3->Visible = true;
				label6->Visible = true;
			}
		}
	}


private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	rExists = true;
	qExists = true;

	//funcion para hallar q y r
	qr = new Mundo(a);
	qr->operar();

	if (rExists && qExists) {
		label4->Text = L"";

		Matrix* q = qr->getQ();
		Matrix* r = qr->getR();

		toDataTable(q, dataGridView2, 4);
		CenterGrid(dataGridView2, panel2, 44);

		toDataTable(r, dataGridView3, 4);
		CenterGrid(dataGridView3, panel3, 51);

		label3->Visible = true;
		dataGridView2->Visible = true;
		dataGridView3->Visible = true;
		label7->Visible = true;
		label8->Visible = true;
	}

	else if (!qExists && rExists) {
		label4->Text = L"No existe una matriz ortogonal.";
	}

	else if (qExists && !rExists) {
		label4->Text = L"No existe una matriz triangular inferior.";
	}
	else {
		label4->Text = L"No existe una matriz ortogonal.\nNo existe una matriz triangular inferior.";
	}
}
};
}
