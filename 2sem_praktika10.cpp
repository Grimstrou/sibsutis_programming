#include <iostream>
#include <cstdlib>

int main(){

    int a[] = {7, 5, 1, 5, 7};
    int A = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < A - 1; i++){
        for(int j = 0; j < A - 1 - i; j++) {
            if(a[j] > a[j+1]){
                int three;
                three = a[j];
                a[j] = a[j+1];
                a[j+1] = three; 
            }
        }
    }
    for(int i = 0; i < A-1; i += 2){
        if(a[i] != a[i+1]){
        //std::cout << a[i] << std::endl;
        break;

            //i индекс 
            //a[i] элемент
        }
    }



    for (int i = 0; i < A; i++) 
    { 
    std::cout << "Жираф ростом " << a[i] << " " << "Остался без пары"; 
    break;
    }


}