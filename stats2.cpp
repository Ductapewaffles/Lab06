#include <iostream> // for cout, cin, endl
#include <cmath>    // for pow -- the only one you're allowed to use from this lib
#include <iomanip>  // for setprecision, setw -- the only ones you're allowed to use from this lib
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
    //Preconditions: It takes in a dynamic int array and its size
    //Post-condition: It sorts the array in ascending order of its values
double average(int *array, int size);
    //Preconditions: It takes in a dynamic int array and its size
    //Postcondition: It returns the average of all elements within the array
double median(int* array, int size);
    //Preconditions: It takes in a dynamic int array and its size
    //Postconditions: It returns the median of the elements within the array.
    //If the number of elements in the array is even then the median is the average of
    //the two integers closest to the center of the array.
double stddev(int* array, int size, double average);
    //Preconditions: It takes in a dynamic int array and its size as 
    //well as the average all values within array
    //Postconditions: It returns the standard deviation which is
    //calculated using the elements within the dynamic array.

typedef int* IntegerPtr; //int* data type is renamed to have the alias IntegerPtr
IntegerPtr gradep = nullptr; //a pointer of type integer is set to null or zero



int main(){
    // Sets the printing of floating-point numbers
    // to show only 2 places after the decimal point
    cout << fixed << showpoint;
    cout << setprecision(2);
    string file_name;
    cout << "Enter filename: ";
    cin >> file_name;
    ifstream inFile;
    inFile.open(file_name);
    if (inFile.fail()){
        cerr << "Cannot open " << file_name << endl;
        exit(1);
    }
    int next, grade_count(0);
    int temp_grade;
    IntegerPtr resized_arr;
    while(inFile >> next){
        resized_arr = new int[grade_count + 1];
        for(int i = 0; i < grade_count; i++){
            resized_arr[i] = gradep[i];
        }
        resized_arr[grade_count] = next;

        delete gradep;
        gradep = resized_arr;
        grade_count++;
    }
    resized_arr = nullptr;
    if(grade_count < 1){
       cerr << "Error!\n";
       exit(1);
    }

    

    bubbleSort(gradep, grade_count); //function call to bubbleSort() using previously defined array
    double avg = average(gradep, grade_count); //a double variable assigned to output of average()    double avg = average(gradep, grade_count); //a double variable assigned to output of average()
    double med = median(gradep, grade_count); //a double variable assigned to output of median()
    double sdev = stddev(gradep, grade_count, avg); //a double variable assigned to output of stddev()
    cout << "Here are some statistics:\n"; //printing for readability for user
    cout << right; //margins are now right oriented
    cout << setw(9) << "N: " << grade_count << endl;
    cout << setw(9) << "Average: " << avg << endl; //lines 55-57 are set to same indent and output each respective
    cout << setw(9) << "Median: " << med << endl;
    cout << setw(9) << "StdDev: " << sdev << endl;
    delete []gradep; //this deletes the array gradep points to
    gradep = nullptr; //gradep pointer is set to zero
    resized_arr = nullptr;
    inFile.close();
    return 0; //main return
}




double average(IntegerPtr array, int array_size){
    double avg1(0), sum(0); //variable initialization
    if (array_size == 1) //if the number of grades is 1, then the average is just that number
        return array[0] / 1.0;
    for (int i = 0; i < array_size; i++){ //adds all elements in the defined array
        sum += array[i];
    }
    avg1 = sum / array_size; //This computes the average and since all variables are doubles, it computes this 
                             //correctly
    return avg1; //function return
}

double median(IntegerPtr array, int array_size){
    int array_middle_left(0), array_middle_right(0), sum(0); //variable initialization
    int median_index(0); //variable initialization
    double median_avg(0), med1(0); //variable initialization
    if (array_size == 1) //if the array has only 1 element, the median is that element
        return array[0] / 1.0;
    else if (array_size % 2 == 0){ //if the array size is even, then goes down this branch
        array_middle_left = (array_size / 2) - 1; //gets the index of element to the left of the exact middle
        array_middle_right = (array_size / 2); //gets index of element to the right of the exact middle
        sum = array[array_middle_left] + array[array_middle_right]; //sums the values at those indices
        median_avg = sum / 2.0; //avgs those two values to get the exact middle of the array
        return median_avg; //function return if program goes down this branch
    }
    else{ //this branch if for arrays with an odd # of elements
        array_middle_left = array_size / 2; //gets the index of the middle element
        median_index = array_middle_left; //adds 1 to get to middle index
        med1 = array[median_index] / 1.0; //divides value at index by float to get a floating point
        return med1; //function return
    }
}


double stddev(IntegerPtr array, int array_size, double average){
    int value(0); //variable initialization
    double sum1(0), sum_total(0), before_sqrt(0), dev(0); //variable initialization
    if (array_size == 1){ //if array size is 1, deviation is 0
        return dev;
    }
    double multiplier = 1.0 / (array_size - 1); //done after confirmed array size >= 1 otherwise dividing by 0
    for (int i = 0; i < array_size; i++){ //To get the sum_total for standard deviation
        value = array[i]; //value at index
        sum1 = value - average; //value minus the average
        sum_total += pow(sum1, 2); //then we square this and add it to sum and repeat through all iterations
    }
    before_sqrt = sum_total * multiplier; //Everything inside the sqrt it assigned to this variable
    dev = pow(before_sqrt, 0.5); //sqrt this value
    return dev; //return this value
}


// This is bubbleSort - it is given for you to use.
// Pre-Condition:: It takes in a dynamic int array and its size
// Post-Condition: It sorts the array in ascending order of its values
void bubbleSort(IntegerPtr array, int size) {
  int temp;
  for (int i = size-1; i >= 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (array[j-1] > array[j]) {
        temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
      } // if
    } // for j
  } // for i
}

