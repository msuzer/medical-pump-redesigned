using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace AsyncSocketClient
{
    class TCPClientSocket
    {
        private const string PASS_CODE = "X16Q";

        Socket client = null;
        String message = "";
        IPEndPoint remoteEP;

        public TCPClientSocket(IPAddress hostIP, int port = 50000) {
            remoteEP = new IPEndPoint(hostIP, port);
        }

        public void SendMessage(String msg)
        {
            // Connect to a remote device.
            try
            {
                message = msg;
                client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                client.BeginConnect(remoteEP, new AsyncCallback(ConnectCallback), client);
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("Client.SendMessage(): " + exc.Message);
            }
        }

        private void ConnectCallback(IAsyncResult ar)
        {
            try
            {
                // Retrieve the socket from the state object.
                Socket client = (Socket)ar.AsyncState;
                // Complete the connection.
                client.EndConnect(ar);
                AppMainForm.getInstance().DebugMessage("Connected to " + client.RemoteEndPoint.ToString());
                Send();
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("Client.ConnectCallBack(): " + exc.Message);
            }
        }

        private void Send()
        {
            try
            {
                // Convert the string data to byte data using ASCII encoding.
                byte[] byteData = Encoding.ASCII.GetBytes(PASS_CODE + message);
                // Begin sending the data to the remote device.
                client.BeginSend(byteData, 0, byteData.Length, 0, new AsyncCallback(SendCallback), client);
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("Client.Send(): " + exc.Message);
            }
        }

        private void SendCallback(IAsyncResult ar)
        {
            try
            {
                // Retrieve the socket from the state object.
                Socket client = (Socket)ar.AsyncState;
                // Complete sending the data to the remote device.
                int bytesSent = client.EndSend(ar);
                //if (bytesSent == message.Length)
                AppMainForm.getInstance().msg("TX: " + message);
                AppMainForm.getInstance().DebugMessage("Disconnecting from " + client.RemoteEndPoint.ToString());

                client.Shutdown(SocketShutdown.Both);
                client.Close();
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("Client.SendCallBack(): " + exc.Message);
            }
        }
    }
}
