#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARDS 5
#define NUM_RANKS 13
#define NUM_SUITS 4

// Define card ranks and suits
const char *ranks = "23456789TJQKA";
const char *suits = "SHDC";

// Structure to represent a card
typedef struct {
    char rank;
    char suit;
} Card;

// Structure to represent a hand
typedef struct {
    Card cards[NUM_CARDS];
} Hand;

// Function to compare cards for sorting
int compare_cards(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

// Function to read a hand from a string
Hand read_hand(const char *str) {
    Hand hand;
    for (int i = 0; i < NUM_CARDS; i++) {
        hand.cards[i].rank = str[i * 3];
        hand.cards[i].suit = str[i * 3 + 1];
    }
    return hand;
}

// Function to evaluate the rank of a hand
int evaluate_hand(Hand hand) {
    // Sort cards in hand
    qsort(hand.cards, NUM_CARDS, sizeof(Card), compare_cards);

    // Check for hand ranks
    int flush = 1;
    int straight = 1;
    int pairs = 0;
    int three_of_a_kind = 0;
    int four_of_a_kind = 0;
    int high_card = 0;

    // Check for flush and straight
    for (int i = 0; i < NUM_CARDS - 1; i++) {
        if (hand.cards[i].suit != hand.cards[i + 1].suit) {
            flush = 0;
        }
        if (hand.cards[i].rank + 1 != hand.cards[i + 1].rank) {
            straight = 0;
        }
    }

    // Check for pairs and three/four of a kind
    for (int i = 0; i < NUM_CARDS - 1; i++) {
        if (hand.cards[i].rank == hand.cards[i + 1].rank) {
            pairs++;
            if (i < NUM_CARDS - 2 && hand.cards[i].rank == hand.cards[i + 2].rank) {
                three_of_a_kind = 1;
                if (i < NUM_CARDS - 3 && hand.cards[i].rank == hand.cards[i + 3].rank) {
                    four_of_a_kind = 1;
                }
            }
        }
    }

    // Evaluate hand rank
    if (flush && straight) {
        return 8; // Straight Flush
    } else if (four_of_a_kind) {
        return 7; // Four of a Kind
    } else if (three_of_a_kind && pairs == 1) {
        return 6; // Full House
    } else if (flush) {
        return 5; // Flush
    } else if (straight) {
        return 4; // Straight
    } else if (three_of_a_kind) {
        return 3; // Three of a Kind
    } else if (pairs == 2) {
        return 2; // Two Pairs
    } else if (pairs == 1) {
        return 1; // One Pair
    } else {
        return 0; // High Card
    }
}

// Function to compare highest cards in two hands
int compare_highest_cards(Hand hand1, Hand hand2) {
    for (int i = NUM_CARDS - 1; i >= 0; i--) {
        if (hand1.cards[i].rank > hand2.cards[i].rank) {
            return 1;
        } else if (hand1.cards[i].rank < hand2.cards[i].rank) {
            return -1;
        }
    }
    return 0;
}

// Function to compare two hands
int compare_hands(const void *a, const void *b) {
    Hand hand1 = *(const Hand *)a;
    Hand hand2 = *(const Hand *)b;

    // Evaluate the ranks of each hand
    int rank_hand1 = evaluate_hand(hand1);
    int rank_hand2 = evaluate_hand(hand2);

    // Compare hand ranks
    if (rank_hand1 > rank_hand2) {
        return 1; // Hand 1 wins
    } else if (rank_hand1 < rank_hand2) {
        return -1; // Hand 2 wins
    } else {
        // If hand ranks are equal, compare the highest cards
        return compare_highest_cards(hand1, hand2);
    }
}

int main() {
    FILE *file = fopen("poker.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int player1_wins = 0;
    char line[30]; // Assuming each line has at most 29 characters
    while (fgets(line, sizeof(line), file)) {
        Hand player1_hand = read_hand(line);
        Hand player2_hand = read_hand(line + 15);
        
        int result = compare_hands(&player1_hand, &player2_hand);
        if (result > 0) {
            player1_wins++;
        }
    }

    fclose(file);

    printf("Player 1 wins: %d hands.\n", player1_wins);

    return 0;
}
