#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	float* note;
	int nrExamene;
	int nrNote;
	string* Examen;
	string numeStudent;
	char sex;
	bool admis;
public:
	Student() {
		this->nrNote = 0;
		this->nrExamene = 0;
		this->admis = 0;
		this->sex = 'M';
		this->numeStudent = "NULL";
		this->Examen = NULL;
		this->note = NULL;
	}

	Student operator= (Student &a) {
		this->nrNote = a.nrNote;
		this->nrExamene = a.nrExamene;
		this->admis = a.admis;
		this->sex = a.sex;
		this->numeStudent = a.numeStudent;
		this->note = new float[a.nrNote];
		for (int i = 0; i < a.nrNote; i++)
			this->note[i] = a.note[i];
		this->Examen = new string[a.nrExamene];
		for (int j = 0; j < a.nrExamene; j++)
			this->Examen[j] = a.Examen[j];
		return *this;
	}

	Student(const string nume, int nrExam, string* exam, int nrNote, float* note, char s, bool adm)
	{
		this->nrNote = nrNote;
		this->nrExamene = nrExam;
		this->admis = adm;
		this->sex = s;
		this->numeStudent = nume;
		this->note = new float[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->note[i] = note[i];
		this->Examen = new string[nrExam];
		for (int j = 0; j < nrExam; j++)
			this->Examen[j] = exam[j];
	}
	Student(Student &a) {
		this->nrNote = a.nrNote;
		this->nrExamene = a.nrExamene;
		this->admis = a.admis;
		this->sex = a.sex;
		this->numeStudent = a.numeStudent;
		this->note = new float[a.nrNote];
		for (int i = 0; i < a.nrNote; i++)
			this->note[i] = a.note[i];
		this->Examen = new string[a.nrExamene];
		for (int j = 0; j < a.nrExamene; j++)
			this->Examen[j] = a.Examen[j];
	}

	void afisare() {
		cout << this->numeStudent << endl;
		cout << this->sex << endl;
		cout << this->nrExamene << "  ";
		for (int i = 0; i < this->nrExamene; i++)
			cout << this->Examen[i] << " ";
		cout << endl << this->nrNote << "  ";
		for (int i = 0; i < this->nrNote; i++)
			cout << this->note[i] << " ";
		cout << endl << this->admis;
	}

	~Student(){
		delete[] this->note;
		delete[] this->Examen;
	}

	friend ostream & operator<<(ostream & out,Student &a) {
		out << a.numeStudent << endl;
		out << a.sex << endl;
		out << a.nrExamene << "  ";
		for (int i = 0; i < a.nrExamene; i++)
			out << a.Examen[i] << " ";
		out << endl << a.nrNote << "  ";
		for (int i = 0; i < a.nrNote; i++)
			out << a.note[i] << " ";
		out << endl << a.admis;
		return out;
	}

	friend istream & operator>>(istream & in, Student &a) {
		in>>a.nrNote;
		in>>a.nrExamene;
		in>>a.admis;
		in>>a.sex;
		in>>a.numeStudent;
		a.note = new float[a.nrNote];
		for (int i = 0; i <a.nrNote; i++)
			in>>a.note[i];
		a.Examen = new string[a.nrExamene];
		for (int j = 0; j < a.nrExamene; j++)
			in>>a.Examen[j];
		return in;
	}

	float operator[] (int i) {
		cout << this->note[i]<<endl;
		cout << this->Examen[i] << endl;
		return 0;
	}

	float medie() {
		float s = 0.0;
		for (int i = 0; i < this->nrNote; i++) {
			s = s + note[i];
		}
	//	s /=this->nrNote;
		return s/this->nrNote;
	}
	
	bool operator>(Student &a) {
		if (this->medie() > a.medie())
			return true;
		else return false;
	}
	bool operator<(Student &a) {
		if (this->note[1] < a.note[1])
			return true;
		else
			return false;
	}

	Student & operator++() {
		for (int i = 0; i < this->nrNote; i++)
			this->note[i]++;
		return *this;
	}

	int CompareNumbers(Student &a) {
		if (this->numeStudent.length() > a.numeStudent.length())
			cout<< "Este mai lung";
		else
			cout<<"Nu este";
		return 0;
	}

	bool operator!() {
		if (this->medie() > 5)
			return 1;
		return 0;
	}

};

int main() {

	string* Exams = new string[3];
	Exams[0] = "Mate";
	Exams[1] = "Fizica";
	Exams[2]= "Chimie";
	float* note = new float[3];
	note[0] = 8.0;
	note[1] = 7.5;
	note[2] = 9.0;
	Student s1;
	Student s2("Stefan", 3, Exams,3,note,'M',0);
	Student s3 = s2;
	Student s4;
	s4 = s2;
	s2.afisare();
	cout << s2;
	//cin >> s4;
	//cout << s4;
	cout << s2[2];
	cout << s2.medie();
	if (s3 > s2)
		cout<<"True";
	++s3;
	if (s3 < s2)
		cout << "t2";
	else
		cout << "f2";
	s3.CompareNumbers(s2);
	if (!s2)
		cout << endl << "Y";
	else
		cout << "N";
}

	//examene sir de caractere, alocare dinamica
//nr exam  dim  int
//note , virgula mobila, aloc float
//nr note int
//string nume stud
// f/m sex student char
// admitere bool t/f
//


//Tema fs virtuale,fs virtuale pure, calse derivate, clase abstracte, vectori de obiecte
