using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

namespace Game
{
    /* [Serializable] To be able to use 
     * BinaryFormatter.Serialize, saves/loads HSItem list
     * to binary data file */
    [Serializable]
    /* High Score item class */
    class HSItem : IComparable // IComparable - For sorting
    {
        private string name;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        private int points;
        public int Points
        {
            get { return points; }
            set { points = value; }
        }

        /* Constructor */
        public HSItem(string name, int points)
        {
            this.name = name;
            this.points = points;
        }

        /* For list sorting */
        public int CompareTo(object obj)
        {
            if (obj == null) return 1;

            HSItem otherItem = obj as HSItem;
            if (otherItem != null)
                return this.points.CompareTo(otherItem.points);
            else
                throw new ArgumentException("Object is not Points!");
        }

    }

    class HighScore
    {
        int maxItems;
        bool descendingSort; // Ascending or descending sort
        string filename = "highscore.dat";
        List<HSItem> highScoreList;

        /* Constructor */
        public HighScore(int maxItems = 10, bool descendingSort = true)
        {
            this.maxItems = maxItems;
            this.descendingSort = descendingSort;
            this.highScoreList = new List<HSItem>();
        }

        /* Add name and score to list */
        public void Add(string name, int points = 0)
        {
            if (name == "") // If no name is entered
            {
                name = "NO NAME";
            }

            highScoreList.Add(new HSItem(name, points));
            Sort();
        }

        /* Print list, for testing purpouses */
        public void Print()
        {
            Console.WriteLine(
                "******** HIGHSCORE ********");
            int place = 1;

            foreach (HSItem score in highScoreList)
            {
                Console.WriteLine(
                    "{0}. {1} {2} points",
                        place++, score.Name, score.Points);
            }
        }

        /* Sort list and remove item if needed */
        private void Sort()
        {
            highScoreList.Sort();

            /* Ascending / descending */
            if (descendingSort)
            {
                /* Reverse sorted list, if largest value
                 * shall be on top */
                highScoreList.Reverse();
            }

            /* Remove if over max items */
            while (highScoreList.Count > maxItems)
            {
                highScoreList.RemoveAt(highScoreList.Count - 1);
            }
        }

        /* Save high scores to file */
        public bool Save()
        {
            FileStream datafile = null;
            bool success = true;

            try
            {
                datafile = new FileStream(
                    this.filename, FileMode.Create);
            }
            /* Eg. If write protected */
            catch (Exception e)
            {
                Console.WriteLine("File error: " + e.Message);
                success = false;
            }

            if (success)
            {
                try
                {
                    BinaryFormatter formatter = new BinaryFormatter();
                    formatter.Serialize(datafile, highScoreList);
                }
                catch (Exception e)
                {
                    Console.WriteLine("Failed to save: " + e.Message);
                    success = false;
                }
                finally
                {
                    datafile.Close();
                }
            }

            return success;
        }

        /* Load high scores from file */
        public bool Load()
        {
            FileStream datafile = null;
            bool success = true;

            try
            {
                datafile = new FileStream(
                    this.filename, FileMode.Open);
            }

            /* If datafile does not exist, or write protected */
            catch (Exception e)
            {
                Console.WriteLine("File error: " + e.Message);
                success = false;
            }

            if (success)
            {
                try
                {
                    BinaryFormatter formatter = new BinaryFormatter();

                    /* Note: Overwrites list if it contains contents */
                    highScoreList = (List<HSItem>)formatter.Deserialize(datafile);
                }
                catch (Exception e)
                {
                    Console.WriteLine("Failed to load: " + e.Message);
                    success = false;
                }

                datafile.Close();
            }

            return success;

        }
    }
}

