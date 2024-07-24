#include <stdio.h>

float convert_C_to_F(float c)
{
    return ((c * 1.8) +32);  
}
float convert_C_to_K(float c)
{
    return (c + 273.15);
}

float convert_F_to_C(float f)
{
    return ((f - 32)*1.8);
}
float convert_F_to_K(float f)
{
    return ((f - 32)/1.8+273.15);
}

float convert_K_to_C(float k)
{
    return (k - 273.15);
}
float convert_K_to_F(float k)
{
    return ((k*9.5) - 459.67);
}
int main() 
{
    FILE *file;
    char *filename = "data.txt";

    // Mở file để ghi (write)
    //write end file
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error in opening file.\n", filename);
        return 0;
    }
    float result = convert_C_to_F(37);   // Ghi dữ liệu vào file
    if(result < -459.67)
    {
        printf("Enter the temp.\n");
    }
    else
    {
        fprintf(file,"C to F is %.2f\n",result);
        
    }
    result = convert_C_to_K(25);
    //0 kelvin or -273.15 C
    if(result < 0)
    {
        printf("Enter the temp.\n");
    }
    else
    {
        fprintf(file,"C to K is %.2f\n",result);
        
    }
    
    
    // Đóng file
    fclose(file);

    printf("Data saved in file %s.\n", filename);

    return 0;
}