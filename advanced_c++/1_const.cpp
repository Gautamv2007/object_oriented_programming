#include <iostream>

//const
//      - A compile time constraint that an object can not be modified

/*
    Why use const
        a) Guards against inadvertent write to the variable
        b) Self Documenting
        c) Enables compiler to do more optimization, making code tighter
        d) const means the variable can be put in ROM
*/


int main(void){
    const int i = 9;
    //i = 6; // This line will give an error
    const_cast<int&>(i) = 9; //This operator casts away the const of the i

    int j;
    static_cast<const int&>(j); //This statement will make the integer j a const variable

    // const int *p1 = &i; // data is const, pointer is not
    // //*p1 = 5; //This line will give an error
    // p1++; //This line will not give an error because the pointer is not const

    // int* const p2; //pointer is const, data is not
    
    // const int* const p3; // data and pointer are both const

    // int const *p4 = &i;



    //Generalized rule
    //If const is on the left of *, data is const
    //If const is on the right of *, pointer is const
}



