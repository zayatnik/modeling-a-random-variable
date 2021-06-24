#include <iostream> 
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#pragma once
using namespace std;
#define PI 3.14159265

int exper(int N, int M, int r) {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		int a;
		if (10 * N < RAND_MAX)
			a = 1 + rand() % (N);
		else {
			bool fl = 0;
			while (fl == 0) {
				a = 1 + rand() % (N);
				if (a <= N * (RAND_MAX / N))
					fl = 1;
			}
		}
		if (a <= M) {
			sum++;
			M--;
		}
		N--;
	}
	return sum;
}

vector <vector <int>> sortirovka(vector <vector<int>> vec) {
	int size = vec[0].size();
	int tmp;
	for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (vec[0][j] > vec[0][j + 1]) {
                tmp = vec[0][j];
                vec[0][j] = vec[0][j + 1];
                vec[0][j + 1] = tmp;
				tmp = vec[1][j];
				vec[1][j] = vec[1][j + 1];
				vec[1][j + 1] = tmp;
            }
        }
    }
	return vec;
}

double E(int N, int M, int r) { //математическое ожидание
	return double(r) * double(M) / double(N);
}

double x(vector <vector <int>> eta, int n) { //выборочное среднее
	double sum = 0;
	int size = eta[0].size();
	for (int i = 0; i < size; i++)
		sum = sum + eta[0][i] * eta[1][i];
	return sum / n;
}

double D(int N, int M, int r) { //дисперсия
	double N1 = double(N), M1 = double(M), r1 = double(r);
	double res = r1 * (M1 / N1) * (1 - M1 / N1) * (N1 - r1) / (N1 - 1);
	return res;
}

double S2(vector <vector <int>> eta, int n) { //выборочная дисперсия
	int size = eta[0].size();
	double X = x(eta, n), res = 0;
	for (int i = 0; i < size; i++)
		res = res + pow(eta[0][i] - X, 2) * eta[1][i];
	return res / n;
}

double Me(vector <vector <int>> eta) { //медиана
	int size = eta[0].size();
	if (size % 2 == 0)
		return (double(eta[0][int(size / 2)]) + double(eta[0][int(size / 2) - 1])) / 2;
	else
		return eta[0][int(size / 2)];
}

int R(vector<vector <int>> eta) { //размах выборки
	int size = eta[0].size();
	return eta[0][size - 1] - eta[0][0];
}

long double factorial(long double N) {
	if (N == 0) 
		return 1; 
	else 
		return N * factorial(N - 1);
}

double C(int n, int k) {
	long double n1 = n, k1 = k;
	return (factorial(n) / (factorial(n - k) * factorial(k)));
}

double P(int N, int M, int r, int k) {
	return (C(M, k) * C(N - M, r - k) / C(N, r));
}

int max(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}

int min(int a, int b) {
	if (a <= b)
		return a;
	else
		return b;
}

double gamma(double x) {
	if (x == 1)
		return 1;
	else
		if (x == 0.5)
			return sqrt(PI);
		else
			return ((x - 1) * gamma(x - 1));
}

double plotn(double x, int r) { //плотность
	if (x <= 0)
		return 0;
	else
		return (pow(2, -1 * double(r) / 2) * pow(gamma(double(r) / 2), -1) * pow(x, double(r) / 2 - 1) * exp(-1 * x / 2));
}

double I(double a, double b, int r) { //метод трапеций
	double res = 0;
	for (int i = 1; i < 1001; i++)
		res = res + (plotn(a + (b - a) * (i - 1) / 1000, r) + plotn(a + (b - a) * i / 1000, r)) * (b - a) / 2000;
	return res;
}

double F(double R0, int r) {
	return (1 - I(0, R0, r));
}

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox4;







	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider2;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: ZedGraph::ZedGraphControl^ zedGraphControl1;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox11;




	private: System::ComponentModel::IContainer^ components;













	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(365, 9);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label1->Size = System::Drawing::Size(721, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Лабораторная работа 1. Моделирование случайных величин";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(57, 85);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(87, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(57, 370);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 29);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Поехали!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(57, 130);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(87, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(188, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 17);
			this->label2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(277, 38);
			this->label3->Name = L"label3";
			this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label3->Size = System::Drawing::Size(967, 29);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Вариант 4.  В лотерее среди N билетов M выигрышных. Игрок покупает r билетов.";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(42, 65);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"всего билетов, N";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(27, 110);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(172, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"выигрышных билетов, M ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(39, 155);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(149, 17);
			this->label6->TabIndex = 8;
			this->label6->Text = L"купленных билетов, r";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(57, 175);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(87, 22);
			this->textBox3->TabIndex = 9;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(27, 200);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(167, 17);
			this->label7->TabIndex = 10;
			this->label7->Text = L"число экспериментов, n";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(57, 220);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(87, 22);
			this->textBox4->TabIndex = 11;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(219, 110);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1109, 180);
			this->dataGridView1->TabIndex = 19;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick_2);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(431, 65);
			this->label8->Name = L"label8";
			this->label8->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label8->Size = System::Drawing::Size(641, 29);
			this->label8->TabIndex = 20;
			this->label8->Text = L"С.в. η — число выигрышных билетов среди купленных.";
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// errorProvider2
			// 
			this->errorProvider2->ContainerControl = this;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(219, 296);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(1109, 103);
			this->dataGridView2->TabIndex = 21;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick);
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(219, 406);
			this->zedGraphControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(1111, 352);
			this->zedGraphControl1->TabIndex = 22;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 419);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(176, 22);
			this->textBox5->TabIndex = 23;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(12, 482);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(176, 22);
			this->textBox6->TabIndex = 24;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(57, 269);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(87, 22);
			this->textBox7->TabIndex = 25;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(27, 249);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(143, 17);
			this->label9->TabIndex = 26;
			this->label9->Text = L"число интервалов, k";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(219, 780);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(1109, 123);
			this->dataGridView3->TabIndex = 27;
			this->dataGridView3->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView3_CellContentClick);
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Location = System::Drawing::Point(221, 909);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowHeadersVisible = false;
			this->dataGridView4->RowHeadersWidth = 51;
			this->dataGridView4->RowTemplate->Height = 24;
			this->dataGridView4->Size = System::Drawing::Size(1109, 123);
			this->dataGridView4->TabIndex = 28;
			this->dataGridView4->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView4_CellContentClick);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(57, 316);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(87, 22);
			this->textBox8->TabIndex = 29;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(9, 296);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(193, 17);
			this->label10->TabIndex = 30;
			this->label10->Text = L"уровень значимости, альфа";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(12, 529);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(176, 22);
			this->textBox9->TabIndex = 31;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(12, 572);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(176, 22);
			this->textBox10->TabIndex = 32;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(12, 635);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(176, 22);
			this->textBox11->TabIndex = 33;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1349, 1055);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->dataGridView4);
			this->Controls->Add(this->dataGridView3);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->zedGraphControl1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		long double ag = factorial(20);
		int N, M, r, n;
		N = System::Convert::ToInt32(textBox1->Text);
		M = System::Convert::ToInt32(textBox2->Text);
		r = System::Convert::ToInt32(textBox3->Text);
		n = System::Convert::ToInt32(textBox4->Text);
		if ((N >= 32000) || (M >= 32000)) {
			dataGridView1->RowCount = 1;
			dataGridView1->ColumnCount = 1;
			dataGridView1->Rows[0]->Cells[0]->Value = "ERROR! N or M is too big. They should be less than 32.000!!!";
			dataGridView1->Rows[0]->Cells[0]->Style->ForeColor = ForeColor.Red;
		}
		else {
			GraphPane^ panel = zedGraphControl1->GraphPane;
			panel->CurveList->Clear();
			PointPairList^ f1_list = gcnew ZedGraph::PointPairList();
			PointPairList^ f2_list = gcnew ZedGraph::PointPairList();
			panel->XAxis->Title->Text = "эта";
			panel->YAxis->Title->Text = "F";
			panel->Title->Text = "графики распределения случайной величины";
			vector <vector <int>> eta(2);
			vector <int> b(0);
			eta[0] = b;
			eta[1] = b;
			for (int i = 0; i < n; i++) {
				bool f = 0;
				int res = exper(N, M, r);
				for (int j = 0; j < eta[0].size(); j++)
					if (eta[0][j] == res) {
						eta[1][j]++;
						f = 1;
						break;
					}
				if (f == 0) {
					eta[0].push_back(res);
					eta[1].push_back(1);
				}
			}
			int size = eta[0].size();
			int tmp;
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (eta[0][j] > eta[0][j + 1]) {
						tmp = eta[0][j];
						eta[0][j] = eta[0][j + 1];
						eta[0][j + 1] = tmp;
						tmp = eta[1][j];
						eta[1][j] = eta[1][j + 1];
						eta[1][j + 1] = tmp;
					}
				}
			}
			dataGridView1->RowCount = 5;
			dataGridView1->ColumnCount = size + 1;
			dataGridView1->Rows[0]->Cells[0]->Value = "i";
			for (int i = 0; i < size; i++)
				dataGridView1->Rows[0]->Cells[i + 1]->Value = System::Convert::ToString(i + 1);
			dataGridView1->Rows[1]->Cells[0]->Value = "эта(i)";
			for (int i = 0; i < size; i++)
				dataGridView1->Rows[1]->Cells[i + 1]->Value = System::Convert::ToString(eta[0][i]);
			dataGridView1->Rows[2]->Cells[0]->Value = "n(i)";
			for (int i = 0; i < size; i++)
				dataGridView1->Rows[2]->Cells[i + 1]->Value = System::Convert::ToString(eta[1][i]);
			dataGridView1->Rows[3]->Cells[0]->Value = "n(i)/n";
			dataGridView1->Rows[4]->Cells[0]->Value = "P(n=y(j))";

			vector <double> ns(size);
			for (int i = 0; i < size; i++)
				ns[i] = eta[1][i];
			double n2 = n;
			for (int i = 0; i < size; i++)
				dataGridView1->Rows[3]->Cells[i + 1]->Value = System::Convert::ToString(ns[i] / n2);
			for (int i = 0; i < size + 1; i++)
				dataGridView1->Rows[0]->Cells[i]->Style->ForeColor = ForeColor.Red;
			for (int i = 1; i < 4; i++)
				dataGridView1->Rows[i]->Cells[0]->Style->ForeColor = ForeColor.Red;
			dataGridView2->RowCount = 2;
			dataGridView2->ColumnCount = 8;
			dataGridView2->Rows[0]->Cells[0]->Value = "E(эта)";
			dataGridView2->Rows[0]->Cells[1]->Value = "x";
			dataGridView2->Rows[0]->Cells[2]->Value = "|E(эта)-x|";
			dataGridView2->Rows[0]->Cells[3]->Value = "D(эта)";
			dataGridView2->Rows[0]->Cells[4]->Value = "S^2";
			dataGridView2->Rows[0]->Cells[5]->Value = "|D(эта)-S^2|";
			dataGridView2->Rows[0]->Cells[6]->Value = "Me";
			dataGridView2->Rows[0]->Cells[7]->Value = "R";
			dataGridView2->Rows[1]->Cells[0]->Value = System::Convert::ToString(E(N, M, r));
			dataGridView2->Rows[1]->Cells[1]->Value = System::Convert::ToString(x(eta, n));
			dataGridView2->Rows[1]->Cells[2]->Value = System::Convert::ToString(abs(E(N, M, r) - x(eta, n)));
			dataGridView2->Rows[1]->Cells[3]->Value = System::Convert::ToString(D(N, M, r));
			dataGridView2->Rows[1]->Cells[4]->Value = System::Convert::ToString(S2(eta, n));
			dataGridView2->Rows[1]->Cells[5]->Value = System::Convert::ToString(abs(D(N, M, r) - S2(eta, n)));
			dataGridView2->Rows[1]->Cells[6]->Value = System::Convert::ToString(Me(eta));
			dataGridView2->Rows[1]->Cells[7]->Value = System::Convert::ToString(R(eta));

			vector <double> vr(M + 1); //функция выборочного распределения
			for (int i = 0; i < M + 1; i++)
				vr[i] = 0;
			for (int i = 0; i < size; i++)
				vr[eta[0][i]] = eta[1][i] / n2;
			for (int i = 1; i < M + 1; i++)
				vr[i] = vr[i] + vr[i - 1];
			for (double i = 0; i < eta[0][size - 1] + 1; i = i + 0.001)
				f1_list->Add(i, vr[floor(i)]);
			for (double i = eta[0][size - 1] + 1; i < min(M, r) + 1; i = i + 0.001)
				f1_list->Add(i, 1);

			vector <double> tr(M + 1); //функция теоретического распределения
			for (int i = 0; i < M + 1; i++)
				if (i < max(0, r - N + M))
					tr[i] = 0;
				else
					if (i > min(r, M))
						tr[i] = 1;
					else
						if (i > 0)
							tr[i] = tr[i - 1] + P(N, M, r, i);
						else
							tr[i] = P(N, M, r, i);
			for (double i = 0; i < min(M, r) + 1; i = i + 0.001)
				f2_list->Add(i, tr[floor(i)]);

			LineItem^ Curve1 = panel->AddCurve("выборочн.", f1_list, Color::Red, SymbolType::XCross);
			LineItem^ Curve2 = panel->AddCurve("теоретическ.", f2_list, Color::Green, SymbolType::XCross);
			Curve1->Line->IsVisible = false;
			Curve2->Line->IsVisible = false;
			panel->XAxis->Scale->Min = -0.1;
			panel->XAxis->Scale->Max = min(r, M) + 1;
			panel->YAxis->Scale->Min = -0.1;
			panel->YAxis->Scale->Max = 1.1;
			zedGraphControl1->AxisChange();
			zedGraphControl1->Invalidate();
			int g;

			for (int i = 0; i < size; i++)
				dataGridView1->Rows[4]->Cells[i + 1]->Value = System::Convert::ToString(P(N, M, r, eta[0][i]));

			double maxotkl = 0;
			for (int i = 0; i < size; i++) {
				double otkl = abs(eta[1][i] / n2 - P(N, M, r, eta[0][i]));
				if (otkl > maxotkl)
					maxotkl = otkl;
			}
			textBox5->Text = "макс. откл. = " + maxotkl;

			double maxdif = 0;
			for (int i = 0; i < M + 1; i++) {
				double dif = abs(vr[i] - tr[i]);
				if (dif > maxdif)
					maxdif = dif;
			}
			textBox6->Text = "D = " + maxdif;

			int k = System::Convert::ToInt32(textBox7->Text); //количество отрезков
			if (k > min(M, r) - max(0, r - N + M) + 1) {
				dataGridView3->RowCount = 1;
				dataGridView3->ColumnCount = 1;
				dataGridView3->Rows[0]->Cells[0]->Value = "too big k";
			}
			else {
				dataGridView3->RowCount = 2;
				dataGridView3->ColumnCount = k - 1;

				vector <double> Z(k - 1); //границы отрезков
				if (k <= size) {
					Z[0] = eta[0][size / k + int(double(size % k) / 2)];
					Z[k - 2] = eta[0][size - size / k - int(double(size % k) / 2)];
					for (int i = 1; i < k - 2; i++)
						Z[i] = Z[0] + i * ((Z[k - 2] - Z[0]) / (k - 2));
				}
				else
					for (int i = 0; i < k - 1; i++)
						Z[i] = max(0, r - N + M) + (i + 1) * (double((min(M, r) - max(0, r - N + M))) / double(k - 1));
				for (int i = 0; i < k - 1; i++) {
					dataGridView3->Rows[0]->Cells[i]->Value = "z" + System::Convert::ToString(i + 1);
					dataGridView3->Rows[1]->Cells[i]->Value = System::Convert::ToString(Z[i]);
				}
				vector <double> Q(k); //теоретические вероятности
				for (int i = max(0, r - N + M); i <= min(M, r); i++)
					if (i < Z[0])
						Q[0] = Q[0] + P(N, M, r, i);
					else
						if (i >= Z[k - 2])
							Q[k - 1] = Q[k - 1] + P(N, M, r, i);
				for (int j = 1; j < k - 1; j++) {
					double q = 0;
					for (int i = max(0, r - N + M) + 1; i < min(M, r); i++)
						if ((i >= Z[j - 1]) & (i < Z[j]))
							q = q + P(N, M, r, i);
					Q[j] = q;
				}
				dataGridView4->RowCount = 2;
				dataGridView4->ColumnCount = k;
				for (int i = 0; i < k; i++) {
					dataGridView4->Rows[0]->Cells[i]->Value = "q" + System::Convert::ToString(i + 1);
					dataGridView4->Rows[1]->Cells[i]->Value = System::Convert::ToString(Q[i]);
				}
				vector <int> ns(k); //значения n
				for (int i = 0; i < size; i++) {
					if (eta[0][i] < Z[0])
						ns[0] = ns[0] + eta[1][i];
					else
						if (eta[0][i] >= Z[k - 2])
							ns[k - 1] = ns[k - 1] + eta[1][i];
				}
				for (int j = 0; j < k - 2; j++)
					for (int i = 0; i < size; i++)
						if ((eta[0][i] >= Z[j]) & (eta[0][i] < Z[j + 1]))
							ns[j + 1] = ns[j + 1] + eta[1][i];
				double R0 = 0;
				for (int j = 0; j < k; j++)
					R0 = R0 + ((double(ns[j]) - n * Q[j]) * (double(ns[j]) - n * Q[j])) / (n * Q[j]);
				textBox11->Text = "R0 = " + R0;

				int r = k - 1; //степени свободы
				double alpha = System::Convert::ToDouble(textBox8->Text);
				double Fres = F(R0, r);
				textBox9->Text = "F(R0) = " + Fres;
				if (Fres < alpha)
					textBox10->Text = "гипотеза Н0 отвергнута";
				else
					textBox10->Text = "гипотеза Н0 принята";
			}
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (System::Convert::ToInt32(textBox1->Text) >= 32000)
			errorProvider1->SetError(textBox1, "Значение должно быть менее 32000");
		else
			errorProvider1->Clear();
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (System::Convert::ToInt32(textBox2->Text) >= 32000)
			errorProvider1->SetError(textBox2, "Значение должно быть менее 32000");
		else
			errorProvider2->Clear();
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

}
private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick_2(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void zedGraphControl1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView3_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void dataGridView4_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
