#include <stdio.h>
#include <unistd.h>

#define REBOOT 1
#define COUNT  2
#define SHOW   3
#define HELP   4

#define FILENAME "/etc/reboots"

    int get_reboots(void);
    int show(void);
    int count(void);
    int reboot(void);
    int help(void);

int main(int argc, char *argv[]) {

    unsigned int job = 0;

    while ((++argv)[0]) {
        if (argv[0][0] == '-' ) {
            switch (argv[0][1])  {
                    case 'h':
                            job = HELP;
                            break;
                    case 's':
                            job = SHOW;
                            break;
                    case 'c':
                            job = COUNT;
                            break;
                    case 'r':
                            job = REBOOT;
                            break;
                    default:
                            job = HELP;
                            break;
            }
        }
    }


    if (job == HELP)   help();
    if (job == SHOW)   show();
    if (job == COUNT)  count();
    if (job == REBOOT) reboot();



return 0;
}


    int help(void) {
        printf("-h \t Hilfe\n");
        printf("-s \t Anzahl reboots anzeigen\n");
        printf("-c \t Anzahl reboots erhoehen\n");
        printf("-r \t Reboot\n");
    return 0;
    }


int get_reboots(void) {

    FILE *fptr;
    int num = 0;

    if( access( FILENAME, F_OK ) == 0 ) {
        fptr = fopen(FILENAME, "r");
        if (fptr != NULL) {
            num = getw(fptr);
        } else {
            printf("Failed to open the file.\n");
        return -1;
        }
      fclose(fptr);
    }
return num;
}


int show(void) {

    printf("%d", get_reboots());

return 0;
}


int count(void) {

    int num = 0;
    FILE *fptr;

    num = get_reboots();

    fptr = fopen(FILENAME, "w");
    if (fptr != NULL) {
        putw(++num, fptr);
    } else {
        printf("Failed to create the file.\n");
    return -1;
    }
    fclose(fptr);
return 0;
}


int reboot(void) {

    system("reboot");

return 0;
}




