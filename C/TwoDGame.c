#include <stdio.h>
#include <stdbool.h>

int main(int argc, char **argv) {
    char map[20][100];
    for(int i=0; i<20; i++){
            for(int j=0; j<100; j++){
                map[i][j] = NULL;
             //   printf("%c", map[i][j]);
        }
    }

    map[2][2] = 'P';

    bool proceed = true;
    bool argsCheck = false;

    int argsRunIndex = 0;

    char directions[][5] = {"North", "East", "South", "West"};
    static int directionX[] = {0, -1, 0, 1};
    static int directionY[] = {1, 0, -1, 0};

    static int currentDirection = 0;

    int currentPosition[] = {2,2};

    char input;

    while(proceed){
       // printf("%c", map[0][0]);
        for(int i=0; i<20; i++){
            for(int j=0; j<100; j++){
                //printf("%c", map[i][j]);
                if(map[i][j] == '\0'){
                    printf("%c", 'x');

                }else{
                    printf("%c", map[i][j]);
                }
            }
            printf("\n");
        }

        printf("Please traverse the world and explore using these commands: \n  W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game\n");

        
        scanf("%s", &input);
        switch(input){
            case 'w':
                printf("Walking\n");
                map[currentPosition[1]][currentPosition[0]] = '#';
                if(!((currentPosition[0] - directionX[currentDirection] < 0) || (currentPosition[0] - directionX[currentDirection] > 100)||(currentPosition[1] - directionY[currentDirection] < 0) || (currentPosition[1] - directionY[currentDirection] > 20))){
                    
                    currentPosition[0] = currentPosition[0] - directionX[currentDirection];
                    currentPosition[1] = currentPosition[1] - directionY[currentDirection];
                    
                }
                map[currentPosition[1]][currentPosition[0]] = 'P';
                break;
            case 'a':
                currentDirection--;
                    //moves your index up or down the 3 arrays listed above
                    if(currentDirection < 0){
                        currentDirection = 3;
                    }
                    break;
            case 'd':
                currentDirection++;
                    //moves your index up or down the 3 arrays listed above

                    if(currentDirection > 3){
                        currentDirection = 0;
                    }
                    break;
            case 'e':
                printf("You are facing in the %sward direction!\n\n", directions[currentDirection]);
                break;
            case 'q':
                proceed = false;
                break;
            default:
                printf("You must enter one of the commands!\n\n");
                break;
        }
    }

    return 0;
}