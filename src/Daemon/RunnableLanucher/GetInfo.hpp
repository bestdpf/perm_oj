#ifndef _GET_INFO
#define _GET_INFO
/**
 *From hustoj src code
 */
#include<iostream>
#include<cstdio>
#include<unistd.h>
#include<stdlib.h>
#include<cstring>
using namespace std;
#define BUFFER_SIZE 1024
namespace Daemon{
int get_proc_status(int pid, const char * mark) {
        FILE * pf;
        char fn[BUFFER_SIZE], buf[BUFFER_SIZE];
        int ret = 0;
        sprintf(fn, "/proc/%d/status", pid);
        pf = fopen(fn, "r");
        int m = strlen(mark);
        while (pf && fgets(buf, BUFFER_SIZE - 1, pf)) {

                buf[strlen(buf) - 1] = 0;
                if (strncmp(buf, mark, m) == 0) {
                        sscanf(buf + m + 1, "%d", &ret);
                }
        }
        if (pf)
                fclose(pf);
        return ret;
}
}//end of Daemon
#endif
