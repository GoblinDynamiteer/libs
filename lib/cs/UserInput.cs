using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UserInput
{
    class User
    {
        static string errorText = "Faulty input, try again: ";

        public static int InputInt(string message)
        {
            Console.Write(message);
            int retVal = 0;
            while (!int.TryParse(Console.ReadLine(), out retVal))
            {
                Console.Write(errorText);
            }
            return retVal;
        }

        public static float InputFloat(string message)
        {
            Console.Write(message);
            float retVal = 0;
            while (!float.TryParse(Console.ReadLine(), out retVal))
            {
                Console.Write(errorText);
            }
            return retVal;
        }

        public static string InputString(string message)
        {
            Console.Write(message);
            return Console.ReadLine();
        }

        public static void PressAnyKey(string message)
        {
            Console.WriteLine(message);
            Console.ReadKey(true);
        }

        public static char InputChar(string message)
        {
            Console.Write(message);
            return Console.ReadKey(true).KeyChar;
        }
    }

}
