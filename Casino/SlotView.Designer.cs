namespace SlotMachine
{
    partial class SlotView
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.spinButton = new System.Windows.Forms.Button();
            this.winningsLabel = new System.Windows.Forms.Label();
            this.collectButton = new System.Windows.Forms.Button();
            this.totalWinningsLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            //
            // label1
            //
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(70, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(39, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "Label1";
            //
            // label2
            //
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(150, 50);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(39, 15);
            this.label2.TabIndex = 1;
            this.label2.Text = "Label2";
            //
            // label3
            //
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(230, 50);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(39, 15);
            this.label3.TabIndex = 2;
            this.label3.Text = "Label3";
            //
            // spinButton
            //
            this.spinButton.Location = new System.Drawing.Point(50, 100);
            this.spinButton.Name = "spinButton";
            this.spinButton.Size = new System.Drawing.Size(75, 23);
            this.spinButton.TabIndex = 3;
            this.spinButton.Text = "Spin";
            this.spinButton.UseVisualStyleBackColor = true;
            this.spinButton.Click += new System.EventHandler(this.spinButton_Click);
            //
            // winningsLabel
            //
            this.winningsLabel.AutoSize = true;
            this.winningsLabel.Location = new System.Drawing.Point(130, 150);
            this.winningsLabel.Name = "winningsLabel";
            this.winningsLabel.Size = new System.Drawing.Size(68, 15);
            this.winningsLabel.TabIndex = 4;
            this.winningsLabel.Text = "Выигрыш: 0";
            //
            // collectButton
            //
            this.collectButton.Location = new System.Drawing.Point(200, 100);
            this.collectButton.Name = "collectButton";
            this.collectButton.Size = new System.Drawing.Size(120, 23);
            this.collectButton.TabIndex = 5;
            this.collectButton.Text = "Собрать выигрыш";
            this.collectButton.UseVisualStyleBackColor = true;
            this.collectButton.Click += new System.EventHandler(this.collectButton_Click);
            //
            // totalWinningsLabel
            //
            this.totalWinningsLabel.AutoSize = true;
            this.totalWinningsLabel.Location = new System.Drawing.Point(130, 175);
            this.totalWinningsLabel.Name = "totalWinningsLabel";
            this.totalWinningsLabel.Size = new System.Drawing.Size(96, 15);
            this.totalWinningsLabel.TabIndex = 6;
            this.totalWinningsLabel.Text = "Общий выигрыш: 0";
            //
            // SlotView
            //
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(350, 200);
            this.Controls.Add(this.totalWinningsLabel);
            this.Controls.Add(this.collectButton);
            this.Controls.Add(this.winningsLabel);
            this.Controls.Add(this.spinButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "SlotView";
            this.Text = "Slot Machine";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button spinButton;
        private System.Windows.Forms.Label winningsLabel;
        private System.Windows.Forms.Button collectButton;
        private System.Windows.Forms.Label totalWinningsLabel;
    }
}