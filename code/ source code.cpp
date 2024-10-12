#include <iostream>
#include <random>
#include <string>

using namespace std;

int player = 0;
int dealer = 0;
string playerMessage = "Las cartas del jugador son: ";
string dealerMessage = "Las cartas del dealer son: ";
int cards[52];

void crearBaraja() {
    int cardValue = 2;
    int cardCount = 0;
    for (int figure = 1; figure <= 4; figure++) {
        for (int card = 1; card <= 13; card++) {
            switch (card) {
                case 10:
                case 11:
                case 12:
                    cardValue = 10;
                    break;
                case 13:
                    cardValue = 11;
                    break;
                default:
                    break;
            }
            cards[cardCount] = cardValue;
            cardCount++;
            cardValue++;
        }
        cardValue = 2;
    }
}

int drawCard(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 52);
    int card = dist(gen);
    return cards[card - 1];
}

void initGame(){
    int playerCard1 = drawCard();
    int playerCard2 = drawCard();
    player = playerCard1 + playerCard2;
    playerMessage += to_string(playerCard1) + " y " + to_string(playerCard2);

    int dealerCard1 = drawCard();
    int dealerCard2 = drawCard();
    dealer = dealerCard1 + dealerCard2;
    dealerMessage += to_string(dealerCard1) + " y " + to_string(dealerCard2);

    cout << playerMessage << endl;
    cout << dealerMessage << endl;
    cout << "Puntuacion del jugador: " << player << endl;
    cout << "Puntuacion del dealer: " << dealer << endl;
}

// Función que valida el resultado del juego
void validarResultado(){
    if (player == 21) {
        cout << "Ganaste, hiciste BLACKJACK!!!" << endl;
    } else if (player > dealer && player <= 21) {
        cout << "Has ganado :)" << endl;
    } else if (player == dealer) {
        cout << "Es un empate" << endl;
    } else if (player > 21) {
        cout << "Tu puntuacion es mayor a 21, has perdido :(" << endl;
    } else {
        cout << "Has perdido :(" << endl;
    }
}

int main(){
    crearBaraja();
    initGame();
    validarResultado();

    return 0;
}
