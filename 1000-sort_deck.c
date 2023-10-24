#include "deck.h"

int strcmp(const char *str1, const char *str2);
char getValue(deck_node_t *car);
void insertionSortDeckKind(deck_node_t **deck);
void insertionSortDeckValue(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * strcmp - Compare two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return:
 * - An integer less than 0 if str1 is less than str2.
 * - 0 if str1 is equal to str2.
 * - An integer greater than 0 if str1 is greater than str2.
 */
int strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * getValue - Assign a numerical value to a card's face value.
 * @car: A pointer to the deck_node_t containing the card information.
 *
 * Return:
 * - An integer representing the numerical value of the card's face value.
 *   0 for "Ace", 1 for "1", 2 for "2", ..., 10 for "10", 11 for "Jack",
 *   12 for "Queen", and 13 for other values.
 */
char getValue(deck_node_t *car)
{
	if (strcmp(car->card->value, "Ace") == 0)
		return (0);
	if (strcmp(car->card->value, "1") == 0)
		return (1);
	if (strcmp(car->card->value, "2") == 0)
		return (2);
	if (strcmp(car->card->value, "3") == 0)
		return (3);
	if (strcmp(car->card->value, "4") == 0)
		return (4);
	if (strcmp(car->card->value, "5") == 0)
		return (5);
	if (strcmp(car->card->value, "6") == 0)
		return (6);
	if (strcmp(car->card->value, "7") == 0)
		return (7);
	if (strcmp(car->card->value, "8") == 0)
		return (8);
	if (strcmp(car->card->value, "9") == 0)
		return (9);
	if (strcmp(car->card->value, "10") == 0)
		return (10);
	if (strcmp(car->card->value, "Jack") == 0)
		return (11);
	if (strcmp(car->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertionSortDeckKind - Sort a deck of cards
 * by their 'kind' using insertion sort.
 * @deck: A pointer to a pointer to the head of
 * the deck (deck_node_t) to be sorted.
 * Return : Nothing.
 */
void insertionSortDeckKind(deck_node_t **deck)
{
	deck_node_t *liter, *ins, *tmp;

	for (liter = (*deck)->next; liter != NULL; liter = tmp)
	{
		tmp = liter->next;
		ins = liter->prev;
		while (ins != NULL && ins->card->kind > liter->card->kind)
		{
			ins->next = liter->next;
			if (liter->next != NULL)
				liter->next->prev = ins;
			liter->prev = ins->prev;
			liter->next = ins;
			if (ins->prev != NULL)
				ins->prev->next = liter;
			else
				*deck = liter;
			ins->prev = liter;
			ins = liter->prev;
		}
	}
}

/**
 * insertionSortDeckValue - Sort a deck of cards by
 * 'kind' and 'value' using insertion sort.
 * @deck: A pointer to a pointer to the head
 * of the deck (deck_node_t) to be sorted.
 * Return : Nothing.
 */
void insertionSortDeckValue(deck_node_t **deck)
{
	deck_node_t *liter, *ins, *tmp;

	for (liter = (*deck)->next; liter != NULL; liter = tmp)
	{
		tmp = liter->next;
		ins = liter->prev;
		while (ins != NULL &&
		       ins->card->kind == liter->card->kind &&
		       getValue(ins) > getValue(liter))
		{
			ins->next = liter->next;
			if (liter->next != NULL)
				liter->next->prev = ins;
			liter->prev = ins->prev;
			liter->next = ins;
			if (ins->prev != NULL)
				ins->prev->next = liter;
			else
				*deck = liter;
			ins->prev = liter;
			ins = liter->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertionSortDeckKind(deck);
	insertionSortDeckValue(deck);
}
