using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tester
{
    static class Printer
    {
        public static void About()
        {
            Console.WriteLine("Tester Version 1.1 Copyright (c) 2014,15 Konstantinov Ostap");
        }

        public static void InvalidArgument()
        {
            Console.WriteLine("Exception: Invalid Argument");
        }

        public static void InvalidCommand()
        {
            Console.WriteLine("Exception: Invalid Command");
        }

        public static void Help()
        {
            Console.WriteLine("Usage: Tester [command] [proc p.] [input f.] [output f.] [etalon f.]");
            Console.WriteLine("Commands: -h Help");
            Console.WriteLine("Examples: Tester -h");
            Console.WriteLine("          Tester e2_fscan.exe Input Output Etalon");
        }
    }
}
