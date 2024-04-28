import java.io.*;
import java.net.*;
import java.nio.charset.*;
import java.util.*;

public class TimeClient {
    
    private static final String IP = "106.15.72.83";
    
    private static final int POST = 13;
        
    public static void main(String[] args) throws IOException{
        try (Socket socket = new Socket(IP, 13);
        Scanner scanner = new Scanner(socket.getInputStream(), StandardCharsets.UTF_8)) {
            while(scanner.hasNextLine()) {
                System.out.println(scanner.nextLine());
            }
        }
        
    }
}