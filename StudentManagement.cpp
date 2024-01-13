#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
 
struct Student {
    int id;
    char Name[30];
    char Gender[10];
    int Age;
    float CPA;
    float Credit;
    char Rank[15] = "-";
};
 
typedef Student student;
 
void printLine(int n);
void EnterStudenInfo(student &sv, int id);
void AddStudent(student a[], int id, int n);
void UpdateStudentInfoName(student a[], int id, int n);
void UpdateStudentInfoGender(student a[], int id, int n);
void UpdateStudentInfoAge(student a[], int id, int n);
void UpdateStudentInfoCPA(student a[], int id, int n);
void UpdateStudentInfoCredit(student a[], int id, int n);
void UpdateStudentInfo(student &sv);
void UpdateStudent(student a[], int id, int n);
int DeleteById(student a[], int id, int n);
void FindByName(student a[], char ten[], int n);
void FindByGender(student a[], char gender[], int n);
void FindByAge(student a[], int age, int n);
void FindByCPA(student a[], float cpa, int n);
void FindByCredit(student a[], float credit, int n);
void FindByRank(student a[], char rank[], int n);
void SetRank(student &sv);
bool CompareRank(student &a, student &b);
int idMax(student a[], int n);
void SortByCPA(student a[], int n);
void SortStudentByName(student a[], int n);
void SortStudentByAge(student a[], int n);
void SortStudentByCredit(student a[], int n);
void SortStudentByRank(student a[], int n);
void ShowStudent(student a[], int n);
int ReadFile(student a[], char fileName[]);
void SaveFile(student a[], int n, char fileName[]);
void pressAnyKey();

vector<int> parseInputString(string& input);
 
int main() {
    int key;
    char fileName[] = "sinhvien.txt";
    student listStudent[MAX];
    int countStudent = 0;
    int idCount = 0;
     
    // nhap danh sach sinh vien tu file
    countStudent = ReadFile(listStudent, fileName);
    idCount = idMax(listStudent, countStudent);
 
    while(true) {
        cout << "Student Management by C/C++\n";
        cout << "****************MENU**********************\n";
        cout << "**  1. Add Student.                     **\n";
        cout << "**  2. Update Student by ID.            **\n";
        cout << "**  3. Delete Student by ID.            **\n";
        cout << "**  4. Find Student.                    **\n";
        cout << "**  5. Sort Student.                    **\n";
        cout << "**  6. Show students.                   **\n";
        cout << "**  7. Create file text.                **\n";
        cout << "**  0. Exit                             **\n";
        cout << "******************************************\n";
        cout << "Enter option: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1. Add Student.";
                idCount++;
                AddStudent(listStudent, idCount, countStudent);
                printf("\nAdd Student Succesfully!\n");
                countStudent++;
                SaveFile(listStudent, countStudent, fileName);
                printf("\nSave into file successfully!");
                pressAnyKey();
                break;
            case 2:
                if(countStudent > 0) {
                    int id;
                    cout << "\n2. Update Student Info. ";
                    ShowStudent(listStudent, countStudent);
                    cout << "\n Enter ID: "; cin >> id;
                    cout << "\n Enter option you want to update: ";
                    cout << "\n ---------------------------------";
                    cout << "\n -- 1. Name                     --";
                    cout << "\n -- 2. Gender                   --";
                    cout << "\n -- 3. Age                      --";
                    cout << "\n -- 4. CPA                      --";
                    cout << "\n -- 5. Credit                   --";
                    cout << "\n -- 6. All                      --";
                    cout << "\n ---------------------------------";
                    cout << "\n Enter option: "; cin >> key;
                    switch (key)
                    {
                    case 1:
                        UpdateStudentInfoName(listStudent, id, countStudent);
                        SaveFile(listStudent, countStudent, fileName);
                        printf("\nUpdate into file successfully!\n");
                        break;

                    case 2:
                        UpdateStudentInfoGender(listStudent, id, countStudent);
                        SaveFile(listStudent, countStudent, fileName);
                        printf("\nUpdate into file successfully!\n");
                        break;

                    case 3:
                        UpdateStudentInfoAge(listStudent, id , countStudent);
                        SaveFile(listStudent, countStudent, fileName);
                        printf("\nUpdate into file successfully!\n");
                        break;
                    
                    case 4:
                        UpdateStudentInfoCPA(listStudent, id, countStudent);
                        SaveFile(listStudent, countStudent, fileName);
                        printf("\nUpdate into file successfully!\n");
                        break;

                    case 5:
                        UpdateStudentInfoCredit(listStudent, id, countStudent);
                        SaveFile(listStudent, countStudent, fileName);
                        printf("\nUpdate into file successfully!\n");
                        break;

                    case 6:
                        UpdateStudent(listStudent, id, countStudent);
                        SaveFile(listStudent, countStudent, fileName);
                        printf("\nUpdate into file successfully!\n");
                        break;

                    default:
                        break;
                    }
                }else{
                    cout << "\nMust have student to update!";
                }
                pressAnyKey();
                break;
            
            case 3:
                if (countStudent > 0) {
                    cout << "\n3. Delete Student.";
                    ShowStudent(listStudent, countStudent);
                    cout << "\n ---------------";
                    cout << "\n - 1. MANY     -";
                    cout << "\n - 2. ONE      -";
                    cout << "\n ---------------";
                    cout << "\nEnter option: ";
                    cin >> key;

                    string input;
                    vector<int> idsToDelete;

                    switch (key) {
                        case 1:
                            cout << "\nEnter IDs of students to delete (separated by spaces): ";
                            cin.ignore();
                            getline(cin, input);
                            idsToDelete = parseInputString(input);
                            for (int id : idsToDelete) {
                                if (DeleteById(listStudent, id, countStudent) == 1) {
                                    printf("\nStudent with ID = %d has been removed.\n", id);
                                    countStudent--;
                                }
                            }
                            SaveFile(listStudent, countStudent, fileName);
                            printf("\nUpdate into file successfully!");
                            break;
                        case 2:
                            cout << "\nEnter ID: ";
                            int id;
                            cin >> id;
                            if (DeleteById(listStudent, id, countStudent) == 1) {
                                printf("\nStudent with ID = %d has been removed.\n", id);
                                countStudent--;
                                SaveFile(listStudent, countStudent, fileName);
                                printf("\nUpdate into file successfully!");
                            }
                            break;
                        default:
                            break;
                    }
                } else {
                    cout << "\nMust have student to delete!";
                }
                pressAnyKey();
                break;
            
            case 4:
                if(countStudent > 0) {
                    cout << "\n-----------------------------------";
                    cout << "\n-- 1 Find Student by Name.       --";
                    cout << "\n-- 2 Find Student by Gender.     --";
                    cout << "\n-- 3 Find Student by Age.        --";
                    cout << "\n-- 4 Find Student by CPA         --";
                    cout << "\n-- 5 Find Student by Credit      --";
                    cout << "\n-- 6 Find Student by Rank        --";
                    cout << "\n-- 0. Exist                      --";
                    cout << "\n-----------------------------------";
                    cout << "\nEnter option: "; cin >> key;
                    switch (key)
                    {
                    case 1:
                        cout << "\n4.1 Find Student by name.";
                        char strTen[30];
                        cout << "\nEnter name: "; fflush(stdin); gets(strTen);
                        FindByName(listStudent, strTen, countStudent);
                        break;
                    
                    case 2:
                        cout << "\n4.2 Find Student by Gender.";
                        char genderStudent[5];
                        cout << "\nEnter gender: "; fflush(stdin); gets(genderStudent);
                        FindByGender(listStudent, genderStudent, countStudent);
                        break;

                    case 3:
                        cout << "\n4.3 Find Student by Age.";
                        int ageStudent;
                        cout << "\nEnter Age: "; cin >> ageStudent;
                        FindByAge(listStudent, ageStudent, countStudent);
                        break;

                    case 4:
                        cout << "\n4.4 Find Student by CPA.";
                        float cpaStudent;
                        cout << "\nEnter CPA: "; cin >> cpaStudent;
                        FindByCPA(listStudent, cpaStudent, countStudent);
                        break;
                    
                    case 5:
                        cout << "\n4.5 Find Student by Credit.";
                        float creditStudent;
                        cout << "\nEnter credit: "; cin >> creditStudent;
                        FindByCredit(listStudent, creditStudent, countStudent);
                        break;

                    case 6:
                        cout << "\n4.6 Find Student by Rank";
                        char rankStudent[10];
                        cout << "\nEnter Rank: "; fflush(stdin); gets(rankStudent);
                        FindByRank(listStudent, rankStudent, countStudent);
                        break;

                    case 0:
                        cout << "\nExist";
                        break;

                    default:
                        cout << "\nPlease choose the right option!";
                        break;
                    }

                    // cout << "\n4. Find Student by name.";
                    // char strTen[30];
                    // cout << "\nEnter name: "; fflush(stdin); gets(strTen);
                    // FindByName(listStudent, strTen, countStudent);
                }else{
                    cout << "\nMust have student!";
                }
                pressAnyKey();
                break;
            case 5:
                if(countStudent > 0) {
                    cout << "\n-----------------------------------";
                    cout << "\n-- 1 Sort Student by CPA.        --";
                    cout << "\n-- 2 Sort Student by Name.       --";
                    cout << "\n-- 3 Sort Student by Age.        --";
                    cout << "\n-- 4 Sort Student by Credit      --";
                    cout << "\n-- 5 Sort Student by Rank        --";
                    cout << "\n-- 0. Exist                      --";
                    cout << "\n-----------------------------------";
                    cout << "\nEnter option: "; cin >> key;
                    switch (key)
                    {
                    case 1:
                        cout << "\n1. Sort Student by CPA.";
                        SortByCPA(listStudent, countStudent);
                        ShowStudent(listStudent, countStudent);
                        break;
                    case 2:
                        cout << "\n2. Sort Student By Name.";
                        SortStudentByName(listStudent, countStudent);
                        ShowStudent(listStudent, countStudent);
                        break;
                    case 3:
                        cout << "\n3. Sort Student By Age.";
                        SortStudentByAge(listStudent, countStudent);
                        ShowStudent(listStudent, countStudent);
                        break;

                    case 4:
                        cout << "\n4. Sort Student by Credit.";
                        SortStudentByCredit(listStudent, countStudent);
                        ShowStudent(listStudent, countStudent);
                        break;

                    case 5:
                        cout << "\n5. Sort Student by Rank.";
                        SortStudentByRank(listStudent, countStudent);
                        ShowStudent(listStudent, countStudent);
                        break;

                    case 0:
                        cout << "\nExist";
                        break;

                    default:
                        cout << "\nPlease choose the right option!";
                        break;
                    }
                }else{
                    cout << "\nMust have student!";
                }
                pressAnyKey();
                break;
            case 6:
                if(countStudent > 0){
                    cout << "\n6. Show Student.";
                    ShowStudent(listStudent, countStudent);
                }else{
                    cout << "\nMust have student!";
                }
                pressAnyKey();
                break;

            case 7:
                if (countStudent > 0) {
                    cout << "\n7. Create student file";
                    char fileSave[100];
                    cout << "\nEnter file name: "; fflush(stdin); gets(fileSave);
                    SaveFile(listStudent, countStudent, fileSave);
                    printf("\nWrite into file successfully!\n");
                } else {
                    cout << "\nMust have student!";
                }
                pressAnyKey();
                break;

            case 0:
                cout << "\nExist!";
                getch();
                return 0;
            default:
                cout << "\nPlease choose the right option!";
                pressAnyKey();
                break;
        }
    }
}
 
void SetRank(student &sv) {
    if(sv.CPA >= 3.6) strcpy(sv.Rank, "Excellent");
    else if(sv.CPA >= 3.2) strcpy(sv.Rank, "Good");
    else if(sv.CPA >= 2.5) strcpy(sv.Rank, "Average");
    else strcpy(sv.Rank, "Poor");
}
  
bool CompareRank(student &a, student &b) {
    // Define the rank order: Excellent > Good > Average > Poor
    if (strcmp(a.Rank, "Excellent") == 0) {
        return true;
    } else if (strcmp(a.Rank, "Good") == 0 && strcmp(b.Rank, "Excellent") != 0) {
        return true;
    } else if (strcmp(a.Rank, "Average") == 0 && strcmp(b.Rank, "Excellent") != 0 && strcmp(b.Rank, "Good") != 0) {
        return true;
    } else if (strcmp(a.Rank, "Poor") == 0 && strcmp(b.Rank, "Excellent") != 0 && strcmp(b.Rank, "Good") != 0 && strcmp(b.Rank, "Average") != 0) {
        return true;
    }
    return false;
}

void EnterStudenInfo(student &sv, int id) {
    cout << "\n Enter Name: "; fflush(stdin); gets(sv.Name);
    cout << " Enter gender: "; gets(sv.Gender);
    cout << " Enter Age: "; cin >> sv.Age;
    cout << " Enter CPA: "; cin >> sv.CPA;
    cout << " Enter credit: "; cin >> sv.Credit;
    sv.id = id;
    SetRank(sv);
}
 
void AddStudent(student a[], int id, int n) {
    printLine(40);
    printf("\n Enter Student %d:", n + 1);
    EnterStudenInfo(a[n], id);
    printLine(40);
}
 
void UpdateStudentInfo(student &sv) {
    cout << "\n Enter name: "; fflush(stdin); gets(sv.Name);
    cout << " Enter gender: "; gets(sv.Gender);
    cout << " Enter age: "; cin >> sv.Age;
    cout << " Enter CPA: "; cin >> sv.CPA;
    cout << " Enter credit: "; cin >> sv.Credit;
    SetRank(sv);
}

void UpdateStudentInfoName(student a[], int id, int n) {
    int found = 0;
    for (int i=0; i<n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Enter name: "; fflush(stdin); gets(a[i].Name);
            break;
        }
    }
    if (found == 0) {
        printf("\n Student with ID = %d doesn't exist.", id);
    }
}

void UpdateStudentInfoGender(student a[], int id, int n) {
    int found = 0;
    for (int i=0; i<n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Enter gender: "; fflush(stdin); gets(a[i].Gender);
            break;
        }
    }
    if (found == 0) {
        printf("\n Student with ID = %d doesn't exist.", id);
    }
}

void UpdateStudentInfoAge(student a[], int id, int n) {
    int found = 0;
    for (int i=0; i<n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Enter age: "; fflush(stdin);  cin >> a[i].Age;
            break;
        }
    }
    if (found == 0) {
        printf("\n Student with ID = %d doesn't exist.", id);
    }
}

void UpdateStudentInfoCPA(student a[], int id, int n) {
    int found = 0;
    for (int i=0; i<n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Enter CPA: "; fflush(stdin); cin >> a[i].CPA;
            SetRank(a[i]);
            break;
        }
    }
    if (found == 0) {
        printf("\n Student with ID = %d doesn't exist.", id);
    }
}

void UpdateStudentInfoCredit(student a[], int id, int n) {
    int found = 0;
    for (int i=0; i<n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Enter credit: "; fflush(stdin); cin >> a[i].Credit;
            break;
        }
    }
    if (found == 0) {
        printf("\n Student with ID = %d doesn't exist.", id);
    }
}
 
void UpdateStudent(student a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Update Student with Id: " << id;
            UpdateStudentInfo(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Student with ID = %d doesn't exist.", id);
    }
}
 
int DeleteById(student a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Delete student by ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Student with Id = %d doesn't exist.", id);
        return 0;
    } else {
        return 1;
    }
}

void FindByRank(student a[], char rank[], int n) {
    student arrayFound[MAX];
    char rankStudent[10];
    int found = 0;
    for (int i=0; i<n; i++) {
        strcpy(rankStudent, a[i].Rank);
        if (strstr(strupr(rankStudent), strupr(rank))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    if (found > 0) {
        ShowStudent(arrayFound, found);
    }
}

void FindByName(student a[], char ten[], int n) {
    student arrayFound[MAX];
    char tenSV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenSV, a[i].Name);
        if(strstr(strupr(tenSV), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    if (found > 0) {
        ShowStudent(arrayFound, found);
    } else {
        cout << "\nNot found!";
    }
}

void FindByGender(student a[], char gender[], int n) {
    student arrayFound[MAX];
    char genderStudent[5];
    int found = 0;
    for (int i=0; i<n; i++) {
        strcpy(genderStudent, a[i].Gender);
        if (strstr(strupr(genderStudent), strupr(gender))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    if (found > 0) {
        ShowStudent(arrayFound, found);
    } else {
        cout << "\nNot found!";
    }
}

void FindByAge(student a[], int age, int n) {
    student arrayFound[MAX];
    int found = 0;
    for (int i=0; i<n; i++) {
        if (a[i].Age == age) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    if (found > 0) {
        ShowStudent(arrayFound, found);
    } else {
        cout << "\nNot found!";
    }
}

void FindByCPA(student a[], float cpa, int n) {
    student arrayFound[MAX];
    int found = 0;
    for (int i=0; i<n; i++) {
        if (a[i].CPA == cpa) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    if (found > 0) {
        ShowStudent(arrayFound, found);
    } else {
        cout << "\nNot found!";
    }
}

void FindByCredit(student a[], float credit, int n) {
    student arrayFound[MAX];
    int found = 0;
    for (int i=0; i<n; i++) {
        if (a[i].Credit == credit) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    if (found > 0) {
        ShowStudent(arrayFound, found);
    } else {
        cout << "\nNot found!";
    }
}
 
void ShowStudent(student a[], int n) {
    printLine(120);
    cout <<"\n STT\t ID\t\t Name\t\t Gender\t\t Age\t\t CPA\t\t Credit\t\t Rank";
    for(int i = 0; i < n; i++) {
        printf("\n %d", i + 1);
        printf("\t %d", a[i].id);
        printf("\t\t %s", a[i].Name);
        printf("\t\t %s", a[i].Gender);
        printf("\t\t %d", a[i].Age);
        printf("\t\t %.2f\t\t %.2f", a[i].CPA, a[i].Credit);
        printf("\t\t %s", a[i].Rank);
    }
    printLine(120);
}

void SortStudentByAge(student a[], int n) {
    student tmp;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i].Age > a[j].Age) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void SortStudentByCredit(student a[], int n) {
    student tmp;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i].Credit > a[j].Credit) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
  
void SortByCPA(student a[], int n) {
    //Sap xep theo DTB tang dan
    student tmp;
    for(int i = 0;i < n;i++) {
        for(int j = i+1; j < n;j++) {
            if(a[i].CPA > a[j].CPA) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
 
void SortStudentByName(student a[], int n) {
    //Sap xep sinh vien theo ten theo thu tu tang dan
    student tmp;
    char nameStudent1[30];
    char nameStudent2[30];
    for(int i = 0;i < n; i++) {
        strcpy(nameStudent1, a[i].Name);
        for(int j = i+1; j < n; j++) {
            strcpy(nameStudent2, a[j].Name);
            if(strcmp(strupr(nameStudent1), strupr(nameStudent2)) > 0) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void SortStudentByRank(student a[], int n) {
    sort(a, a+n, CompareRank);
}
 
int idMax (student a[], int n) {
    int idMax = 0;
    if (n > 0) {
        idMax = a[0].id;
        for(int i = 0;i < n; i++) {
            if (a[i].id > idMax) {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}
 
int ReadFile(student a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "Read file: "; puts(fileName);

    if (fp == nullptr) {
        cout << "Error opening file." << endl;
        return 0;
    }
    // doc thong tin sinh vien
    while (fscanf(fp, "%5d%30s%15s%15d%15f%15f%15s\n", &a[i].id, &a[i].Name, 
            &a[i].Gender, &a[i].Age, &a[i].CPA, &a[i].Credit, &a[i].Rank) != EOF) {
        // cout << a[i].id << " " << a[i].Name << endl;
       i++;
       cout << " Read record number: " << i << endl;
    }
    cout << " Number of student in file: " << i << endl;
    cout << endl;
    fclose (fp);
    // tra ve so luong sinh vien duoc doc tu file
    return i;
}
 
void SaveFile(student a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%15s%15d%15f%15f%15s\n", a[i].id, a[i].Name,a[i].Gender, 
            a[i].Age, a[i].CPA, a[i].Credit, a[i].Rank);
    }
    fclose (fp);
}
 
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
 
void pressAnyKey() {
    cout << "\n\nEnter any key to continue...";
    getch();
    system("cls");
}

vector<int> parseInputString(string& input) {
    vector<int> result;
    istringstream iss(input);
    int value;
    while (iss >> value) {
        result.push_back(value);
    }
    return result;
}