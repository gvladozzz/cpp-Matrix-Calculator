#include <iostream>
#include <vector>


void answer(int n, int m, std::vector<std::vector<int>>&vector){
    std::cout<<std::endl<<"Відповідь: "<<std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << vector[i][j] << " ";
        std::cout << std::endl;
    }
}


int matrixDeterminant(int n,int m,std::vector<std::vector<int>>&vector){
    if(n==m){
        if(n==2) return vector[0][0] * vector[1][1] - vector[0][1] * vector[1][0];
        else if(n==3) return vector[0][0] * vector[1][1] * vector[2][2] + vector[0][1] * vector[1][2] * vector[2][0] + vector[1][0] * vector[2][1] * vector[0][2] - vector[2][0] * vector[1][1] * vector[0][2] - vector[0][1] * vector[1][0] * vector[2][2] - vector[2][1] * vector[1][2] * vector[0][0];
        else std::cout<<std::endl<<"Я ще не вмію шукати визначник такої великої матриці.";
    }else std::cout<<std::endl<<"Я ще не вмію шукати визначник не квадратної матриці.";
    return 0;
}


void addNumberToMatrix(int sumNumber,int n,int m,std::vector<std::vector<int>>&vector){
    std::cout<<std::endl<<sumNumber;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) vector[i][j] = vector[i][j] + sumNumber;
    }
    answer(n, m, vector);
}


void multiplyNumberByMatrix(int multiNumber,int n,int m,std::vector<std::vector<int>>&vector){
    std::cout<<std::endl<<multiNumber;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            vector[i][j] = vector[i][j] * multiNumber;
    }
    std::cout<<std::endl<<"Відповідь: "<<std::endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout <<vector[i][j] << " ";
        std::cout << std::endl;
    }
}


void transposeMatrix(int n,int m,std::vector<std::vector<int>>&vector){
    std::vector<std::vector <int> >transposedArr(n,std::vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            transposedArr[i][j]=vector[j][i];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout << transposedArr[i][j] << " ";
        std::cout << std::endl;
    }
}


void chooseAction(const std::string& menu,int n,int m,std::vector<std::vector<int>>&vector){
    int action;
    std::cin>>action;
    int multiNumber, sumNumber;
    switch(action){
        case 1:
            std::cout<<std::endl<<"Відповідь: ";
            transposeMatrix(n, m, vector);
            std::cout<<menu;
            chooseAction(menu,n,m,vector);
        case 3:
            std::cout<<std::endl<<"Введіть, яке число потрібно додати до матриці: ";
            std::cin>>sumNumber;
            addNumberToMatrix(sumNumber,n,m,vector);
            std::cout<<menu;
            chooseAction(menu,n,m,vector);
            break;
        case 5:
            std::cout<<std::endl<<"Введіть, яке число потрібно помножити на матрицю: ";
            std::cin>>multiNumber;
            multiplyNumberByMatrix(multiNumber,n,m,vector);
            std::cout<<menu;
            chooseAction(menu,n, m, vector);
            break;
        case 6:
            std::cout<<std::endl<<"Відповідь: "<< matrixDeterminant(n, m, vector);
            std::cout<<menu;
            chooseAction(menu,n,m,vector);
            break;
        case 666:
            std::cout<<std::endl<<"Ваша матриця: "<<std::endl;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++)
                    std::cout << vector[i][j] << " ";
                std::cout << std::endl;
            }
            std::cout<<menu;
            chooseAction(menu,n,m,vector);
            break;
        default:
            std::cout<<std::endl<<"Це не відома для мене команда, спробуй ще."<<std::endl;
            chooseAction(menu,n, m, vector);
    }
}


int main(){
    int n,m;
    std::string element;
    const std::string menu = "\nТепер обери дію:\n1. Транспортувати матрицю(недоступно);\n2. Додати матриці(недоступно);\n3. Додати число матриці;\n4. Помножити матриці(недоступно);\n5. Помножити число на матрицю;\n6. Знайти визначник матриці;\n666. Показати матрицю.\n";
    std::cout<<std::endl<<"Введи розмір матриці: ";
    std::cin>>n>>m;
    std::vector<std::vector <int> >vector(n,std::vector<int>(m));
    std::cout<<std::endl<<"Зараз будемо вводити значення в матрицю.";
    for(int i=0;i<n;i++){
        if(m==1) element = "елемент";
        else if(m<=4) element = "елемента";
        else element = "елементів";
        std::cout<<std::endl<<"Введіть "<<m<<" "<<element<<" "<<i+1<<"-го рядка: ";
        for(int j=0;j<m;j++){
            std::cin>>vector[i][j];
        }
    }
    std::cout<<menu;
    chooseAction(menu,n,m,vector);
}
