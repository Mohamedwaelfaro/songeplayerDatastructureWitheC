#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu(int is_empty, int is_full);

int main()
{
  Queue q;
  init_queue(&q);

  // Example usage
  int choice;
  int Is_empty = is_empty(&q);
  int Is_full = is_full(&q);
  system("cls");
  print_menu(Is_empty, Is_full);
  do
  {

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      system("cls");
      printf("%s", is_empty(&q) ? "==>No songs are in the playlist\n" : "==>There are songs in the playlist\n");
      Is_empty = is_empty(&q);
      Is_full = is_full(&q);
      print_menu(Is_empty, Is_full);
      break;

    case 2:
      system("cls");
      printf("%s", is_full(&q) ? "==>The playlist is full!\n" : "==>There is space left for more songs\n");
      Is_empty = is_empty(&q);
      Is_full = is_full(&q);
      print_menu(Is_empty, Is_full);
      break;

    case 3:
      if (Is_full)
      {
        system("cls");
        print_menu(Is_empty, Is_full);
        break;
      }

      system("cls");
      Song new_song;
      printf("Enter the title of the song: ");
      scanf(" %[^\n]s", &new_song.title);
      printf("Enter the duration of the song in seconds: ");
      scanf("%d", &new_song.duration);

      enqueue(&q, new_song);
      system("cls");

      printf("==>Song '%s' added to the playlist\n\n", new_song.title);
      Is_empty = is_empty(&q);
      Is_full = is_full(&q);
      print_menu(Is_empty, Is_full);

      break;

    case 4:
      if (Is_empty)
      {
        system("cls");
        print_menu(Is_empty, Is_full);
        break;
      }

      system("cls");

      Song song = dequeue(&q);

      printf("\n\n=============================\n");
      printf("Playing song '%s' for %d seconds...\n", song.title, song.duration);
      printf("=============================\n\n");
      Is_empty = is_empty(&q);
      Is_full = is_full(&q);
      print_menu(Is_empty, Is_full);

      break;

    case 5:
      if (Is_empty)
      {
        system("cls");
        print_menu(Is_empty, Is_full);

        break;
      }

      system("cls");

      printf("\n\n=============================\n");
      printf("Current playlist:\n");
      display_queue(&q);
      printf("=============================\n\n");
      Is_empty = is_empty(&q);
      Is_full = is_full(&q);
      print_menu(Is_empty, Is_full);
      break;

    case 6:
      if (is_empty(&q))
      {
        system("cls");
        print_menu(1, is_full(&q));
        printf("==>The playlist is empty!\n");
        break;
      }

      system("cls");
      printf("Enter the title of the song to remove: ");
      char title[50];
      scanf(" %[^\n]s", title);

      int removed = 0;
      Queue temp_q;
      init_queue(&temp_q);
      while (!is_empty(&q))
      {
        Song song = dequeue(&q);
        if (strcmp(song.title, title) == 0)
        {
          printf("==>Song '%s' removed from the playlist\n\n", song.title);
          removed = 1;
        }
        else
        {
          enqueue(&temp_q, song);
        }
      }

      while (!is_empty(&temp_q))
      {
        Song song = dequeue(&temp_q);
        enqueue(&q, song);
      }

      if (!removed)
      {
        printf("==>Song '%s' not found in the playlist\n\n", title);
      }

      Is_empty = is_empty(&q);
      Is_full = is_full(&q);
      print_menu(Is_empty, Is_full);
      break;
    default:
      system("cls");
      Is_empty = is_empty(&q);
      Is_full = is_full(&q);
      printf("Please make sure you have entered (1, 2,%s%s%s%s)\n", Is_full ? "" : " 3", Is_empty ? "" : ", 4", Is_empty ? "" : ", 5", Is_empty ? "" : ", 6");
      print_menu(Is_empty, Is_full);
      break;
    }

  } while (choice != -1);

  return 0;
}

void print_menu(int Is_empty, int Is_full)
{
  printf("Enter '-1' to exit.\n");
  printf("What operation do you want to perform:\n\n");
  printf("%s%s%s%s%s%s", "1-Check if there are no songs in the playlist\n", "2-Check if the playlist is full\n", Is_full ? "" : "3-Add a new song to the playlist\n", Is_empty ? "" : "4-Play the next song in the playlist\n", Is_empty ? "" : "5-Display the current playlist\n", Is_empty ? "" : "6-Remove a song from the playlist\n");
}