package tcp;

import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.TimeUnit;

public class NagleClient {

    private static final String HOST = "106.15.72.83";
    
    private static final int PORT = 9999;

    public static void main(String[] args) throws Exception {
        Socket socket = new Socket();
        socket.setTcpNoDelay(true);
        socket.connect(new InetSocketAddress(HOST, PORT));
        OutputStream out = socket.getOutputStream();
        byte[] request = new byte[10];
        for (int i = 0; i < 5; i ++) {
            out.write(request);
        }

        TimeUnit.SECONDS.sleep(1);
        socket.close();
    }
}
