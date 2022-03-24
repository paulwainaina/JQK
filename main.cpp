#include <iostream>
void processBet(int bet,int & cash) {
    char game[]{ 'J','K','Q' };
    if (bet > cash) {
       std::cout << "You don't have sufficient funds, Current Balance:" << cash << std::endl;
       return;
    }
    else {
        std::cout << "Quess the Position of Queen" << std::endl;
        int guess;
        std::cin >> guess;
        if (guess >= 1 && guess <= 3) {
            srand(time(NULL));
            int x{ rand() %3},y{rand()%3};
            char temp = game[x];
            game[x] = game[y];
            game[y] = temp;
            cash += (game[guess-1] == 'Q') ? 3 * bet : -bet;            
        }
        else {
            std::cout << "Guess must be 1,2,3" << std::endl;
        }
    }
}

int main(){ 
    int cash{ 1000 };
   
    do { std::cout << "Current Balance "<<cash << std::endl;
        int bet{ 0 };
        std::cout << "Place your bet\n" << std::endl;
        std::cin >> bet;
        processBet(bet,cash);
    } while (cash > 0);
    std::cout << "\nGame is done !!!\n" << std::endl;
    return 0;
}
