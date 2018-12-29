#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;

int main() {

    ifstream input;
    ofstream output;

    string magic_number;
    int width;
    int height;
    int max_p;
    int pixels;
    int invert;
    string filename;

//code to read a file
    cout<<"Enter File to invert:";//asks the user to input file
    cin>>filename;//saves file in  string file name
    input.open(filename,ifstream::in);//opens file



    if(!input.is_open()){//if statement incase it doesnt work
        cerr<<"ERROR:could not open file.txt\n";
        exit(1);
    }

    input>> magic_number; //inputs magic number
    //cout<<" "<<magic_number<<endl;
    input>>width;//inputs witdh
    //cout<<" "<<width<<" ";
    input>> height;//inputs height
    //cout<<" "<<height<<endl;
    input>> max_p;//inputs max posible pixels
    //cout<<" "<<max_p<<endl;
    //cout<<"pixel values"<<endl;



    //ofstream is used to write to a fileout
    output.open("inversion.ppm",ofstream::out);//writes inversion of ppm file.
    if(!output.is_open()){
        cerr<<"ERROR: could not open file.txt\n";
        exit(1);
    }

    output<<magic_number<<endl<<width<<" "<<height<<endl<<max_p<<endl;//output headers info

    while(input){//takes care of the inversion and itterates over pixel values
        input>>pixels;//inputs all the pixels one by one
        invert=max_p-pixels;//inverts the pixels
        output<<invert<<" ";//outputs the inverted pixels.

    }
    input.close();
    output.close();
}