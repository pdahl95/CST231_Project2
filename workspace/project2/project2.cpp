#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std; 

struct student{ // declaring a struct called student and assing 4 varibales to correspond with each student - name, attempt and avarge 
    string firstName;
    string lastName; 
    int numAttempts; 
    float average; 
}; 

void printAllStudents(student allStudents[], int numStudents){ // function that takes of student and prints out all values in a user friendly way. 
    for(int i = 0; i < numStudents; i++){ // for loop to print all student with the student struct variables 
        cout << allStudents[i].firstName << " " << allStudents[i].lastName 
        << " has made " << allStudents[i].numAttempts << " attempts and have an average of " 
        << allStudents[i].average << endl;
    }
}

void readStudentsFromFile(student allStudents[], int numStudents){ // function to read student from the file and add it to the struct student and print the student array 
     ifstream myReadFile;
    
   // cout << "Open the file. Student data is stored in the studetnData.txt" << endl;
    myReadFile.open("studentData.txt");  // check if file exist
     //cout << "Every time we read something in from the file, we will store it inside of the varibale." << endl;
    string input; 
    
   // cout << "Check is the file successfully opened... " << endl;
    if(myReadFile.is_open()){
      //  cout << "Loop through all my students one by one" << endl;
             for(int i = 0; i < numStudents && myReadFile.eof() == 0; i++){
        //    cout << "Read in the students first name. Store inside the corresponding student array" << endl;
            myReadFile >> allStudents[i].firstName;
        //    cout << "Read in the students last name. Store inside the corresponding student array" << endl;
            myReadFile >> allStudents[i].lastName;
        //    cout << "Read in the students number of attempts. Store inside the corresponding student array" << endl;
            myReadFile >> allStudents[i].numAttempts;
         //   cout << "Read in the students averages. Store inside the corresponding student array" << endl;
            myReadFile >> allStudents[i].average; 
        }
    }
    // cout << "Close the file"
    myReadFile.close(); 
}

// create an outstream (ofstream)
void writeStudentsToFile(student allStudents[], int numStudents){ // function that prints all of our students back into a file 
    ofstream writeStudentDataFile("studentData.txt", ios::out | ios::trunc); // clear contents of studentData.txt (ios::out | ios::trunc is a c++ predifend function from c++ library)
    for(int i = 0; i < numStudents; i++){ // for loop to go through all the student and print the info of each student back to to file StudentData.txt
        writeStudentDataFile << allStudents[i].firstName << " " << allStudents[i].lastName << " " 
        << allStudents[i].numAttempts << " " << allStudents[i].average << endl;
    }
}

void pickRandomStudent(student students[], int num){ // code for function to pick randomstudent and add new grade to the student 
    // Pick a random number between 0 and num 
    int r1 = rand()%num; 
    
    // Pick that praticualr entry from the student array as the picked student
    student picked;
    picked = students[r1]; 
    
    // Print the picked student information on the screen 
    cout << "Student name: " << picked.firstName << " " << picked.lastName << ", Average: " << picked.average << ", numAttempts: " << picked.numAttempts << endl;
   
    // Ask intrctuor for new grade for the picked student  & read in to a varibale 
   int newGrade; // declaring a int varibale for new grade 
   cout << "Enter new grade for the picked student: "; // ask user to input new grade
   cin >> newGrade; // let the user input the new grade
   
    // calculate new average for student - increase number of attempts for picked student 
   picked.average = ((picked.average * picked.numAttempts) + newGrade)/(picked.numAttempts+1); // average is total / number 
   picked.numAttempts++; // adding one each time to number of attempts 
   
   cout << "Updated Info: Student name: " << picked.firstName << " " << picked.lastName << ", Average: " << picked.average << ", numAttempts: " << picked.numAttempts << endl;
    
    students[r1] = picked;  // Update the array with the new info - call write to file function to push thi data on to the file 
    // writeStudentsToFile(students, num); 
}

void searchByFirstName(student allStudents[], int numStudents){ //code function for searching for students by first name 
    string firstName;  // declare a varibale string to store user input
    bool ifNoMatch = true; // this will make sure that the cout "Didn;t find student..." will not be printed it the cout statement happened and they found a student to print 
    
    cout << "Enter first name: " << endl; // ask user to input first name 
    cin >> firstName; // let user input the first name of the student they want to search for 
    
    for(int i = 0; i < numStudents; i++){ // search through the array of student for the firstname by using a for loop 
        if(allStudents[i].firstName == firstName){ // if there is a match, print student 
            cout << allStudents[i].firstName << " " << allStudents[i].lastName 
        << " has made " << allStudents[i].numAttempts << " attempts and have an average of " 
        << allStudents[i].average << endl;
        ifNoMatch = false; // saying the the for loop ran and that the found a student 
        }
    }
    if(ifNoMatch){ // if we could not find a match print out a statement - only prints when a student is not found!
        cout << "Didn't find the student with first name : " << firstName << endl;
    }
}

void searchByLastName(student allStudents[], int numStudents){ // code function for searching for students by last name
    string lastName; // declare a varibale string to store user input 
    bool ifNoMatch = true; // this will make sure that the cout "Didn;t find student..." will not be printed it the cout statement happened and they found a student to print 
    
    cout << "Enter last name: " << endl; // asking user to enter last name 
    cin >> lastName; // let user input last name
    
    // search through the array of student for the lastname by using a for loop 
    for(int i = 0; i < numStudents; i++){
        if(allStudents[i].lastName == lastName){ // if there is a match, print student 
            cout << allStudents[i].firstName << " " << allStudents[i].lastName 
        << " has made " << allStudents[i].numAttempts << " attempts and have an average of " 
        << allStudents[i].average << endl;
        ifNoMatch = false; // saying the the for loop ran and that the found a student 
        }
    }
    if(ifNoMatch){// if we could not find a match print out a statement - only prints when a student is not found!
        cout << "Didn't find the student with last name : " << lastName << endl;
    }
}

void showMenu(student sArray[], int num){ // function for showing menu to user 
    char choice; // declaring a varibale called choice 
    
    while(true){
    // code to print a menu to the user so they can chose what they want to do with the program 
    cout << "1 - Print all student info" << endl;
    cout << "2 - Pick a random student to Engange" << endl;
    cout << "3 - Search for Student by First Name" << endl;
    cout << "4 - Search for Student by Last Name" << endl;
    cout << "q - Quit Program" << endl;
    cout << "Enter your choice: " << endl;
    
    // Read user input
    cin >> choice; 
    // Based on the input, call different functions to have different responsed
        if(choice == '1'){
            printAllStudents(sArray, num); // if user input number 1 - function to printAllStudent will be called and the will run
        }else if (choice == '2'){
            pickRandomStudent(sArray, num); // if user input number 2 - function to pickRandomStudent will be called and the will run
        }else if (choice == '3'){
            searchByFirstName(sArray, num);  // if user input number 3 - function to SearchByFirstName will be called and the will run
        }else if (choice == '4'){
            searchByLastName(sArray, num);  // if user input number 4 - function to searchByFirstName will be called and the will run
        }else if (choice == 'q'){  // if user input number q - and the program quit
            return; 
        }else {
            cout << "I don't understand the choice" << endl; // if the user don't input any of the assigned numbers, the program will tell the user that it don't understand the choice! 
        }
    }
}

int main(){
    // cout << "call the random function, so each student will be picked random" << endl;
    srand(time(NULL));  
    // cout << "const --> making sure 25 will always be the number - never changes" << endl;
    const int numStudents = 25;
    // cout << "Getting the struct and siging it the name allStudent, and declare that it will be an array of numStudents" << endl;
    student allStudents[numStudents];
    // cout << "Calling the 'readStudentFromFile and asigning it the struct array of allStudent and numStudents" << endl;
    readStudentsFromFile(allStudents, numStudents); 
    // cout << "Calling the 'showMenu' and asigning it the struct array of allStudent and numStudents" << endl;
    showMenu(allStudents, numStudents);
    // cout << "Calling the 'writeStudentsToFile' and asigning it the struct array of allStudent and numStudents" << endl;
    writeStudentsToFile(allStudents, numStudents); 
    
    return 0; 
}