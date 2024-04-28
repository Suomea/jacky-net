import java.io.*;
import java.net.*;
import java.time.*;
import java.time.format.*;

public class TimeServer {
    
    private static final int PORT = 13;
    
    private static DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss.SSS");
    
    public static void main(String[] args) {
        try(ServerSocket ss = new ServerSocket(PORT)) {
            while(true) {
                try (Socket socket = ss.accept()) {
                    PrintWriter out = new PrintWriter(socket.getOutputStream());
                    out.println(LocalDateTime.now().format(dtf));
                    out.flush();
                } catch(IOException e) {
                    e.printStackTrace();
                }
            }
            
        } catch(IOException e) {
            e.printStackTrace();
        }
    } 
}