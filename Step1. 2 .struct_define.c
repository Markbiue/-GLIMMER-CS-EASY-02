#include <stdio.h>

int main(){
    typedef struct PerInfo{
    char sex;
    double height;
    int age;
    char name[10];
} self_information;

    self_information my = {'M',18.0,18,"jack"};

    printf("%zu",sizeof(self_information));

return 0;
}