using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SlotMachine
{
    public partial class SlotView : Form, ISlotView
    {
        private readonly SlotPresenter presenter;
        private int totalWinnings = 0; // ���������� ��� �������� ����� ����� ��������

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
            winningsLabel.Text = $"�������: {winnings}";
        }

        private void spinButton_Click(object sender, EventArgs e)
        {
            presenter.SpinButtonClicked();
        }

        private void collectButton_Click(object sender, EventArgs e)
        {
            // �������� ������� ������� �� winningsLabel
            if (int.TryParse(winningsLabel.Text.Replace("�������: ", ""), out int currentWinnings))
            {
                totalWinnings += currentWinnings; // ��������� � ����� �����
                totalWinningsLabel.Text = $"����� �������: {totalWinnings}"; // ���������� ����� �����
                winningsLabel.Text = "�������: 0"; // �������� ������� �������
            }
        }
        public void SetTotalWinnings(int totalWinnings)
        {
            totalWinningsLabel.Text = $"����� �������: {totalWinnings}";
        }
    }

    public interface ISlotView
    {
        void SetSymbols(List<string> symbols);
        void SetWinnings(int winnings);
        void SetTotalWinnings(int totalWinnings);
    }
}