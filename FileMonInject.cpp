using System; 
using System.Collections.Generic; 
using System.Text; 
using System.Threading; 
using System.Runtime.InteropServices; 
using EasyHook; 
namespace FileMonInject 
{ 
 public class Main : EasyHook.IEntryPoint 
 { 
 FileMon.FileMonInterface Interface; 
 LocalHook CreateFileHook; 
 Stack<String> Queue = new Stack<String>(); 
 public Main( 
 RemoteHooking.IContext InContext, 
 String InChannelName) 
 { 
 // connect to host... 
 Interface = 
RemoteHooking.IpcConnectClient<FileMon.FileMonInterface>(InChannelName); 
 } 
 public void Run( 
 RemoteHooking.IContext InContext, 
 String InChannelName) 
 { 
 // install hook... 
 try 
 { 
 CreateFileHook = LocalHook.Create( 
 LocalHook.GetProcAddress("kernel32.dll", "CreateFileW"), 
 new DCreateFile(CreateFile_Hooked), 
this); 
 CreateFileHook.ThreadACL.SetExclusiveACL(new Int32[] { 0 }); 
 } 
 catch (Exception ExtInfo) 
 { 