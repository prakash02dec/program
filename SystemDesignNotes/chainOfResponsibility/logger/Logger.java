package logger ; 

import logProcessor.* ; 

public class Logger {
    public static LogProcessor getLogger(){
        LogProcessor fatal = new FatalLogProcessor(null) ; 
        LogProcessor error = new ErrorLogProcessor(fatal) ;
        LogProcessor debug = new DebugLogProcessor(error) ;
        LogProcessor info = new InfoLogProcessor(debug) ;
        return  info ; 
    }
}
