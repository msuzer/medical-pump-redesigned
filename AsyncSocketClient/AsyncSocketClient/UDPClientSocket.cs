using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace AsyncSocketClient
{
    public class UdpState
    {
        public UdpState(UdpClient cl, IPEndPoint ep) {
            client = cl;
            endPoint = ep;
        }

        public UdpClient client;
        public IPEndPoint endPoint;
    }

    public class UDPClientSocket
    {
        IPEndPoint remoteEP = new IPEndPoint(IPAddress.Broadcast, 30000);
        UdpClient client = null;

        public void SendMessage(String message)
        {
            try
            {
                client = new UdpClient();
                client.EnableBroadcast = true;
                IPEndPoint serverEp = new IPEndPoint(IPAddress.Any, 0);
                UdpState state = new UdpState(client, serverEp);
                byte[] RequestData = Encoding.ASCII.GetBytes(message);
                client.Send(RequestData, RequestData.Length, remoteEP);
                AppMainForm.getInstance().msg("TX: " + message);
                client.BeginReceive(new AsyncCallback(ReceiveCallback), state);
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("UDPClient.SendMessage(): " + exc.ToString());
            }
        }

        public static void ReceiveCallback(IAsyncResult ar)
        {
            try
            {
                UdpClient client = ((UdpState)(ar.AsyncState)).client;
                IPEndPoint endPoint = ((UdpState)(ar.AsyncState)).endPoint;
                Byte[] receiveBytes = client.EndReceive(ar, ref endPoint);
                string receiveString = Encoding.ASCII.GetString(receiveBytes);
                AppMainForm.getInstance().msg("RX: <" + endPoint.Address + "> " + receiveString);
                client.Close();
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("UDPClient.ReceiveCallback(): " + exc.ToString());
            }
        }
    }
}
