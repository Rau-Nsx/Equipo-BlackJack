import java.util.Random;
import java.util.Scanner;
class Main{
    static int player = 0;
    static int dealer = 0;
    static String playerMessage = "Las cartas del jugador son: ";
    static String dealerMessage = "Las cartas del dealer son: ";
    static int[] cards = new int[52];

    public static void crearBaraja() {
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

    public static int drawCard() {
        Random random = new Random();
        int card = random.nextInt(52) + 1;
        return cards[card - 1];
    }

    public static void initGame() {
        int playerCard1 = drawCard();
        int playerCard2 = drawCard();
        player = playerCard1 + playerCard2;
        playerMessage += playerCard1 + " y " + playerCard2;

        int dealerCard1 = drawCard();
        int dealerCard2 = drawCard();
        dealer = dealerCard1 + dealerCard2;
        dealerMessage += dealerCard1 + " y " + dealerCard2;

        System.out.println(playerMessage);
        System.out.println(dealerMessage);
        System.out.println("Puntuación del jugador: " + player);
        System.out.println("Puntuación del dealer: " + dealer);
    }

    // Función que valida el resultado del juego
    public static void validarResultado() {
        if (player == 21) {
            System.out.println("Ganaste, hiciste BLACKJACK!!!");
        } else if (player > dealer && player <= 21) {
            System.out.println("Has ganado :)");
        } else if (player == dealer) {
            System.out.println("Es un empate");
        } else if (player > 21) {
            System.out.println("Tu puntuación es mayor a 21, has perdido :(");
        } else {
            System.out.println("Has perdido :(");
        }
    }

    public static void main(String[] args) {
        crearBaraja();
        initGame();
        validarResultado();
    }
}
