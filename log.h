
/*
* Copyright (C) Yankai
*/


#ifndef _LOG_H_
#define _LOG_H_

#include "common.h"


typedef struct log_s log_t;
typedef int (*write_log_pt)(log_t *log,char *fmt,...);
typedef int (*open_log_pt)(log_t *log,char *filepath);
typedef int (*free_log_pt)(log_t *log);


int free_log(log_t *log);
int open_log(log_t *log,char *filepath);
int write_log(log_t *log,char *fmt,...);


struct log_s {
    FILE* fp;
    char *file_path;
    write_log_pt writelog;    
    open_log_pt openlog;
    free_log_pt freelog;
};


void err_exit(char *fmt,...);


#endif
