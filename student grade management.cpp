#include<iostream>
#include<utility>
using namespace std;

#define MAX 100
int grades[MAX];
int count=0;

//توابع
void  addgrades();
void  displaygrades();
int   findmax(int[] , int n);
int   findmin(int[] , int n);
float calculateaverage();
void  checkpass();
void  sortdescending();
void  menu();

int main(){
    int choice;
    do{
        menu();
        cout<<"please select an option: ";
        cin>>choice;

        switch(choice){
            case 1: addgrades();
                    break;// افزودن نمرات
            case 2: displaygrades();
                    break;// نمایش تمام نمرات
            case 3:
                if(count>0)
                    cout<<"highest grade:"<<findmax(grades,count)<<endl;
                else
                    cout<<"no grades have been entered yet!"<<endl;
                    break;// پیدا کردن بالا ترین نمره
            case 4:
                if(count>0)
                    cout<<"lowest grade:"<<findmin(grades,count)<<endl;
                else
                    cout<<"no grade have been entered yet!"<<endl;
                    break;// پیدا کردن پایین ترین نمره
            case 5:
                if(count>0)
                    cout<<"average grade:"<<calculateaverage()<<endl;
                else
                    cout<<"no grade have been entered yet!"<<endl;
                    break;// محاسبه میانگین نمرات
            case 6: checkpass();
                    break;// بررسی قبولی
            case 7: sortdescending();
                    break;// مرتب سازی نزولی نمرات
            case 8: cout<<" exiting the program..."<<endl;
                    break;// خروج
            default : cout<<"invalid option! please try again."<<endl;// گزینه نامعتبر
        }
    }while(choice != 8);
    return 0;
}

// نمایش منوی اصلی
void menu(){
     cout<<"\n student grades management menu \n";
     cout<<"1. add grades\n";
     cout<<"2. display all grades\n";
     cout<<"3. find highest grade\n";
     cout<<"4. find lowest grade\n";
     cout<<"5. calculate average grade\n";
     cout<<"6. check pass/fail\n";
     cout<<"7. sort grades in descending order\n";
     cout<<"8. exit\n";

     }

// 1. افزودن نمرات
void addgrades(){
     int  n;
     cout<<"enter the number of grades to add:";
     cin>>n;
     if(count+n>MAX){
        cout<<"error: grade capacity exceeded!"<<endl;
     return;
    }
     for(int i=0 ; i<n ; i++){
        cout<<"grade"<<(count+1)<<": ";
        cin>>grades[count];
        count++;
    }
}

// 2. نمایش تمام نمرات
void displaygrades(){
     if(count==0){
        cout<<"no grades have been recorded!"<<endl;
     return;
    }
     cout<<"recorded grades:";
     for(int i=0 ; i<count ; i++){
        cout<<grades[i]<<" ";
    }
     cout<<endl;

}

// 3. پیدا کردن بالا ترین نمره(تابع بازگشتی)
int findmax(int arr[] , int n)
{
    if(n==1)
        return arr[0];
    else
        return max((arr[n-1]) , findmax(arr , n-1));
}

// 4. پیدا کردن پایین ترین نمره(تابع بازگشتی)
int findmin(int arr[] , int n)
{
    if(n==1)
        return arr[0];
    else
        return min((arr[n-1]) , findmin(arr , n-1));
}

// 5. محاسبه میانگین نمرات
float calculateaverage(){
      int sum=0;
      for(int i=0 ; i<count ; i++){
        sum+=grades[i];
     }
      return(float)sum/count;
}

// 6. بررسی قبولی
void checkpass(){
     if(count==0){
        cout<<"no grades have been recorded!"<<endl;
     return;
    }
     cout<<"pass/fail status:\n";
     for(int i=0 ; i<count ; i++){
        cout<<"grade="<<grades[i]<<": "<<(grades[i] >= 50 ? "pass" : "fail")<<endl;
     }
    }

// 7. مرتب سازی نزولی نمرات
void sortdescending(){
     if(count==0){
        cout<<"no grades have been recorded!"<<endl;
     return;
    }
     for(int i=0 ; i<count-1 ; i++){

     for(int j=i+1 ; j<count ; j++){
        if(grades[i]<grades[j]){
            swap(grades[i] , grades[j]);
        }
      }
    }
     for(int i=0 ; i<count ; i++){
     cout<<grades[i]<<endl;
    }
     cout<<"grades have been sorted in descending order."<<endl;
}
