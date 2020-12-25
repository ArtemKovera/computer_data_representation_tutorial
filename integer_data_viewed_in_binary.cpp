/*   
     this little C++ program demonstrates how different integer values
     are represented in binary 
*/

#include<iostream>

template<typename T>
void printInBinary (T a)
{
    unsigned char       var8   = 0x80;        
    unsigned short      var16  = 0x8000;
    unsigned int        var32  = 0x80000000;
    unsigned long long  var64  = 0x8000000000000000;

    size_t sizeInBytes = sizeof(a);

    switch(sizeInBytes)
    {
        case 1:
            
            for(int i = 0; i < 8; i++)
            {
                if(a & var8)
                    std::cout << "1";
                else
                    std::cout << "0";
                
                
                var8 >>= 1;
            } 
            break;

        case 2:  
            
            for(int i = 0; i < 16; i++)
            {
                if(a & var16)
                    std::cout << "1";
                else
                    std::cout << "0";                    
                
                
                var16 >>= 1;
            } 
            break;   

        case 4: 
            for(int i = 0; i < 32; i++)
            {
                if(a & var32)
                    std::cout << "1";
                else
                    std::cout << "0";

                var32 >>= 1;
            } 
            break;                   

        case 8:  
            for(int i = 0; i < 64; i++)
            {
                if(a & var64)
                    std::cout << "1";
                else
                    std::cout << "0";                    
                
                var64 >>= 1;
            } 
            break;

        default:
           std::cout << "Something went wrong";    
           break;       
    }
    

    std::cout << std::endl;
}

int main()
{   
    std::cout << "Exploring char data type\n" << std::endl;

    char ch0 = 0;
    printInBinary<char>(ch0);   
    printf("char 0 = %d \n", ch0); 
    std::cout << "-----" <<std::endl;

    char ch1 = 1;
    printInBinary<char>(ch1);   
    printf("char 1 = %d \n", ch1); 
    std::cout << "-----" <<std::endl;

    char ch2 = 2;
    printInBinary<char>(ch2);   
    printf("char 2 = %d \n", ch2); 
    std::cout << "-----" <<std::endl;

    char ch127 = 127;
    printInBinary<char>(ch127);
    printf("char 127 = %d \n", ch127); 
    std::cout << "-----" <<std::endl;

    char ch128 = 128;
    printInBinary<char>(ch128);  
    printf("char 128 = %d \n", ch128);  
    std::cout << "-----" <<std::endl; 

    char ch_128 = -128;
    printInBinary<char>(ch_128);
    printf("char -128 = %d \n", ch_128);  
    std::cout << "-----" <<std::endl;

    char ch129 = 129;
    printInBinary<char>(ch129);
    printf("char 129 = %d \n", ch129);  
    std::cout << "-----" <<std::endl;    

    char ch_129 = -129;
    printInBinary<char>(ch_129);  
    printf("char -129 = %d \n", ch_129);
    std::cout << "-----" <<std::endl;    

    char ch_130 = -130;
    printInBinary<char>(ch_130); 
    printf("char -130 = %d \n", ch_130);
    std::cout << "-----" <<std::endl; 
    std::cout << "-----------------------" <<std::endl; 

    std::cout << "\nExploring other integer data types\n" << std::endl;

    short sh_130 = -130;
    printInBinary<short>(sh_130); 
    printf("short -130 = %d \n", sh_130);
    std::cout << "-----" <<std::endl; 

    int int_130 = -130;
    printInBinary<int>(int_130); 
    printf("int -130 = %d \n", int_130);
    std::cout << "-----" <<std::endl; 

    long long ll_130 = -130;
    printInBinary<long long>(ll_130); 
    printf("long long -130 = %lld \n", ll_130);
    std::cout << "-----" <<std::endl;
         
    return 0;
}

// g++ -o prog integer_data_viewed_in_binary.cpp 