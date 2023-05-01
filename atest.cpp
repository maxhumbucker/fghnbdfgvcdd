#include <iostream>
#include <exception>
class ExceptionEqual : public std::exception {
    void ee(int x, int y){
        if (x == y){
            std::cout<<"X=Y!!!"<<"\n";
        }
        else{
            std::cout<<"x != Y!!!"<<"\n";
        }
    }
};
class ExceptionLess : public std::exception {
    void el(int x, int y){
        while (x != y){
            x = x + 1;
            std::cout<<x<<"\n";
        }
        ExceptionEqual.ee(x, y);
    }
};
class ExceptionGreater : public std::exception {
    void eg(int x, int y){
        while (x != y){
            x = x - 1;
            std::cout<<x<<"\n";
        }
        ExceptionEqual.ee(x, y);
    }
};
class BlackBox {
public:
 
 void GuessNumber(int x, int y) const{
    int a = 0;
    int b = 0;

    for(int i = 0; i < 30; i++ ){
        a = x;
        std::cout <<"A = "<<a<<"\n";
        if (a > y){
            b = 25;
            x = b;
            std::cout<<"X = "<<x<<"\n";
            if(x < y){
                ExceptionLess.el(x, y);
            }
        }
        else{
            b = 75;
            x = b;
            std::cout<<"X = "<<x<<"\n";
            if(x > y){
               ExceptionGreater.eg(x, y);
            }
        }


    }
 }
};

int guess(const BlackBox& box) {
    int x = 50;
    int y;
    std::cin >> y;
    BlackBox bb;
    bb.GuessNumber(x, y);
    return 0;
}
