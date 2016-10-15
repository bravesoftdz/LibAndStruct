using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

namespace Tester
{
    static class RunMode
    {
        private static bool FileCompare(string file1, string file2)
        {
            if (file1 == file2)
                return true;

            int file1byte;
            int file2byte;

            using (FileStream fs1 = File.OpenRead(file1),
                fs2 = File.OpenRead(file2))
            {
                if (fs1.Length != fs2.Length)
                    return false;

                do
                {
                    file1byte = fs1.ReadByte();
                    file2byte = fs2.ReadByte();
                }
                while ((file1byte == file2byte) && (file1byte != -1));
            }

            return (file1byte == file2byte);
        }


        public static void FullLog(string phProcess, string phInput, string phOutput, string phEtalon)
        {
            if (!Directory.Exists(phOutput) && Directory.Exists(phInput))
                Directory.CreateDirectory(phOutput);

            const string logFl = "Log.txt";
            int good = 0, bad = 0;
            DateTime start = DateTime.Now;

            using (StreamWriter sw = File.AppendText(logFl)) {
                sw.WriteLine("Start at: " + start);
                sw.WriteLine("Folder: " + phInput);
                sw.WriteLine();
            }

            foreach (string inpFl in Directory.EnumerateFiles(phInput, "*.in"))
            {
                string shInpFl = Path.GetFileNameWithoutExtension(inpFl);
                string outFl = phOutput + "\\" + shInpFl + ".out";
                string etFl = phEtalon + "\\" + shInpFl + ".et";

                // Переопределение потов дочернего процесса
                Process p = new Process();
                p.StartInfo.UseShellExecute = false;
                p.StartInfo.RedirectStandardInput = true;
                p.StartInfo.RedirectStandardOutput = true;
                p.StartInfo.FileName = phProcess;
                p.Start();
                using (StreamReader sr = new StreamReader(inpFl))
                {
                    p.StandardInput.Write(sr.ReadToEnd());
                }

                using (StreamWriter sw = new StreamWriter(outFl))
                {
                    sw.Write(p.StandardOutput.ReadToEnd());
                }
                p.WaitForExit();

                using (StreamWriter sw = File.AppendText(logFl))
                {
                    string test = shInpFl + ": ";

                    if (File.Exists(etFl))
                        if (FileCompare(outFl, etFl))
                        {
                            test += "OK";
                            ++good;
                        }
                        else
                        {
                            test += "ERROR";
                            ++bad;
                        }
                    else
                        test += "NOT TESTED";

                    Console.WriteLine(test);
                    sw.WriteLine(test);
                }
            }

            Console.WriteLine();
            Console.WriteLine("Successful: " + good);
            Console.WriteLine("Failed: " + bad);
            Console.WriteLine("------------------");

            using (StreamWriter sw = File.AppendText(logFl))
            {
                DateTime finish = DateTime.Now;
                double leftTime = (finish - start).TotalMilliseconds;

                sw.WriteLine();
                sw.WriteLine("Spent time: " + leftTime + "ms");
                sw.WriteLine("total test passed: " + (good + bad));
                sw.WriteLine("successful: " + good);
                sw.WriteLine("failed: " + bad);
                sw.WriteLine("==================================");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                switch (args.Length)
                {
                    case 0:
                        Printer.About();
                        break;

                    case 1:
                        switch (args[0])
                        {
                            case "-h":
                                Printer.Help();
                                break;
                            default:
                                Printer.InvalidCommand();
                                break;
                        }
                        break;

                    case 4:
                        RunMode.FullLog(args[0], args[1], args[2], args[3]);
                        break;

                    default:
                        Printer.InvalidArgument();
                        break;
                }
            }
            catch (Exception e)
            {
                Console.Error.WriteLine("Error: " + e.Message);
            }
        }
    }
}
