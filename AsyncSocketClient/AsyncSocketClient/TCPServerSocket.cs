using System.Collections.Generic;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System;

namespace AsyncSocketClient
{
    class TCPServerSocket
    {
        //Stores the IP Adress the server listens on
        private IPAddress ip;

        //Stores the port the server listens on
        private int port;

        //Stores the counter of connected clients. *Note* The counter only gets increased, it acts as "id"
        private int clientCount = 0;

        //Defines if the server is running. When chaning to false the server will stop and disconnect all clients.
        private bool running = false;

        //Stores all connected clients.
        public List<Client> clients = new List<Client>();

        //Event to pass recived data to the main class
        public delegate void GotDataFromCTCHandler(object sender, string msg);
        public event GotDataFromCTCHandler GotDataFromCTC;

        //Constructor for Server. If autoStart is true, the server will automaticly start listening.
        public TCPServerSocket(int port = 40000)
        {
            this.ip = IPAddress.Any;
            this.port = port;
        }

        //Starts the server.
        public void Run()
        {
            if (this.running)
                return;
            //Run in new thread. Otherwise the whole application would be blocked
            new Thread(() =>
            {
                //Init TcpListener
                TcpListener listener = null;

                try
                {
                    listener = new TcpListener(this.ip, this.port);
                    listener.Server.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReuseAddress, 1);
                }
                catch (Exception exc) {
                    AppMainForm.getInstance().DebugMessage("Server.TcpListener(): " + exc.Message);
                    return;
                }

                this.running = true;

                try
                {
                    //Start listener
                    listener.Start();
                }
                catch (Exception exc) {
                    AppMainForm.getInstance().DebugMessage("Server.listener.Start(): " + exc.Message);
                    this.running = false;
                }
                //While the server should run
                while (running)
                {
                    try
                    {
                        if (listener.Pending()) { //Check if someone wants to connect
                            //Client connection incoming. Accept, setup data incoming event and add to client list
                            Client client = new Client(listener.AcceptTcpClient(), this.clientCount);
                            client.internalGotDataFromCTC += GotDataFromClient;
                            
                            clients.Add(client); //Add to list
                            this.clientCount++; //Increase client count
                        } else {
                            //No new connections. Sleep a little to prevent CPU from going to 100%
                            Thread.Sleep(100);
                        }
                    }
                    catch (Exception exc)
                    {
                        AppMainForm.getInstance().DebugMessage("Server.listener.Pending(): " + exc.Message);
                        this.running = false;
                    }
                }

                //When we land here running were set to false or another problem occured. Stop server and disconnect all.
                Stop();
            }).Start(); //Start thread. Lambda \(o.o)/
        }

        //Fires event for the user
        private void GotDataFromClient(object sender, string data)
        {
            //Data gets passed to parent class
            GotDataFromCTC(sender, data);
        }

        //Send string "data" to all clients in list "clients"
        public void SendToAll(string data)
        {
            //Call send method on every client. Lambda \(o.o)/
            try
            {
                this.clients.ForEach(client => client.Send(data));
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("Server.SendToAll(): " + exc.Message);
                this.running = false;
            }
        }

        //Stop server
        public void Stop()
        {
            //Exit listening loop
            this.running = false;

            try
            {
                //Disconnect every client in list "client". Lambda \(o.o)/
                this.clients.ForEach(client => client.Close());

                //Clear clients.
                this.clients.Clear();
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("Server.Stop(): " + exc.Message);
            }
        }
    }

    class Client
    {
        //Stores the TcpClient
        private TcpClient client;
        public string cip;

        //Stores the StreamWriter. Used to write to client
        private StreamWriter writer;

        //Stores the StreamReader. Used to recive data from client
        private StreamReader reader;

        //Defines if the client shuld look for incoming data
        private bool listen = true;

        //Stores clientID. ClientID = clientCount on connection time
        public int id;

        //Event to pass recived data to the server class
        public delegate void internalGotDataFromCTCHandler(object sender, string msg);
        public event internalGotDataFromCTCHandler internalGotDataFromCTC;

        //Constructor
        public Client(TcpClient client, int id)
        {
            //Assain members
            this.client = client;
            this.id = id;

            //Init the StreamWriter
            writer = new StreamWriter(this.client.GetStream());
            reader = new StreamReader(this.client.GetStream());
            //reader.BaseStream.ReadTimeout = 2000;

            cip = ((IPEndPoint)client.Client.RemoteEndPoint).Address.ToString();

            new Thread(() =>
            {
                Listen(reader);
            }).Start();
        }

        //Reads data from the connection and fires an event wih the recived data
        public void Listen(StreamReader reader)
        {
            AppMainForm.getInstance().UpdateClientList(this.cip, true);
            //AppMainForm.getInstance().changeConnectionStatus(true);
            //AppMainForm.getInstance().DebugMessage("Client " + this.cip + " connected.");
            //While we should look for new data
            while (listen)
            {
                //Read whole lines. This will read from start until \r\n" is recived!
                try
                {
                    string input = reader.ReadLine();
                    //If input is null the client disconnected. Tell the user about that and close connection.
                    if (input == null)
                    {
                        //Close
                        Close();

                        //Exit thread.
                        return;
                    }

                    internalGotDataFromCTC(this, input);

                }
                catch (Exception exc) {
                    AppMainForm.getInstance().DebugMessage("Server.Client.Listen(): " + exc.Message);
                    Close();
                }
            }
        }

        //Sends the string "data" to the client
        public void Send(string data)
        {
            try
            {
                //Write and flush data
                writer.WriteLine(data);
                writer.Flush();
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("Server.Client.Send(): " + exc.Message);
            }
        }

        //Closes the connection
        public void Close()
        {
            //Stop listening
            listen = false;

            //Inform user
            AppMainForm.getInstance().UpdateClientList(this.cip, false);

            try
            {
                //Close streamwriter FIRST
                writer.Close();

                //Then close connection
                client.Close();

                AppMainForm.getInstance().DebugMessage("Server.Client.Close(): Closed the connection!");
            }
            catch (Exception exc)
            {
                AppMainForm.getInstance().DebugMessage("Server.Client.Close(): " + exc.Message);
            }
        }
    }
}
