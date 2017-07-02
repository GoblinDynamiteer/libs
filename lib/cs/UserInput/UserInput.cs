using System;

namespace UserInput
{
    class User
    {
        static string errorText = "Faulty input, try again: ";

        /* Ask for integer input, with message */
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

        /* Ask for float input, with message */
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

        /* Ask for string input, with message */
        public static string InputString(string message)
        {
            Console.Write(message);
            return Console.ReadLine();
        }

        /* Ask for char input, with message */
        public static char InputChar(string message)
        {
            Console.Write(message);
            return Console.ReadKey(true).KeyChar;
        }

        /* Halt until keypress, with message */
        public static void PressAnyKey(string message)
        {
            Console.WriteLine(message);
            Console.ReadKey(true);
        }

        /* Check if a key is pressed down, non blocking */
        static bool PressedKey()
        {
            bool retval = false;

            /* KeyAvailable checks if a key is pressed down */
            if (Console.KeyAvailable)
            {
                /* Catch key input */
                Console.ReadKey(true);
                retval = true;
            }

            return retval;
        }

    }

}
