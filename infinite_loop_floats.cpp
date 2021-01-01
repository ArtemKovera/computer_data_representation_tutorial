/*

    This little program demonstrates making an infinite loop 
    by using a float variable as a loop counter

*/

#include<iostream>
#include<iomanip>


int main()
{
    float counter = 16700000;

    std::cout<<std::fixed;

    while (counter < 16780000)
    {
        std::cout << counter << "\n";
        counter++;
    }

    return 0;
}

//g++ infinite_loop_floats.cpp  
//./a.out
//Ctrl+C