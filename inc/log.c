
#define N_LINES_LOG 10
String logStr[N_LINES_LOG];
int logIdx = 0;
int logNrTotal = 0;

void writeLog(String str){
    logNrTotal++;

    int lastIdxOfLog = N_LINES_LOG-1;
    if(logIdx == lastIdxOfLog){
        for(int i=0; i < lastIdxOfLog; i++){
            logStr[i] = logStr[i+1];
        }
    }

    logStr[logIdx] = "";
    logStr[logIdx].concat(logNrTotal);
    logStr[logIdx].concat(" ");
    logStr[logIdx].concat(str);
    logStr[logIdx].concat("\n");

    if(logIdx < lastIdxOfLog)
        logIdx++;
}

void writeLog(int val){
    writeLog(String(val, 10));
}
