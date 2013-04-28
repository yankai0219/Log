#include "log.h"

int main(int argc,char **argv)
{
    DEBUG("YK:%s\n","WHO");
    if(argc != 2){
       err_exit("parameter is NOT 2\n");
    }
    log_t log={NULL,NULL,write_log,open_log,free_log};
    log.openlog(&log,argv[1]);
    log.writelog(&log," SUCCEED");
    log.freelog(&log);
    printf("succeed\n");
    return 0;

}
