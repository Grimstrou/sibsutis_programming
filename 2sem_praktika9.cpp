#include <iostream>

int main(){
    //задачка на температуру
    /*
    int n[] = {13, 12, 15, 11, 9, 12, 16};
    int k = sizeof(n) / sizeof(n[0]);
    for(int i = 0; i < k - 1; i++){
        int mne_vseravno = 1;
        for(int j = i + 1; j < k; j++){
            if(n[i] > n[j]){
                mne_vseravno += 1;
            }
            else{
                std::cout << mne_vseravno << " ";
                break;
            }
            
        }
    }
    std::cout << "0";
    */

    std::string kashi[] = {"Манная", "Гречневая", "Пшённая", "Овсяная", "Рисовая"};
    int n;
    std::cin >> n;
    int k = sizeof(kashi) / sizeof(kashi[0]);
    int i;
    int i1 = 0;
    for(i = 0; i <n; i++){
        std::cout << kashi[i1] << std::endl; 
        i1 += 1;
        if (i1 >= k)
            i1 = 0;   
    }
    
    return 0;
}