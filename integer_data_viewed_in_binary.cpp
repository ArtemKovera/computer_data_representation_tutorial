/*   this little C++ program demonstrates how different integer values
     are represented in binary 
*/

#include<iostream>

template<typename T>
void printInBinary (T a)
{
    size_t sizeInBytes = sizeof(a);

    int8_t   var8   = 1;
    int16_t  var16  = 1;
    int32_t  var32  = 1;
    int64_t  var64  = 1;

    switch(sizeInBytes)
    {
        case 1:
            for(int i = 0; i < 8; i++)
            {
                if(a & var8)
                    std::cout << "1";
                else
                    std::cout << "0";
                
                
                var8 <<= 1;
            } 
            break;

        case 2:  
            for(int i = 0; i < 16; i++)
            {
                if(a & var16)
                    std::cout << "1";
                else
                    std::cout << "0";                    
                
                
                var16 <<= 1;
            } 
            break;   

        case 4:  
            for(int i = 0; i < 32; i++)
            {
                if(a & var32)
                    std::cout << "1";
                else
                    std::cout << "0";

                var32 <<= 1;
            } 
            break;                   

        case 8:  
            for(int i = 0; i < 64; i++)
            {
                if(a & var64)
                    std::cout << "1";
                else
                    std::cout << "0";                    
                
                var64 <<= 1;
            } 
            break;

        default:
           std::cout << "Something went wrong";    
           break;       
    }
    

    std::cout << std::endl;
}

template<typename T>
void printInBinaryReverse (T a)
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
    char ch1 = 0;
    printInBinary<char>(ch1);
    printInBinaryReverse<char>(ch1);
    std::cout << "-----" <<std::endl;

    char ch2 = 2;
    printInBinary<char>(ch2);
    printInBinaryReverse<char>(ch2);
    std::cout << "-----" <<std::endl;  

    char ch3 = 127;
    printInBinary<char>(ch3);
    printInBinaryReverse<char>(ch3);
    std::cout << "-----" <<std::endl;   
    
    char ch4 = 128;
    printInBinary<char>(ch4);
    printInBinaryReverse<char>(ch4);
    std::cout << "-----" <<std::endl;  

    char ch5 = -128;
    printInBinary<char>(ch5);
    printInBinaryReverse<char>(ch5);
    std::cout << "-----" <<std::endl;          
    std::cout << "-----" <<std::endl;  


    short sh1 = 3;
    printInBinary<short>(sh1);
    printInBinaryReverse<short>(sh1);
    std::cout << "-----" <<std::endl;
    std::cout << "-----" <<std::endl;   

    int in1 = 65535;
    printInBinary<int>(in1);
    printInBinaryReverse<int>(in1);
    std::cout << "-----" <<std::endl;    

    int in2 = 0x80000000; 
    printInBinary<int>(in2);
    printInBinaryReverse<int>(in2);
    std::cout << "-----" <<std::endl; 
    std::cout << "-----" <<std::endl;   
 
    long lo1 = 0x80000000;  
    printInBinary<long>(lo1);
    printInBinaryReverse<long>(lo1);
    std::cout << "-----" <<std::endl; 

    long lo2 = 2 * 2 * 2 * 2 * 2 * 2 * 2;
    printInBinary<long>(lo2);
    printInBinaryReverse<long>(lo2);
    std::cout << "-----" <<std::endl; 
         
    return 0;
}

// g++ -o prog integer_data_viewed_in_binary.cpp 