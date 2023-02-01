#include <iostream>
#include <vector>

int matrixDeterminant(int n,int m,std::vector<std::vector<int>>&arr){
    if(n==m){
        if(n==2) return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
        else if(n==3) return arr[0][0]*arr[1][1]*arr[2][2]+arr[0][1]*arr[1][2]*arr[2][0]+arr[1][0]*arr[2][1]*arr[0][2]-arr[2][0]*arr[1][1]*arr[0][2]-arr[0][1]*arr[1][0]*arr[2][2]-arr[2][1]*arr[1][2]*arr[0][0];
        else std::cout<<std::endl<<"Я ще не вмію шукати визначник такої великої матриці.";
    }else std::cout<<std::endl<<"Я ще не вмію шукати визначник не квадратної матриці.";
}
void addNumberToMatrix(int sumNumber,int n,int m,std::vector<std::vector<int>>&arr){
    std::cout<<std::endl<<sumNumber;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            arr[i][j] = arr[i][j] + sumNumber;
    }
    std::cout<<std::endl<<"Відповідь: "<<std::endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout <<arr[i][j] << " ";
        std::cout << std::endl;
    }
}
void multiplyNumberByMatrix(int multiNumber,int n,int m,std::vector<std::vector<int>>&arr){
    std::cout<<std::endl<<multiNumber;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            arr[i][j] = arr[i][j] * multiNumber;
    }
    std::cout<<std::endl<<"Відповідь: "<<std::endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout <<arr[i][j] << " ";
        std::cout << std::endl;
    }

}
void chooseAction(std::string menu,int n,int m,std::vector<std::vector<int>>&arr){
    int action;
    std::cin>>action;
    int multiNumber, sumNumber;
    switch(action){
        case 3:
            std::cout<<std::endl<<"Введіть, яке число потрібно додати до матриці: ";
            std::cin>>sumNumber;
            addNumberToMatrix(sumNumber,n,m,arr);
            std::cout<<menu;
            chooseAction(menu,n, m, arr);
            break;
        case 5:
            std::cout<<std::endl<<"Введіть, яке число потрібно помножити на матрицю: ";
            std::cin>>multiNumber;
            multiplyNumberByMatrix(multiNumber,n,m,arr);
            std::cout<<menu;
            chooseAction(menu,n, m, arr);
            break;
        case 6:
            std::cout<<std::endl<<"Відповідь: "<< matrixDeterminant(n, m, arr);
            std::cout<<menu;
            chooseAction(menu,n,m,arr);
            break;
        case 666:
            std::cout<<std::endl<<"Ваша матриця: "<<std::endl;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++)
                    std::cout << arr[i][j] << " ";
                std::cout << std::endl;
            }
            std::cout<<menu;
            chooseAction(menu,n,m,arr);
            break;
        default:
            std::cout<<std::endl<<"Це не відома для мене команда, спробуй ще."<<std::endl;
            chooseAction(menu,n, m, arr);
    }
}
int main(){
    int n,m;
    std::string element;
    std::string menu = "\nТепер обери дію:\n1. Транспортувати матрицю(недоступно);\n2. Додати матриці(недоступно);\n3. Додати число матриці;\n4. Помножити матриці(недоступно);\n5. Помножити число на матрицю;\n6. Знайти визначник матриці;\n666. Показати матрицю.\n";
    std::cout<<std::endl<<"Введи розмір матриці: ";
    std::cin>>n>>m;
    std::vector<std::vector <int> >arr(n,std::vector<int>(m));
    std::cout<<std::endl<<"Зараз будемо вводити значення в матрицю.";
    for(int i=0;i<n;i++){
        if(m==1) element = "елемент";
        else if(m<=4) element = "елемента";
        else element = "елементів";
        std::cout<<std::endl<<"Введіть "<<m<<" "<<element<<" "<<i+1<<"-го рядка: ";
        for(int j=0;j<m;j++){
            std::cin>>arr[i][j];
        }
    }
    std::cout<<menu;
    chooseAction(menu,n,m,arr);
}
