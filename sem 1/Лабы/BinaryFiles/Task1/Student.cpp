#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student(char* firstName, char* lastName, char* patronymic, char*gender, char* nationality, char* homeAddress, char* schoolName, int height, int weight, int birthdayDay, int birthdayMonth, int birthdayYear, long long phoneNumber, int classNumb)
{
	this->SetStudent(firstName, lastName, patronymic, gender, nationality, homeAddress, schoolName, height, weight, birthdayDay, birthdayMonth, birthdayYear, phoneNumber, classNumb);
}

void Student::SetFirstName(char* firstName)
{
	strcpy(this->firstName, firstName);
}

void Student::SetLastName(char* lastName)
{
	strcpy(this->lastName, lastName);
}

void Student::SetPatronymic(char * patronymic)
{
	strcpy(this->patronymic, patronymic);
}

void Student::SetGender(char * gender)
{
	strcpy(this->gender, gender);
}

void Student::SetNationality(char * nationality)
{
	strcpy(this->nationality, nationality);
}

void Student::SetHomeAddress(char * homeAddress)
{
	strcpy(this->homeAddress, homeAddress);
}

void Student::SetSchoolName(char * schoolName)
{
	strcpy(this->schoolName, schoolName);
}

void Student::SetHeight(int height)
{
	this->height = height;
}

void Student::SetWeight(int weight)
{
	this->weight = weight;
}

void Student::SetBirthdayDay(int birthdayDay)
{
	this->birthdayDay = birthdayDay;
}

void Student::SetBirthdayMonth(int birthdayMonth)
{
	this->birthdayMonth = birthdayMonth;
}

void Student::SetBirthdayYear(int birthdayYear)
{
	this->birthdayYear = birthdayYear;
}

void Student::SetPhoneNumber(long long phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Student::SetClassNumb(int classNumb)
{
	this->classNumb = classNumb;
}


char* Student::GetFirstName()
{
	return this->firstName;
}

char* Student::GetLastName()
{
	return this->lastName;
}

char * Student::GetPatronymic()
{
	return this->patronymic;
}

char * Student::GetGender()
{
	return this->gender;
}

char * Student::GetNationality()
{
	return this->nationality;
}

char * Student::GetHomeAddress()
{
	return this->homeAddress;
}

char * Student::GetSchoolName()
{
	return this->schoolName;
}

int Student::GetHeight()
{
	return this->height;
}

int Student::GetWeight()
{
	return this->weight;
}

int Student::GetBirthdayDay()
{
	return this->birthdayDay;
}

int Student::GetBirthdayMonth()
{
	return this->birthdayMonth;
}

int Student::GetBirthdayYear()
{
	return this->birthdayYear;
}

long long Student::GetPhoneNumber()
{
	return this->phoneNumber;
}

int Student::GetClassNumb()
{
	return this->classNumb;
}


void Student::SetStudent(char* firstName, char* lastName, char* patronymic, char*gender, char* nationality, char* homeAddress, char* schoolName, int height, int weight, int birthdayDay, int birthdayMonth, int birthdayYear, long long phoneNumber, int classNumb)
{
	this->SetFirstName(firstName);
	this->SetLastName(lastName);
	this->SetPatronymic(patronymic);
	this->SetGender(gender);
	this->SetNationality(nationality);
	this->SetHomeAddress(homeAddress);
	this->SetSchoolName(schoolName);
	this->SetHeight(height);
	this->SetWeight(weight);
	this->SetBirthdayDay(birthdayDay);
	this->SetBirthdayMonth(birthdayMonth);
	this->SetBirthdayYear(birthdayYear);
	this->SetPhoneNumber(phoneNumber);
	this->SetClassNumb(classNumb);
}


void Student::DisplayStudent()
{
	cout << "Student: " << this->GetFirstName() << " " << this->GetLastName() << " " << this->GetPatronymic() << " , " << this->GetGender() << " , born in:" << this->GetBirthdayDay() << " " << this->GetBirthdayMonth() << " " << this->GetBirthdayYear() << endl;
	cout << "Height: " << this->GetHeight() << " , Weight:" << this->GetWeight() << " , Phone number:+" << this->GetPhoneNumber() << endl;
	cout << "Nationality:" << this->GetNationality() << " , Live:" << this->GetHomeAddress() << endl;
	cout << "Study in:" << this->GetSchoolName() << " in " << this->GetClassNumb() << " class" << endl;
}

void Student::EnterStudent()
{
	const int N = 256;
	char firstName[N] = "", lastName[N] = "", patronymic[N] = "", gender[N] = "", nationality[N] = "", homeAddress[N] = "", schoolName[N] = "";
	int height = 0, weight = 0, birthdayDay = 0, birthdayMonth = 0, birthdayYear = 0, classNumb = 0;
	long long phoneNumber = 0;
	cout << "Enter the first name of student:";
	cin.ignore();
	cin.getline(firstName, N, '\n');
	cout << "Enter the last name of student:";
	cin.getline(lastName, N, '\n');
	cout << "Enter patronymic of student:";
	cin.getline(patronymic, N, '\n');
	cout << "Enter gender of student:";
	cin.getline(gender, N, '\n');
	cout << "Enter nationality of student:";
	cin.getline(nationality, N, '\n');
	cout << "Enter homeAddress of student:";
	cin.getline(homeAddress, N, '\n');
	cout << "Enter schoolName of student:";
	cin.getline(schoolName, N, '\n');

	cout << "Enter the heigth of student:";
	cin >> height;
	cout << "Enter the weight of student:";
	cin >> weight;
	cout << "Enter the birthday of student:";
	cin >> birthdayDay;
	cin >> birthdayMonth;
	cin >> birthdayYear;

	cout << "Enter the phone number of student:";
	cin >> phoneNumber;
	cout << "Enter the class number of student:";
	cin >> classNumb;

	this->SetStudent(firstName, lastName, patronymic, gender, nationality, homeAddress, schoolName, height, weight, birthdayDay, birthdayMonth, birthdayYear, phoneNumber, classNumb);
}
