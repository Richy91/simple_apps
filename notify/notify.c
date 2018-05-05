#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <libnotify/notify.h>

int get_available_mem(void);
void print(void);

int main(int argc, char *argv[])
{
    float stringnum;
    NotifyNotification *notify;

    for(;;) {
    sleep(5);

    stringnum = get_available_mem();

    if (stringnum / 1000 < 5000) {

        notify_init ("notify");


        notify = notify_notification_new ("Memory notification",
                         "Your memory is less than 500 MB. Close some apps",
                         "gtk-info");


        notify_notification_show (notify,
                                   NULL);

        notify_uninit ();

        printf("Low memory\n");
    }
    printf("%.3f\n", stringnum);

    }

}


int get_available_mem(void)
{
    char word_to_search[] = "MemAvailable:";
    char numarr[20], i = 0, text[1000], *ret;
    int number;
    float stringnum;

    FILE *fp = fopen("/proc/meminfo", "r");

    while(!feof(fp)) {

    fgets(text, 1000, fp);
        if(strstr(text, word_to_search)) {
            //printf("%s", text);
            ret = strchr(text, ' ');
            //printf("%s", ret);
            ret++;
            while(*ret == ' ') {
                ret++;
            }
            while(*ret != ' ') {
                numarr[i] = *ret;
                i++;
                ret++;
                number = i;
            }

        }

    }

    stringnum = atoi(numarr);

    fclose(fp);

    return stringnum;
}

void print(void)
{
    printf("WHAT?");
}