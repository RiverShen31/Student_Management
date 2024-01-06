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
    char Gender[5];
    int Age;
    float CPA;
    float Credit;
    char Rank[10] = "-";
};
 
typedef Student student;
 
void printLine(int n);
void EnterStudenInfo(student &sv, int id);
void AddStudent(student a[], int id, int n);
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
                    cout << "\n Enter ID: "; cin >> id;
                    UpdateStudent(listStudent, id, countStudent);
                    SaveFile(listStudent, countStudent, fileName);
                    printf("\nUpdate into file successfully!\n");
                }else{
                    cout << "\nMust have student to update!";
                }
                pressAnyKey();
                break;
            case 3:
                if(countStudent > 0) {
                    int id;
                    cout << "\n3. Delete Student.";
                    cout << "\n Enter ID: "; cin >> id;
                    if (DeleteById(listStudent, id, countStudent) == 1) {
                        printf("\nStudent with Id = %d have been removed.\n", &id);
                        countStudent--;
                        SaveFile(listStudent, countStudent, fileName);
                        printf("\nUpdate into file successfully!");
                    }
                }else{
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
    printLine(100);
    cout <<"\nSTT\tID\tName\tGender\tAge\tCPA\tCredit\tRank";
    for(int i = 0; i < n; i++) {
        printf("\n %d", i + 1);
        printf("\t%d", a[i].id);
        printf("\t%s", a[i].Name);
        printf("\t%s", a[i].Gender);
        printf("\t%d", a[i].Age);
        printf("\t%.2f\t%.2f", a[i].CPA, a[i].Credit);
        printf("\t%s", a[i].Rank);
    }
    printLine(100);
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
    // doc thong tin sinh vien
    while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10s\n", &a[i].id, &a[i].Name, 
            &a[i].Gender, &a[i].Age, &a[i].CPA, &a[i].Credit, &a[i].Rank) != EOF) {
        // cout << a[i].id << " " << a[i].Name << endl;
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
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
        fprintf(fp, "%5d%30s%5s%5d%10f%10f%10s\n", a[i].id, a[i].Name,a[i].Gender, 
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