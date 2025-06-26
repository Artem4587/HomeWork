using System;
using System.Windows.Forms;

namespace SlotMachine
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new SlotView()); // Запуск SlotView
        }
    }
}