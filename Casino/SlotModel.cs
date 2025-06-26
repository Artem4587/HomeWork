using System;
using System.Collections.Generic;

namespace SlotMachine
{
    public class SlotModel
    {
        private static readonly Random random = new Random();
        private readonly List<string> symbols = new List<string> { "Cherry", "Lemon", "Orange", "Plum", "Bell", "Bar" }; // Возможные символы

        public List<string> Spin()
        {
            List<string> result = new List<string>();
            for (int i = 0; i < 3; i++) // Три барабана
            {
                result.Add(symbols[random.Next(symbols.Count)]);
            }
            return result;
        }

        public int CalculateWinnings(List<string> result)
        {
            if (result[0] == result[1] && result[1] == result[2])
            {
                switch (result[0])
                {
                    case "Cherry": return 10;
                    case "Lemon": return 20;
                    case "Orange": return 30;
                    case "Plum": return 40;
                    case "Bell": return 50;
                    case "Bar": return 100;
                    default: return 0;
                }
            }
            else if (result[0] == "Cherry" && result[1] == "Cherry")
            {
                return 5;
            }
            else if (result[0] == "Cherry")
            {
                return 2;
            }

            return 0; // Нет выигрыша
        }
    }
}