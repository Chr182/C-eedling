#include<stdio.h>
#include<time.h>

void menu();
int timer();
int printAsciiNumbers();

int main(){
  menu();
  timer();
  return 0;
}

int timer(){
  int minutes = 0;

  printf("How many minutes do you wanna study eh?: ");
  scanf("%d", &minutes);

  int total_seconds = minutes * 60;

    while (total_seconds >= 0) {
        // Calculate H:M:S for display
        int h = total_seconds / 3600;
        int m = (total_seconds % 3600) / 60;
        int s = total_seconds % 60;

        // Clear the screen (ANSI escape code) to keep the ASCII art in place
        printf("\033[H\033[J"); 

        // Prepare the digits for the ASCII printer (MM:SS style)
        // For simplicity, let's display the minutes and seconds
        int display_digits[4] = { m / 10, m % 10, s / 10, s % 10 };
        
        printf("TIME REMAINING (MM:SS):\n\n");
        printAsciiNumbers(display_digits, 4);

        fflush(stdout);

        // Pause for one second
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

void PrintHewooWowld(){
  printf("Hewwo Wowld\n");
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
  printf("3. Quit");
}