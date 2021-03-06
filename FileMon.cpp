using System;
using System.Collections.Generic;
using System.Runtime.Remoting;
using System.Text;
using EasyHook;

namespace FileMon
{
    public class FileMonInterface : MarshalByRefObject
    {
        public void IsInstalled(Int32 InClientPID)
        {
            Console.WriteLine("FileMon has been installed in target {0}.\r\n", InClientPID);
        }

        public void OnCreateFile(Int32 InClientPID, String[] InFileNames)
        {
            for (int i = 0; i < InFileNames.Length; i++)
            {
                Console.WriteLine(InFileNames[i]);
            }
        }

        public void ReportException(Exception InInfo)
        {
            Console.WriteLine("The target process has reported" + 
                              " an error:\r\n" + InInfo.ToString());
        }

      public void Ping()
        {
        }
    }

    class Program
    {
        static String ChannelName = null;

        static void Main(string[] args)
        {
			Int32 TargetPID = 0;
			//Added
			
			if ((args.Length != 1) || !Int32.TryParse(args[0], out TargetPID))
			{
				Console.WriteLine();
				Console.WriteLine("Usage: FileMon %PID%");
				Console.WriteLine();

				// return;
			}


            try
            {                
				//Im thinking it registers the hook??
            Config.Register(
                    "A FileMon like demo application.",
                    "FileMon.exe",
                    "FileMonInject.dll");

                RemoteHooking.IpcCreateServer<FileMonInterface>(
                     ref ChannelName, WellKnownObjectMode.SingleCall);
				//Added
				//Gets Processlist
				Process[] ProcList = Process.GetProcesses();
				String FileName;
				Int32 Id;
				//Looks for notepad and gets its PID..very Useful
				for (int i = 0; i < ProcList.Length; i++)
				{
					Process Proc = ProcList[i];
					FileName = Proc.ProcessName;
					Id = Proc.Id;
					if (FileName == "notepad")
						TargetPID = Id;
				}

				RemoteHooking.Inject(

					//Int32.Parse(args[0]),
					TargetPID = Id;
					"FileMonInject.dll",
                    "FileMonInject.dll",
                    ChannelName);

                Console.ReadLine();
            }
            catch (Exception ExtInfo)
            {
                Console.WriteLine("There was an error while connecting " + 
                                  "to target:\r\n{0}", ExtInfo.ToString());
            }
        }
    }
}