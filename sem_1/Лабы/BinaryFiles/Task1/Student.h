#ifndef student_h
#define student_h

const int N = 256;
const int M = 5;

class Student
{
public:
	Student() {}
	Student(char*, char*, char*, char*, char*, char*, char*, int, int, int, int, int, long long, int);
	~Student() {}
	void SetFirstName(char*);
	void SetLastName(char*);
	void SetPatronymic(char*);
	void SetGender(char*);
	void SetNationality(char*);
	void SetHomeAddress(char*);
	void SetSchoolName(char*);
	void SetHeight(int);
	void SetWeight(int);
	void SetBirthdayDay(int);
	void SetBirthdayMonth(int);
	void SetBirthdayYear(int);
	void SetPhoneNumber(long long);
	void SetClassNumb(int);
	char* GetFirstName();
	char* GetLastName();
	char* GetPatronymic();
	char* GetGender();
	char* GetNationality();
	char* GetHomeAddress();
	char* GetSchoolName();
	int GetHeight();
	int GetWeight();
	int GetBirthdayDay();
	int GetBirthdayMonth();
	int GetBirthdayYear();
	long long GetPhoneNumber();
	int GetClassNumb();

	void SetStudent(char* , char* , char* , char*, char* , char* , char* , int , int , int , int , int , long long, int);
	void EnterStudent();
	void DisplayStudent();
private:
	char firstName[N]{}, lastName[N]{}, patronymic[N]{}, gender[N]{}, nationality[N]{}, homeAddress[N]{}, schoolName[N]{};
	int height, weight, birthdayDay, birthdayMonth, birthdayYear, classNumb;
	long long phoneNumber;
};

#endif