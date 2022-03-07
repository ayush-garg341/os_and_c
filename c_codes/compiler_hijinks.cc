#include<iostream>
using namespace std;


void m61_printstatistics(){
    cout << "here"<< endl;
}

int main() {
    char* ptrs[10];
    for (int i = 0; i < 10; ++i) {
        ptrs[i] = new char[i + 1];
    }
    for (int i = 0; i < 5; ++i) {
        delete[] ptrs[i];
    }
    m61_printstatistics();
}


//Here's a typical high level flow for this process for code in High Level Language such as C.

//--> goes through pre-processor.

//--> to give optimized code, still in C

//--> goes through compiler

//--> to give assembly code

//--> goes through an assembler

//--> to give code in machine language which is stored in OBJECT FILES

//--> goes through Linker

//--> to get an executable file.

// --> gcc file_name.c -c -> gives object file .o
// --> objdump -d file_name.o
// When we have an object file and we don’t have the source code with us and we have to find out the maximum information from the file. To do so objdump plays a very vital role. The main purpose of the objdump command is to help in debugging the object file
//      -f, -p, -x, -h, -d, -D
