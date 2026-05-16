#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

void menu();
void timer();
int printASCIINumbers();
void inputTime();
void printASCIITree();

int main(){
  int exit = 0;
  int menuOption;
  do{
    menu();
    printf("Input menu: ");
    scanf("%d", &menuOption);
  
    int sessionMinutes, breakMinutes, sessions, currentSession = 0;
    switch(menuOption){
      case 1:
        while(currentSession <= sessions){
          inputTime(&sessions, &sessionMinutes, &breakMinutes, menuOption);
          /*Timer for session*/
          timer(sessionMinutes, &exit);
          if(exit == 1) break;
          currentSession++;
          if(currentSession == sessions) break;
          /*Tree grows*/
          /*Timer for break*/
          timer(breakMinutes, &exit);
          
        }
        break;
  
      case 2:
        inputTime(&sessions, &sessionMinutes, &breakMinutes, menuOption);
        printf("%d \n %d \n %d", sessions, sessionMinutes, breakMinutes);
        int totalMinutes = ((sessions*sessionMinutes) + (sessions-1)*breakMinutes);
  
        while(currentSession <= sessions){
          /*Timer for session*/
        
          /*Tree grows*/
          /*Timer for break*/
        }
        break;
  
    }
  }
  while(exit != 1);
  
  
  return 0;
}

void inputTime(int *sessions, int *sessionMinutes, int *breakMinutes, int menuOption){
  if(menuOption = 1){
    *sessions = 4;
    *sessionMinutes = 25;
    *breakMinutes = 5;
    return;
  }

  printf("Input Amount of sessions: ");
  scanf("%d", sessions);

  printf("Input Minutes per Session: ");
  scanf("%d", sessionMinutes);
  if(*sessionMinutes > 50){
    printf(" Each session has to be below 50 minutes");
  }

  printf("Input Minutes per Break: ");
  scanf("%d", breakMinutes);
  if(*breakMinutes > 60){
    printf(" Break minutes cannot be over 60 minutes");
  }
  
}

void timer(int minutes, int *exit){
  int totalSeconds = minutes * 60;
  int paused = 0;
  int needsFixFlicker = 1;

  while (totalSeconds >= 0) {
    if(kbhit()){
      char key = getch();
      if(key == ' '){
        paused = !paused;
        needsFixFlicker = 1;
      }
      if(key == 's'){
        return;
      }
      if(key == 'q'){
        *exit = 1;
        return;
      }
    }

    if(!needsFixFlicker){
      Sleep(100);
      continue;
    }

    int h = totalSeconds / 3600;
    int m = (totalSeconds % 3600) / 60;
    int s = totalSeconds % 60;

    printf("\033[2J\033[3J\033[H");

    printASCIITree();

    int displayDigits[5] = { m / 10, m % 10, 10, s / 10, s % 10 };
        
    printf("\t\t       TIME REMAINING (MM:SS):\n\n");
    printASCIINumbers(displayDigits);

    if(paused){
      printf("\n\n\t\t    PAUSED - Press SPACE to resume\n");
    }
    else printf("\n\n\t\t         Press SPACE to pause\n");

    printf("\n\t\t       Press s to skip the timer\n");
    printf("\n\t\t       Press q to quit the timer\n");

    fflush(stdout);
    needsFixFlicker = 0;

    if(paused){
      Sleep(100);
      continue;
    }

    Sleep(1000);

    totalSeconds--;
    needsFixFlicker = 1;
    }
} 

int printASCIINumbers(int digits[]) {
  const char *ascii_art[11][6] = {
      {"  ██████╗ ", " ██╔═████╗", " ██║██╔██║", " ████╔╝██║", " ╚██████╔╝", "  ╚═════╝ "}, // 0
      {"   ██╗    ", "  ███║    ", "  ╚██║    ", "   ██║    ", "   ██║    ", "   ╚═╝    "}, // 1
      {" ██████╗  ", " ╚════██╗ ", "  █████╔╝ ", " ██╔═══╝  ", " ███████╗ ", " ╚══════╝ "}, // 2
      {"  ██████╗ ", "  ╚════██╗", "   █████╔╝", "   ╚═══██╗", "  ██████╔╝", "  ╚═════╝ "}, // 3
      {" ██╗  ██╗ ", " ██║  ██║ ", " ███████║ ", " ╚════██║ ", "      ██║ ", "      ╚═╝ "}, // 4
      {" ███████╗ ", " ██╔════╝ ", " ███████╗ ", " ╚════██║ ", " ███████╗ ", " ╚══════╝ "}, // 5
      {"  ██████╗ ", " ██╔════╝ ", " ███████╗ ", " ██╔═══██╗", " ╚██████╔╝", "  ╚═════╝ "}, // 6
      {" ███████╗ ", " ╚══███╔╝ ", "   ███╔╝  ", "  ███╔╝   ", " ███╔╝    ", " ╚══╝     "}, // 7
      {"  █████╗  ", " ██╔══██╗ ", " ╚█████╔╝ ", "  ██╔══██╗", "  ╚█████╔╝", "   ╚════╝ "}, // 8
      {"  ██████╗ ", " ██╔══██╗ ", " ╚██████║ ", "  ╚═══██║ ", "  ██████╔╝", "  ╚═════╝ "}, // 9
      {"    ", " ██╗", " ╚═╝", " ██╗", " ╚═╝", "    "} // :
  };

  for (int row = 0; row < 6; row++) {
    printf("         ");
    for (int i = 0; i < 5; i++) {
        int digit = digits[i];
        // Safety
        if (digit >= 0 && digit <= 10) {
            printf("%s  ", ascii_art[digit][row]);
        }
    }
    printf("\n");
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
  printf("|______________________________________________________________|\n");
  printf("Hello! Welcome to our app, what do you want to do cuh\n");
  printf("1. Default Pomodoro Timer\n");
  printf("2. Customizable Pomodoro Timer\n");
  printf("3. Quit\n");
}

void printASCIITree(){
  printf("     ============================================================\n");
  printf("     |                                                          |\n");
  printf("     |                                                          |\n");
  printf("     |                                                          |\n");
  printf("     |                                                          |\n");
  printf("     |                                                          |\n");
  printf("     |                                                          |\n");
  printf("     |                                                          |\n");
  printf("     |                                                          |\n");
  printf("     |                                                          |\n");
  printf("     ============================================================\n");
}