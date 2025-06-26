using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SlotMachine
{
    public partial class SlotView : Form, ISlotView
    {
        private readonly SlotPresenter presenter;
        private int totalWinnings = 0; // Переменная для хранения общей суммы выигрыша

        public SlotView()
        {
            InitializeComponent();
            presenter = new SlotPresenter(this, new SlotModel());
        }

        public void SetSymbols(List<string> symbols)
        {
            label1.Text = symbols[0];
            label2.Text = symbols[1];
            label3.Text = symbols[2];
        }

        public void SetWinnings(int winnings)
        {
            winningsLabel.Text = $"Выигрыш: {winnings}";
        }

        private void spinButton_Click(object sender, EventArgs e)
        {
            presenter.SpinButtonClicked();
        }

        private void collectButton_Click(object sender, EventArgs e)
        {
            // Получаем текущий выигрыш из winningsLabel
            if (int.TryParse(winningsLabel.Text.Replace("Выигрыш: ", ""), out int currentWinnings))
            {
                totalWinnings += currentWinnings; // Добавляем к общей сумме
                totalWinningsLabel.Text = $"Общий выигрыш: {totalWinnings}"; // Отображаем общую сумму
                winningsLabel.Text = "Выигрыш: 0"; // Обнуляем текущий выигрыш
            }
        }
        public void SetTotalWinnings(int totalWinnings)
        {
            totalWinningsLabel.Text = $"Общий выигрыш: {totalWinnings}";
        }
    }

    public interface ISlotView
    {
        void SetSymbols(List<string> symbols);
        void SetWinnings(int winnings);
        void SetTotalWinnings(int totalWinnings);
    }
}