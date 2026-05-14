#include<stdio.h>
#include<time.h>

void menu();
int timer();
int printAsciiNumbers();
void InputTime();

int main(){
  int MenuOption;
  menu();
  printf("Input menu: ");
  scanf("%d", &MenuOption);
  switch(MenuOption){
    case 1:
      int SessionMinutes, BreakMinutes, Sessions;
      InputTime(&Sessions, &SessionMinutes, &BreakMinutes);
      printf("%d \n %d \n %d", Sessions, SessionMinutes, BreakMinutes);
  }
  return 0;
}

void InputTime(int *Sessions, int *SessionMinutes, int *BreakMinutes){
  printf("Input Amount of Sessions: ");
  scanf("%d", Sessions);
  
  printf("Input Minutes per Session: ");
  scanf("%d", SessionMinutes);
  if(*SessionMinutes > 50){
    printf(" Each session has to be below 50 minutes");
  }

  printf("Input Minutes per Break: ");
  scanf("%d", BreakMinutes);
  if(*BreakMinutes > 60){
    printf(" Break minutes cannot be over 60 minutes");
  }
}

int timer(){
  int minutes = 0;

  int total_seconds = minutes * 60;

    while (total_seconds >= 0) {
        int h = total_seconds / 3600;
        int m = (total_seconds % 3600) / 60;
        int s = total_seconds % 60;

        printf("\033[H\033[J"); 

        int display_digits[4] = { m / 10, m % 10, s / 10, s % 10 };
        
        printf("TIME REMAINING (MM:SS):\n\n");
        printAsciiNumbers(display_digits, 4);

        fflush(stdout);

        clock_t stop = clock() + CLOCKS_PER_SEC;
        while (clock() < stop) { }

        total_seconds--;
    }
} 

int printAsciiNumbers(int digits[], int length) {
  const char *ascii_art[10][6] = {
      {"  ██████╗ ", " ██╔═████╗", " ██║██╔██║", " ████╔╝██║", " ╚██████╔╝", "  ╚═════╝ "}, // 0
      {"   ██╗    ", "  ███║    ", "  ╚██║    ", "   ██║    ", "   ██║    ", "   ╚═╝    "}, // 1
      {" ██████╗  ", " ╚════██╗ ", "  █████╔╝ ", " ██╔═══╝  ", " ███████╗ ", " ╚══════╝ "}, // 2
      {"  ██████╗ ", "  ╚════██╗", "   █████╔╝", "   ╚═══██╗", "  ██████╔╝", "  ╚═════╝ "}, // 3
      {" ██╗  ██╗ ", " ██║  ██║ ", " ███████║ ", " ╚════██║ ", "      ██║ ", "      ╚═╝ "}, // 4
      {" ███████╗ ", " ██╔════╝ ", " ███████╗ ", " ╚════██║ ", " ███████╗ ", " ╚══════╝ "}, // 5
      {"  ██████╗ ", " ██╔════╝ ", " ███████╗ ", " ██╔═══██╗", " ╚██████╔╝", "  ╚═════╝ "}, // 6
      {" ███████╗ ", " ╚══███╔╝ ", "   ███╔╝  ", "  ███╔╝   ", " ███╔╝    ", " ╚══╝     "}, // 7
      {"  █████╗  ", " ██╔══██╗ ", " ╚█████╔╝ ", "  ██╔══██╗", "  ╚█████╔╝", "   ╚════╝ "}, // 8
      {"  ██████╗ ", " ██╔══██╗ ", " ╚██████║ ", "  ╚═══██║ ", "  ██████╔╝", "  ╚═════╝ "}  // 9
  };

  for (int row = 0; row < 6; row++) {
    for (int i = 0; i < length; i++) {
        int digit = digits[i];
        // Safety
        if (digit >= 0 && digit <= 9) {
            printf("%s  ", ascii_art[digit][row]);
        }
    }
    printf("\n"); // Move to the next row of the ASCII block
}
}

void menu(){
  printf("______________________________________________________________\n");
  printf("|                                                              |\n");
  printf("|   ██████╗      ███████╗███████╗██████╗ ██╗     ██╗███╗   ██╗ ██████╗ ™\n");
  printf("|  ██╔════╝      ██╔════╝██╔════╝██╔══██╗██║     ██║████╗  ██║██╔════╝\n");
  printf("|  ██║     █████╗█████╗  █████╗  ██║  ██║██║     ██║██╔██╗ ██║██║  ███╗\n");
  printf("|  ██║     ╚════╝██╔══╝  ██╔══╝  ██║  ██║██║     ██║██║╚██╗██║██║   ██║\n");
  printf("|  ╚██████╗      ███████╗███████╗██████╔╝███████╗██║██║ ╚████║╚██████╔╝\n");
  printf("|   ╚═════╝      ╚══════╝╚══════╝╚═════╝ ╚══════╝╚═╝╚═╝  ╚═══╝ ╚═════╝\n");
  printf("|______________________________________________________________|");
  printf("Hello! Welcome to our app, what do you want to do cuh\n");
  printf("1. Set a new timer\n");
  printf("2. Check on the C-eedling™\n");
  printf("3. Quit\n");
}