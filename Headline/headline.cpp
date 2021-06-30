/*
This program allow user to input new headlines and save the nearest three(can be adjusted to different number N), also user have the option to display in back-order. 

For example, if user input headlines "abc", "def", "ghi", and "jkl", the display will be: "jkl" "ghi" "def", the first input will be deleted.

The program will run until user input command 'q'
*/
#include <iostream>
#include<string>
using namespace std;

//This value can be adjusted to different number, default value = 3
const int N = 3;

//when user input more headlines than N, this function will be called and shift all the elements in the array backward, first element will be deleted
void arrange(string HL[]) {
    for (int i = 0; i < N-1; i++) {
        HL[i] = HL[i + 1];
    }
}

//add function
void addHL(string HL[], int count, string newHL) {
    if (count > N) {
        arrange(HL);
        HL[N-1] = newHL; //add to the end of array if numbers of array is beyond N
    }
    else {
        HL[count-1] = newHL; //add to the corresponding position of array if numbers of array is not beyond N
    }
}

//display function, backward to the input order
void display(string HL[], int count) {
    if (count <= N) {
        for (int i = count-1; i >=0 ; i--) {
            cout << HL[i] << endl;
        }
    }
    else {
        for (int i = N-1; i >=0; i--) {
            cout << HL[i] << endl;
        }
    }
}

int main()
{
    string HL[N], newHL;
    char choice;
    bool run = false; //loop tracker
    int count=0; //count of headlines tracker

    cout << "This driver shows how we might manage a 'Most Recent' list of headlines" << endl << endl;

    do {
        cout << "Enter one of : " << endl;
        cout << "q to exit program" << endl << "a to add a new headline" << endl << "d to display most recent headlines" << endl;
        cin >> choice;  //command input
        switch (choice) {
        case 'q': 
            run = false;  //quit program
            break;
        case 'a':
            run = true;
            count++;
            cout << "Enter latest headline :";
            getline(cin.ignore(1), newHL);  //read in headlines
            addHL(HL,count,newHL);  //add function call
            break;
        case 'd':
            run = true;
            cout << "Latest news :" << endl;
            display(HL,count);  //display function call
            break;
        default:
            run = true;
            cout << "Invalid input, trt again"<<endl;  //error message
            break;
        }
    } while (run);
    return 0;
}
