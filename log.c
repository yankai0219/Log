#include "log.h"
void err_exit(char *fmt,...)
{
    char buf[2048]={0};
    va_list ap;
    int n;
    va_start(ap,fmt);
    time_t timep;
    time(&timep);
    printf("%s",ctime(&timep));
    n = sprintf(buf,"%s:%d error",__FILE__,__LINE__);
    vsprintf(buf+n,fmt,ap);
    printf("buf:%s",buf);
    va_end(ap);
    exit(0);
}
int write_log(log_t *log,char *fmt,...)
{
    va_list ap;
    time_t timep;
    va_start(ap,fmt);
    time(&timep);
    fprintf(log->fp,"%s",ctime(&timep));
    fprintf(log->fp,"%s:%d",__FILE__,__LINE__);
    vfprintf(log->fp,fmt,ap);
    fprintf(log->fp,"\n");
    va_end(ap);
    return 0;
}

int open_log(log_t *log,char *filepath)
{
    int filepath_len = strlen(filepath);
    log->file_path = (char*)calloc(filepath_len+1,sizeof(char));
    strncpy(log->file_path,filepath,filepath_len);
    log->file_path[filepath_len]='\0';
    
    log->fp = fopen(log->file_path,"w+");
    if(log->fp == NULL){
       err_exit("fopen error\n"); 
   }
   return 0;
}
int free_log(log_t *log)
{
    free(log->file_path);
    fclose(log->fp);
    return 0;

}
