package tcp;

import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.TimeUnit;

public class NagleClient {

    public static void main(String[] args) throws Exception {
        Socket socket = new Socket();
        socket.setTcpNoDelay(true);
        socket.connect(new InetSocketAddress("172.31.8.118", 9999));
        OutputStream out = socket.getOutputStream();
        byte[] request = new byte[10];
        for (int i = 0; i < 5; i ++) {
            out.write(request);
        }

        TimeUnit.SECONDS.sleep(1);
        socket.close();
    }
}
