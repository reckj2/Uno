#define _CRT_SECURE_NO_WARNINGS // authors: James Hart, Josh Reck

#include <stdio.h> // creates the game uno.

#include <string.h> //

#include <stdlib.h> // hours logged: 46.

#include <math.h> //

#include <time.h> //

#define NA 199 // some arbitrary number to decide if there is no value for the card.

#define FORWARD 1

#define BACKWARD 0

#define FAIL 1

#define PASS 0

#define REVERSE 4 // definitions to help with what to do with the action card.

#define SKIP 5

#define WILD 6

#define PFOUR 7

#define PTWO 8

#define NONE 9







typedef struct card_s { // defines some structure that we have to use.

	char suit[7];

	int value;

	char action[15];

	struct card_s *pt;

} card;



void delay(int number_of_seconds) { // for the dramatic effect

	int milli_seconds = 1000 * number_of_seconds; // Converting time into milli_seconds

	clock_t start_time = clock(); // Stroing start time

	while (clock() < start_time + milli_seconds); // looping till required time is not acheived

}



void deal_player(card **p, card **head1) { //Deals players in

	card *temp = NULL;



	if (*head1 == NULL) {



		*head1 = *p;



		*p = (*p)->pt;



		(*head1)->pt = NULL;



	}



	else {



		temp = *head1;



		while (temp->pt != NULL) {



			temp = temp->pt;



		}



		temp->pt = *p;



		*p = (*p)->pt;



		temp->pt->pt = NULL;



	}



}



void resetting_the_game(card **p, card **head1) {







	card *temp = NULL;







	while (*p != NULL) {



		if (*head1 == NULL) {



			*head1 = *p;



			*p = (*p)->pt;



			(*head1)->pt = NULL;



		}



		else {



			temp = *head1;



			while (temp->pt != NULL) {



				temp = temp->pt;



			}



			temp->pt = *p;



			*p = (*p)->pt;



			temp->pt->pt = NULL;



		}



	}



}



void discard_Pile(card **p, card **head1) { // this will be where we have all the played cards go.



	card *temp = NULL;







	if (*head1 == NULL) {



		*head1 = *p;



		*p = (*p)->pt;



		(*head1)->pt = NULL;



	}



	else {



		temp = *head1;



		while (temp->pt != NULL) {



			temp = temp->pt;



		}



		temp->pt = *p;



		*p = (*p)->pt;



		temp->pt->pt = NULL;



	}



}



int counting_cards(card **p) {



	int counter = 0;



	card *temp = NULL;



	temp = *p;







	while (temp != NULL) {



		counter++;



		temp = temp->pt;



	}











	return counter;



}



void print_discard(card *p) {

	//_______________________________________________________card art_____________________________________________//

	while (p->pt != NULL) {

		p = p->pt;

	}

	if (strcmp(p->suit, "YELLOW") == 0) {



		if (strcmp(p->action, "REVERSE") == 0) { // reverse card

			printf(" ----------------\n");

			printf("|YELLOW          |\n");

			printf("|                |\n");

			printf("|      __        |\n");

			printf("|     |          |\n");

			printf("|     v    ^     |\n");

			printf("|        __|     |\n");

			printf("|                |\n");

			printf("|         REVERSE|\n");

			printf(" ----------------\n");

		}

		else if (strcmp(p->action, "SKIP") == 0) { // skip card

			printf(" ----------------\n");

			printf("|YELLOW          |\n");

			printf("|     ------     |\n");

			printf("|    | \\    |    |\n");

			printf("|    |  \\   |    |\n");

			printf("|    |   \\  |    |\n");

			printf("|    |    \\ |    |\n");

			printf("|     ------     |\n");

			printf("|            SKIP|\n");

			printf(" ----------------\n");

		}

		else if (strcmp(p->action, "PLUS TWO") == 0) {

			printf(" ----------------\n");

			printf("|YELLOW          |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|    PLUS TWO    |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|          YELLOW|\n");

			printf(" ----------------\n");

		}

		else {

			printf(" ----------------\n");

			printf("|YELLOW          |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|       %d        |\n", p->value);

			printf("|                |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|          YELLOW|\n");

			printf(" ----------------\n");

		}

	}

	else if (strcmp(p->suit, "RED") == 0) {

		if (strcmp(p->action, "REVERSE") == 0) { // reverse card

			printf(" ----------------\n");

			printf("|RED             |\n");

			printf("|                |\n");

			printf("|      __        |\n");

			printf("|     |          |\n");

			printf("|     v    ^     |\n");

			printf("|        __|     |\n");

			printf("|                |\n");

			printf("|         REVERSE|\n");

			printf(" ----------------\n");

		}

		else if (strcmp(p->action, "SKIP") == 0) { // skip card

			printf(" ----------------\n");

			printf("|RED             |\n");

			printf("|     ------     |\n");

			printf("|    | \\    |    |\n");

			printf("|    |  \\   |    |\n");

			printf("|    |   \\  |    |\n");

			printf("|    |    \\ |    |\n");

			printf("|     ------     |\n");

			printf("|            SKIP|\n");

			printf(" ----------------\n");

		}

		else if (strcmp(p->action, "PLUS TWO") == 0) {

			printf(" ----------------\n");

			printf("|RED             |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|    PLUS TWO    |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|             RED|\n");

			printf(" ----------------\n");

		}

		else {

			printf(" ----------------\n");

			printf("|RED             |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|       %d        |\n", p->value);

			printf("|                |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|             RED|\n");

			printf(" ----------------\n");

		}

	}

	else if (strcmp(p->suit, "GREEN") == 0) {

		if (strcmp(p->action, "REVERSE") == 0) { // reverse card

			printf(" ----------------\n");

			printf("|GREEN           |\n");

			printf("|                |\n");

			printf("|      __        |\n");

			printf("|     |          |\n");

			printf("|     v    ^     |\n");

			printf("|        __|     |\n");

			printf("|                |\n");

			printf("|         REVERSE|\n");

			printf(" ----------------\n");

		}

		else if (strcmp(p->action, "SKIP") == 0) { // skip card

			printf(" ----------------\n");

			printf("|GREEN           |\n");

			printf("|     ------     |\n");

			printf("|    | \\    |    |\n");

			printf("|    |  \\   |    |\n");

			printf("|    |   \\  |    |\n");

			printf("|    |    \\ |    |\n");

			printf("|     ------     |\n");

			printf("|            SKIP|\n");

			printf(" ----------------\n");

		}

		else if (strcmp(p->action, "PLUS TWO") == 0) {

			printf(" ----------------\n");

			printf("|GREEN           |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|    PLUS TWO    |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|           GREEN|\n");

			printf(" ----------------\n");

		}

		else {

			printf(" ----------------\n");

			printf("|GREEN           |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|       %d        |\n", p->value);

			printf("|                |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|           GREEN|\n");

			printf(" ----------------\n");

		}

	}

	else if (strcmp(p->suit, "BLUE") == 0) {

		if (strcmp(p->action, "REVERSE") == 0) { // reverse card

			printf(" ----------------\n");

			printf("|BLUE            |\n");

			printf("|                |\n");

			printf("|      __        |\n");

			printf("|     |          |\n");

			printf("|     v    ^     |\n");

			printf("|        __|     |\n");

			printf("|                |\n");

			printf("|         REVERSE|\n");

			printf(" ----------------\n");

		}

		else if (strcmp(p->action, "SKIP") == 0) { // skip card

			printf(" ----------------\n");

			printf("|BLUE            |\n");

			printf("|     ------     |\n");

			printf("|    | \\    |    |\n");

			printf("|    |  \\   |    |\n");

			printf("|    |   \\  |    |\n");

			printf("|    |    \\ |    |\n");

			printf("|     ------     |\n");

			printf("|            SKIP|\n");

			printf(" ----------------\n");

		}

		else if (strcmp(p->action, "PLUS TWO") == 0) {

			printf(" ----------------\n");

			printf("|BLUE            |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|    PLUS TWO    |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|            BLUE|\n");

			printf(" ----------------\n");

		}

		else {

			printf(" ----------------\n");

			printf("|BLUE            |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|       %d        |\n", p->value);

			printf("|                |\n");

			printf("|                |\n");

			printf("|                |\n");

			printf("|            BLUE|\n");

			printf(" ----------------\n");

		}

	}

	else if (strcmp(p->action, "WILD") == 0) {

		printf(" ----------------\n");

		printf("|WILD            |\n");

		printf("|     -------    |\n");

		printf("|    |   |   |   |\n");

		printf("|    |___|___|   |\n");

		printf("|    |   |   |   |\n");

		printf("|    |   |   |   |\n");

		printf("|     -------    |\n");

		printf("|            WILD|\n");

		printf(" ----------------\n");

	}

	else if (strcmp(p->action, "PLUS FOUR") == 0) {

		printf(" ----------------\n");

		printf("|PLUS FOUR       |\n");

		printf("|     -------    |\n");

		printf("|    |   |   |   |\n");

		printf("|    |___|___|   |\n");

		printf("|    |   |   |   |\n");

		printf("|    |   |   |   |\n");

		printf("|     -------    |\n");

		printf("|       PLUS FOUR|\n");

		printf(" ----------------\n");

	}

	//___________________________________________________end card art____________________________________//



	//while (p->pt != NULL) {

	//            p = p->pt;

	//}

	//if (strcmp(p->suit, "None") != 0) {

	//            printf("%s ", p->suit);

	//}

	//if (p->value != NA) {

	//            printf("- %d", p->value);

	//}

	//if (strcmp(p->action, "None") != 0) {

	//            printf("%s", p->action);

	//}

	//printf("\n");

}



int win_checker(card *p) { // this will check for wins by checking if the hands of the players are empty



	if (p == NULL) {



		return 1;



	}



	else {



		return 0;



	}



}



char whatever(card **p) {

	card *temp = NULL;

	temp = *p;

	char cshort;

	while (temp->pt != NULL) {

		temp = temp->pt;

	}



	if (strcmp(temp->suit, "BLUE") == 0) {

		cshort = 'b';

	}

	if (strcmp(temp->suit, "GREEN") == 0) {

		cshort = 'g';

	}

	if (strcmp(temp->suit, "RED") == 0) {

		cshort = 'r';

	}

	if (strcmp(temp->suit, "YELLOW") == 0) {

		cshort = 'y';

	}



	return cshort;

}



int playable_card(card **p, int x, card **disc, char c) { // this will check to see if the card is able to be played. (work in progress)



	int i = 0;

	card *temp1 = NULL, *temp2 = NULL;

	char color[10];



	temp1 = *p;

	temp2 = *disc;



	for (i = 1; i < x; i++) {

		temp1 = temp1->pt;

	}

	while (temp2->pt != NULL) {

		temp2 = temp2->pt;

	}



	if (c == 'b') {

		strcpy(color, "BLUE");

	}

	if (c == 'g') {

		strcpy(color, "GREEN");

	}

	if (c == 'r') {

		strcpy(color, "RED");

	}

	if (c == 'y') {

		strcpy(color, "YELLOW");

	}





	if (strcmp(temp1->suit, color) == 0 || strcmp(temp1->suit, temp2->suit) == 0 || strcmp(temp1->action, "WILD") == 0 || strcmp(temp1->action, "PLUS FOUR") == 0 || strcmp(temp2->action, "WILD") == 0 || strcmp(temp2->action, "PLUS FOUR") == 0 || temp1->value == temp2->value || strcmp(temp1->action, temp2->action) == 0) {

		if (strcmp(temp1->action, "None") != 0 || strcmp(temp1->suit, temp2->suit) == 0 || strcmp(temp1->action, "WILD") == 0 || strcmp(temp1->action, "PLUS FOUR") == 0 || strcmp(temp2->action, "WILD") == 0 || strcmp(temp2->action, "PLUS FOUR") == 0 || temp1->value == temp2->value) {

			if (strcmp(temp1->suit, "None") != 0) {

				strcpy(color, temp1->suit);

			}

			return PASS;

		}

	}

	return FAIL;



}



void draw_cards(card **p, card **head1) { // puts a card into the player's hands.



	card *temp = NULL;



	temp = *head1;



	while (temp->pt != NULL) {



		temp = temp->pt;



	}



	temp->pt = *p;



	*p = (*p)->pt;



	temp->pt->pt = NULL;



}



int action_stat(card **p, int x) { // if an action card is played, this will do whatever needs to be done.

	card *temp = NULL;

	temp = *p;

	for (int i = 1; i < x; i++) {

		temp = temp->pt;

	}



	if (strcmp(temp->action, "None") == 0) {

		return NONE;

	}

	if (strcmp(temp->action, "SKIP") == 0) {

		return SKIP;

	}

	if (strcmp(temp->action, "WILD") == 0) {

		return WILD;

	}

	if (strcmp(temp->action, "REVERSE") == 0) {

		return REVERSE;

	}

	if (strcmp(temp->action, "PLUS FOUR") == 0) {

		return PFOUR;

	}

	if (strcmp(temp->action, "PLUS TWO") == 0) {

		return PTWO;

	}



}



void reset_deck(card **head1, card **p, int disCount) {

	card *temp = NULL;



	while ((*p)->pt != NULL) {



		if (*head1 == NULL) {

			*head1 = *p;

			*p = (*p)->pt;

			(*head1)->pt = NULL;

		}

		else {

			temp = *head1;

			while (temp->pt != NULL) {

				temp = temp->pt;

			}

			temp->pt = *p;

			*p = (*p)->pt;

			temp->pt->pt = NULL;

		}

	}

}



void print_hand(card *p) { // this will print the players hand.



	while (p != NULL) {



		//________________________________________________________________card art__________________________________________________//          

		if (strcmp(p->suit, "YELLOW") == 0) {



			if (strcmp(p->action, "REVERSE") == 0) { // reverse card

				printf(" ----------------\n");

				printf("|YELLOW          |\n");

				printf("|                |\n");

				printf("|      __        |\n");

				printf("|     |          |\n");

				printf("|     v    ^     |\n");

				printf("|        __|     |\n");

				printf("|                |\n");

				printf("|         REVERSE|\n");

				printf(" ----------------\n");

			}

			else if (strcmp(p->action, "SKIP") == 0) { // skip card

				printf(" ----------------\n");

				printf("|YELLOW          |\n");

				printf("|     ------     |\n");

				printf("|    | \\    |    |\n");

				printf("|    |  \\   |    |\n");

				printf("|    |   \\  |    |\n");

				printf("|    |    \\ |    |\n");

				printf("|     ------     |\n");

				printf("|            SKIP|\n");

				printf(" ----------------\n");

			}

			else if (strcmp(p->action, "PLUS TWO") == 0) {

				printf(" ----------------\n");

				printf("|YELLOW          |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|    PLUS TWO    |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|          YELLOW|\n");

				printf(" ----------------\n");

			}

			else {

				printf(" ----------------\n");

				printf("|YELLOW          |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|       %d        |\n", p->value);

				printf("|                |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|          YELLOW|\n");

				printf(" ----------------\n");

			}

		}

		else if (strcmp(p->suit, "RED") == 0) {

			if (strcmp(p->action, "REVERSE") == 0) { // reverse card

				printf(" ----------------\n");

				printf("|RED             |\n");

				printf("|                |\n");

				printf("|      __        |\n");

				printf("|     |          |\n");

				printf("|     v    ^     |\n");

				printf("|        __|     |\n");

				printf("|                |\n");

				printf("|         REVERSE|\n");

				printf(" ----------------\n");

			}

			else if (strcmp(p->action, "SKIP") == 0) { // skip card

				printf(" ----------------\n");

				printf("|RED             |\n");

				printf("|     ------     |\n");

				printf("|    | \\    |    |\n");

				printf("|    |  \\   |    |\n");

				printf("|    |   \\  |    |\n");

				printf("|    |    \\ |    |\n");

				printf("|     ------     |\n");

				printf("|            SKIP|\n");

				printf(" ----------------\n");

			}

			else if (strcmp(p->action, "PLUS TWO") == 0) {

				printf(" ----------------\n");

				printf("|RED             |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|    PLUS TWO    |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|             RED|\n");

				printf(" ----------------\n");

			}

			else {

				printf(" ----------------\n");

				printf("|RED             |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|       %d        |\n", p->value);

				printf("|                |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|             RED|\n");

				printf(" ----------------\n");

			}

		}

		else if (strcmp(p->suit, "GREEN") == 0) {

			if (strcmp(p->action, "REVERSE") == 0) { // reverse card

				printf(" ----------------\n");

				printf("|GREEN           |\n");

				printf("|                |\n");

				printf("|      __        |\n");

				printf("|     |          |\n");

				printf("|     v    ^     |\n");

				printf("|        __|     |\n");

				printf("|                |\n");

				printf("|         REVERSE|\n");

				printf(" ----------------\n");

			}

			else if (strcmp(p->action, "SKIP") == 0) { // skip card

				printf(" ----------------\n");

				printf("|GREEN           |\n");

				printf("|     ------     |\n");

				printf("|    | \\    |    |\n");

				printf("|    |  \\   |    |\n");

				printf("|    |   \\  |    |\n");

				printf("|    |    \\ |    |\n");

				printf("|     ------     |\n");

				printf("|            SKIP|\n");

				printf(" ----------------\n");

			}

			else if (strcmp(p->action, "PLUS TWO") == 0) {

				printf(" ----------------\n");

				printf("|GREEN           |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|    PLUS TWO    |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|           GREEN|\n");

				printf(" ----------------\n");

			}

			else {

				printf(" ----------------\n");

				printf("|GREEN           |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|       %d        |\n", p->value);

				printf("|                |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|           GREEN|\n");

				printf(" ----------------\n");

			}

		}

		else if (strcmp(p->suit, "BLUE") == 0) {

			if (strcmp(p->action, "REVERSE") == 0) { // reverse card

				printf(" ----------------\n");

				printf("|BLUE            |\n");

				printf("|                |\n");

				printf("|      __        |\n");

				printf("|     |          |\n");

				printf("|     v    ^     |\n");

				printf("|        __|     |\n");

				printf("|                |\n");

				printf("|         REVERSE|\n");

				printf(" ----------------\n");

			}

			else if (strcmp(p->action, "SKIP") == 0) { // skip card

				printf(" ----------------\n");

				printf("|BLUE            |\n");

				printf("|     ------     |\n");

				printf("|    | \\    |    |\n");

				printf("|    |  \\   |    |\n");

				printf("|    |   \\  |    |\n");

				printf("|    |    \\ |    |\n");

				printf("|     ------     |\n");

				printf("|            SKIP|\n");

				printf(" ----------------\n");

			}

			else if (strcmp(p->action, "PLUS TWO") == 0) {

				printf(" ----------------\n");

				printf("|BLUE            |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|    PLUS TWO    |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|            BLUE|\n");

				printf(" ----------------\n");

			}

			else {

				printf(" ----------------\n");

				printf("|BLUE            |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|       %d        |\n", p->value);

				printf("|                |\n");

				printf("|                |\n");

				printf("|                |\n");

				printf("|            BLUE|\n");

				printf(" ----------------\n");

			}

		}

		else if (strcmp(p->action, "WILD") == 0) {

			printf(" ----------------\n");

			printf("|WILD            |\n");

			printf("|     -------    |\n");

			printf("|    |   |   |   |\n");

			printf("|    |___|___|   |\n");

			printf("|    |   |   |   |\n");

			printf("|    |   |   |   |\n");

			printf("|     -------    |\n");

			printf("|            WILD|\n");

			printf(" ----------------\n");

		}

		else if (strcmp(p->action, "PLUS FOUR") == 0) {

			printf(" ----------------\n");

			printf("|PLUS FOUR       |\n");

			printf("|     -------    |\n");

			printf("|    |   |   |   |\n");

			printf("|    |___|___|   |\n");

			printf("|    |   |   |   |\n");

			printf("|    |   |   |   |\n");

			printf("|     -------    |\n");

			printf("|       PLUS FOUR|\n");

			printf(" ----------------\n");

		}

		p = p->pt;

	}

	//_______________________________________________________________________________end card art_______________________________________________________//

	/*while (p != NULL) {



	if (strcmp(p->suit, "None") != 0) {

	printf("%s ", p->suit);

	}



	if (p->value != NA) {

	printf("- %d", p->value);

	}



	if (strcmp(p->action, "None") != 0) {

	printf("%s", p->action);

	}

	p = p->pt;

	if (p != NULL) {

	printf(", ");

	}



	}*/

}



void print_deck(card *head) { // prints the deck out. (won't need for the final code)



	while (head != NULL) {



		if (strcmp(head->suit, "None") != 0) {



			printf("%s ", head->suit);



		}



		if (head->value != NA) {



			printf("- %d", head->value);



		}



		if (strcmp(head->action, "None") != 0) {



			printf("%s", head->action);



		}



		head = head->pt;



		printf("\n");



	}



}



int rand_gen(int count) { // RNG



	double frac;



	frac = (double)rand() / ((double)RAND_MAX + 1);



	return floor(count * frac); // random number in [0, 108]



}



void shuffle(card *p, int i, int j) { // Shuffle function



	int x, y, temp;



	char temp4[15];







	card *temp1 = NULL, *temp2 = NULL, *head = NULL;



	head = p;







	for (x = 0; x < i; ++x) {



		p = p->pt;



	}







	temp1 = p;



	p = head;







	for (y = 0; y < j; ++y) {



		p = p->pt;



	}







	temp2 = p; // switching the values of the cards.



	temp = temp1->value;



	temp1->value = temp2->value;



	temp2->value = temp;







	strcpy(temp4, temp1->suit); // switches the suits around



	strcpy(temp1->suit, temp2->suit);



	strcpy(temp2->suit, temp4);



	strcpy(temp4, temp1->action); // switches the actions around.



	strcpy(temp1->action, temp2->action);



	strcpy(temp2->action, temp4);







}



void move_player_card(card **p, card **head1, int x) {

	card *temp1 = NULL, *temp2 = NULL, *temp3 = NULL;



	temp1 = *p;

	temp2 = *p;

	temp3 = *head1;



	for (int j = 1; j < x; j++) {

		temp1 = temp1->pt;

	}

	for (int j = 1; j < (x - 1); j++) {

		temp2 = temp2->pt;

	}

	while (temp3->pt != NULL) {

		temp3 = temp3->pt;

	}

	temp3->pt = temp1;

	temp2->pt = temp1->pt;

	temp1->pt = NULL;

}



int main(void) {



	struct card_s n;

	card *head = NULL; // head for the deck

	card *temp = NULL; // temp for the deck

	card *tail = NULL; // tail for the deck

	card **userplayer[10] = { NULL };

	card *discard = NULL;

	int i = 0;

	FILE *deck; // the file that will load in a pre-shuffled deck.

	char userChar = 'y'; // asking if they want to use a stacked deck.

	int numPlayers = 0; // number of players there will be in the game.

	srand((int)time(NULL)); // generates a seed for the random numbers.



	printf("Welecome to uno.\n");

	while (userChar == 'y' || userChar == 'Y') {



		//___________________________________________________________game initialization_________________________________________________________________//



		printf("How many players are there? ");

		scanf("%d", &numPlayers);



		while (numPlayers == 0 || numPlayers > 10) {



			if (numPlayers <= 0) {

				printf("Please enter a real number of players ");

				scanf("%d", &numPlayers);

			}

			if (numPlayers > 10) {

				printf("A maximum of 10 players is allowed. Please re-enter the number of players ");

				scanf("%d", &numPlayers);

			}

		}

		printf("Would you like to use your own deck? ");

		scanf(" %c", &userChar);



		if (userChar != 'y' && userChar != 'Y') { // doesnt make a deck or shuffle it if the user wants to use their own deck.

												  //____________________________________________________________deck_creator_5000________________________________________________________________//

			temp = (card*)malloc(sizeof(card));

			for (int i = 1; i <= 9; i++) {



				for (int j = 0; j < 4; j++) {



					if (j == 0) {



						strcpy(temp->suit, "RED");

					}



					if (j == 1) {



						strcpy(temp->suit, "YELLOW");



					}



					if (j == 2) {



						strcpy(temp->suit, "GREEN");



					}



					if (j == 3) {



						strcpy(temp->suit, "BLUE");



					}







					temp->value = i;



					strcpy(temp->action, "None");







					if (head == NULL) {



						head = temp;



					}







					else {



						tail->pt = temp;



					}







					tail = temp;



					tail->pt = NULL;







					temp = (card*)malloc(sizeof(card));



				}







			}



			for (int i = 0; i <= 9; i++) {



				for (int j = 0; j < 4; j++) {



					if (j == 0) {



						strcpy(temp->suit, "RED");



					}



					if (j == 1) {



						strcpy(temp->suit, "YELLOW");



					}



					if (j == 2) {



						strcpy(temp->suit, "GREEN");



					}



					if (j == 3) {



						strcpy(temp->suit, "BLUE");



					}







					temp->value = i;



					strcpy(temp->action, "None");







					if (head == NULL) {



						head = temp;



					}







					else {



						tail->pt = temp;



					}







					tail = temp;



					tail->pt = NULL;







					temp = (card*)malloc(sizeof(card));



				}







			}



			for (int i = 0; i < 3; i++) {



				for (int j = 0; j < 4; j++) {



					if (j == 0) {



						strcpy(temp->suit, "RED");



					}



					if (j == 1) {



						strcpy(temp->suit, "YELLOW");



					}



					if (j == 2) {



						strcpy(temp->suit, "GREEN");



					}



					if (j == 3) {



						strcpy(temp->suit, "BLUE");



					}



					temp->value = NA;







					if (i == 0) {



						strcpy(temp->action, "SKIP");



					}



					if (i == 1) {



						strcpy(temp->action, "REVERSE");



					}



					if (i == 2) {



						strcpy(temp->action, "PLUS TWO");



					}







					if (head == NULL) {



						head = temp;



					}



					else {



						tail->pt = temp;



					}



					tail = temp;



					tail->pt = NULL;



					temp = (card*)malloc(sizeof(card));



				}



			}



			for (int i = 0; i < 3; i++) {



				for (int j = 0; j < 4; j++) {



					if (j == 0) {



						strcpy(temp->suit, "RED");



					}



					if (j == 1) {



						strcpy(temp->suit, "YELLOW");



					}



					if (j == 2) {



						strcpy(temp->suit, "GREEN");



					}



					if (j == 3) {



						strcpy(temp->suit, "BLUE");



					}



					temp->value = NA;







					if (i == 0) {



						strcpy(temp->action, "SKIP");







					}



					if (i == 1) {



						strcpy(temp->action, "REVERSE");



					}



					if (i == 2) {



						strcpy(temp->action, "PLUS TWO");



					}







					if (head == NULL) {



						head = temp;



					}



					else {



						tail->pt = temp;



					}



					tail = temp;



					tail->pt = NULL;



					temp = (card*)malloc(sizeof(card));



				}



			}



			for (int i = 0; i < 4; i++) {



				for (int j = 0; j < 2; j++) {



					if (j == 0) {



						strcpy(temp->action, "WILD");



					}



					if (j == 1) {



						strcpy(temp->action, "PLUS FOUR");



					}



					strcpy(temp->suit, "None");



					temp->value = NA;







					if (head == NULL) {



						head = temp;



					}



					else {



						tail->pt = temp;



					}



					tail = temp;



					tail->pt = NULL;



					temp = (card*)malloc(sizeof(card));



				}



			}



			//______________________________________________________________END DECK CREATION______________________________________________________________//



			//___________________________________________________________DRAMATIC EFFECT/Shuffle __________________________________________________________//



			printf("Please wait while we shuffle the deck");

			delay(1);

			for (int i = 0; i < 250; i++) {

				shuffle(head, rand_gen(108), rand_gen(108));

			}

			printf(" . ");

			delay(1);

			for (int i = 0; i < 250; i++) {



				shuffle(head, rand_gen(108), rand_gen(108));



			}

			printf(" . ");

			delay(1);

			for (int i = 0; i < 250; i++) {



				shuffle(head, rand_gen(108), rand_gen(108));



			}

			printf(" . \n");

			delay(1);

			for (int i = 0; i < 250; i++) {



				shuffle(head, rand_gen(108), rand_gen(108));



			}



			//______________________________________________________________END OF DRAMATIC EFFEECT________________________________________________________//



		}







		//____________________________________________________________Deck From a file___________________________________________________________________//







		else { // if they are using their own deck.

			int fval = 0;

			char fsuit[100];

			char faction[100];

			deck = fopen("deck.txt", "r");

			if (deck == NULL) { // insert deck file here

				printf("This file doesn't exist. Try again.\n");

				return 0;

			}

			else {

				while (fscanf(deck, "%s %d %s", fsuit, &fval, faction) != EOF) {

					temp = (card*)malloc(sizeof(card));

					strcpy(temp->suit, fsuit);

					temp->value = fval;

					if (strcmp(faction, "+2") == 0) {

						strcpy(temp->action, "PLUS TWO");

					}

					else if (strcmp(faction, "+4") == 0) {

						strcpy(temp->action, "PLUS FOUR");

					}

					else {

						strcpy(temp->action, faction);

					}

					if (head == NULL) {

						head = temp;

					}

					else {

						tail->pt = temp;

					}

					tail = temp;

					tail->pt = NULL;

				}

			}

			fclose(deck); // closing the deck file.

		}



		//____________________________________________________________End deck from a file______________________________________________________________//







		//___________________________________________________________End game initialization____________________________________________________________//







		// print_deck(head); // Prints out the deck             !!!!REMOVE!!!!







		//____________________________________________________________The meat of the game_____________________________________________________________//



		printf("\nLet's start the game.\nDecide who is going to be player 1.\n\n");







		for (int i = 0; i < 7; i++) {



			for (int i = 0; i < numPlayers; i++) {



				deal_player(&head, &userplayer[i]);



			}



		}







		discard_Pile(&head, &discard);

		i = 0;

		int order = FORWARD;

		int numCardsInHand;

		int userInp;

		int unused;

		int playable;

		int deckNum = 0;

		int action;

		int disCount = 0;

		char color[100] = "Whatever";

		char cshort;

		cshort = whatever(&discard);



		while (win_checker(*userplayer[i]) == 0) { // checks to see if a player has won the game. and loops around the meat of the game.

			unused = i;

			playable = FAIL;



			printf("Discard Pile: \n");

			print_discard(discard); // prints out the discard pile.

			printf("\n");

			printf("Player %d's hand: \n", i + 1);

			print_hand(userplayer[i]); // prints out the player's hand.

			printf("\n");

			numCardsInHand = counting_cards(&userplayer[i]); // counts the number of cards in a player's hand.

			printf("\n");



			if (numCardsInHand == 0) {

				break;

			}

			else if (numCardsInHand == 1) {

				printf("Player %d has UNO! \n", i + 1);

				printf("Press 1 to play the card from your hand, or press zero to draw from the deck: ");

			}

			else {

				printf("Press 1-%d to play any card from your hand, or press zero to draw from the deck: ", numCardsInHand);

			}

			scanf("%d", &userInp);



			if (userInp == 0) { // if they want to draw a card.

				draw_cards(&head, &userplayer[i]);

				print_hand(userplayer[i]);

				printf("\n");

				numCardsInHand = counting_cards(&userplayer[i]);

				printf("Press 1 - %d to play any card from your hand, or press zero to end your turn: ", numCardsInHand);

				scanf("%d", &userInp);

			}



			if (userInp != 0) { // if they want to play a card from their hand.

				playable = FAIL;

				while (playable == FAIL) {



					playable = playable_card(&userplayer[i], userInp, &discard, cshort);



					printf("\n");



					if (playable == FAIL) {

						printf("That card is not playable, please pick another card: ");

						scanf("%d", &userInp);

					}



					else {

						action = action_stat(&userplayer[i], userInp);

						move_player_card(&userplayer[unused], &discard, userInp);



						if (win_checker(*userplayer[unused]) == 1) {

							break;

						}

						if (action == REVERSE) {

							if (order == FORWARD) {

								order = BACKWARD;

							}

							else if (order == BACKWARD) {

								order = FORWARD;

							}

						}

						else if (action == PTWO) {

							for (int j = 0; j < 2; j++) {

								if (head == NULL) {

									disCount = counting_cards(&discard);

									reset_deck(&head, &discard, disCount); // if the deck becomes empty during the action.

									disCount = disCount - 1;

									//___________________________________________________________DRAMATIC EFFECT/ in game Shuffle __________________________________________________________//

									printf("Please wait while we shuffle the deck");

									delay(1);

									for (int i = 0; i < 250; i++) {

										shuffle(head, rand_gen(disCount), rand_gen(disCount));

									}

									printf(" . ");

									delay(1);

									for (int i = 0; i < 250; i++) {

										shuffle(head, rand_gen(disCount), rand_gen(disCount));

									}

									printf(" . ");

									delay(1);

									for (int i = 0; i < 250; i++) {

										shuffle(head, rand_gen(disCount), rand_gen(disCount));

									}

									printf(" . \n");

									delay(1);

									for (int i = 0; i < 250; i++) {

										shuffle(head, rand_gen(disCount), rand_gen(disCount));

									}

									//______________________________________________________________END OF DRAMATIC EFFEECT________________________________________________________//

								}

								if (order == FORWARD) {

									if (i == (numPlayers - 1)) {

										draw_cards(&head, &userplayer[0]);

									}

									else {

										draw_cards(&head, &userplayer[i + 1]);

									}

								}

								else if (order == BACKWARD) {

									if (i == 0) {

										draw_cards(&head, &userplayer[(numPlayers - 1)]);

									}

									else {

										draw_cards(&head, &userplayer[i - 1]);

									}

								}

							}

							if (order == FORWARD) { // decides who goes next based on a game status.

								i++;

								if (i >= numPlayers) {

									i = 0;

								}

							}



							else if (order == BACKWARD) { // decides who goes next based on a game status.

								i--;

								if (i < 0) {

									i = (numPlayers - 1);

								}

							}

						}

						else if (action == PFOUR) {

							for (int j = 0; j < 4; j++) {

								if (head == NULL) {

									disCount = counting_cards(&discard);

									reset_deck(&head, &discard, disCount); // if the deck becomes empty during the action.

									disCount = disCount - 1;

									//___________________________________________________________DRAMATIC EFFECT/ in game Shuffle __________________________________________________________//

									printf("Please wait while we shuffle the deck");

									delay(1);

									for (int i = 0; i < 250; i++) {

										shuffle(head, rand_gen(disCount), rand_gen(disCount));

									}

									printf(" . ");

									delay(1);

									for (int i = 0; i < 250; i++) {

										shuffle(head, rand_gen(disCount), rand_gen(disCount));

									}

									printf(" . ");

									delay(1);

									for (int i = 0; i < 250; i++) {

										shuffle(head, rand_gen(disCount), rand_gen(disCount));

									}

									printf(" . \n");

									delay(1);

									for (int i = 0; i < 250; i++) {

										shuffle(head, rand_gen(disCount), rand_gen(disCount));

									}

									//______________________________________________________________END OF DRAMATIC EFFEECT________________________________________________________//

								}

								if (order == FORWARD) {

									if (i == (numPlayers - 1)) {

										draw_cards(&head, &userplayer[0]);

									}

									else {

										draw_cards(&head, &userplayer[i + 1]);

									}

								}

								else if (order == BACKWARD) {

									if (i == 0) {

										draw_cards(&head, &userplayer[(numPlayers - 1)]);

									}

									else {

										draw_cards(&head, &userplayer[i - 1]);

									}

								}

							}

							printf("What color would you like it to be? (b/y/g/r) ");

							scanf(" %c", &cshort);

							if (order == FORWARD) { // decides who goes next based on a game status.

								i++;

								if (i >= numPlayers) {

									i = 0;

								}

							}



							else if (order == BACKWARD) { // decides who goes next based on a game status.

								i--;

								if (i < 0) {

									i = (numPlayers - 1);

								}

							}

						}

						else if (action == WILD) {

							printf("What color would you like it to be? (b/y/g/r) ");

							scanf(" %c", &cshort);

						}

						else if (action == SKIP) {

							if (order == BACKWARD) {

								if (i != 0) {

									--i;

								}

								else {

									i = numPlayers - 1;

								}

							}

							else {

								if (i != (numPlayers - 1)) {

									++i;

								}

								else {

									i = 0;

								}

							}

						}

					}

				}

				if (win_checker(*userplayer[unused]) == 1) {

					break;

				}

			}



			if (order == FORWARD) { // decides who goes next based on a game status.

				i++;

				if (i >= numPlayers) {

					i = 0;

				}

			}

			else if (order == BACKWARD) { // decides who goes next based on a game status.

				i--;

				if (i < 0) {

					i = (numPlayers - 1);

				}

			}

			if (head == NULL) { // if the deck is empty, move all of the discarded cards minus the top, to the deck and shuffle them.

				disCount = counting_cards(&discard);

				reset_deck(&head, &discard, disCount);



				//___________________________________________________________DRAMATIC EFFECT/ in game Shuffle __________________________________________________________//



				printf("Please wait while we shuffle the deck");

				delay(1);

				for (int i = 0; i < 250; i++) {



					shuffle(head, rand_gen(disCount - 1), rand_gen(disCount - 1));



				}

				printf(" . ");

				delay(1);

				for (int i = 0; i < 250; i++) {

					shuffle(head, rand_gen(disCount - 1), rand_gen(disCount - 1));

				}

				printf(" . ");

				delay(1);

				for (int i = 0; i < 250; i++) {

					shuffle(head, rand_gen(disCount - 1), rand_gen(disCount - 1));

				}

				printf(" . \n");

				delay(1);

				for (int i = 0; i < 250; i++) {

					shuffle(head, rand_gen(disCount - 1), rand_gen(disCount - 1));

				}

				//______________________________________________________________END OF DRAMATIC EFFEECT________________________________________________________//



			}

		}



		//____________________________________________________________end of the meat__________________________________________________________________//



		printf("PLAYER %d WINS!\n", (i + 1));

		printf("Thank you for playing.\n");

		printf("Would you like to play again? ");

		scanf(" %c", &userChar);

		printf("\n");



		for (int k = 0; k < numPlayers; k++) {

			resetting_the_game(&userplayer[k], &discard);

		}

		resetting_the_game(&discard, &head);

	}

	free(temp);

	return 0;

}