#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 150;
const int MAX_PROFESSORS = 20;

struct Student {
	string name;
	char sex;
	int group;
	int id;
	int grades[8];
	double averageScore;
};

struct Professor {
	string secondName;
	string name;
	char sex;
	int age;
	string academicDegree;
	string disciplineName;
	string email;
	int groupID;
};

int professorCount = 0;

void addProfessor(Professor professor[])
{
	setlocale(LC_ALL, "ru");
	Professor newProfessor;
	cout << "Введите Фамилию преподавателя: ";
	getline(cin >> ws, newProfessor.secondName);
	cout << "Введите Имя преподавателя: ";
	getline(cin >> ws, newProfessor.name);
	cout << "Введите пол преподавателя (M/F): ";
	cin >> newProfessor.sex;
	cout << "Введите возраст преподавателя: ";
	cin >> newProfessor.age;
	cout << "Введите ученую степень преподавателя: ";
	getline(cin >> ws, newProfessor.academicDegree);
	cout << "Введите название дисциплины: ";
	getline(cin >> ws, newProfessor.disciplineName);
	cout << "Введите почту преподавателя: ";
	getline(cin >> ws, newProfessor.email);
	cout << "Введите номер группы, у которой ведутся занятия: ";
	cin >> newProfessor.groupID;

	professor[professorCount++] = newProfessor;


	for (int j = 0; j < professorCount; ++j) {

		ofstream database;
		database.open("professors.txt", ios::app);
		if (!database.is_open())
			cout << "\nНе удается открыть файл!";
		else
		{
			database << professor[j].secondName << "\n";
			database << professor[j].name << "\n";
			database << professor[j].sex << "\n";
			database << professor[j].age << "\n";
			database << professor[j].academicDegree << "\n";
			database << professor[j].disciplineName << "\n";
			database << professor[j].email << "\n";
			database << professor[j].groupID << "\n";
			database.close();
			cout << "\nПрофиль преподавателя сохранен успешно.\n";
		}
	}
}

void showIdzData()
{
	ifstream database("professors.txt");
	if (!database.is_open())
		cout << "Не удалось открыть файл!";
	else
	{
		string data;
		int count = 0;
		while (!database.eof())
		{
			getline(database, data);
			cout << data << '\n';
			count++;
			if (count == 8) {
				count = 0;
				cout << "\n";
			}
		}
		database.close();
	}
}

void showIdzNameData(Professor professor[])
{
	setlocale(LC_ALL, "ru");
	string secondName;
	cout << "Введите фамилию преподавателя: ";
	getline(cin >> ws, secondName);
	ifstream database("professors.txt");
	if (!database.is_open())
		cout << "Не удалось октрыть файл.";

	for (int i = 0; i < MAX_PROFESSORS; i++) {
		getline(database >> ws, professor[i].secondName);
		getline(database >> ws, professor[i].name);
		database >> professor[i].sex;
		database >> professor[i].age;
		getline(database >> ws, professor[i].academicDegree);;
		getline(database >> ws, professor[i].disciplineName);
		getline(database >> ws, professor[i].email);
		database >> professor[i].groupID;
	}
	database.close();
	int temp = 0;
	for (int i = 0; i < MAX_PROFESSORS; i++) {
		if (professor[i].secondName == secondName) {
			cout << "Фамилия: " << professor[i].secondName << "\n";
			cout << "Имя: " << professor[i].name << "\n";
			cout << "Пол: " << professor[i].sex << "\n";
			cout << "Возраст: " << professor[i].age << "\n";
			cout << "Ученная степень: " << professor[i].academicDegree << "\n";
			cout << "Дисциплина: " << professor[i].disciplineName << "\n";
			cout << "Почта: " << professor[i].email << "\n";
			cout << "Группа: " << professor[i].groupID << "\n";
			temp++;
			cout << "\n";
		}
	}
	if (temp == 0) {
		cout << "Нет информации о " << secondName << "\n";
	}
}

void showIdzGroupData(Professor professor[])
{
	setlocale(LC_ALL, "ru");
	int groupNumber;
	cout << "Введите номер группы, чтобы узнать ее преподавателя: ";
	cin >> groupNumber;
	ifstream database("professors.txt");
	if (!database.is_open())
		cout << "Не удалось октрыть файл.";

	for (int i = 0; i < MAX_PROFESSORS; i++) {
		getline(database >> ws, professor[i].secondName);
		getline(database >> ws, professor[i].name);
		database >> professor[i].sex;
		database >> professor[i].age;
		getline(database >> ws, professor[i].academicDegree);;
		getline(database >> ws, professor[i].disciplineName);
		getline(database >> ws, professor[i].email);
		database >> professor[i].groupID;
	}
	database.close();
	int temp = 0;
	for (int i = 0; i < MAX_PROFESSORS; i++) {
		if (professor[i].groupID == groupNumber) {
			cout << "Фамилия: " << professor[i].secondName << "\n";
			cout << "Имя: " << professor[i].name << "\n";
			cout << "Пол: " << professor[i].sex << "\n";
			cout << "Возраст: " << professor[i].age << "\n";
			cout << "Ученная степень: " << professor[i].academicDegree << "\n";
			cout << "Дисциплина: " << professor[i].disciplineName << "\n";
			cout << "Почта: " << professor[i].email << "\n";
			cout << "Группа: " << professor[i].groupID << "\n";
			temp++;
			cout << "\n";
		}
	}
	if (temp == 0) {
		cout << "Нет информации о группе №" << groupNumber << "\n";
	}
}

void showIdzDisciplineData(Professor professor[])
{
	setlocale(LC_ALL, "ru");
	string discipline;
	cout << "Введите название дисциплины, чтобы узнать преподавателя: ";
	cin >> discipline;
	ifstream database("professors.txt");
	if (!database.is_open())
		cout << "Не удалось октрыть файл.";

	for (int i = 0; i < MAX_PROFESSORS; i++) {
		getline(database >> ws, professor[i].secondName);
		getline(database >> ws, professor[i].name);
		database >> professor[i].sex;
		database >> professor[i].age;
		getline(database >> ws, professor[i].academicDegree);;
		getline(database >> ws, professor[i].disciplineName);
		getline(database >> ws, professor[i].email);
		database >> professor[i].groupID;
	}
	database.close();
	int temp = 0;
	for (int i = 0; i < MAX_PROFESSORS; i++) {
		if (professor[i].disciplineName == discipline) {
			cout << "Фамилия: " << professor[i].secondName << "\n";
			cout << "Имя: " << professor[i].name << "\n";
			cout << "Пол: " << professor[i].sex << "\n";
			cout << "Возраст: " << professor[i].age << "\n";
			cout << "Ученная степень: " << professor[i].academicDegree << "\n";
			cout << "Дисциплина: " << professor[i].disciplineName << "\n";
			cout << "Почта: " << professor[i].email << "\n";
			cout << "Группа: " << professor[i].groupID << "\n";
			temp++;
			cout << "\n";
		}
	}
	if (temp == 0) {
		cout << "Нет информации о дисциплине: " << discipline << "\n";
	}
}

Student student[MAX_STUDENTS];
int studentsCount = 0;
void createRecord(Student student[]);

void addStudentToArray(Student student[])
{
	if (studentsCount >= MAX_STUDENTS) {
		cout << "Максимальное количесвто студентов превышено!\n";
		return;
	}
	Student newStudent;
	cout << "Введите ФИО: ";
	getline(cin >> ws, newStudent.name);
	cout << "Введите пол студента (M/W): ";
	cin >> newStudent.sex;
	cout << "Введите номер группы: ";
	cin >> newStudent.group;
	cout << "Введите ID студента: ";
	cin >> newStudent.id;
	cout << "Введите оценки за сессию ( 8 ): ";
	int gradeSum = 0;
	for (int i = 0; i < 8; i++) {
		cin >> newStudent.grades[i];
		gradeSum += newStudent.grades[i];
	}
	newStudent.averageScore = double(gradeSum) / 8.0;

	student[studentsCount++] = newStudent;
}

int currentStudentCount()
{
	ifstream database("students.txt");
	if (database.is_open()) {
		int temp = 0;
		string data;
		while (!database.eof())
		{
			getline(database, data);
			temp++;
		}
		database.close();
		int n;
		n = temp / 6;
		return n;
	}
	else return 0;
}

void createRecord(Student student[]) {
	if (studentsCount >= MAX_STUDENTS) {
		cout << "Максимальное количесвто студентов превышено!\n";
		return;
	}
	for (int j = 0; j < studentsCount; ++j) {

		int temp = 0;
		for (int i = 0; i < 8; i++) {
			if (student[j].grades[i] <= 2)
				temp++;
		}
		if (temp == 0) {
			ofstream database;
			database.open("students.txt", ios::app);
			if (!database.is_open())
				cout << "\nНе удается открыть файл!";
			else
			{
				database << student[j].name << "\n";
				database << student[j].sex << "\n";
				database << student[j].group << "\n";
				database << student[j].id << "\n";
				for (int i = 0; i < 8; i++)
					database << student[j].grades[i] << " ";
				database << "\n";
				database << student[j].averageScore << "\n";
				database.close();
				cout << "\nПрофиль студента сохранен успешно.\n";
			}
		}
		else {
			cout << "\nНевозможно добавить этот профиль. Студент имеет неудовлетворительные оценки.";
		}
	}
}

void changeStudent(Student students[]) {
	ifstream database("students.txt");
	int count = 0, changeID;
	count = currentStudentCount();
	for (int i = 0; i < count; i++) {
		getline(database >> ws, students[i].name);
		database >> students[i].sex;
		database >> students[i].group;
		database >> students[i].id;
		for (int j = 0; j < 8; j++) {
			database >> students[i].grades[j];
		}
		database >> students[i].averageScore;
	}
	database.close();
	ofstream database1("students.txt", ios::trunc);
	cout << "Введите номер студента, данные которого нужно изменить: ";
	cin >> changeID;
	cout << "ФИО: ";
	getline(cin >> ws, students[changeID].name, '\n');
	cout << "Пол: ";
	cin >> students[changeID].sex;
	cout << "Номер группы: ";
	cin >> students[changeID].group;
	cout << "Номер в списке: ";
	cin >> students[changeID].id;
	cout << "Оценки за сессию: ";
	for (int i = 0; i < 8; ++i) {
		cin >> students[changeID].grades[i];
	}
	double sum = 0;
	for (int i = 0; i < 8; ++i) {
		sum += students[changeID].grades[i];
	}
	students[changeID].averageScore = sum / 8.0;
	for (int i = 0; i < count; i++) {
		database1 << students[i].name << "\n";
		database1 << students[i].sex << "\n";
		database1 << students[i].group << "\n";
		database1 << students[i].id << "\n";
		for (int j = 0; j < 8; j++) {
			database1 << students[i].grades[j] << " ";
		}
		database1 << "\n";
		database1 << students[i].averageScore << "\n";
	}
	database1.close();
}

void showData()
{
	ifstream database("students.txt");
	if (!database.is_open())
		cout << "Не удалось открыть файл!";
	else
	{
		int temp;
		temp = currentStudentCount();
		if (temp == 0)
			cout << "Файл пустой";
		else
		{
			string data;
			int count = 0;
			while (!database.eof())
			{
				getline(database, data);
				cout << data << '\n';
				count++;
				if (count == 6) {
					cout << "\n";
					count = 0;
				}
			}
		}
		database.close();
	}
}

void showGroupInfo(Student student[])
{
	int n;
	cout << "Введите номер группы: ";
	cin >> n;
	ifstream database("students.txt");
	if (!database.is_open())
		cout << "Не удалось октрыть файл.";


	for (int i = 0; i < MAX_STUDENTS; i++) {
		getline(database >> ws, student[i].name);
		database >> student[i].sex;
		database >> student[i].group;
		database >> student[i].id;
		for (int j = 0; j < 8; j++) {
			database >> student[i].grades[j];
		}
		database >> student[i].averageScore;
	}
	database.close();
	int temp = 0;
	for (int i = 0; i < MAX_STUDENTS; i++) {
		if (student[i].group == n) {
			cout << "ФИО: " << student[i].name << "\n";
			cout << "Пол: " << student[i].sex << "\n";
			cout << "ID: " << student[i].id << "\n";
			cout << "Оценки за сессию:\n";
			for (int j = 0; j < 8; j++)
				cout << "[" << j + 1 << " экзамен] " << student[i].grades[j] << "\n";
			cout << "Средний балл: " << student[i].averageScore << "\n";
			temp++;
			cout << "\n";
		}
	}
	if (temp == 0) {
		cout << "Нет информации о группе № " << n << "\n";
	}

}

void showSexInfo(Student student[])
{
	ifstream database("students.txt");
	if (!database.is_open())
		cout << "Не удается открыть файл!\n";
	else
	{
		for (int i = 0; i <= MAX_STUDENTS; i++) {
			getline(database >> ws, student[i].name);
			database >> student[i].sex;
			database >> student[i].group;
			database >> student[i].id;
			for (int j = 0; j < 8; j++) {
				database >> student[i].grades[j];
			}
			database >> student[i].averageScore;
		}
		database.close();
		int tempMale = 0;
		int tempFemale = 0;
		for (int i = 0; i < MAX_STUDENTS; i++) {
			if (student[i].sex == 'M' || student[i].sex == 'm') {
				tempMale++;
			}
			if (student[i].sex == 'W' || student[i].sex == 'w') {
				tempFemale++;
			}
		}
		cout << "Количество студентов мужского пола: " << tempMale << "\n";
		cout << "Количество студентов женского пола: " << tempFemale << "\n";
	}
}

void showGrantsData(Student student[])
{
	ifstream database("students.txt");
	if (!database.is_open())
		cout << "Не удалось открыть файл\n";
	else
	{
		for (int i = 0; i < MAX_STUDENTS; i++) {
			getline(database >> ws, student[i].name);
			database >> student[i].sex;
			database >> student[i].group;
			database >> student[i].id;
			for (int j = 0; j < 8; j++)
				database >> student[i].grades[j];
			database >> student[i].averageScore;
		}
		database.close();
		bool isTopGrants = false;
		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			if (student[i].averageScore == 5.0) {
				cout << "\n«Отличник»:\n";
				isTopGrants = true;
				cout << "ФИО: " << student[i].name << "\n";
				cout << "Пол: " << student[i].sex << "\n";
				cout << "Группа: " << student[i].group << "\n";
				cout << "ID: " << student[i].id << "\n";
				cout << "Оценки за сессию:\n";
				for (int j = 0; j < 8; j++)
					cout << "[" << j + 1 << " экзамен] " << student[i].grades[j] << "\n";
				cout << "Средний балл: " << student[i].averageScore << "\n";
			}
		}
		if (isTopGrants == false) {
			cout << "\nНет студентов, которые учатся только на «отлично»:\n";
		}

		int goodGradesCount = 0;
		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((student[i].grades[j] == 4 || student[i].grades[j] == 5) && student[i].averageScore != 5.0) {
					goodGradesCount++;
				}
			}
			if (goodGradesCount == 8) {
				cout << "\n«Хорошист»:\n";
				cout << "ФИО: " << student[i].name << "\n";
				cout << "Пол: " << student[i].sex << "\n";
				cout << "Группа: " << student[i].group << "\n";
				cout << "ID: " << student[i].id << "\n";
				cout << "Оценки за сессию:\n";
				for (int j = 0; j < 8; j++)
					cout << "[" << j + 1 << " экзамен] " << student[i].grades[j] << "\n";
				cout << "Средний балл: " << student[i].averageScore << "\n";
			}
			goodGradesCount = 0;
		}

		bool isGrade3 = false;
		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (student[i].grades[j] == 3) {
					isGrade3 = true;
					break;
				}
			}
			if (isGrade3) {
				cout << "\n«Студент без стипендии»:\n";
				cout << "ФИО: " << student[i].name << "\n";
				cout << "Пол: " << student[i].sex << "\n";
				cout << "Группа: " << student[i].group << "\n";
				cout << "ID: " << student[i].id << "\n";
				cout << "Оценки за сессию:\n";
				for (int j = 0; j < 8; j++)
					cout << "[" << j + 1 << " экзамен] " << student[i].grades[j] << "\n";
				cout << "Средний балл: " << student[i].averageScore << "\n";
			}
			isGrade3 = false;
		}
	}
}

void showStudentIdInfo(Student student[])
{
	int k;
	cout << "\nВведите номер студента: ";
	cin >> k;
	ifstream database("students.txt");
	if (!database.is_open())
		cout << "\nНе удается открыть файл!\n";
	else
	{
		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			getline(database >> ws, student[i].name);
			database >> student[i].sex;
			database >> student[i].group;
			database >> student[i].id;
			for (int j = 0; j < 8; j++) {
				database >> student[i].grades[j];
			}
			database >> student[i].averageScore;
		}
		database.close();

		int kCount = 0;
		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			if (student[i].id == k) {
				kCount++;
				cout << "ФИО: " << student[i].name << "\n";
				cout << "Пол: " << student[i].sex << "\n";
				cout << "Группа: " << student[i].group << "\n";
				cout << "ID: " << student[i].id << "\n";
				cout << "Оценки за сессию:\n";
				for (int j = 0; j < 8; j++)
					cout << "[" << j + 1 << " экзамен] " << student[i].grades[j] << "\n";
				cout << "Средний балл: " << student[i].averageScore << "\n";
			}
		}
		cout << "Количество студентов под №" << k << ": " << kCount << "\n";

	}
}

void bubbleSort(Student student[])
{
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		for (int j = 0; j < MAX_STUDENTS - i - 1; j++) {
			if (student[j].averageScore < student[j + 1].averageScore) {
				swap(student[j], student[j + 1]);
			}
		}
	}
}

void showTopStudents(Student student[])
{
	ifstream database("students.txt");
	if (!database.is_open())
		cout << "\nНе удается открыть файл!\n";
	else
	{
		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			getline(database >> ws, student[i].name);
			database >> student[i].sex;
			database >> student[i].group;
			database >> student[i].id;
			for (int j = 0; j < 8; j++) {
				database >> student[i].grades[j];
			}
			database >> student[i].averageScore;
		}
		database.close();

		bubbleSort(student);

		cout << "\nСписок топ студентов:\n";

		for (int i = 0; i < 5; i++)
		{
			cout << "«Топ " << i + 1 << "»:\n";
			cout << "ФИО: " << student[i].name << " - ";
			cout << student[i].averageScore << "\n\n";
		}
	}
}

void showIdzMenu(Professor professor[]);

void menu(Student student[], Professor professor[])
{
	setlocale(LC_ALL, "ru");
	int mainMenu;
	{
		cout << "Главное меню:\n\nКакой пункт вы хотите выбрать?\n"
			<< "1 - Создать новую запись о студенте\n"
			<< "2 - Внести изменения в уже имеющуюся запись\n"
			<< "3 - Вывести данные о всех студентах\n"
			<< "4 - Вывести данные о всех студентах определенной группы\n"
			<< "5 - Вывести топ самых успешных студентов с наивысшим по рейтингу средним баллом\n"
			<< "6 - Вывести количество студентов мужского и женского пола\n"
			<< "7 - Вывести данные о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»\n"
			<< "8 - Вывести данные о студентах, имеющих определенный номер в списке\n"
			<< "9 - ИДЗ ( Струткура преподавателей )\n"
			<< "0 - Выход.\n";
	}
	cin >> mainMenu;
	switch (mainMenu)
	{
	case 1:
		addStudentToArray(student);
		createRecord(student);
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	case 2:
		showData();
		changeStudent(student);
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	case 3:
		showData();
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	case 4:
		showGroupInfo(student);
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	case 5:
		showTopStudents(student);
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	case 6:
		showSexInfo(student);
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	case 7:
		showGrantsData(student);
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	case 8:
		showStudentIdInfo(student);
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	case 9:
		system("cls");
		showIdzMenu(professor);
		system("Pause");
		system("cls");
		break;
	case 0:
		system("cls");
		break;
	default:
		cout << "Ошибка! Попробуйте снова\n";
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	}
}

void showIdzMenu(Professor professor[])
{
	int idzMenu;
	{
		cout << "ИДЗ меню:\n\nВыберите пункт:\n"
			<< "1 - Создать новую запись о преподавателе\n"
			<< "2 - Вывести данные о всех преподавателях\n"
			<< "3 - Вывести данные о преподавателе по фамилии\n"
			<< "4 - Вывести данные о всех преподавателях, которые ведут занятия у определенной группы\n"
			<< "5 - Вывести данные о преподавателе по наименованию дисциплины\n"
			<< "9 - Вернуться в главное меню\n"
			<< "0 - Выход из программы.\n";
	}
	cin >> idzMenu;
	switch (idzMenu)
	{
	case 1:
		addProfessor(professor);
		system("Pause");
		system("cls");
		showIdzMenu(professor);
		break;
	case 2:
		showIdzData();
		system("Pause");
		system("cls");
		showIdzMenu(professor);
		break;
	case 3:
		showIdzNameData(professor);
		system("Pause");
		system("cls");
		showIdzMenu(professor);
		break;
	case 4:
		showIdzGroupData(professor);
		system("Pause");
		system("cls");
		showIdzMenu(professor);
		break;
	case 5:
		showIdzDisciplineData(professor);
		system("Pause");
		system("cls");
		showIdzMenu(professor);
		break;
	case 9:
		system("Pause");
		system("cls");
		menu(student, professor);
		break;
	case 0:
		system("cls");
		break;
	default:
		cout << "Ошибка! Попробуйте снова\n";
		system("Pause");
		system("cls");
		showIdzMenu(professor);
		break;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	Student student[MAX_STUDENTS];
	Professor professor[MAX_PROFESSORS];
	menu(student, professor);
	return 0;
}
